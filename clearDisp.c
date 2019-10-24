#include "sense.h"

int main (void)
{
  pi_framebuffer_t *fb=getFrameBuffer();
  clearFrameBuffer(fb,0);
  return 0;
}
