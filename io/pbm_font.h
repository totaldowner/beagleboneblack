#ifndef PBM_FONT_H
#define PBM_FONT_H

#include "pbm.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <errno.h>

#define MAX_FONT_SPACE 0x80

typedef struct
{
    pbm_image *chars[MAX_FONT_SPACE];
} pbm_font;

pbm_font *pbm_font_load(char *path);
void pbm_font_free(pbm_font *font);

#endif
