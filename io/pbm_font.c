#include "pbm_font.h"

pbm_font *pbm_font_load(char *path)
{
    pbm_font *font;
    char fn[256];

    font = malloc(sizeof(pbm_font));
    if(font == NULL)
    {
        perror("Could not allocate font memory.\n");
        return NULL;
    }

    int x = 0;
    for(x = 0; x < MAX_FONT_SPACE; x++)
    {
        snprintf(fn, 256, "%s/%X.pbm", path, x);
        font->chars[x] = load_pbm(fn);
    }

    return font;
}

void pbm_font_free(pbm_font *font)
{
    int x = 0;
    for(x = 0; x <MAX_FONT_SPACE; x++)
    {
        if(font->chars[x] != NULL)
        {
            free_pbm(font->chars[x]);
        }
    }
    free(font);
}
