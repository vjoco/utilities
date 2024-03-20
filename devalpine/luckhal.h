#ifndef PI_HAL_H
#define PI_HAL_H


#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <linux/spi/spidev.h>


#include <string.h>
#include <time.h>

// include RadioLib
//#include <RadioLib.h>
#include "TypeDef.h"
#include "Module.h"

#include "PhysicalLayer.h"


#define SPI_DEVICE "/dev/spidev0.0"

/*
//Victor



  //spi dev
  int spi_fd;
  struct spi_ioc_transfer spii;

    void spiTransfer(uint8_t* out, size_t len, uint8_t* in)
    {
      //test
      spii.rx_buf=(__u64) in;
      spii.tx_buf=(__u64) out;
      spii.len=len;

      ioctl(spi_fd, SPI_IOC_MESSAGE(1), &spii);

    }

*/


// create a new Raspberry Pi hardware abstraction layer
// using the pigpio library
// the HAL must inherit from the base RadioLibHal class
// and implement all of its virtual methods
class luckhal : public RadioLibHal {
  public:
    // default constructor - initializes the base HAL and any needed private members
    luckhal(uint8_t spiChannel, uint32_t spiSpeed = 2000000)
      : RadioLibHal(1, 1, 1, 1, 1, 1), 
      _spiChannel(spiChannel),
      _spiSpeed(spiSpeed) {
    }

    void init() override {
      // first initialise pigpio library
      //gpioInitialise();

      // now the SPI
      spiBegin();

      // Waveshare LoRaWAN Hat also needs pin 18 to be pulled high to enable the radio
      //gpioSetMode(18, PI_OUTPUT);
      //gpioWrite(18, PI_HIGH);
    }

    void term() override {
      // stop the SPI
      //spiEnd();

      // pull the enable pin low
     // gpioSetMode(18, PI_OUTPUT);
     // gpioWrite(18, PI_LOW);

      // finally, stop the pigpio library
     // gpioTerminate();
    }

    // GPIO-related methods (pinMode, digitalWrite etc.) should check
    // RADIOLIB_NC as an alias for non-connected pins
    void pinMode(uint32_t pin, uint32_t mode) override {
      //if(pin == RADIOLIB_NC) {
    //    return;
   //   }

   //   gpioSetMode(pin, mode);
    }

    void digitalWrite(uint32_t pin, uint32_t value) override {
    //  if(pin == RADIOLIB_NC) {
    //    return;
   //   }

   //   gpioWrite(pin, value);
    }

    uint32_t digitalRead(uint32_t pin) override {
     // if(pin == RADIOLIB_NC) {
     //   return(0);
    //  }

     // return(gpioRead(pin));
     return 1;
    }

    void attachInterrupt(uint32_t interruptNum, void (*interruptCb)(void), uint32_t mode) override {
    //  if(interruptNum == RADIOLIB_NC) {
    //    return;
    //  }

    //  gpioSetISRFunc(interruptNum, mode, 0, (gpioISRFunc_t)interruptCb);
    }

    void detachInterrupt(uint32_t interruptNum) override {
    //  if(interruptNum == RADIOLIB_NC) {
     //   return;
    //  }

    //  gpioSetISRFunc(interruptNum, 0, 0, NULL);
    }

    void delay(unsigned long ms) override {
   //   gpioDelay(ms * 1000);
   usleep(ms*1000);
    }

    void delayMicroseconds(unsigned long us) override {
    //  gpioDelay(us);
    usleep(us);
    }

    unsigned long millis() override {
       struct timespec ts;
     clock_gettime(CLOCK_MONOTONIC, &ts);
     return (ts.tv_sec * 1000) + (ts.tv_nsec / 1000000);
    // return 1;
    }

  //  unsigned long micros() override {
   //   return(gpioTick());
  // return 1;
  //  }

unsigned long micros() {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return (ts.tv_sec * 1000000UL) + (ts.tv_nsec / 1000);
}

    long pulseIn(uint32_t pin, uint32_t state, unsigned long timeout) override {
    //  if(pin == RADIOLIB_NC) {
    //    return(0);
    //  }

    //  this->pinMode(pin, PI_INPUT);
    //  uint32_t start = this->micros();
    //  uint32_t curtick = this->micros();

    //  while(this->digitalRead(pin) == state) {
    //    if((this->micros() - curtick) > timeout) {
    //      return(0);
    //    }
    //  }

    //  return(this->micros() - start);
    return 1;
    }

   void spiBegin() {
     // if(_spiHandle < 0) {
    //    _spiHandle = spiOpen(_spiChannel, _spiSpeed, 0);
   //  }
 
    fd = open(SPI_DEVICE, O_RDWR);

    if (fd<0) printf("spi not opened\n"); else printf("spi opened\n");

 uint8_t mode = SPI_MODE_1;
ioctl(fd, SPI_IOC_WR_MODE, &mode);

     uint32_t speed_hz = 500000;
     ioctl(fd, SPI_IOC_WR_MAX_SPEED_HZ, &speed_hz);
     ioctl(fd, SPI_IOC_RD_MAX_SPEED_HZ, &speed_hz);

//__u32 delay_us = 3;
//ioctl(fd, SPI_IOC_WR_DELAY_AFTER_CS, &delay_us);
   
   memset(&spii, 0, sizeof(spii));


    }

    void spiBeginTransaction() {}

// SPItransfer(SPIreadCommand, reg, NULL, &resp, 1);

    void spiTransfer(uint8_t* out, size_t len, uint8_t* in) {
    //  spiXfer(_spiHandle, (char*)out, (char*)in, len);
 
   //  memcpy(in1,in,len);
   // memcpy(out1,out,len);
  // printf("len %d\n", len);


      spii.rx_buf=(__u64) in; 
      spii.tx_buf=(__u64) out;
      spii.len=len;
      spii.bits_per_word=8;
   // printf("call IOCTL\n");
    //  ioctl(spi_fd, SPI_IOC_MESSAGE(1), &spii);
   

        ioctl(fd, SPI_IOC_MESSAGE(1), &spii);

 // printf("IN  "); for (int i=0; i<len; i++) printf("%02X ", in1[i]); printf("\n");
 // printf("OUT "); for (int i=0; i<len; i++) printf("%02X ", out1[i]); printf("\n");

 // memcpy(in,in1,len);


    }

    void spiEndTransaction() {}

    void spiEnd() {
    //  if(_spiHandle >= 0) {
     //   spiClose(_spiHandle);
    //    _spiHandle = -1;
    //  }
    }

  private:
    // the HAL can contain any additional private members
    const unsigned int _spiSpeed;
    const uint8_t _spiChannel;
    int _spiHandle = -1;

    int fd;
    struct spi_ioc_transfer spii;
    uint8_t in1[11];
    uint8_t out1[11];
    
};

#endif