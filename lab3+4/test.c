//Name of Motors used throughout the Program.
int leftMotor = 1;
int rightMotor = 2;


//This function is responsible for making the motor go forward and backwards.
void drive(long nMotorRatio, long dist, long power)
{
	int encoderRatio = 0;
	encoderRatio = (360/(2*3.14* 2.75)) * dist ; // EncoderRatio = 360/Circumference * distance
	setMotorSyncEncoder(leftMotor, rightMotor,nMotorRatio, encoderRatio, power);
	sleep((500*dist/25) * (100/power)); //An issue with sleep meant that when changing power the robot would not go the full distance specified, this was fixed by adding distance and power into the function.
	//500*60/25 * 100 will go foward exactly 60cm and if you change power to half speed itll double the time delay to account for the decreased speed.
	
	//Resets Motor Speed as a precaution.
	setMotorSpeed(leftMotor, 0);
	setMotorSpeed(rightMotor, 0);
	
	
}



//This function extends drive and is used to turn left at a given power.
void turn90left(long Power)
{
	drive(100,10.25,Power);
	delay(500); //Delay to distinguish multiple turns.
	
}


//This function extends drive and is used to turn right at a given power
void turn90right(long Power)
{
	drive(-100,10.25,Power);
	delay(500); //Delay to distinguish multiple turns.
	
}
task main()
{
	//Variables used throughout.
	int darkval = 0;
	int lightval = 0;
	int threshold;
	int movement;
	int lines =0;
	
	//Sensors used throughout:
	SensorType[S2] = sensorEV3_Ultrasonic;
	SensorType[S1] = sensorEV3_Color;
	
	//Text Display
	displayTextLine(1, "Press left for light");
	displayTextLine(3, "Press right for dark.");
	displayTextLine(5, "Press up for reccomended threshold");
	displayTextLine(3, "Press down to continue.");
	
	//While program is running
	while(getButtonPress(buttonDown)!= 1)
	{
		if(getButtonPress(buttonRight))
		{
			darkval = getColorReflected(S1);
			displayTextLine(3, "DarkValue inputted.");
			
			
		}//end if
		if(getButtonPress(buttonLeft))
		{
			
			lightval = getColorReflected(S1);
			displayTextLine(1, "LightValue inputted.");
			
		}//end if
		if(getButtonPress(buttonUp))
		{
			threshold = (lightval + darkval) / 2;
			displayTextLine(5, "Reccomended Value: %d", threshold);
			movement = 1;
			
		}//end if
		
		//========================MOVEMENT===========================
		//Only starts program when threshold is calculated.
		while(movement==1)
		{
			//If there is a line drive forward
			if(getColorReflected(S1) < threshold)
			{
				
				drive(0,5,100);				
				delay(100);			
				
			}
			else
			{
				//Exits the while loop
				movement = 2;
				
			}
			
			
			
		}
		//Has the robot perform a turning motion to get around the obstacle.
		if(SensorValue[S2] <10)
		{
			turn90left(95);
			drive(0,30,100);
			turn90right(95);
			drive(0,50,100);
			turn90right(95);
			drive(0,30,100);
			turn90left(95);
			movement = 1;
		}
		
		//Robot continues to drive along the line.
		while(movement==1)
		{
			
			if(getColorReflected(S1) < threshold)
			{
				
				drive(0,5,100);				
				delay(100);			
				
			}
			
			
			
		}
		
		
		
		
		
		
		
	}
	
	
	
}