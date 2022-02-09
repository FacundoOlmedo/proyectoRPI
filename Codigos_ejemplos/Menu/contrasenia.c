#include <stdio.h>
#include <termios.h>

#define FD_STDIN 0

int main()
{
    int intentos = 0;
    char tec;
    char contra[6];
    struct termios t_old, t_new;
    tcgetattr(FD_STDIN, &t_old); //lee atributos del teclado
    t_new = t_old;
    t_new.c_lflag &= ~(ECHO | ICANON); // anula entrada canonica y eco
    tcsetattr(FD_STDIN,TCSANOW,&t_new); //actualiza con los valores nuevos de la config. TCSANOW = activar la modificacion inmediatamente
    tec = 0;
    int i = 0;
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
        if(contra[0] == 'c' && contra[1] && 'i' && contra[2] && 'n' && contra[3] == 'c' && contra[4] == 'o'){
            puts("\n---------------------------\n   Bienvenido al Sistema\n---------------------------");
            break;
        }
        else
            puts("\n---------------------------\n     Password invalida\n---------------------------");
            
        intentos++;
        tec = 0;
        i=0;
    }
    tcsetattr(FD_STDIN, TCSANOW, &t_old); //actualiza con los valores previos
}
