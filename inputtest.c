#include "project.h"
#include <unistd.h>
int main(void)
{
  pi_i2c_t* gyro=geti2cDevice();
  configureAccelGyro(gyro);
  pi_joystick_t* joystick=getJoystickDevice();
  while(1)
  {    
    char out = getIn(gyro, joystick);
    printf("%c\n", out);
    usleep(500000);
  }
  return 0;
}
