/*
LAB 2 function
AUTHOR: Isaac
*/

int leftMotor = 1;
int rightMotor = 2;

void goForward2second() //both motors at the same speed keep it in a straight line for sleep(1000) = 1 second
{
	setMotorSpeed(leftMotor, 50);
	setMotorSpeed(rightMotor, 50);
	sleep(2000);
}
void turn180degreesright() //just like turn90degreesleft above, however the motor speeds are swapped to make the robot turn right
{
	setMotorSpeed(leftMotor, -45);
	setMotorSpeed(rightMotor, 45);
	sleep(900);
	
	
}
void returnBackSlow() //both motors at the same speed keep it in a straight line for sleep(1000) = 1 second
{
	setMotorSpeed(leftMotor, 25);
	setMotorSpeed(rightMotor, 25);
	sleep(4000);
}

task main() 
{	//executing the function
	goForward2second();
	turn180degreesright();
	returnBackSlow();
}