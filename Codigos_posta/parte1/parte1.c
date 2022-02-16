#include "EasyPIO_Custom.h"
#include <unistd.h>

#define led1 3
#define led2 4
#define led3 17
#define led4 18
#define led5 27
#define led6 22
#define led7 23
#define led8 24
#define retardo 250000

int v[8] = {led1, led2, led3, led4, led5, led6, led7, led8};

int main(void){
	pioInit();

	for(int i=0; i<8; i++)
		pinMode(v[i], OUTPUT);  
	
	int op = menu();

	switch(op){
		case 1:	auto_fantastico();
						break;
		case 2:	el_choque();
						break;
		case 3:	la_apilada();
						break;
		case 4:	la_carrera();
						break;
		case 5:	la_pareja();
						break;
		case 6:	la_serpiente();
						break;
		case 7:	tiro_vertical();
						break;
		// case 8:	();
		// 				break;
	}
	return 0;
}

int menu(){
	int op;
	do{
		puts("Seleccione la secuencia deseada [1-8]");
		puts("1. Auto fantastico");
		puts("2. El choque");
		puts("3. La apilada");
		puts("4. La carrera");
		puts("5. La pareja");
		puts("6. La serpiente");
		puts("7. Tiro vertical");
		puts("8. ");
		scanf("%d", &op);
		if((op < 1) || (op < 8))
			puts("Secuencia no valida, intente nuevamente");
	}while((op < 1) || (op < 8));
	return op; 
}

void autofantastico(){
	for (int i = 0; i < 8; i++){
		for (int j = 0; j < 8; j++)
			digitalWrite(v[j], 0);
		
		digitalWrite(v[i], 1);
		usleep(retardo);
	}
	for (int i = 6; i > 0; i--){
		for (int j = 0; j < 8; j++)
			digitalWrite(v[j], 0);

		digitalWrite(v[i], 1);
		usleep(retardo);
	}
}

void el_choque(){
	for (int i = 0; i < 8; i++){
		for (int j = 0; j < 8; j++)
			digitalWrite(v[j], 0);

		digitalWrite(v[i], 1);
		digitalWrite(v[7 - i], 1);
		usleep(retardo);
	}
}

void la_apilada(){
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

void la_carrera(){
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

void la_pareja(void){
	for (int i = 0; i <= 8; i++){
		if(suma == 3){
			suma = 0;
			i = i - 2;
		}
		for (int j = 0; j < 8; j++)
			digitalWrite(v[j], 0);

		if(i != 8)
				digitalWrite(v[i], 1);
		if(i != 0)
				digitalWrite(v[i-1], 1)
		suma++;
		usleep(retardo);
	}
	for (int j = 0; j < 8; j++)
		digitalWrite(v[j], 0);
	suma = 0;
	usleep(retardo);
}

void la_serpiente(){
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

void tiro_vertical(){
	int delay = 125000;
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
	  usleep(delay);
	}
}
