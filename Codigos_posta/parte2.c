#include <stdio.h>
#include <termios.h>
#include <string.h>

#define FD_STDIN 0

int main(){
	if( !login() ){
		puts("Limite de intentos alcanzado");
		puts("Abortando programa...");
	}

            

}

//Devuelve 1 para acceso exitoso, 0 para 3 intentos fallidos
bool login(){
	const char * password = "cinco";
	int intentos = 0;
	char tec = 0;
	int i = 0;
	char contra[6];
	bool login = false;		//bandera para guardar el estado de los intentos
	struct termios t_old, t_new;
	tcgetattr(FD_STDIN, &t_old); //lee atributos del teclado
	t_new = t_old;
	t_new.c_lflag &= ~(ECHO | ICANON); // anula entrada canonica y eco
	tcsetattr(FD_STDIN,TCSANOW,&t_new); //actualiza con los valores nuevos de la config. TCSANOW = activar la modificacion inmediatamente

	while(intentos < 3){
		puts("Ingrese su password de 5 digitos:");
		while (tec!=10){
			tec=getchar();
			if(i<5){
				printf("*");
				contra[i] = tec;
				i++;
			}
		}
		if( strncmp(contra, password, 5) == 0){
			login = true;
			puts("\n---------------------------\n   Bienvenido al Sistema\n---------------------------");
			break;
		}else
			puts("\n---------------------------\n     Password invalida\n---------------------------");
				
		intentos++;
		tec = 0;
		i = 0;
	}
	tcsetattr(FD_STDIN, TCSANOW, &t_old); //actualiza con los valores previos
	return login;
}