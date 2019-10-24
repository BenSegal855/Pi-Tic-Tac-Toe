#include "project.h"

/*fillSqur
 *Decription:
 *  This function takes in a point and a color and fills
 *  that point with that color on the board
 *
 *Paramaters:
 *  fb: a framebuffer for the display
 *  pt: The point to be filled
 *  color: the desired color of the point
 */
void fillSqur(pi_framebuffer_t *fb, point *pt)
{
  char btmp[8][8] = {{0,0,0,0,0,0,0},
		     {0,0,0,0,0,0,0},
		     {0,0,0,0,0,0,0},
		     {0,0,0,0,0,0,0},
		     {0,0,0,0,0,0,0},
		     {0,0,0,0,0,0,0},
		     {0,0,0,0,0,0,0},
		     {0,0,0,0,0,0,0}};
  if(pt->x == 0 && pt->y == 0)
  {
    btmp[0][0] = 1;
    btmp[0][1] = 1;
    btmp[1][0] = 1;
    btmp[1][1] = 1;
  }
  else if(pt->x == 1 && pt->y == 0)
  {
    btmp[0][3] = 1;
    btmp[0][4] = 1;
    btmp[1][3] = 1;
    btmp[1][4] = 1;
  }
  else if(pt->x == 2 && pt->y == 0)
  {
    btmp[0][6] = 1;
    btmp[0][7] = 1;
    btmp[1][6] = 1;
    btmp[1][7] = 1;
  }
  else if(pt->x == 0 && pt->y == 1)
  {
    btmp[3][0] = 1;
    btmp[3][1] = 1;
    btmp[4][0] = 1;
    btmp[4][1] = 1;
  }
  else if(pt->x == 1 && pt->y == 1)
  {
    btmp[3][3] = 1;
    btmp[3][4] = 1;
    btmp[4][3] = 1;
    btmp[4][4] = 1;
  }
  else if(pt->x == 2 && pt->y == 1)
  {
    btmp[3][6] = 1;
    btmp[3][7] = 1;
    btmp[4][6] = 1;
    btmp[4][7] = 1;
  }
  else if(pt->x == 0 && pt->y == 2)
  {
    btmp[6][0] = 1;
    btmp[6][1] = 1;
    btmp[7][0] = 1;
    btmp[7][1] = 1;
  }
  else if(pt->x == 1 && pt->y == 2)
  {
    btmp[6][3] = 1;
    btmp[6][4] = 1;
    btmp[7][3] = 1;
    btmp[7][4] = 1;
  }
  else if(pt->x == 2 && pt->y == 2)
  {
    btmp[6][6] = 1;
    btmp[6][7] = 1;
    btmp[7][6] = 1;
    btmp[7][7] = 1;
  }
  
  dispBTMP(fb, btmp, pt->color);
}


/*dispGrid
 *
 *Decription:
 *  Displayes the tick tack toe grid
 *
 *Paramaters:
 *  fb: The framebuffer of the display
 */
void dispGrid(pi_framebuffer_t *fb)
{
  char btmp[8][8] = {{0,0,1,0,0,1,0,0},
		     {0,0,1,0,0,1,0,0},
		     {1,1,1,1,1,1,1,1},
		     {0,0,1,0,0,1,0,0},
		     {0,0,1,0,0,1,0,0},
		     {1,1,1,1,1,1,1,1},
		     {0,0,1,0,0,1,0,0},
		     {0,0,1,0,0,1,0,0}};
  dispBTMP(fb, btmp, WHITE);
}

/*dispTie
 *
 *Decriotion:
 *  displays the tie immage
 *
 *Paramaters:
 *  fb: The framebuffer of the display
 */
void dispTie(pi_framebuffer_t *fb)
{
  char face[8][8] = {{0,0,1,1,1,1,0,0},
		     {0,1,1,1,1,1,1,0},
		     {1,1,0,1,1,0,1,1},
		     {1,1,1,1,1,1,1,1},
		     {1,1,1,0,0,1,1,1},
		     {1,1,0,1,1,0,1,1},
		     {0,1,1,1,1,1,1,0},
		     {0,0,1,1,1,1,0,0}};

  char eyes[8][8] = {{0,0,0,0,0,0,0,0},
		     {0,0,0,0,0,0,0,0},
		     {0,0,1,0,0,1,0,0},
		     {0,0,0,0,0,0,0,0},
		     {0,0,0,1,1,0,0,0},
		     {0,0,1,0,0,1,0,0},
		     {0,0,0,0,0,0,0,0},
		     {0,0,0,0,0,0,0,0}};

  dispColo(fb, BLACK);
  dispBTMP(fb, face, YELLOW);
  dispBTMP(fb, eyes, WHITE);
}

/*dispBTMP
 *
 *Decription:
 *  Displayes a bitmap to the screen in a desired color
 *
 *Paramaters:
 *  fb: The framebuffer of the display
 *  btmp: An 8x8 array whic is the bitmap to be displayed
 *  color: Color that the bitmap is to be displayed in
 */
void dispBTMP(pi_framebuffer_t *fb, char btmp[8][8], uint16_t color)
{
  for(int i = 0; i < 8; i++)
    for(int j = 0; j < 8; j++)
      if(btmp[i][j])
	fb->bitmap->pixel[i][j] = color;
}

/*dispColo
 *
 *Decription:
 *  Fills the display with a color. This only exists because
 *  you can't directly access IO via main
 *
 *Paramaters:
 *  fb: The frambebuffer device
 *  color: The color to be filled
 */
void dispColo(pi_framebuffer_t *fb, uint16_t color)
{
  clearFrameBuffer(fb, color);
}
