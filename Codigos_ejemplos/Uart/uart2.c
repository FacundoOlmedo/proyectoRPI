#include "EasyPIO.h"
#define MAX_STR_LEN 80

void getStrSerial(char *str)
{
    int i = 0;
    do
    {
        str[i] = getCharSerial();
    } while ((str[i++] != '\r') && (i < MAX_STR_LEN));
    str[i - 1] = 0;
}

void putStrSerial(char *str)
{
    int i = 0;
    while (str[i] != 0)
    {
        putCharSerial(str[i++]);
    }
}

int main(void)
{
    char str[MAX_STR_LEN];
    pioInit();
    printf("Inicilizando UART...\n");
    uartInit(115200);
    printf("Done\n");
    printf("recibiendo dato...\n");
    getStrSerial(str);
    printf("Enviando dato... %s\n", str);
    putStrSerial("Escribir algo:\r\n");
    //printf("Done\n");
    //putCharSerial('b');

    //	while(1){
    //		putStrSerial("Tipear algo:\r\n");
    //		putStrSerial("usted tipeo: ");
    //		putStrSerial(str);
    //		putStrSerial("\r\n");
    //	}
}