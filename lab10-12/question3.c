//reuse.c

// Program author Isaac Barry; 

void dest_one(int x,int y);
void desttwo(int x,int y);

int leftMotor = 1;
int rightMotor = 2;
task main()
{
	
	int x=3;
	int y=1;
	int xx = 3;
	int yy = 7;
	
	SensorType[0] = sensorEV3_Gyro;
	
	dest_one(x,y);
	displayBigTextLine(1, "Driven to position 3,7 now going to 1,1");
	
	desttwo(xx,yy);
	displayBigTextLine(2, "Line finished");
	
}
void drive(long nMotorRatio, long dist, long power) 
{
	
	setMotorSyncEncoder(leftMotor, rightMotor, nMotorRatio, (360/17.27875959)*dist, power);
	wait1Msec(100);
	
}

void turn90left()
{
	int degrees;
	int heading;
	int rate;
	
	SensorType[0] = sensorEV3_Gyro;
	
	
	eraseDisplay();
	resetGyro(S1);
	degrees = getGyroDegrees(S1);
	
	
	while(degrees < 84)
	{
		setMotorSpeed(leftMotor, 40);
		setMotorSpeed(rightMotor, -40);
		degrees = getGyroDegrees(S1);
		heading = getGyroHeading(S1);
		rate = getGyroRate(S1);
		sleep(10);
		
	} // end while
	
	eraseDisplay();
	setMotorSpeed(leftMotor, 0);
	setMotorSpeed(rightMotor, 0);
	
} // end turn90left()

void turn90right()
{
	int degreesToTurn = -74;
	float degreesSoFar = 0;
	int initialTurnReading = SensorValue[0];
	int motorPower;
	int currentGyroReading;
	
	SensorType[0] = sensorEV3_Gyro;
	
	// Start turning
	motorPower = 15*sgn(degreesToTurn);
	setMotorSync(leftMotor, rightMotor, 100, motorPower);
	
	while(abs(degreesSoFar) < abs(degreesToTurn))
	{
		wait1Msec(10); // wait 10ms, or 0.01s
		currentGyroReading = SensorValue[0] - initialTurnReading;
		degreesSoFar = degreesSoFar + currentGyroReading*0.01;
	} // end while
	
	motor[leftMotor] = 0;
	
	
} // end Turn 90 right()

void dest_one(int x, int y)
{
	int xDest = 3;
	int yDest = 7;
	int i;
	
	turn90right(); 
	
	while(x<xDest)
	{
		drive(0,15,50);
		wait1Msec(1000);
		x=x+1;
		wait1Msec(1000);
	}
	
	while(y<yDest)
	{
		drive(0,15,50);
		wait1Msec(1000);
		y=y+1;
	}
	for(i=0;i<5;i++)
	{
		sleep(1000);
		playSound(soundBeepBeep);
		
	}
}

void desttwo(int x, int y)
{
	int xDest = 1;
	int yDest = 1;
	int i;
	//turn90right();
	turn90right();  
	
	while(x<xDest)
	{
		drive(0,15,50);
		wait1Msec(1000);
		x=x+1;
		wait1Msec(1000);
	}
	
	while(y<yDest)
	{
		drive(0,15,50);
		wait1Msec(1000);
		y=y+1;
	}
	turn90left;
}
