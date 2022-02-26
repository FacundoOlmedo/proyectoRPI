#include "EasyPIO_Custom.h"
#include <unistd.h>
#define LOW 0
#define HIGH 1

void auto_fantastico(int * pin){
	const int retardo = 250000;
	for (int i = 0; i < 8; i++){
		for (int j = 0; j < 8; j++)
			digitalWrite(pin[j], LOW);
		
		digitalWrite(pin[i],HIGH);
		usleep(retardo);
	}
	for (int i = 6; i > 0; i--){
		for (int j = 0; j < 8; j++)
			digitalWrite(pin[j], LOW);

		digitalWrite(pin[i],HIGH);
		usleep(retardo);
	}
}

void el_choque(int * pin){
	const int retardo = 250000;
	for (int i = 0; i < 8; i++){
		for (int j = 0; j < 8; j++)
			digitalWrite(pin[j], LOW);

		digitalWrite(pin[i], HIGH);
		digitalWrite(pin[7 - i], HIGH);
		usleep(retardo);
	}
}

void la_apilada(int * pin){
	const int retardo = 250000;
	int i = 0, j = 0;
 	int final = 8;
 	for(j=0; j<8;j++){
		for(i=0; i<final; i++){
			digitalWrite(v[i], HIGH);
			delay(250);
			digitalWrite(v[i], LOW);
		}
		usleep(retardo);
		digitalWrite(v[i-1], HIGH);
		final--;
  	}

void la_carrera(int * pin){
	const int retardo = 250000;
	int secuencia[18][8] = {
{0,0,0,0,0,0,0,0},
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
	for( int i=0; i < 18; i++){
	  digitalWrite(pin[0], secuencia[i][0]);
	  digitalWrite(pin[1], secuencia[i][1]);
	  digitalWrite(pin[2], secuencia[i][2]);
	  digitalWrite(pin[3], secuencia[i][3]);
	  digitalWrite(pin[4], secuencia[i][4]);
	  digitalWrite(pin[5], secuencia[i][5]);
	  digitalWrite(pin[6], secuencia[i][6]);
	  digitalWrite(pin[7], secuencia[i][7]);
	  usleep(retardo);
	}
}

void la_pareja(int * pin){
	const int retardo = 500000;
	for (int i = 0; i <= 8; i++){
		if(suma == 3){
			suma = 0;
			i = i - 2;
		}
		for (int j = 0; j < 8; j++)
			digitalWrite(pin[j], LOW);

		if(i != 8)
				digitalWrite(pin[i], HIGH);
		if(i != 0)
				digitalWrite(pin[i-1], HIGH)
		suma++;
		usleep(retardo);
	}
	for (int j = 0; j < 8; j++)
		digitalWrite(pin[j], LOW);
	suma = 0;
	usleep(retardo);
}

void la_serpiente(int * pin){
	const int retardo = 250000;
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

	for( int i=0; i < 8; i++){
	  digitalWrite(pin[0], secuencia[i][0]);
	  digitalWrite(pin[1], secuencia[i][1]);
	  digitalWrite(pin[2], secuencia[i][2]);
	  digitalWrite(pin[3], secuencia[i][3]);
	  digitalWrite(pin[4], secuencia[i][4]);
	  digitalWrite(pin[5], secuencia[i][5]);
	  digitalWrite(pin[6], secuencia[i][6]);
	  digitalWrite(pin[7], secuencia[i][7]);
	  usleep(retardo);
	}
}

void tiro_vertical(int * pin){
	const int retardo = 30000;
	int x = 0;  //altura, tiene un valor entre 0 y 8 (corresponde a un led)
 	float vel = 4.0;
 	float a = -1.0;
  	float t = 0;
  	float dt = 0.1; //tamaño del paso en cada ciclo
	//con estos parametros la parabola que se describe tiene una raiz en t=8
	while(t <= 8){
		x = round(vel*t + 0.5*a*t*t);
		ledsOff();
		if(x >= 1)
			digitalWrite(v[x-1], HIGH);
		usleep(retardo);
		t += dt; 
  	}
}

void ledsOff(int * pin){
  for (int j = 0; j < 8; j++)
    digitalWrite(pin[j], LOW);
}

void caida_pelota(int * pin){
	int secuencia[][] = {
{0,0,0,0,0,0,0,1},
{0,0,0,0,0,0,0,1},
{0,0,0,0,0,0,0,1},
{0,0,0,0,0,0,1,0},
{0,0,0,0,0,0,1,0},
{0,0,0,0,0,0,1,0},
{0,0,0,0,0,1,0,0},
{0,0,0,0,0,1,0,0},
{0,0,0,0,1,0,0,0},
{0,0,0,0,1,0,0,0},
{0,0,0,1,0,0,0,0},
{0,0,1,0,0,0,0,0},
{0,1,0,0,0,0,0,0},
{1,0,0,0,0,0,0,0},
{0,1,0,0,0,0,0,0},
{0,0,1,0,0,0,0,0},
{0,0,0,1,0,0,0,0},
{0,0,0,1,0,0,0,0},
{0,0,0,0,1,0,0,0},
{0,0,0,0,1,0,0,0},
{0,0,0,0,1,0,0,0},
{0,0,0,1,0,0,0,0},
{0,0,0,1,0,0,0,0},
{0,0,1,0,0,0,0,0},
{0,1,0,0,0,0,0,0},
{1,0,0,0,0,0,0,0},
{0,1,0,0,0,0,0,0},
{0,0,1,0,0,0,0,0},
{0,0,1,0,0,0,0,0},
{0,1,0,0,0,0,0,0},
{1,0,0,0,0,0,0,0},
{0,1,0,0,0,0,0,0},
{1,0,0,0,0,0,0,0},
};

	for( int i=0; i < 33; i++){
	  digitalWrite(pin[0], secuencia[i][0]);
	  digitalWrite(pin[1], secuencia[i][1]);
	  digitalWrite(pin[2], secuencia[i][2]);
	  digitalWrite(pin[3], secuencia[i][3]);
	  digitalWrite(pin[4], secuencia[i][4]);
	  digitalWrite(pin[5], secuencia[i][5]);
	  digitalWrite(pin[6], secuencia[i][6]);
	  digitalWrite(pin[7], secuencia[i][7]);
	  usleep(retardo);
	}
}