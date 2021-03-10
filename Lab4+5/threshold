/*
 authour Emma Jane Power
 threshold
*/

task main()
{
	int light;
	int dark;
	int sum;
	int threshold;
	SensorType[S1] = sensorEV3_Touch;
	SensorType[S3] = sensorEV3_Color;
	
	while(SensorValue[0] == 0)
	{
		displayBigTextLine(2, "Read light");
		displayBigTextLine(4, "value = %d", SensorValue[2]);
		wait1Msec(1000);
	}
	
	light = SensorValue[2];
	wait1Msec(1000);
	
	while(SensorValue[0] == 0)
	{
		displayBigTextLine(2, "Read dark");
		displayBigTextLine(4, " value = %d", SensorValue[3]);
		wait1Msec(1000);
	}
	
	dark = SensorValue[2];
	
	sum = light + dark;
	threshold  = sum/2;
	displayBigTextLine(2, "light = %d", light);
	displayBigTextLine(4, "dark = %d", dark);
	displayBigTextLine(6, "threshold = %d", threshold);
	
	sleep(3000);
	
}