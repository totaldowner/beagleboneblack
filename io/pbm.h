#ifndef PBM_H
#define PBM_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct
{
    int width;
    int height;
    uint8_t *data;
} pbm_image;

pbm_image *load_pbm(char *path);
void free_pbm(pbm_image *img);

#endif
