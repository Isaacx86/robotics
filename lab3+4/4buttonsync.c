int leftMotor = 1;
int rightMotor = 2;

void drive(long nMotorRatio, long dist, long power) 
{
	
	setMotorSyncEncoder(leftMotor, rightMotor, nMotorRatio, (dist/17.27875959)*360, power);
	wait1Msec(5000);
	
}


task main()
{
	
	int speed;
	int distance;
	displayCenteredTextLine(1, "please press a button:");
	
	waitForButtonPress();
	
	
	
	while (getButtonPress(buttonEnter) == 0)
	{
		speed = 0;
		speed = random(100);
		
		if(getButtonPress(buttonUp))
		{
			distance = 10;
			displayTextLine(4, "distance = %d", distance);
			drive(0, 10, speed);
			wait1Msec(100);
		}
		else if (getButtonPress(buttonDown))
		{
			distance = 40;
			displayTextLine(4, "distance = %d", distance);
			drive(0, 40, speed);
			wait1Msec(100);
		}
		else if (getButtonPress(buttonLeft))
		{
			distance = 60;
			displayTextLine(4, "distance = %d", distance);
			drive(0, 60, speed);
			wait1Msec(100);
		}
		else if (getButtonPress(buttonRight))
		{
			distance = 80;
			displayTextLine(4, "distance = %d", distance);
			drive(0, 80, 50);
			wait1Msec(100);
		}
	}
	
	
	
}