#include <iostream>
#include <sstream>
#include <algorithm>
#include <stdint.h>
#include <assert.h>

using namespace std;

void usage(string name);
uint8_t stringToUInt8(char* s);

#include <DriveSubsystem/DriveSubsystem.h>

int main(int argc, char* argv[])
{
	if(argc < 3)
	{
		usage(argv[0]);
		return 1;
	}

	uint8_t i2cBusNumber = stringToUInt8(argv[1]);
	uint8_t i2cDeviceAddress = stringToUInt8(argv[2]);

	I2CBus bus(i2cBusNumber);
	DriveSubsystem device(&bus, i2cDeviceAddress);

	if(!device.inApplicationMode())
	{
		cout << "Device NOT in application mode" << endl;
		cout << "Switching to application mode..." << endl;
		device.enterApplicationMode();
	}
	else
	{
		cout << "Device in application mode..." << endl;
	}

	cout << device.getAngle() << endl;

	return 0;
}

void usage(string name)
{
	cout << "usage: " << name << " [ I2C Bus Number ] [I2C Device Address]" << endl;
}

uint8_t stringToUInt8(char* s)
{
	uint8_t result;
	
	result = atoi(s);
	
	if(result == 0 && s[0] != '0')
	{
		stringstream o;
		o << s << " is not a number";		
		throw ios_base::failure(o.str());
	}

	return result;
}
