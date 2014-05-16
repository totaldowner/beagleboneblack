#include "gpio.h"
#include <stdio.h>
#include <stdlib.h>

int main(int args, char *argv[])
{
    FILE *fp = NULL;
    char *export = NULL;
    char *unexport = NULL;
    char *pin = NULL;

    export = (char *) malloc(sizeof(char) * 100);
    unexport = (char *) malloc(sizeof(char) * 100);
    pin = (char *) malloc(sizeof(char) * 100);

    if (pin == NULL || unexport == NULL || export == NULL)
    {
        printf("Error allocationg memory.");
        return -1;
    }

    snprintf(pin, 100, "%s/gpio%d/value", GPIO_DIRECTORY, GPIO_PIN_12);

    printf("%s\n", pin);

    fp = fopen(pin, "w+");

    //while(1)
    //{
        fprintf(fp, "1\n");
    //    printf("Value: %c\n", fgetc(fp));
    //    sleep(1);

    //    fputc('0', fp);
    //    printf("Value: %c\n", fgetc(fp));
    //    sleep(1);
    //}
    fclose(fp);

    free(export);
    free(unexport);
    free(pin);
    
    return 0;
}
