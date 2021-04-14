int leftMotor = 1; // right and motor assignment
int rightMotor = 2;

void turn90()
{
	SensorType[S3] = sensorEV3_Gyro;
	
	sleep(2000);
	
	// while the gyro is less than or eqal to 90 turn left
	while (getGyroDegrees(S3) < 85)
	{
		setMotorSpeed(rightMotor, -50);
		setMotorSpeed(leftMotor, 50);
	}
	
	// resetting motor speed
	setMotorSpeed(rightMotor, 0);
	setMotorSpeed(leftMotor, 0);
}

task main()
{
	int Onoff = 0;
	int currentDistance = 0;
	int count=0;
	
	SensorType[S1] = sensorEV3_Touch; //assigning the variables to sensors
	SensorType[S2] = sensorEV3_Ultrasonic;
	
	currentDistance = SensorValue[S2];
	Onoff = SensorValue[S1];
	
	while(count<200) //this while loop gets the current distance from the nearest obstacle
	{
		count = count + 1; 
		wait1Msec(2);
		getUSDistance(S2);
		getTouchValue(S1);
	}
	
	
	while(SensorValue[S2] > 25) //go forward while you are 25cm or more away from wall
	{
		setMotorSpeed(leftMotor, 100);
		setMotorSpeed(rightMotor, 100);
	}
	
	
	setMotorSpeed(leftMotor, 0); 
	setMotorSpeed(rightMotor, 0);
	sleep(1000);	
	
	turn90();
	
	while(SensorValue[S1] == 0) //go forward until bump sensor is activated
	{
		setMotorSpeed(leftMotor, 100);
		setMotorSpeed(rightMotor, 100);
	}
	
	setMotorSpeed(leftMotor, 0);
	setMotorSpeed(rightMotor, 0);
	sleep(1000);
	
	
	turn90();
	
	while (SensorValue[S1] == 0 && SensorValue[S2] > 25) //go forward until bump sensor is activated or ultrasonic sensor is below 25
	{
		setMotorSpeed(leftMotor, 100);
		setMotorSpeed(rightMotor, 100);
	}
	
	setMotorSpeed(leftMotor, 0);
	setMotorSpeed(rightMotor, 0);
	sleep(1000);
	
	turn90();
	
	//Move Forward
	setMotorSpeed(leftMotor, 50); //Set motorspeed to half power forward
	setMotorSpeed(rightMotor, 50);
	sleep(1500); //Wait for 1.5 seconds
	
	
	//Stop sync
	setMotorSpeed(leftMotor, 0);	//Set the leftMotor (motor1) to stop(0)
	setMotorSpeed(rightMotor , 0);	//Set the rightMotor (motor2) to stop (0)
}

