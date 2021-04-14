// Program author: isaac barry
int leftMotor = 1;
int rightMotor = 2;
//This is the main drive function i call to make the robotc move
void drive(long nMotorRatio, long dist, long power) 
{
	
	setMotorSyncEncoder(leftMotor, rightMotor, nMotorRatio, (360/17.27875959)*dist, power);
	wait1Msec(100);
	
} // finish function



int selectDestination()
{
	int speed;
	int distance;
	int i;
	int count = 0;
	int motorPower;
	
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
	int degrees;
	int heading;
	int rate;
	
	SensorType[0] = sensorEV3_Gyro;
	
	
	eraseDisplay();
	resetGyro(S1);
	degrees = getGyroDegrees(S1);
	
	
	while(degrees < 84)
	{
		setMotorSpeed(leftMotor, 40);
		setMotorSpeed(rightMotor, -40);
		degrees = getGyroDegrees(S1);
		heading = getGyroHeading(S1);
		rate = getGyroRate(S1);
		sleep(10);
		
	} // end while
	
	eraseDisplay();
	setMotorSpeed(leftMotor, 0);
	setMotorSpeed(rightMotor, 0);
	
} // end turn90left()

void turn90right()
{
	int degreesToTurn = -74;
	float degreesSoFar = 0;
	int initialTurnReading = SensorValue[0];
	int motorPower;
	int currentGyroReading;
	
	SensorType[0] = sensorEV3_Gyro;
	
	// Start turning
	motorPower = 15*sgn(degreesToTurn);
	setMotorSync(leftMotor, rightMotor, 100, motorPower);
	
	while(abs(degreesSoFar) < abs(degreesToTurn))
	{
		wait1Msec(10); // wait 10ms, or 0.01s
		currentGyroReading = SensorValue[0] - initialTurnReading;
		degreesSoFar = degreesSoFar + currentGyroReading*0.01;
	} // end while
	
	motor[leftMotor] = 0;
	
	
} // end Turn 90 right()

void destination_one(int x, int y)
{
	int xDest = 4;
	int yDest = 1;
	
	
	while(x < xDest)
	{
		displayBigTextLine(1, "Current position:");
		displayBigTextLine(3, "%d, %d", x, y);
		wait1Msec(1000);
		drive(0, 15, 50);
		wait1Msec(1000);
		x = x + 1;
		displayBigTextLine(1, "Current position:");
		displayBigTextLine(3, "%d, %d", x, y);
		wait1Msec(1000);
	} // end while
	
	turn90left();
	
	while(y > yDest)
	{
		displayBigTextLine(1, "Current position:");
		displayBigTextLine(3, "%d, %d", x, y);
		drive(0, 15, 50);
		wait1Msec(1000);
		y = y - 1;
		displayBigTextLine(1, "Current position:");
		displayBigTextLine(3, "%d, %d", x, y);
		wait1Msec(1000);
	} // end while
	
} // end destination_one()

void destination_two(int x, int y)
{
	int xDest = 5;
	int yDest = 6;
	
	while(x < xDest)
	{
		displayBigTextLine(1, "Current position:");
		displayBigTextLine(3, "%d, %d", x, y);
		wait1Msec(1000);
		drive(0, 15, 50);
		wait1Msec(1000);
		x = x + 1;
		displayBigTextLine(1, "Current position:");
		displayBigTextLine(3, "%d, %d", x, y);
		wait1Msec(1000);
	} // end while
	
	turn90right(); // right function
	
	while(y < yDest)
	{
		displayBigTextLine(1, "Current position:");
		displayBigTextLine(3, "%d, %d", x, y);
		wait1Msec(1000);
		drive(0, 15, 50);
		wait1Msec(1000);
		y = y + 1;
		displayBigTextLine(1, "Current position:");
		displayBigTextLine(3, "%d, %d", x, y);
		wait1Msec(1000);
	} // end while
	
} // end destination_two


task main()
{
	// Declaring the variables in main
	int dest = 0;
	int x = 1;
	int y = 4;
	
	
	// Set up sensors
	SensorType[0] = sensorEV3_Gyro;
	
	dest = selectDestination();
	
	if (dest == 1)
	{
		destination_one(x, y);
	} // end if
	else
	{
		destination_two(x, y);
	} // end else
	
	
} // end main()

