#include "gpio.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define TEST_GPIO GPIO_P9_PIN_12

int main(int args, char *argv[])
{
    int x=0;

    printf("Exporting gpio %d\n", TEST_GPIO);
    if(!gpio_export(TEST_GPIO))
    {
        printf("Success.\n");
    }

    printf("Setting gpio %d as output", TEST_GPIO);
    if(!gpio_set_output(TEST_GPIO))
    {
        printf("Success.\n");
    }
     
    for(x=0; x < 10; x++)
    {
        printf("Set 1\n");
        gpio_set_value(TEST_GPIO, 1);
        usleep(500000);
        
        printf("Set 0\n");
        gpio_set_value(TEST_GPIO, 0);
        usleep(500000);
    }

    printf("Unexporting gpio %d\n", TEST_GPIO);
    if(!gpio_unexport(TEST_GPIO))
    {
        printf("Success.\n");
    }

    return 0;
}
