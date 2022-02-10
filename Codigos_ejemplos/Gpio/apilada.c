#include "EasyPIO_Custom.h"
#include <unistd.h>
#define retardo 250000
#define led1 3
#define led2 4
#define led3 17
#define led4 18
#define led5 27
#define led6 22
#define led7 23
#define led8 24


int main(void){

pioInit();

int v[8] = {led1, led2, led3, led4, led5, led6, led7, led8};



pinMode(v[0],OUTPUT);
pinMode(v[1],OUTPUT);
pinMode(v[2],OUTPUT);
pinMode(v[3],OUTPUT);
pinMode(v[4],OUTPUT);
pinMode(v[5],OUTPUT);
pinMode(v[6],OUTPUT);
pinMode(v[7],OUTPUT);


while(1){
    for(int i = 8; i > 0; i--){
        for(int j = 0; j < i; j++){
            for(int k = 0; k < i; k++)
                digitalWrite(v[k], 0);
            digitalWrite(v[j], 1);
            usleep(retardo);
        }
	  	digitalWrite(v[j-1], 0);
	 	usleep(retardo);
        digitalWrite(v[j-1], 1);
        usleep(retardo);
	}
}

return 0;
}