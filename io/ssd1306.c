#include "ssd1306.h"

int ssd1306_init(ssd1306_info *display, int bus, int device, int reset_pin, int dc_pin)
{
    /* Fill struct */
    display->reset_pin = reset_pin;
    display->dc_pin = dc_pin;
    display->dev.bus = bus;
    display->dev.device = device;
    display->dev.mode = SPI_MODE_0;
    display->dev.bpw = 8;
    display->dev.shz = 4000000;

    /* Enable GPIO */
    fsgpio_export(display->reset_pin);
    fsgpio_set_output(display->reset_pin);
    fsgpio_set_value(display->reset_pin, 1);

    fsgpio_export(display->dc_pin);
    fsgpio_set_output(display->dc_pin);
    fsgpio_set_value(display->dc_pin, 0);

    /* Set up SPI */
    spi_setup(&(display->dev));

    /* Set up display */
    ssd1306_command(display, DISPLAY_OFF);
    
    ssd1306_command(display, SET_DISPLAY_CLOCK_DIVIDE);
    ssd1306_command(display, 0x80);
    ssd1306_command(display, SET_MULTIPLEX_RATIO);
    ssd1306_command(display, 0x3F);
    
    ssd1306_command(display, SET_DISPLAY_OFFSET);
    ssd1306_command(display, 0x00);
    ssd1306_command(display, SET_DISPLAY_START_LINE);

    ssd1306_command(display, CHARGE_PUMP_SETTING);
    ssd1306_command(display, CHARGE_PUMP_ON);

    ssd1306_command(display, SET_MEMORY_MODE);
    ssd1306_command(display, 0x00);
    ssd1306_command(display, SET_SEGMENT_REMAP);
    ssd1306_command(display, SET_COM_OUT_SCAN_DIR);
    ssd1306_command(display, SET_COM_CONFIG);
    ssd1306_command(display, 0x12);
    ssd1306_command(display, SET_CONTRAST);
    ssd1306_command(display, 0xCF);
    ssd1306_command(display, SET_PRECHARGE);
    ssd1306_command(display, 0xF1);
    ssd1306_command(display, SET_VCOMM_LEVEL);
    ssd1306_command(display, 0x40);
    ssd1306_command(display, ENTIRE_DISPLAY_ON);
    ssd1306_command(display, DISPLAY_ON);

    return 0;
}

int ssd1306_command(ssd1306_info *display, uint8_t byte)
{
    fsgpio_set_value(display->dc_pin, 0); /* Ensure command bit is low */
    spi_write(&(display->dev), &byte, 1);
    return 0;
}

int ssd1306_data(ssd1306_info *display, uint8_t *bytes, int length)
{
    fsgpio_set_value(display->dc_pin, 1); /* Ensure command bit is low */
    spi_write(&(display->dev), bytes, length);
    return 0;
}

int ssd1306_reset(ssd1306_info *display)
{
    fsgpio_set_value(display->reset_pin, 0);
    usleep(100000);
    fsgpio_set_value(display->reset_pin, 1);
    return 0;
}

int ssd1306_destroy(ssd1306_info *display)
{
    ssd1306_command(display, DISPLAY_OFF);
    spi_close(&(display->dev));
    fsgpio_unexport(display->reset_pin);
    fsgpio_unexport(display->dc_pin);
    return 0;
}

int ssd1306_show_buffer(ssd1306_info *display)
{
    ssd1306_command(display, SET_COL_ADDRESS);
    ssd1306_command(display, 0x00);
    ssd1306_command(display, 0x7F);

    ssd1306_command(display, SET_PAGE_ADDRESS);
    ssd1306_command(display, 0x00);
    ssd1306_command(display, 0x07);

    ssd1306_data(display, display->buffer, SSD1306_BUFFER_SIZE);

    return 0;
}

int ssd1306_clear_buffer(ssd1306_info *display)
{
    int x = 0;
    for(x = 0; x < SSD1306_BUFFER_SIZE; x++)
    {
        display->buffer[x] = 0x00;
    }
    return 0;
}

int ssd1306_fill_buffer(ssd1306_info *display)
{
    int x = 0;
    for(x = 0; x < SSD1306_BUFFER_SIZE; x++)
    {
        display->buffer[x] = 0xFF;
    }
    return 0;
}

int ssd1306_set_buffer(ssd1306_info *display, uint8_t *buffer)
{
    display->buffer = buffer;
    return 0;
}

int ssd1306_set_pixel(ssd1306_info *display, uint16_t x, uint16_t y)
{
    display->buffer[x + ((y/8) * SSD1306_WIDTH)] |= (1 << (y&7));
    return 0;
}

int ssd1306_clear_pixel(ssd1306_info *display, uint16_t x, uint16_t y)
{
    display->buffer[x + ((y/8) * SSD1306_WIDTH)] &= ~(1 << (y&7));
    return 0;
}

int ssd1306_draw_bitmap(uint8_t *bmp, int width, int height)
{
    return 0;
}
