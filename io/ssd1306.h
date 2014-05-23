#ifndef SSD1306_H
#define SSD1306_H

#include "spi.h"
#include "fsgpio.h"
#include "pbm.h"
#include "pbm_font.h"

/*
 * Command table. B1[1], B2[2], ... Means parameter with [x] bits of the byte
 * that follow in order. Complex parameter should be reviewed in datasheet.
 */

#define SET_CONTRAST        0x81 /* P[8]: contrast level */
#define ENTIRE_DISPLAY_ON   0xA4 /* 0xA4 keeps ram content, 0xA5 ignores it */
#define ENTIRE_DISPLAY_ON_2 0xA5
#define SET_NORMAL_DISPLAY  0xA6 /* As opposed to inverse */
#define SET_INVERSE_DISPLAY 0xA7
#define DISPLAY_OFF         0xAE
#define DISPLAY_ON          0xAF

#define RIGHT_HORIZ_SCROLL_SETUP        0x26 /* Complex */
#define LEFT_HORIZ_SCROLL_SETUP         0x27
#define RIGHT_HORIZ_VERT_SCROLL_SETUP   0x29
#define LEFT_HORIZ_VERT_SCROLL_SETUP    0x2A
#define DEACTIVATE_SCROLL               0x2E
#define ACTIVATE_SCROLL                 0x2F
#define SET_VERT_SCROLL_AREA            0xA3 /* Complex */

#define SET_LOWCOL_START            0x00 /* From 0x00 - 0x0F. Page address mode */
#define SET_HIGHCOL_START           0x10 /* From 0x10 - 0x1F. Page address mode */
#define SET_MEMORY_MODE             0x20 /* B1[2]: 0=Horiz 1=Vert 2=Page 3=Invalid */
#define SET_COL_ADDRESS             0x21 /* B1[7]: Start address B2[7]: End address */
#define SET_PAGE_ADDRESS            0x22 /* B1[3]: Start address B2[3]: End address */
#define SET_PAGE_ADDRESS_PAGE_MODE  0xB0 /* From 0xB0 - 0xB7 Page address Mode*/

#define SET_DISPLAY_START_LINE  0x40 /* From 0x40 - 0x7F. */
#define SET_SEGMENT_REMAP       0xA0 /* Column address 0 mapped to SEG0 */
#define SET_SEGMENT_REMAP_2     0xA1 /* Column address 127 mapped to SEG0 */
#define SET_MULTIPLEX_RATIO     0xA8 /* B1[6]: 16 - 64 */
#define SET_COM_OUT_SCAN_DIR    0xC0 /* Scan COM0 to COM[N-1] */
#define SET_COM_OUT_SCAN_DIR_2  0xC8 /* Scan COM[N-1] to COM0 */
#define SET_DISPLAY_OFFSET      0xD3 /* B1[6]: 0 - 63 vertical shift */
#define SET_COM_CONFIG          0xDA /* Complex */

#define SET_DISPLAY_CLOCK_DIVIDE    0xD5 /* Complex */
#define SET_PRECHARGE               0xD9
#define SET_VCOMM_LEVEL             0xDB
#define ssd1306_NOP                     0xE3

#define CHARGE_PUMP_SETTING 0x8D
#define CHARGE_PUMP_ON      0x14
#define CHARGE_PUMP_OFF     0x10

#define SSD1306_WIDTH   128
#define SSD1306_HEIGHT  64
#define SSD1306_BUFFER_SIZE (SSD1306_WIDTH * SSD1306_HEIGHT)/8

typedef struct ssd1306_info
{
    spi_info dev;       /* SPI device info */
    int reset_pin;      /* Reset pin */
    int dc_pin;         /* D/C pin */
    uint8_t *buffer;    /* Set and manage own buffer */
} ssd1306_info;

int ssd1306_init(ssd1306_info *display, int bus, int device, int reset_pin, int dc_pin);
int ssd1306_command(ssd1306_info *display, uint8_t byte);
int ssd1306_data(ssd1306_info *display, uint8_t *bytes, int length);
int ssd1306_reset(ssd1306_info *display);
int ssd1306_destroy(ssd1306_info *display);
int ssd1306_show_buffer(ssd1306_info *display);
int ssd1306_clear_buffer(ssd1306_info *display);
int ssd1306_fill_buffer(ssd1306_info *display);
int ssd1306_set_buffer(ssd1306_info *display, uint8_t *buffer);
int ssd1306_set_pixel(ssd1306_info *display, uint16_t x, uint16_t y);
int ssd1306_clear_pixel(ssd1306_info *display, uint16_t x, uint16_t y);
int ssd1306_draw_pbm(ssd1306_info *display, pbm_image *img, uint16_t x, uint16_t y, uint8_t invert);
int ssd1306_draw_text(ssd1306_info *display, pbm_font *font, uint8_t padding, uint16_t x, uint16_t y, char *str, uint16_t length);
#endif
