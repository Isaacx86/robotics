/*
 authour Emma Jane Power
 moving until line
*/

void forward(long nMotorRatio, long time, long power)// moving forward
{
	int LeftMotor = 1;
	int RightMotor = 2;
	
	setMotorSyncTime(LeftMotor, RightMotor, 0, 1000, 50 );
	sleep(1500);
	
}
int ReadLightValue() // function for reading light value
{
	int light;
	SensorType[S1] = sensorEV3_Touch; //touch sensor
	SensorType[S3] = sensorEV3_Color;// light sensor
	
	while(SensorValue[0] == 0) // sensor needs to be touched manually to read the value
	{
		displayBigTextLine(2, "Read light");
		displayBigTextLine(4, "value = %d", SensorValue[2]); // displayimg value of light
		wait1Msec(500);
	}
	eraseDisplay();
	
	light = SensorValue[2];
	wait1Msec(1000);
	
	return light; // returning lihght to function GetThreshold
	
}

int ReadDarkValue() //function for reading dark value
{
	int dark;
	SensorType[S3] = sensorEV3_Color;
	SensorType[S1] = sensorEV3_Touch;
	
	while(SensorValue[0] == 0)
	{
		displayBigTextLine(2, "Press button, read dark");
		displayBigTextLine(4, " value = %d", SensorValue[3]);
		wait1Msec(500);
	}
	eraseDisplay();
	
	
	dark = SensorValue[2];
	
	return dark; //returning value of dark to GetThreshold
	
}


int Threshold(int lightValue, int darkValue) // function to get the threshold of light and dark 
{
	int threshold;
	
	threshold  = (lightValue + darkValue)/2; // adding light and dark and dividing by 2
	
	sleep(3000);
	
	return threshold; //returning value to GetThreshold
	
}

int GetThreshold() // function to return the threshold to countLines
{
	int lightValue;
	int darkValue;
	int threshold;
	
	lightValue = ReadLightValue(); // function to read value of light
	darkValue = ReadDarkValue(); // function to read value of dark 
	threshold = Threshold(lightValue, darkValue);// function to find the threshold by passing two values - light and dark
	
	return threshold; //returning the value of threshold to countLines function
}


void countLines() //this function senses when passing a line pauses and counts it 
{
	
	int loop = 0;
	int lastSeen;
	int count = 0;
	int threshold = GetThreshold();// calling the get threshold function 
	
	do
	{
		forward(0 ,1000, 50);// caling the function forward to move the robot
		
		lastSeen = SensorValue[2]; 
		
		if (SensorValue[2] < threshold)
		{
			if ( lastSeen == 75)
			{
				count++;
			}
			
			wait1Msec(500);
		}	
		while(SensorValue[2] < threshold)
		{
			forward(0, 1000,50);
			
		}
		
		wait1Msec(500);
		
		displayBigTextLine(4, "line count = %d", count);
		
	}
	while(loop == 0);
	
}

task main()
{
	countLines();
	
}

