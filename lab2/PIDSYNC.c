/*	
	SetMotorSyncTime command
*/

void moveRobot(long nMotorRatio, long time, long power)
{
	int LeftMotor = 1;
	int RightMotor = 2;
	
	setMotorSyncTime(LeftMotor, RightMotor, 0, 1000, 50 );
	sleep(1500);
	
}


task main()
{
	
	moveRobot(0, 1000, 50);
}

