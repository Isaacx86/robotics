// Task author isaac barry
task main() //comment
{	int count=0;
	float degrees;
	int heading;
	int rate;
	int i =1;

	float firstdist = 0;
	float secdist = 0;
	float distance = 0;
	float temp;
	float final;
	
	// sensor type setup
	SensorType[S1]= sensorEV3_Gyro;
	SensorType[S2] = sensorEV3_Ultrasonic;

	// This is the button press section
	while (i=1)
	{
		
		if (getButtonPress(buttonUp)) //when button up is pressed
		{
			//this will get the first distance
			firstdist = SensorValue[S2];
			displayBigTextLine(5, "First Destination=%f",firstdist);
			
			
		}
		else if (getButtonPress(buttonRight)) // when right button is pressed
		{
			//rotate the robot manually and point
			// at target
			// it will then get degress
			degrees = getGyroDegrees(S1);
			displayBigTextLine(2, "Degrees=%f",degrees);
		}
		
		else if (getButtonPress(buttonDown)) //when down button is pressed
		{
			// when this is pressed it will get the second distance
			secdist = SensorValue[S2];
			displayBigTextLine(5, "Second distance =%f",secdist);
			i=0;
			break;
		}
		sleep(50);
	}
	// we then erease the display
	eraseDisplay();
	// calculation to get area
	
	
	//temp = distance * sinDegrees(degrees);
	//final = .5 * temp;
	final = firstdist / 2 * secdist; // This works better than sindegrees 
	//displays calculation
	displayBigTextLine(5, "area=%f",final);
	sleep(5000);
	//program ends
}