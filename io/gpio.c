#include "gpio.h"


int gpio_export(char gpioNum)
{
    FILE *fp = NULL;
    char *path = NULL;

    path = malloc(sizeof(char) * PATH_SIZE);
    if( path == NULL )
    {
        printf("Cannot allocate memory\n");
        return -1;
    }

    snprintf(path, PATH_SIZE, GPIO_PATH_EXPORT);
    fp = fopen(path, "w");
    if(fp == NULL)
    {
        printf("Cannot open file %s.\n", path);
        return -1;
    }

    fprintf(fp, "%d", gpioNum);

    fclose(fp);
    free(path);

    return 0;
}

int gpio_unexport(char gpioNum)
{
    FILE *fp = NULL;
    char *path = NULL;

    path = malloc(sizeof(char) * PATH_SIZE);
    if( path == NULL )
    {
        printf("Cannot allocate memory\n");
        return -1;
    }

    snprintf(path, PATH_SIZE, GPIO_PATH_UNEXPORT);
    fp = fopen(path, "w");
    if(fp == NULL)
    {
        printf("Cannot open file %s.\n", path);
        return -1;
    }

    fprintf(fp, "%d", gpioNum);

    fclose(fp);
    free(path);

    return 0;
}

int gpio_set_output(char gpioNum)
{
    FILE *fp = NULL;
    char *path = NULL;

    path = malloc(sizeof(char) * PATH_SIZE);
    if( path == NULL )
    {
        printf("Cannot allocate memory\n");
        return -1;
    }

    snprintf(path, PATH_SIZE, "%s/gpio%d/direction", GPIO_PATH_BASE, gpioNum);
    fp = fopen(path, "w");
    if(fp == NULL)
    {
        printf("Cannot open file %s.\n", path);
        return -1;
    }

    fprintf(fp, "out");

    fclose(fp);
    free(path);

    return 0;
}

int gpio_set_input(char gpioNum)
{
    FILE *fp = NULL;
    char *path = NULL;

    path = malloc(sizeof(char) * PATH_SIZE);
    if( path == NULL )
    {
        printf("Cannot allocate memory\n");
        return -1;
    }

    snprintf(path, PATH_SIZE, "%s/gpio%d/direction", GPIO_PATH_BASE, gpioNum);
    fp = fopen(path, "w");
    if(fp == NULL)
    {
        printf("Cannot open file %s.\n", path);
        return -1;
    }

    fprintf(fp, "in");

    fclose(fp);
    free(path);

    return 0;
}

int gpio_set_value(char gpioNum, char value)
{
    FILE *fp = NULL;
    char *path = NULL;

    path = malloc(sizeof(char) * PATH_SIZE);
    if( path == NULL )
    {
        printf("Cannot allocate memory\n");
        return -1;
    }

    snprintf(path, PATH_SIZE, "%s/gpio%d/value", GPIO_PATH_BASE, gpioNum);
    fp = fopen(path, "w");
    if(fp == NULL)
    {
        printf("Cannot open file %s.\n", path);
        return -1;
    }

    fprintf(fp, "%d", value);

    fclose(fp);
    free(path);

    return 0;
}
