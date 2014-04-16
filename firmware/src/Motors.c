#include <Motors.h>

#define MOTOR_A_DDR DDRB
#define MOTOR_A_PORT PORTB

#define MOTOR0_A_BIT 1
#define MOTOR1_A_BIT 2

#define MOTOR_B_DDR DDRC
#define MOTOR_B_PORT PORTC

#define MOTOR0_B_BIT 2
#define MOTOR1_B_BIT 3

#define MOTOR_EN_DDR DDRD
#define MOTOR_EN_PORT PORTD

#define MOTOR0_EN_BIT 6
#define MOTOR1_EN_BIT 7

void motorsInit()
{
  //Make motor channels outputs
  MOTOR_EN_DDR |= (_BV(MOTOR0_EN_BIT) | _BV(MOTOR1_EN_BIT));
  MOTOR_A_DDR |= (_BV(MOTOR0_A_BIT) | _BV(MOTOR1_A_BIT));
  MOTOR_B_DDR |= (_BV(MOTOR0_B_BIT) | _BV(MOTOR1_B_BIT));

  //Enable motors
  MOTOR_EN_PORT |= (_BV(MOTOR0_EN_BIT) | _BV(MOTOR1_EN_BIT));
}

void motorsSet(int left, int right)
{
  if(left > 0)
  {
    MOTOR_A_PORT &= ~_BV(MOTOR0_A_BIT);
    MOTOR_B_PORT |= _BV(MOTOR0_B_BIT);
  }
  else if(!left)
  {
    MOTOR_A_PORT &= ~_BV(MOTOR0_A_BIT);
    MOTOR_B_PORT &= ~_BV(MOTOR0_B_BIT);
  }
  else
  {
    MOTOR_A_PORT |= _BV(MOTOR0_A_BIT);
    MOTOR_B_PORT &= ~_BV(MOTOR0_B_BIT);
  }

  if(right > 0)
  {
    MOTOR_A_PORT &= ~_BV(MOTOR1_A_BIT);
    MOTOR_B_PORT |= _BV(MOTOR1_B_BIT);
  }
  else if(!right)
  {
    MOTOR_A_PORT &= ~_BV(MOTOR1_A_BIT);
    MOTOR_B_PORT &= ~_BV(MOTOR1_B_BIT);
  }
  else
  {
    MOTOR_A_PORT |= _BV(MOTOR1_A_BIT);
    MOTOR_B_PORT &= ~_BV(MOTOR1_B_BIT);
  }
}
