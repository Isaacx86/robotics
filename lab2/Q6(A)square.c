/*	
	using functions to go in a square
*/

int leftMotor = 1;
int rightMotor = 2;


//moving forward function
void moveForward()
{
	setMotorSpeed(leftMotor, 50);
	setMotorSpeed(rightMotor, 50);
	sleep(2000);
}

//turning left function
void turnLeft()
{
	setMotorSpeed(leftMotor, 50);
	setMotorSpeed(rightMotor, -50);
	sleep(412);
}

//moving in a square
task main()
{
	
	moveForward();
	turnLeft();
	moveForward();
	turnLeft();
	moveForward();
	turnLeft();
	moveForward();
	turnLeft();
	
}

