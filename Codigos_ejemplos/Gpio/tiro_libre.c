// Animacion por tabla. Una serpiente como la del juego se desplaza hacia la derecha
// y reaparece por el otro

#include "EasyPIO_Custom.h"
#include <unistd.h>
#define retardo 125000	//125 ms, la animacion en total dura 2s (16 pasos)
#define led1 3
#define led2 4
#define led3 17
#define led4 18
#define led5 27
#define led6 22
#define led7 23
#define led8 24

int main(void)
{

	pioInit();

	int v[8] = {led1, led2, led3, led4, led5, led6, led7, led8};

    for(int i=0; i<8; i++)
	    pinMode(v[i], OUTPUT);  

	void tiro_libre(void);

int main(){

	while (1){
		tiro_libre();
	}

	return 0;
}

void tiro_libre(void){
	int x = 0;
	float v = 4.0;
	float a = -1.0;
  float t = 0;

	for(int i=0; i < 8; i++){
		t = i/2.0;	//cuántos instantes de tiempo quiero mostrar
		x = v*t + 0.5*a*t^2;
		for(int j=0; j<8; j++)
			digitalWrite(v[j], 0);

		digitalWrite(x, 1);
	  usleep(retardo);
	}
}
