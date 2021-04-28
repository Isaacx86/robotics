// Program by isaac barry
// Location finder 3 q6 of lab10-12
int leftMotor = 1;
int rightMotor = 2; 

void drive(long nMotorRatio, long dist, long power) 
{
	
	setMotorSyncEncoder(leftMotor, rightMotor, nMotorRatio, (360/17.27875959)*dist, power);
	wait1Msec(100);
	
} // end drive



int selectDestination()
{
	
	while (getButtonPress(buttonEnter) == 0)
	{
		// Display options to user
		displayTextLine(1, "Choose your destination:");
		displayTextLine(3, "Up = Position [4,1]");
		displayTextLine(5, "Down = Position [5,6]");
		
		wait1Msec(100);
		
		eraseDisplay();
		
		
		if(getButtonPress(buttonUp))
		{
			return 1;
			
			
		} // end if
		else if (getButtonPress(buttonDown))
		{
			return 0;
			
			
		} // end else if
		
	} // end while
	
} // end selectDestination


void turn90left()
{
	resetMotorEncoder(1);
	resetMotorEncoder(2);
	setMotorSyncEncoder(leftMotor, rightMotor, 100, 190, 50);	
	wait1Msec(1000);
	
} // end turn90left()

void turn90right()
{
	resetMotorEncoder(1);
	resetMotorEncoder(2);
	setMotorSyncEncoder(leftMotor, rightMotor, -100, 190, 50);	
	wait1Msec(1000);
	
} // end turn90right()

void destOne(int x, int y)
{
	int xDest = 1;
	int yDest = 1;
	
	
	
	while(x > xDest)
	{
		displayBigTextLine(1, "Current position is:");
		displayBigTextLine(3, "%d, %d", x, y);
		wait1Msec(1000);
		drive(0, 15, 50);
		wait1Msec(1000);
		x = x - 1;
		displayBigTextLine(1, "Current position is:");
		displayBigTextLine(3, "%d, %d", x, y);
		wait1Msec(1000);
	} // end while
	
	turn90right();
	
	while(y > yDest)
	{
		displayBigTextLine(1, "Current position is:");
		displayBigTextLine(3, "%d, %d", x, y);
		drive(0, 15, 50);
		wait1Msec(1000);
		y = y - 1;
		displayBigTextLine(1, "Current position is:");
		displayBigTextLine(3, "%d, %d", x, y);
		wait1Msec(1000);
	} // end while
	
} // end destOne()

void destTwo(int x, int y)
{
	int xDest = 3;
	int yDest = 7;
	int beep = 5;
	int i;
	
	
	
	while(x < xDest)
	{
		displayBigTextLine(1, "Current position is:");
		displayBigTextLine(3, "%d, %d", x, y);
		wait1Msec(1000);
		drive(0, 15, 50);
		wait1Msec(1000);
		x = x + 1;
		displayBigTextLine(1, "Current position is:");
		displayBigTextLine(3, "%d, %d", x, y);
		wait1Msec(1000);
	} // end while
	
	turn90right();
	
	while(y < yDest)
	{
		displayBigTextLine(1, "Current position is:");
		displayBigTextLine(3, "%d, %d", x, y);
		wait1Msec(1000);
		drive(0, 15, 50);
		wait1Msec(1000);
		y = y + 1;
		displayBigTextLine(1, "Current position is:");
		displayBigTextLine(3, "%d, %d", x, y);
		wait1Msec(1000);
	} // end while
	
	for(i=0;i<beep;i++) // beeps for 5 seconds then stops. 
	{
		playSound(soundBeepBeep);
		sleep(1000);
	}
	
	turn90right();
	
} // end destTwo


task main()
{
	// Declare variables
	int dest = 0;
	int x = 3;
	int y = 1;
	
	
	// Set up sensors
	SensorType[0] = sensorEV3_Gyro;
	
	destTwo(x, y);
	x = 3;
	y = 7;
	destOne(x, y);	
} // end main()