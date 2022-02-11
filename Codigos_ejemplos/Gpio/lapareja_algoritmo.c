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

int main(void)
{

	pioInit();

	int v[8] = {led1, led2, led3, led4, led5, led6, led7, led8};

	pinMode(v[0], OUTPUT);
	pinMode(v[1], OUTPUT);
	pinMode(v[2], OUTPUT);
	pinMode(v[3], OUTPUT);
	pinMode(v[4], OUTPUT);
	pinMode(v[5], OUTPUT);
	pinMode(v[6], OUTPUT);
	pinMode(v[7], OUTPUT);

    int suma=0;
    
	void lapareja(void);

	int main()
	{

		while (1)
		{

			lapareja();
		}

		return 0;
	}

	void lapareja(void)
	{
		for (int i = 0; i <= 8; i++)
		{
            if(suma == 3)
            {
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