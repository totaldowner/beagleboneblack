#ifndef SPI_H
#define SPI_H

#include <errno.h>
#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <linux/spi/spidev.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/types.h>

#define MAXPATH 1024

typedef struct spi_info
{
    int fd;         /* Device file descriptor */
    uint32_t shz;   /* Speed in Hz */
    uint8_t mode;   /* SPI mode */
    uint8_t bpw;    /* Bits per word */
    uint8_t bus;    /* /dev/spidevX.X */
    uint8_t device; /* /dev/spidevX.X */
} spi_info;


int spi_setup(spi_info *dev);
int spi_close(spi_info *dev);
int spi_write(spi_info *dev, uint8_t *data, int length);
int spi_read(spi_info *dev, uint8_t *data, int length);

#endif
