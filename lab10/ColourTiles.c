// Emma Jane Power

int rightMotor = 1;
int leftMotor = 2;

// drive function putting cm into degrees of rotation
void drive(long nMotorRatio,long dist, long power)
{
	int degreeToCm = (360/17.27875959)*dist;
	
	setMotorSyncEncoder(leftMotor, rightMotor, nMotorRatio, degreeToCm , power);
	wait1Msec(1000);
	
} // end drive

// turning right function
void turnRight(long nMotorRatio, long power)
{
	setMotorSpeed(leftMotor, power);
	setMotorSpeed(rightMotor, -power);
	sleep(410);
	
}// end right turn 

// turning left function
void turnLeft(long nMotorRatio, long power)
{
	setMotorSpeed(leftMotor, -power);
	setMotorSpeed(rightMotor, power);
	sleep(410);
	
}// end left turn


// this function reads in a colour and displays it to output and sets LED to matching or corrisponding colour 
void Colour()
{
	// using if statments dependent on colour which display the name of the colour and setting the LED to the colour 
	
	if (getColorName(S3) == colorRed)
	{
		
		displayBigTextLine(3, "RED");
		wait1Msec(1000);
		
		setLEDColor(ledRed);
		sleep(2000);
	}
	
	if (getColorName(S3) == colorBlue)
	{
		
		displayBigTextLine(3, "BLUE");
		wait1Msec(1000);
		
		setLEDColor(ledGreen);
		sleep(2000);
	}
	
	if (getColorName(S3) == colorYellow)
	{
		
		displayBigTextLine(3, "YELLOW");
		wait1Msec(1000);
		
		setLEDColor(ledOrange);
		sleep(2000);
	}
	
	if (getColorName(S3) == colorGreen)
	{
		
		displayBigTextLine(3, "GREEN");
		wait1Msec(1000);
		
		setLEDColor(ledGreen);
		sleep(2000);
	}
	
	eraseDisplay();  //clearing display
	
}// end colour


task main()
{
	//declaring sensors
	SensorType[S3] = sensorEV3_Color;
	SensorMode[S3] = modeEV3Color_Color;
	
	// calling functions 
	drive(0, 98, 50);
	wait1Msec(3000);
	
	Colour();
	
	wait1Msec(1000);
	turnRight(0,50);
	
	drive(0, 90, 50);
	wait1Msec(3000);
	
	Colour();
	
	wait1Msec(1000);
	turnRight(0,50);
	
	sleep(500);
	turnRight(0,50);
	
	drive(0, 30, 50);
	sleep(1000);
	
	
	Colour();
	
}// end main


