/*
 authour Emma Jane Power
 moving until line
*/
void move(long nMotorRatio, long time, long power)
{
	int LeftMotor = 1;
	int RightMotor = 2;
	
	setMotorSyncTime(LeftMotor, RightMotor, 0, 1000, 25 );
	sleep(1000);
	
}

task main()
{
	int LeftMotor = 1;
	int RightMotor = 2;
	int light;
	int dark;
	int sum;
	int threshold;
	//int loop = 0;
	int move;
	SensorType[S1] = sensorEV3_Touch;
	SensorType[S3] = sensorEV3_Color;
	
	
	while(SensorValue[0] == 0)
	{
		displayBigTextLine(2, "Read light");
		displayBigTextLine(4, "value = %d", SensorValue[2]);
		wait1Msec(500);
	}
	
	light = SensorValue[2];
	wait1Msec(1000);
	
	while(SensorValue[0] == 0)
	{
		displayBigTextLine(2, "Read dark");
		displayBigTextLine(4, " value = %d", SensorValue[2]);
		wait1Msec(500);
	}
	
	dark = SensorValue[2];
	
	sum = light + dark;
	threshold  = sum/2;
	displayBigTextLine(2, "light = %d", light);
	displayBigTextLine(4, "dark = %d", dark);
	displayBigTextLine(6, "threshold = %d", threshold);
	
	sleep(3000);
	
	
	eraseDisplay();
	writeDebugStream("Threshold:Value %d \n", threshold);
	wait1Msec(1000);
	displayCenteredTextLine(4, "Theshold : Value %d", threshold);
	
	
	while (SensorValue[2] > threshold)
	{
		wait1Msec(100);
		displayCenteredTextLine(4, "threshold: Value %d", threshold);
		move(0, 1000, 25 );
	}
	
	setMotorSpeed(LeftMotor, 100);
	setMotorSpeed(RightMotor, 100);
	
	
	
}