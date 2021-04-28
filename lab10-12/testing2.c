int leftMotor = 1;
int rightMotor = 2;
int i = 0;
void Drive(long,long,long,long);
void turn90Left();
void turn90Right();
void goal(int,int,int,int);
void sec_goal(int,int,int,int);

task main()
{
	int startx = 3;
	int starty = 1;
	int finishx = 3;
	int finishy = 7;
	
	int sec_startx = 7; //Reverse
	int sec_starty = 3; //Reverse
	int sec_finishx = 1;
	int sec_finishy = 1;
	
	SensorType[S1]= sensorEV3_Gyro; //Port to Sensor
	
	while (getButtonPress(buttonEnter) == 0)
	{
		sleep(200);
		
		if (getButtonPress(buttonUp)) //when button up is pressed
		{			
			startx = startx + 1;
			displayCenteredBigTextLine(4, "X is %d Y is %d", startx,starty);	
			
		}
		else if (getButtonPress(buttonRight)) // when right button is pressed
		{
			starty = starty + 1;	
			displayCenteredBigTextLine(4, "X is %d Y is %d", startx,starty);	
		}	
		else if (getButtonPress(buttonDown)) //when down button is pressed
		{
			
			startx = startx - 1;
			displayCenteredBigTextLine(4, "X is %d Y is %d", startx,starty);		
		}
		else if (getButtonPress(buttonLeft))//when left button is pressed
		{
			starty = starty - 1;	
			displayCenteredBigTextLine(4, "X is %d Y is %d", startx,starty);	
		}
		else if (getButtonPress(buttonEnter))//when left button is pressed
		{
			break;	
		}
		
	}	
	
	if (startx >= 1 && starty >= 1)
	{
		displayCenteredBigTextLine(6, "succesful");
		goal(startx,starty,finishx,finishy);
	}
	else
	{
		displayCenteredBigTextLine(6, "cant be negative");
		sleep(2000);
	}
	
	sleep(5000);
	playSound(soundBeepBeep);
	
	if(sec_startx >= 1 && sec_starty >= 1)
	{
		displayCenteredBigTextLine(6, "succesful");
		sec_goal(sec_startx,sec_starty,sec_finishx,sec_finishy);
	}
	else
	{
		displayCenteredBigTextLine(6, "cant be negative");
		sleep(2000);
	}
}


//Function for 90 Degrees right turn by using Gyro!
void turn90Right(){
	
	wait1Msec(100);
	
	resetGyro(S1);
	
	wait1Msec(100);
	
	while(abs(getGyroDegrees(S1))<90)
	{
		setMotorSpeed(leftMotor, 10);
		setMotorSpeed(rightMotor, -10);
	}
	
	setMotorSpeed(leftMotor, 0);
	setMotorSpeed(rightMotor, 0);
	wait1Msec(1000);
}

//Function for 90 Degrees left turn by using Gyro!
void turn90Left(){
	
	wait1Msec(100);
	
	resetGyro(S1);
	
	wait1Msec(100);
	
	while(abs(getGyroDegrees(S1))<90)
	{
		setMotorSpeed(leftMotor, -10);
		setMotorSpeed(rightMotor, 10);
	}
	
	setMotorSpeed(leftMotor, 0);
	setMotorSpeed(rightMotor, 0);
	wait1Msec(1000);
}


void Drive(long nmotorratio, long encoderRatio, long power,long dist)
{
	//500 for encoderratio is equal to 30 cm
	setMotorSyncEncoder(leftMotor,rightMotor,nmotorratio,encoderRatio,power);
	sleep(500*dist/25);
	setMotorSpeed(leftMotor,0);
	setMotorSpeed(rightMotor,0);	
	resetMotorEncoder(leftMotor);
	resetMotorEncoder(rightMotor);
}

void goal(int startx, int starty,int finishx,int finishy)
{
	int offsetx = finishx - startx;
	int offsety = finishy - starty;
	int quad1;
	int quad2;
	int goingup;
	int goingdown;
	offsetx = abs(offsetx);
	offsety = abs(offsety);
	
	if (startx > finishx)
	{
		quad2 = 1;
		turn90Left();
		turn90Left();
		for(i=0;i< offsetx;i++)
		{
			Drive(0,300, 50,100);   
		}
	}
	else
	{
		quad1 = 1;
		for(i=0;i< offsetx;i++)
		{
			Drive(0,300, 50,100);   
		}	
	}
	// checks if starty is bigger than finishy
	if (starty > finishy)
	{
		//if its bigger its going upwards
		goingup = 1;
		
		
	}
	else if (starty < finishy)
	{
		// if its smaller its going down
		goingdown = 1;
	}
	// determines which way the robot should move to navigate towards the finish
	if(quad1 == 1 && goingdown == 1)
	{
		turn90Left();
		
	}
	else if(quad1 == 1 && goingup == 1)
	{
		turn90Right();
	}
	else if (quad2 == 1 && goingdown == 1)
	{
		turn90Right();
	}
	else if (quad2 == 1 && goingup == 1)
	{
		turn90Left();
	}
	
	for(i=0;i< offsety;i++)
	{
		Drive(0,300, 50,100);   
	}
	
	
	
}


void sec_goal(int sec_startx, int sec_starty,int sec_finishx,int sec_finishy)
{
	int offsetx = sec_finishx - sec_startx;
	int offsety = sec_finishy - sec_starty;
	int quad1;
	int quad2;
	int goingup;
	int goingdown;
	offsetx = abs(offsetx);
	offsety = abs(offsety);
	
	if (sec_startx > sec_finishx)
	{
		quad2 = 1;
		turn90Left();
		turn90Left();
		for(i=0;i< offsetx;i++)
		{
			Drive(0,300, 50,100);   
		}
	}
	else
	{
		quad1 = 1;
		for(i=0;i< offsetx;i++)
		{
			Drive(0,300, 50,100);   
		}	
	}
	// checks if starty is bigger than finishy
	if (sec_starty > sec_finishy)
	{
		//if its bigger its going upwards
		goingup = 1;
		
		
	}
	else if (sec_starty < sec_finishy)
	{
		// if its smaller its going down
		goingdown = 1;
	}
	// determines which way the robot should move to navigate towards the finish
	if(quad1 == 1 && goingdown == 1)
	{
		turn90Right();
		
	}
	else if(quad1 == 1 && goingup == 1)
	{
		turn90Left();
	}
	else if (quad2 == 1 && goingdown == 1)
	{
		turn90Left();
	}
	else if (quad2 == 1 && goingup == 1)
	{
		turn90Right();
	}
	
	for(i=0;i< offsety;i++)
	{
		Drive(0,300, 50,100);   
	}
	
	
	
}