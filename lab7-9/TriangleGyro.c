int rightMotor = 2;
int leftMotor = 1;

// turning 60 degrees for an equalateral triangle 
void turn60()
{
	SensorType[S2] = sensorEV3_Gyro; //setting gyro to sensor 1
	
	// while gyro is less than 60 turn left
	while (getGyroDegrees(1) < 120)
	{
		setMotorSpeed(rightMotor, -50);
		setMotorSpeed(leftMotor, 50);
	}
	
	setMotorSpeed(rightMotor, 0);
	setMotorSpeed(leftMotor, 0);
}


// convert distance to degrees 
float distanceInDegrees(long distance) // function to turn distance to degrees 
{
	const float DEGREESTOCM = 360/17.3;
	
	return DEGREESTOCM*distance;
	
}

//moving forward 
void drive(long nMotorRatio, long dist, long power)
{
	
	float degreesToTurn = 0;
	
	degreesToTurn = distanceInDegrees(dist); // getting the degrees to turn 
	nMotorEncoder[leftMotor] = 0;
	
	// move while motor is less than the degrees 
	while (nMotorEncoder[leftMotor] < degreesToTurn )
	{
		setMotorSpeed(leftMotor, power);
		setMotorSpeed(rightMotor, power);
		sleep(2000);
		
	}
	
	// turn function
	turn60();
}

task main()
{
	
	int input;
	displayCenteredTextLine(1, "please press a button:\n top, bottom or left"); // promt for input 
	
	waitForButtonPress();
	
	// giving the variable "input" different value dependent on button pressed 
	if (getButtonPress(buttonUp))
	{
		displayCenteredBigTextLine(4, "50");
		input = 1;
		sleep(200);
	}
	
	if (getButtonPress(buttonLeft))
	{
		displayCenteredBigTextLine(4, "75");
		input = 2;
		sleep(200);
	}
	
	if (getButtonPress(buttonDown))
	{
		displayCenteredBigTextLine(4, "100");
		input = 3;
		sleep(200);
	}
	
	
	
	// giving distance to function dependent of input 
	
	if (input == 1)
	{
		drive(0, 50, 25);
		drive(0, 50, 25);
		drive(0, 50, 25);
	}
	
	else if (input == 2)
	{
		drive(0, 75, 25);
		drive(0, 75, 25);
		drive(0, 75, 25);
	}
	else if (input == 3)
	{
		drive(0, 100, 25);
		drive(0, 100, 25);
		drive(0, 100, 25);
	}
	
	
}




