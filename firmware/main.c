#include <AVRI2CBootloader/avr/application.h>

#include <inttypes.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <util/delay.h>

#include <Motors.h>

#include "../libMaster/include/DriveSubsystemRegisters.h"

/*
 * BeagleBone Black callbacks
 */
size_t onI2CRead(uint8_t reg, uint8_t* buffer);
void onI2CWrite(uint8_t reg, uint8_t* buffer, size_t bufferSize);

int main()
{
  I2CCallbacks.onReadFunction = onI2CRead;
  I2CCallbacks.onWriteFunction = onI2CWrite;

  sei();

  motorsInit();

  while(true);

  return 0;
}

size_t onI2CRead(uint8_t reg, uint8_t* buffer)
{
  switch(reg)
  {
  }

  return 0;
}

void onI2CWrite(uint8_t reg, uint8_t* buffer, size_t bufferSize)
{
  switch(reg)
  {
  }
}
