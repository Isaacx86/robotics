

/*	Challenge 1 Lab3 
	Programm author: isaac barry
	2/23/2021
*/



task main()
{
	int Onoff = 0;
	int leftMotor = 1; // right and motor assignment
	int rightMotor = 2; 
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
	
	// Turn left 
	setMotorSpeed(leftMotor, 40);	//Set the leftMotor (motor1) to 40
	setMotorSpeed(rightMotor, -5);//Set the rightMotor (motor2) to -5
	sleep(1000);			//Wait for 1 second before continuing on in the program.
	
	
	while(SensorValue[S1] == 0) //go forward until bump sensor is activated
	{
		setMotorSpeed(leftMotor, 100);
		setMotorSpeed(rightMotor, 100);
	}
	
	setMotorSpeed(leftMotor, 0);
	setMotorSpeed(rightMotor, 0);
	sleep(1000);
	
	// Turn left 
	setMotorSpeed(leftMotor, 30);	//Set the leftMotor (motor1) to 30
	setMotorSpeed(rightMotor, -29);//Set the rightMotor (motor2) to -29
	sleep(1000);			//Wait for 1 second before continuing on in the program.
	
	while (SensorValue[S1] == 0 && SensorValue[S2] > 25) //go forward until bump sensor is activated or ultrasonic sensor is below 25
	{
		setMotorSpeed(leftMotor, 100);
		setMotorSpeed(rightMotor, 100);
	}
	
	setMotorSpeed(leftMotor, 0);
	setMotorSpeed(rightMotor, 0);
	sleep(1000);
	
	// Turn left 
	setMotorSpeed(leftMotor, 40);	//Set the leftMotor (motor1) to 40
	setMotorSpeed(rightMotor, -5);//Set the rightMotor (motor2) to -5
	sleep(1000);			//Wait for 1 second before continuing on in the program.
	
	//Move Forward
	setMotorSpeed(leftMotor, 50); //Set motorspeed to half power forward
	setMotorSpeed(rightMotor, 50);
	sleep(1500); //Wait for 1.5 seconds
	
	//Stop sync
	setMotorSpeed(leftMotor, 0);	//Set the leftMotor (motor1) to stop(0)
	setMotorSpeed(rightMotor , 0);	//Set the rightMotor (motor2) to stop (0)
}
