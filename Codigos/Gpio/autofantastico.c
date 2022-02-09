#include "EasyPIO_Custom.h"
#include <unistd.h>

int main(void){

pioInit();

pinMode(18,INPUT);

pinMode(23,OUTPUT);
pinMode(24,OUTPUT);
pinMode(22,OUTPUT);

#define retardo 500000

while(1){

	if(digitalRead(18)){
		digitalWrite(23,0);
		digitalWrite(24,0);
		digitalWrite(22,0);
		break;
	}else{
		
		digitalWrite(23,0);
		digitalWrite(24,0);
		digitalWrite(22,1);
		usleep(retardo);
		
		digitalWrite(23,0);
		digitalWrite(24,1);
		digitalWrite(22,0);
		usleep(retardo);
		
		digitalWrite(23,1);
		digitalWrite(24,0);
		digitalWrite(22,0);
		usleep(retardo);
		
		digitalWrite(23,0);
		digitalWrite(24,1);
		digitalWrite(22,0);
		usleep(retardo);
		
	}
	
}

return 0;
}
