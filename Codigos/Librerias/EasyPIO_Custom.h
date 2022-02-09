#include <sys/mman.h>
#include <stdio.h>

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BCM2835_PERI_BASE 0x3F000000
#define GPIO_BASE (BCM2835_PERI_BASE + 0x200000)

volatile unsigned int *gpio; //Pointer to base of gpio
#define GPLEV0 (* (volatile unsigned int *) (gpio + 13))
#define BLOCK_SIZE (4*1024)

void pioInit(){
 int mem_fd;
 void *reg_map;
 mem_fd = open("/dev/mem", O_RDWR|O_SYNC); // abre /dev/mem
 reg_map = mmap(
 NULL, // dir. donde comienza el mapeo (null=no importa)
 BLOCK_SIZE, // 4KB bloque mapeado
 PROT_READ|PROT_WRITE, // permite lect.y escr.en la mem.
 MAP_SHARED, // acceso no exclusivo
 mem_fd, // puntero a /dev/mem
 GPIO_BASE); // offset a la GPIO
 gpio = (volatile unsigned *)reg_map;

}

#define GPFSEL ((volatile unsigned int *) (gpio + 0))
#define GPSET ((volatile unsigned int *) (gpio + 7))
#define GPCLR ((volatile unsigned int *) (gpio + 10))
#define GPLEV ((volatile unsigned int *) (gpio + 13))
#define INPUT 0
#define OUTPUT 1

void pinMode(int pin, int function) {
 int reg = pin/10;
 int offset = (pin%10)*3;
 GPFSEL[reg] &= ~((0b111 & ~function) << offset);
 GPFSEL[reg] |= ((0b111 & function) << offset);
}

void digitalWrite(int pin, int val) {
 int reg = pin / 32;
 int offset = pin % 32;
 if (val) GPSET[reg] = 1 << offset;
 else GPCLR[reg] = 1 << offset;
}

int digitalRead(int pin) {
 int reg = pin / 32;
 int offset = pin % 32;
 return (GPLEV[reg] >> offset) & 0x00000001;
}




