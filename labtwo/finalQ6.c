// We have to declare the motor[x] index we will assign to the left and right motors. 
//They are global variables as we are using them in functions outside of main() and will not be changed
int leftMotor = 1;
int rightMotor = 2;


void moveRobot(long nMotorRatio, long time, long power)
{
	// Synchronizes two motors for a set amount of time
	setMotorSyncTime( leftMotor, rightMotor, nMotorRatio, time, power);
	wait1Msec(time);
}


task main()

{
	// a. Go in a square and return to original postion
	moveRobot(0, 2000, 100); 
	sleep(1000); 
	
	moveRobot(100, 412, 50);
	sleep(1000);
	
	moveRobot(0, 2000, 100);
	sleep(1000);
	
	moveRobot(100, 412, 50);
	sleep(1000);
	
	moveRobot(0, 2000, 100);
	sleep(1000);
	
	moveRobot(100, 412, 50);
	sleep(1000);
	
	moveRobot(0, 2000, 100);
	sleep(1000);
	
	moveRobot(100, 412, 50);
	sleep(1000);
	
	// c. 
	moveRobot(0, 2000, 100);
	sleep(1000);
	
	moveRobot(100, 814, 50);
	sleep(1000);
	
	moveRobot(0, 4000, 50);
	
}