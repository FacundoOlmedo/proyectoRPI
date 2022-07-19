#ifndef ANIMACIONES_H
#define ANIMACIONES_H

#include "EasyPIO_Custom.h"
#include <unistd.h>
#include <math.h>

// int multiplicador = 1;

int menu();
void auto_fantastico(int *, float vel);
void el_choque(int *);
void la_apilada(int *);
void la_carrera(int *);
void la_pareja(int *);
void la_serpiente(int *);
void tiro_vertical(int *);
void caida_pelota(int *);



/* 	void auto_fantastico(int *, int vel);
	void el_choque(int *, int vel);
	void la_apilada(int *, int vel);
	void la_carrera(int *, int vel);
	void la_pareja(int *, int vel);
	void la_serpiente(int *, int vel);
	void tiro_vertical(int *, int vel);
	void caida_pelota(int *, int vel);
*/

void ledsOff(int *);
int check_keys();

#endif
