#include "project.h"

/*getAccl
 *
 *Decription:
 *  Gets and parces acceleromater data
 *
 *Paramaters:
 *  gyro: an i2c device for the gyro
 *
 *Returns:
 *  A char with the following values:
 *    U: normal oritation when on a table
 *    D: upside down orientation when on a table
 *    P: orietation if placed on its side
 *    Q: else
 */
char getAccl(pi_i2c_t* gyro)
{
  coordinate_t data;
  getAccelData(gyro,&data);

  if(data.z > fabs(data.x) && data.z > fabs(data.y))
    return 'U';
  else if (data.z < -0.7)
    return 'D';
  else if((fabs(data.x) > fabs(data.y) && fabs(data.x) > data.z) || ((fabs(data.y) > fabs(data.x) && fabs(data.y) > data.z)))
    return 'P';
  return 'Q';
}


/*getJoy *CALLBACK FUNCTION*
 *Decription:
 *  Sets global variable joy to NSEW for joystic direction
 *
 *Paramaters:
 *  code: joystick code
 */
char joy = 'Q';
void getJoy(unsigned int code)
{
  joy = 'Q';
  if(code == KEY_UP)
    joy = 'N';
  else if(code == KEY_DOWN)
    joy = 'S';
  else if(code == KEY_LEFT)
    joy = 'W';
  else if(code == KEY_RIGHT)
    joy = 'E';
}

/*getIn
 *Decription:
 *  Returns input code
 *
 *Paramaters:
 *  gyro: the i2c gyroscope
 *  joystick: the joystick device
 *
 *Returns:
 *  Returns input code:
 *    N,S,E,W: joystick direction if device is in upward orientaion
 *    P: if device is on its side
 *    D: if device is upside down
 *    Q: else
 */ 
char getIn(pi_i2c_t* gyro, pi_joystick_t* joystick)
{
  if(getAccl(gyro) == 'U')
  {
    joy = 'Q';
    pollJoystick(joystick,getJoy,500);
    return joy;
  }
  return getAccl(gyro);
}
