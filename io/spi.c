#include "spi.h"

int spi_setup(spi_info *dev)
{
    char path[MAXPATH];
    
    snprintf(path, MAXPATH, "/dev/spidev%d.%d", dev->bus, dev->device);
    if((dev->fd = open(path, O_RDWR)) < 0)
    {
        perror("SPI: Could not open path.\n");
        return -1;
    }

    if(ioctl(dev->fd, SPI_IOC_WR_MODE, &(dev->mode)) < 0)
    {
        perror("SPI: Could not set write mode\n");
        return -1;
    }

    if(ioctl(dev->fd, SPI_IOC_RD_MODE, &(dev->mode)) < 0)
    {
        perror("SPI: Could not set read mode\n");
        return -1;
    }
    
    if(ioctl(dev->fd, SPI_IOC_WR_BITS_PER_WORD, &(dev->bpw)) < 0)
    {
        perror("SPI: Could not set write bits per word\n");
        return -1;
    }

    if(ioctl(dev->fd, SPI_IOC_RD_BITS_PER_WORD, &(dev->mode)) < 0)
    {
        perror("SPI: Could not set read bits per word\n");
        return -1;
    }
    
    if(ioctl(dev->fd, SPI_IOC_WR_MAX_SPEED_HZ, &(dev->shz)) < 0)
    {
        perror("SPI: Could not set write speed\n");
        return -1;
    }

    if(ioctl(dev->fd, SPI_IOC_RD_MAX_SPEED_HZ, &(dev->shz)) < 0)
    {
        perror("SPI: Could not set read speed\n");
        return -1;
    }

    return 0;
}

int spi_close(spi_info *dev)
{
    if(close(dev->fd) < 0)
    {
        perror("SPI: Could not close device.\n");
        return -1;
    }

    return 0;
}

int spi_write(spi_info *dev, uint8_t *data, int length)
{
    if(write(dev->fd, data, length) < 0)
    {
        perror("SPI: Error writing data.\n");
        return -1;
    }
    return 0;
}

int spi_read(spi_info *dev, uint8_t *data, int length)
{
    if(read(dev->fd, data, length) < 0)
    {
        perror("SPI: Error reading data.\n");
        return -1;
    }
    return 0;
}

