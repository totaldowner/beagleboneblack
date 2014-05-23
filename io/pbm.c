#include "pbm.h"

pbm_image *load_pbm(char *path)
{
    pbm_image *img = NULL;
    char line[256];
    FILE *fp = NULL;

    fp = fopen(path, "r");
    if(fp == NULL)
    {
        return NULL;
    }

    fscanf(fp, "%s", line);
    
    img = malloc(sizeof(pbm_image));
    if(img == NULL)
    {
        fclose(fp);
        return NULL;
    }

    fscanf(fp, "%d", &(img->width));
    fscanf(fp, "%d\n", &(img->height));

    int byte_width = (img->width + (8 - (img->width % 8)))/8;

    img->data = malloc(sizeof(uint8_t) * (byte_width * img->height));
    if(img->data == NULL)
    {
        free(img);
        fclose(fp);
        return NULL;
    }
    fread(img->data, (byte_width * img->height), 1, fp);

    printf("%s Loaded\n", path);
    return img;
}

void free_pbm(pbm_image *img)
{
    free(img->data);
    free(img);
}
