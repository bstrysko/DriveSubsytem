#include <DriveSubsystem.h>

DriveSubsystem::DriveSubsystem(I2CBus* bus, uint8_t address) : I2CDeviceBootable(bus, address)
{
}

DriveSubsystem::~DriveSubsystem()
{
}

void DriveSubsystem::getPosition(float* x, float* y)
{
	uint8_t buffer[2];
	i2cRead(DRIVE_SUBSYSTEM_REGISTER_POSITION, buffer, 2);

	(*x) = (float)buffer[0];
	(*y) = (float)buffer[1];
}

float DriveSubsystem::getAngle()
{
	uint8_t v;

	i2cRead(DRIVE_SUBSYSTEM_REGISTER_ANGLE, &v, 1);

	return (float)v;
}

void DriveSubsystem::setPosition(float x, float y)
{
	uint8_t buffer[2];

	buffer[0] = (uint8_t)x;
	buffer[1] = (uint8_t)y;

	i2cWrite(DRIVE_SUBSYSTEM_REGISTER_POSITION, buffer, 2);
}
