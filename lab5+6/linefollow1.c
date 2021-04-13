//Programm created by Isaac Barry 3/10/21
// This is question 4 and 5 in one file

//Name of Motors used throughout the Program.
int leftMotor = 1; // left motor
int rightMotor = 2; // right motor

task main()
{
	int darkval =25; //The following is the light values for the dark black line, IT will be sent too the debug stream to write the output of the sensor
	int lightval=75;
	int threshold=0;
	threshold=(darkval + lightval)/2;

	displayTextLine(4,"Light = %d",lightval);
	displayTextLine(6,"Dark = %d",darkval);
	displayTextLine(8,"Threshold = %d",threshold);

	SensorType[S1] = sensorEV3_Color; // This is the color sensor 

	while(true)
	{
		if(SensorValue[S1] < threshold) // if the value of the sensor is greater than the threshold which is the dark val + the light val divided by 2, execute the following
		{
			setMotorSpeed(leftMotor,50); // threshold set to 50 for motor because it will go of the rail.
			setMotorSpeed(rightMotor,0);
		}
		else // Else it will go too the right instead of the left
		{
			setMotorSpeed(leftMotor,0);
			setMotorSpeed(rightMotor,50);
		}
	}
}
