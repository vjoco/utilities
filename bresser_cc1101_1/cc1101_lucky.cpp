#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <linux/spi/spidev.h>

#include "CC1101/CC1101.h"
#include "Module.h"

#include "luckhal.h"

 #include <signal.h>

 #include <time.h>


#define SPI_DEVICE1 "/dev/spidev0.0"


typedef enum DecodeStatus {
    DECODE_OK, DECODE_PAR_ERR, DECODE_CHK_ERR, DECODE_DIG_ERR
} DecodeStatus;


struct WeatherData_S {
    uint8_t  s_type;               // only 6-in1
    uint32_t sensor_id;            // 5-in-1: 1 byte / 6-in-1: 4 bytes
    uint8_t  chan;                 // only 6-in-1
    bool     temp_ok;              // only 6-in-1
    float    temp_c;
    int      humidity;
    bool     uv_ok;                // only 6-in-1
    float    uv;                   // only 6-in-1
    bool     wind_ok;              // only 6-in-1
    float    wind_direction_deg;
    float    wind_gust_meter_sec;
    float    wind_avg_meter_sec;
    bool     rain_ok;              // only 6-in-1
    float    rain_mm;
    bool     battery_ok;
    bool     moisture_ok;          // only 6-in-1
    int      moisture;             // only 6-in-1
};

typedef struct WeatherData_S WeatherData_t;

// Weather data object
WeatherData_t weatherData;

//int state = radio.begin(868.35, 8.22, 57.136417, 270.0, 10, 32);
/*
begin()
int16_t CC1101::begin	(	float 	freq = RADIOLIB_CC1101_DEFAULT_FREQ,
float 	br = RADIOLIB_CC1101_DEFAULT_BR,
float 	freqDev = RADIOLIB_CC1101_DEFAULT_FREQDEV,
float 	rxBw = RADIOLIB_CC1101_DEFAULT_RXBW,
int8_t 	pwr = RADIOLIB_CC1101_DEFAULT_POWER,
uint8_t 	preambleLength = RADIOLIB_CC1101_DEFAULT_PREAMBLELEN 
)	

radio.begin(868.35, 8.22, 57.136417, 270.0, 10, 32);
*/

//PiHal* hal = new PiHal(1);
 
RadioLibHal* hal=new luckhal(1);
CC1101 radio = new Module(hal, 10, 2, RADIOLIB_NC, 3);


    int spi_fd;
    unsigned char tx_buffer[200] = {0x01, 0x02}; // Example data to be transmitted
    unsigned char rx_buffer[200];

    struct spi_ioc_transfer tr = {
        .tx_buf = (unsigned long)tx_buffer,
        .rx_buf = (unsigned long)rx_buffer,
        .len = sizeof(tx_buffer),
    };

#define PARTNUM        0xF0   // Part number
#define VERSION        0xF1   // Current version number

#define WRITE_SINGLE_BYTE   0x00
#define WRITE_BURST         0x40
#define READ_SINGLE_BYTE    0x80
#define READ_BURST          0xC0

volatile sig_atomic_t stop = 0;

// Signal handler for Ctrl+C
void sigint_handler(int signum) {
    stop = 1;
}






DecodeStatus decodeBresser5In1Payload(uint8_t *msg, uint8_t msgSize, WeatherData_t *pOut) { 
    // First 13 bytes need to match inverse of last 13 bytes
    for (unsigned col = 0; col < msgSize / 2; ++col) {
      //  printf("%d %02X %02X %02X should be %02X\n",col, msg[col] , msg[col + 13], msg[col] ^ msg[col + 13], msg[col] ^ 0xFF );
        if ((msg[col] ^ msg[col + 13]) != 0xff) {
         //   printf("%s: Parity wrong at %u\n", __func__, col);
           // return DECODE_PAR_ERR;
        }
    }

#if 0
    // Verify checksum (number number bits set in bytes 14-25)
    uint8_t bitsSet = 0;
    uint8_t expectedBitsSet = msg[13];

    for(uint8_t p = 14 ; p < msgSize ; p++) {
      uint8_t currentByte = msg[p];
      while(currentByte) {
        bitsSet += (currentByte & 1);
        currentByte >>= 1;
      }
    }

    if (bitsSet != expectedBitsSet) {
       printf("%s: Checksum wrong actual [%02X] != expected [%02X]\n", __func__, bitsSet, expectedBitsSet);
      // return DECODE_CHK_ERR;
    }
#endif
    pOut->sensor_id = msg[14];

    int temp_raw = (msg[20] & 0x0f) + ((msg[20] & 0xf0) >> 4) * 10 + (msg[21] &0x0f) * 100;
    if (msg[25] & 0x0f) {
        temp_raw = -temp_raw;
    }
    pOut->temp_c = temp_raw * 0.1f;

    pOut->humidity = (msg[22] & 0x0f) + ((msg[22] & 0xf0) >> 4) * 10;

    pOut->wind_direction_deg = ((msg[17] & 0xf0) >> 4) * 22.5f;

    int gust_raw = ((msg[17] & 0x0f) << 8) + msg[16];
    pOut->wind_gust_meter_sec = gust_raw * 0.1f;

    int wind_raw = (msg[18] & 0x0f) + ((msg[18] & 0xf0) >> 4) * 10 + (msg[19] & 0x0f) * 100;
    pOut->wind_avg_meter_sec = wind_raw * 0.1f;

    int rain_raw = (msg[23] & 0x0f) + ((msg[23] & 0xf0) >> 4) * 10 + (msg[24] & 0x0f) * 100;
    pOut->rain_mm = rain_raw * 0.1f;

    pOut->battery_ok = (msg[25] & 0x80) ? false : true;

    return DECODE_OK;
}



uint8_t spi_read_register(uint8_t spi_instr)
{

	uint8_t temp, value;
	temp = spi_instr| READ_SINGLE_BYTE;
 

  tr.len=2;

 tx_buffer[0]=temp;
 tx_buffer[1]=0;
 
  //  spi_write_blocking(spi1, &temp, 1);
  //  spi_read_blocking(spi1, 0x00, &value, 1);

   ioctl(spi_fd, SPI_IOC_MESSAGE(1), &tr);

 
	return  rx_buffer[1];
}
void setupspi()
{
    // Open SPI device
    spi_fd = open(SPI_DEVICE1, O_RDWR);

     uint32_t speed_hz = 1000000;
     ioctl(spi_fd, SPI_IOC_WR_MAX_SPEED_HZ, &speed_hz);


    uint8_t partnum = spi_read_register(PARTNUM); //reads CC1100 partnumber
    uint8_t version = spi_read_register(VERSION); //reads CC1100 version number

    printf("debug: %d %d \r\n", partnum, version);
 
}



int main() {
    
//  setupspi();

signal(SIGINT, sigint_handler);

printf("opening radio\n"); 

 

 int state = radio.begin(868.35, 8.22, 57.136417, 270.0, 10, 32);

//int state = radio.begin(868.35, 8.22, 57.136417, 50, 10, 32);


 state = radio.setCrcFiltering(false);
 
 state = radio.fixedPacketLengthMode(27);
 
 state = radio.setSyncWord(0xAA, 0x2D, 0, false);
 //state = radio.setSyncWord(0xAA, 0xAA, 0, false);


// Module(RadioLibHal *hal, uint32_t cs, uint32_t irq, uint32_t rst, uint32_t gpio = RADIOLIB_NC);

   uint8_t recvData[50];

  //droping registries
     for(uint8_t i = 0 ; i < 0x3F; i++)  //showes rx_buffer for debug
        {
         //   printf("%d 0x%02X\n", i, radio.SPIreadRegister2(i) );
          //  if(i==9 || i==19 || i==29 || i==39)   printf("\r\n");
             
        }
         
bool decode_ok = false;
   
struct timespec start, end;
double elapsed_time;
clock_gettime(CLOCK_MONOTONIC, &start);
   while(!stop)
   { 

   
     state = radio.receive(recvData, 27+2+4);

if (state==0)
{
   // printf("char msg[29]={"); for (int i=0; i<29; i++) printf("0x%02X,", recvData[i]); printf("};\n");
clock_gettime(CLOCK_MONOTONIC, &end);
 elapsed_time = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
 clock_gettime(CLOCK_MONOTONIC, &start);
printf("Elapsed time: %f seconds\n", elapsed_time);

  for (int i=0; i<29; i++) printf(" %02X", recvData[i]); printf("\n");
 // for (int i=0; i<29; i++) printf(" %02X", recvData[i] ^ 0xFF); printf("\n");

  decode_ok = (decodeBresser5In1Payload(&recvData[1], sizeof(recvData) - 1, &weatherData) == DECODE_OK);
                weatherData.temp_ok     = true;  weatherData.uv_ok       = false;  weatherData.wind_ok     = true;
                weatherData.rain_ok     = true;
                weatherData.moisture_ok = false;


if (decode_ok)
{
printf("Id: [%8X] Battery: [%s] ",   weatherData.sensor_id, weatherData.battery_ok ? "OK " : "Low");
printf("Temp: [%3.1fC] Hum: [%3d%%] ",weatherData.temp_c, weatherData.humidity);

printf("Wind max: [%3.1fm/s] Wind avg: [%3.1fm/s] Wind dir: [%4.1fdeg] ",
                         weatherData.wind_gust_meter_sec,
                         weatherData.wind_avg_meter_sec,
                         weatherData.wind_direction_deg);

printf("Rain: [%6.1fmm] \n",  
                        weatherData.rain_mm);

}


}

     //try to transmit
   //  int state = radio.transmit("Hello World!");
    


 // sleep(1);

   }

//int state = radio.begin(868.35, 8.22, 57.136417, 270.0, 10, 32);

//just check the version module

printf("done\n");


}