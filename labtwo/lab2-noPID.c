/*
LAB 2 functtion
AUTHOR: Isaac Barry & Emma Jane
2/3/2021
*/

int leftMotor = 1;
int rightMotor = 2;

void turn90degreesleft() //by setting one of the motors to the negative speed, it allows the robot to turn 90 degrees left on the spot, depending on the speed and sleep time
{
	setMotorSpeed(leftMotor, 50); 
	setMotorSpeed(rightMotor, -50);
	sleep(420);
}

void turn90degreesright() //just like turn90degreesleft above, however the motor speeds are swapped to make the robot turn right
{
	setMotorSpeed(leftMotor, -50);
	setMotorSpeed(rightMotor, 50);
	sleep(420);
}

void goForward1second() //both motors at the same speed keep it in a straight line for sleep(1000) = 1 second
{
	setMotorSpeed(leftMotor, 50);
	setMotorSpeed(rightMotor, 50);
	sleep(1000);
}

void swingRight90degrees() //by having more power in one motor than the other we can swing turn rather than turn on the spot, we just need to calculate the right sleep() time
{
	setMotorSpeed(leftMotor, 20);
	setMotorSpeed(rightMotor, 60);
	sleep(950);
}

void swingLeft90degrees() //swapped like swingRight90degrees() above
{
	setMotorSpeed(leftMotor, 60);
	setMotorSpeed(rightMotor, 20);
	sleep(950);
}

void reverse1second() //reverse power in the motor allows the robot to go backwards for 1 second
{
	setMotorSpeed(leftMotor, -50);
	setMotorSpeed(rightMotor, -50);
	sleep(1000); 
}

task main() 
{	//executing the functions in order.
	turn90degreesleft();
	turn90degreesright();
	goForward1second();
	swingLeft90degrees();
	swingRight90degrees();
	reverse1second();
}