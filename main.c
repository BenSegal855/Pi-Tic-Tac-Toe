#include "project.h"

int main(void)
{
  //Setting up all the devices
  pi_framebuffer_t *fb=getFrameBuffer();
  pi_joystick_t* joy=getJoystickDevice();
  pi_i2c_t* gyro=geti2cDevice();
  configureAccelGyro(gyro);

  //Displaying that grid and making the curssor
  dispGrid(fb);
  point *cur = malloc(sizeof(point));
  cur->x = 1;
  cur->y = 1;
  cur->color = GRAY;

  //Look at that empty board
  char tick[3][3] = {{'0','0','0'},
		     {'0','0','0'},
		     {'0','0','0'}};

  //Its the drawing point
  point *draw = malloc(sizeof(point));
  draw->x = 0;
  draw->y = 0;
  draw->color = BLACK;

  //Flags
  char in = 'Q', turn = 'X', win = '0';
  char curOn = 1;

  //Welsome to the main loop
  while(in != 'D'){
    in = getIn(gyro, joy);
   
    if(in != 'D'){
      //Positioning cusrso   
      if(in == 'W' && (cur->x - 1 >= 0))
	cur->x--;
      if(in == 'E' && (cur->x + 1 <= 2))
	cur->x++;
      if(in == 'S' && (cur->y + 1 <= 2))
	cur->y++;
      if(in == 'N' && (cur->y - 1 >= 0))
	cur->y--;

      //Drawing squares
      for(int i = 0; i < 3; i++){
	for(int j = 0; j <3; j++){
	  draw->x = i;
	  draw->y = j;
	  if(tick[i][j] == 'X')
	    draw->color = BLUE;
	  else if(tick[i][j] == 'O')
	    draw->color = PINK;
	  else
	    draw->color = BLACK;
	  fillSqur(fb, draw);
	}
      }
      
      //Drawing curssor
      if(curOn)
	fillSqur(fb, cur);
      curOn = !curOn;
    }

    //Placment of stuff on tick
    if(in == 'P' && tick[cur->x][cur->y] == '0'){
	tick[cur->x][cur->y] = turn;
      if(turn == 'X')
	turn = 'O';
      else
	turn = 'X';
    }

    //Who won?
    if(tick[1][1] != '0' && ((tick[0][0] == tick[1][1] && tick[0][0] == tick[2][2]) || (tick[0][2] == tick [1][1] && tick[1][1] == tick[2][0])))
      //diagional check ^
      win = tick[1][1];
    //row check
    for(int i = 0; i < 3; i++)
      if(tick[i][0] == tick[i][1] && tick[i][0] == tick[i][2] && tick[i][0] != '0')
	win = tick[i][0];
    //col check
    for(int i = 0; i < 3; i++)
      if(tick[0][i] == tick[1][i] && tick[0][i] == tick[2][i] && tick[0][i] != '0')
	win = tick[0][i];
    //tie chenk
    if(win == '0'){
      char tmp = 0;
      for(int i = 0; i < 3; i++)
	for(int j = 0; j < 3; j++)
	  if(tick[i][j] == '0')
	    tmp++;
      if(!tmp)
	win = 'T';
    }
    
    //Victory time and reset
    if(win == 'X'){
      dispColo(fb,BLUE);
      sleep(3);
      dispColo(fb,BLACK);
      for(int i = 0; i < 3; i ++)
	for(int j = 0; j < 3; j++)
	  tick[i][j] = '0';
      dispGrid(fb);
      win = '0';
      turn = 'X';
      cur->x = 1;
      cur->y = 1;
    }
    else if(win == 'O'){
      dispColo(fb,PINK);
      sleep(3);
      dispColo(fb,BLACK);
      for(int i = 0; i < 3; i ++)
	for(int j = 0; j < 3; j++)
	  tick[i][j] = '0';
      dispGrid(fb);
      win = '0';
      turn = 'X';
      cur->x = 1;
      cur->y = 1;
    }
    else if (win == 'T'){
      dispTie(fb);
      sleep(3);
      dispColo(fb,BLACK);
      for(int i = 0; i < 3; i ++)
	for(int j = 0; j < 3; j++)
	  tick[i][j] = '0';
      dispGrid(fb);
      win = '0';
      turn = 'X';
      cur->x = 1;
      cur->y = 1;
    }
    usleep(400000);
  }

  //RAGE QUIT
  dispColo(fb,BLACK);
  free(cur);
  free(draw);
  freeJoystick(joy);
  return 0;
}
