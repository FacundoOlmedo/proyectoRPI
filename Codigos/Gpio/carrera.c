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

pinMode(3,OUTPUT);
pinMode(4,OUTPUT);
pinMode(17,OUTPUT);
pinMode(18,OUTPUT);
pinMode(27,OUTPUT);
pinMode(22,OUTPUT);
pinMode(23,OUTPUT);
pinMode(24,OUTPUT);

int secuencia[18][8] = {{0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0},
{1,0,0,0,0,0,0,0},
{1,0,0,0,0,0,0,0},
{0,1,0,0,0,0,0,0},
{0,1,0,0,0,0,0,0},
{0,0,1,0,0,0,0,0},
{0,0,1,0,0,0,0,0},
{0,0,0,1,0,0,0,0},
{0,0,0,1,0,0,0,0},
{1,0,0,0,1,0,0,0},
{0,1,0,0,1,0,0,0},
{0,0,1,0,0,1,0,0},
{0,0,0,1,0,1,0,0},
{0,0,0,0,1,0,1,0},
{0,0,0,0,0,1,1,0},
{0,0,0,0,0,0,1,1},
{0,0,0,0,0,0,0,1},
};

while(1){
	for( int i=0; i < 18; i++){
	  digitalWrite(led1, secuencia[i][0]);
	  digitalWrite(led2, secuencia[i][1]);
	  digitalWrite(led3, secuencia[i][2]);
	  digitalWrite(led4, secuencia[i][3]);
	  digitalWrite(led5, secuencia[i][4]);
	  digitalWrite(led6, secuencia[i][5]);
	  digitalWrite(led7, secuencia[i][6]);
	  digitalWrite(led8, secuencia[i][7]);
	  usleep(retardo);
	}
	
}

return 0;
}
