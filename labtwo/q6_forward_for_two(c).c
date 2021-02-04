/*
LAB 2 function
AUTHOR: Isaac
*/

int leftMotor = 1;
int rightMotor = 2;

void goForward2second() //both motors at the same speed keep it in a straight line for 2 seconds (sleep 2000)
{
	setMotorSpeed(leftMotor, 50);
	setMotorSpeed(rightMotor, 50);
	sleep(2000);
}
void turn180degreesright() //This function will turn 180 degrees too the right on the spot.
{
	setMotorSpeed(leftMotor, -45);
	setMotorSpeed(rightMotor, 45);
	sleep(900);
	
	
}
void returnBackSlow() //This will slow the motors down, and double the time to bring it back to its starting position
{
	setMotorSpeed(leftMotor, 25);
	setMotorSpeed(rightMotor, 25);
	sleep(4000);
}

task main() 
{	//executing the functions as followed
	goForward2second();
	turn180degreesright();
	returnBackSlow();
}