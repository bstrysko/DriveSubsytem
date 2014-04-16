#include <DriveSubsystem.h>

DriveSubsystem::DriveSubsystem(I2CBus* bus, uint8_t address) : I2CDeviceBootable(bus, address)
{
}

DriveSubsystem::~DriveSubsystem()
{
}

void DriveSubsystem::getPosition(float* x, float* y)
{
	float buffer[2];
	i2cRead(DRIVE_SUBSYSTEM_REGISTER_POSITION, (uint8_t*)buffer, 8);

	(*x) = buffer[0];
	(*y) = buffer[1];
}

float DriveSubsystem::getAngle()
{
	float v;
	i2cRead(DRIVE_SUBSYSTEM_REGISTER_ANGLE, (uint8_t*)&v, 4);
	return v;
}

void DriveSubsystem::setPosition(float x, float y)
{
	float buffer[2];

	buffer[0] = x;
	buffer[1] = y;

	i2cWrite(DRIVE_SUBSYSTEM_REGISTER_POSITION, (uint8_t*)buffer, 8);
}
