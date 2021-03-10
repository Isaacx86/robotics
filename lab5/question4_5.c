//Programm created by Isaac Barry 3/10/21

//Name of Motors used throughout the Program.
int leftMotor = 1;
int rightMotor = 2;

task main()
{
	int darkval =25;
	int lightval=75;
	int threshold=0;
	threshold=(darkval + lightval)/2;

	displayTextLine(4,"Light = %d",lightval);
	displayTextLine(6,"Dark = %d",darkval);
	displayTextLine(8,"Threshold = %d",threshold);

	SensorType[S1] = sensorEV3_Color;

	while(true)
	{
		if(SensorValue[S1] < threshold)
		{
			setMotorSpeed(leftMotor,50); // threshold set to 50 for motor because it will go of the rail.
			setMotorSpeed(rightMotor,0);
		}
		else
		{
			setMotorSpeed(leftMotor,0);
			setMotorSpeed(rightMotor,50);
		}
	}
}
