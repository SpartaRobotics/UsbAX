/*
    Example for moving at variable speeds on the Dynamixel AX12-A series servos
    
	Serial:
	USB  UART: "/dev/ttyUSB0"
	
	*Moves the servo to the selected position (in degrees) at variable speed
	Position (150 to 0) moves on the left, 0 stops in the middle, (0 to -150) moves to the right
		UAX.moveSpeedDeg(ID, Position, Speed):
		@ID - ID of the servo
		@Position - degrees from -150 to 150 with 0 in the middle
		@Speed - speed to move from 0 to 1020 or can use the following constants:
				FULL_SPEED = 1020
				TRIQUARTER = 756
				HALF_SPEED = 512
				QUARTER_SPEED = 256
				STOP = 0
		
*/

#include<iostream>
#include "UsbAX.h"

#define ID 1        // ID for singl servo
#define SEC 1000000 // 1 Second in micro second units for delay
#define MSEC 1000	// 1 milli second in micro second units for delay

using namespace std;

int main()
{
    UsbAX control;

	control.begin("/dev/ttyUSB0", B1000000);

	control.setEndless(ID, OFF); // Sets the servo to "Servo" mode
    
    for(int i = 0; i < 3; i ++)
    {
        control.moveSpeedDeg(ID, 150, 1023);
        usleep(2*SEC);
        
        control.moveSpeedDeg(ID, 120, 768);
        usleep(2*SEC);
        
        control.moveSpeedDeg(ID, 90, 512);
        usleep(2*SEC);
        
        control.moveSpeedDeg(ID, 60, 256);
        usleep(2*SEC);
        
        control.moveSpeedDeg(ID, 30, 128);
        usleep(2*SEC);
        
        control.moveSpeedDeg(ID, 0, 0);
        usleep(2*SEC);
        
        control.moveSpeedDeg(ID, -30, 128);
        usleep(2*SEC);
        
        control.moveSpeedDeg(ID, -60, QUARTER_SPEED);
        usleep(2*SEC);
        
        control.moveSpeedDeg(ID, -90, HALF_SPEED);
        usleep(2*SEC);
        
        control.moveSpeedDeg(ID, -120, TRIQUARTER_SPEED);
        usleep(2*SEC);
        
        control.moveSpeedDeg(ID, -150, FULL_SPEED);
        usleep(2*SEC);
        
    }
    
    control.disconnect();
    return 0;
}

