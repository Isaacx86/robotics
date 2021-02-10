/*	
	Author Emma jane:
	Date: 2/3/2020
	using functions to go in a square
    and using random function
*/

int leftMotor = 1;
int rightMotor = 2;
int direction = random(1);


//moving forward function
void moveForward()
{
	setMotorSpeed(leftMotor, 50);
	setMotorSpeed(rightMotor, 50);
	sleep(2000);
}

//turning function
void turn()
{
	if (direction == 1)
	{
	    //turn left
	    setMotorSpeed(leftMotor, 50);
		setMotorSpeed(rightMotor, -50);
		sleep(412);	
	}
	if (direction == 0)
	{
		//turn right
		setMotorSpeed(leftMotor, -50);
		setMotorSpeed(rightMotor, 50);
		sleep(412);
	} 	
}


//moving in a square
task main()
{
	
	moveForward();
	turn();
	moveForward();
	turn();
	moveForward();
	turn();
	moveForward();
	turn();
	
}

