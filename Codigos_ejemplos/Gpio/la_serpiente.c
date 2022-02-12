// Animacion por tabla. Una serpiente como la del juego se desplaza hacia la derecha
// y reaparece por el otro

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

int secuencia[][] = {
{1,1,1,1,0,0,0,0},
{0,1,1,1,1,0,0,0},
{0,0,1,1,1,1,0,0},
{0,0,0,1,1,1,1,0},
{0,0,0,0,1,1,1,1},
{1,0,0,0,0,1,1,1},
{1,1,0,0,0,0,1,1},
{1,1,1,0,0,0,0,1},
};

int v[8] = {led1, led2, led3, led4, led5, led6, led7, led8};
void la_serpiente(void);

int main(void){

	pioInit();

	for(int i=0; i<8; i++)
		pinMode(v[i], OUTPUT);  

	while (1){
		la_serpiente();
	}

	return 0;
}

void la_serpiente(void){
	for( int i=0; i < 8; i++){
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
