#ifndef _DRIVE_SUBSYSTEM_DRIVE_SUBSYSTEM_H_
#define _DRIVE_SUBSYSTEM_DRIVE_SUBSYSTEM_H_

#include <AVRI2CBootloader/I2CDeviceBootable.h>

#include "DriveSubsystemRegisters.h"

#include <stdint.h>

class DriveSubsystem : public I2CDeviceBootable
{
  public:
    DriveSubsystem(I2CBus* bus, uint8_t address);
    ~DriveSubsystem();

    void getPosition(float* x, float* y);
    float getAngle();

    void setPosition(float x, float y);
};

#endif
