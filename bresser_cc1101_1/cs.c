#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <linux/spi/spidev.h>

#define SPI_DEVICE "/dev/spidev0.0"





int main() {
    int spi_fd;
    unsigned char tx_buffer[200] = {0x01, 0x02}; // Example data to be transmitted
    unsigned char rx_buffer[200];

    // Open SPI device
    spi_fd = open(SPI_DEVICE, O_RDWR);
 


    struct spi_ioc_transfer tr = {
        .tx_buf = (unsigned long)tx_buffer,
        .rx_buf = (unsigned long)rx_buffer,
        .len = sizeof(tx_buffer),
    };


 for (int i=0; i<10000; i++) {
    // Perform SPI transfer

    if (ioctl(spi_fd, SPI_IOC_MESSAGE(1), &tr) < 0) {
        perror("Error transferring data over SPI");
        close(spi_fd);
        return EXIT_FAILURE;
    }
 }
    // Close SPI device
    close(spi_fd);

    return EXIT_SUCCESS;
}
