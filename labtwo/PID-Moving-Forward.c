// We have to declare the motor[x] index we will assign to the left and right motors. 
//They are global variables as we are using them in functions outside of main() and will not be changed
int leftMotor = 1;
int rightMotor = 2;


void turnLeft(long time, long motorpower)
{
	
	setMotorSpeed(leftMotor, -motorpower);		//Set the leftMotor (motor1) to half power (50)
	setMotorSpeed(rightMotor, motorpower);  //Set the rightMotor (motor6) to half power (50)
	sleep(time);										//Wait for 2 seconds before continuing on in the program.
}
task main()
{
	turnLeft(1000,50);
	
}
