#ifndef _DRIVE_SUBSYSTEM_DRIVE_SUBSYSTEM_H_
#define _DRIVE_SUBSYSTEM_DRIVE_SUBSYSTEM_H_

#include <AVRI2CBootloader/I2CDeviceBootable.h>

#include <stdint.h>

#define DRIVE_SUBSYSTEM_REGISTER_POSITION 0x10
#define DRIVE_SUBSYSTEM_REGISTER_ANGLE 0x11

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
