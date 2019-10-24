#include "sense.h"
#include <stdlib.h>
#include <stdio.h>
#include <linux/input.h>
#include <unistd.h>
#include <math.h>

//Structs
typedef struct{
  char x;
  char y;
  uint16_t color;
}point;

//Colors
#define WHITE getColor(0xff,0xff,0xff)
#define YELLOW getColor(0xff,0xff,0)
#define BLUE getColor(0,0,0xff)
#define BLACK 0
#define GRAY getColor(0x50, 0x50, 0x50)
#define PINK getColor(0xff, 0x88, 0x88)

//Forward declarations
//output.c
void dispGrid(pi_framebuffer_t *fb);
void dispBTMP(pi_framebuffer_t *fb, char btmp[8][8], uint16_t color);
void fillSqur(pi_framebuffer_t *fb, point *pt);
void dispTie(pi_framebuffer_t *fb);
void dispColo(pi_framebuffer_t *fb, uint16_t color);

//input.c
char getAccl(pi_i2c_t* gyro);
void getJoy(unsigned int code);
char getIn(pi_i2c_t* gyro, pi_joystick_t* joystick);
