#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <termios.h>
#include <sys/ioctl.h>

#include <errno.h>  // Include errno for error handling

int main() {
    int fd;
    struct termios options;

    // Open the serial port (replace /dev/ttyUSB0 with your serial port)
    fd = open("/dev/ttyUSB0", O_RDWR ); // | O_NOCTTY
    if (fd == -1) {
        perror("Error opening serial port");
        return 1;
    } else printf("ttyusb0 opened ok\n");

// set dtr set rts clear

    // Get the current serial port options
    if (tcgetattr(fd, &options) == -1) {
        perror("tcgetattr");
        return 1;
    }
 
    // Set CLOCAL flag to prevent modem control
        options.c_cflag &= ~CSIZE; // Clear the current data bits setting
    options.c_cflag |= CS8;    // Set 8 data bits

    // Apply the updated settings
    if (tcsetattr(fd, TCSANOW, &options) == -1) {
        perror("tcsetattr");
        return 1;
    }



 tcgetattr(fd, &options);
   // Parse and interpret serial port options
    printf("Baud rate: %d\n", cfgetospeed(&options)); // Print baud rate
    printf("Data bits: %d\n", options.c_cflag & CSIZE); // Extract data bits
    printf("Parity: %d\n", options.c_cflag & (PARENB | PARODD)); // Extract parity
    printf("Stop bits: %s\n", (options.c_cflag & CSTOPB) ? "2" : "1"); // Extract stop bits

    // Check flow control settings
    if (options.c_cflag & CRTSCTS)
        printf("Hardware flow control enabled\n");
    else if (options.c_iflag & (IXON | IXOFF))
        printf("Software flow control enabled\n");
    else
        printf("No flow control enabled\n");

int status = ~TIOCM_DTR | ~TIOCM_RTS; // Set DTR and RTS signals

 

    //if (ioctl(fd, TIOCMBIS, TIOCM_DTR) == -1) {
  status =  ~ TIOCM_DTR | TIOCM_RTS ; //RTS HIGH
  ioctl(fd, TIOCMSET, &status);
 
  sleep(0.1);
 
  status =  ~ TIOCM_DTR | ~ TIOCM_RTS ; //RTL LOW
  ioctl(fd, TIOCMSET, &status);

    // Sleep for 1 second
   // sleep(1);
 
    close(fd);

    return 0;
}
