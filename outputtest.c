#include "project.h"

int main(void)
{
  pi_framebuffer_t *fb=getFrameBuffer();
  dispGrid(fb);
  
  point *pt = malloc(sizeof(point));
  pt->x = 0;
  pt->y = 0;
  pt->color = YELLOW;
  fillSqur(fb, pt);
  pt->x = 1;
  pt->y = 0;
  pt->color = BLUE;
  fillSqur(fb, pt);
  pt->x = 2;
  pt->y = 0;
  pt->color = PINK;
  fillSqur(fb, pt);
  pt->x = 0;
  pt->y = 1;
  pt->color = BLUE;
  fillSqur(fb, pt);
  pt->x = 1;
  pt->y = 1;
  pt->color = YELLOW;
  fillSqur(fb, pt);
  pt->x = 2;
  pt->y = 1;
  pt->color = BLUE;
  fillSqur(fb, pt);
  pt->x = 0;
  pt->y = 2;
  pt->color = PINK;
  fillSqur(fb, pt);
  pt->x = 1;
  pt->y = 2;
  pt->color = BLUE;
  fillSqur(fb, pt);
  pt->x = 2;
  pt->y = 2;
  pt->color = YELLOW;
  fillSqur(fb, pt);

  sleep(5);
  (fb->bitmap,0);

  dispTie(fb);
  sleep(5);
  clearFrameBuffer(fb,0);
}
