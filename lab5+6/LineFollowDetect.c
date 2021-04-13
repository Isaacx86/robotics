//Program created by Isaac Barry /3/10/21
// Question 6 

// global variables created
int leftMotor = 1;
int rightMotor = 2;
int threshold = 50;
int point; // This will be the color value 
int ranging; // Range will be USD distance

task main()
{
	SensorType[S2] = sensorEV3_Ultrasonic;
	SensorType[S1] = sensorEV3_Color;
	
	while (true)
	{
		point = getColorReflected(S1);
		ranging = getUSDistance(S2);
		
		if (point == 25) // If the color reflected is dark, do the following 
		{
			setMotorSpeed(leftMotor, 50);
			setMotorSpeed(rightMotor, 0);
			
			wait1Msec(1);
			
		}// End if
		
		else // Else if its not do this
		{
			setMotorSpeed(leftMotor, 0);
			setMotorSpeed(rightMotor, 50);
			
			wait1Msec(1);
			
		}// End else
		
		if (ranging < 5) // if the range can see an object less than five to the following
		{
			setMotorSpeed(leftMotor, 50);
			setMotorSpeed(rightMotor, -50);
			sleep(350);
			
			setMotorSpeed(leftMotor, 50);
			setMotorSpeed(rightMotor, 50);
			sleep(1000);
			
			setMotorSpeed(leftMotor, -50);
			setMotorSpeed(rightMotor, 50);
			sleep(350);
			
			setMotorSpeed(leftMotor, 50);
			setMotorSpeed(rightMotor, 50);
			sleep(1000);
			
			setMotorSpeed(leftMotor, -50);
			setMotorSpeed(rightMotor, 50);
			sleep(350);
			
			setMotorSpeed(leftMotor, 50);
			setMotorSpeed(rightMotor, 50);
			sleep(1000);
			
			setMotorSpeed(leftMotor, 50);
			setMotorSpeed(rightMotor, -50);
			sleep(350);
			
		}// End if
		
	}// End while
	
}// End main