int leftMotor = 1;
int rightMotor = 2;

void SetMeasuredDrive(int speed, int target)
{
	//NEED RESETS SINCE setMotorTarget() is to ABSOLUTE TARGET
	resetMotorEncoder(leftMotor);
	resetMotorEncoder(rightMotor);
	setMotorTarget(leftMotor,target, speed);
	setMotorTarget(rightMotor,target, speed);
	
	
	while(getMotorRunning(leftMotor) || getMotorRunning(rightMotor))
		wait1Msec(50);
	return;
}
task main()
{
	
	int input;
	displayCenteredTextLine(1, "please press a button:");
	// Possible values for getButtonPress() are:
	// buttonNone 	= 0,
	// buttonUp = 1,
	// buttonEnter = 2,
	// buttonDown 	= 3,
	// buttonRight = 4,
	
	if (getButtonPress(buttonUp))
		displayCenteredBigTextLine(4, "Up");
	input = 1;
	sleep(200);
	if (getButtonPress(buttonEnter))
		displayCenteredBigTextLine(4, "Enter");
	input = 2;
	sleep(200);
	if (getButtonPress(buttonDown))
		displayCenteredBigTextLine(4, "Down");
	input = 3;
	sleep(200);
	if (getButtonPress(buttonRight))
		displayCenteredBigTextLine(4, "Right");
	input = 4;
	sleep(200);
	
	if (input == 1)
		SetMeasuredDrive(50, 200);
	else if (input == 2)
		SetMeasuredDrive(50, 800);
	else if (input == 3)
		SetMeasuredDrive(50, 1200);
	else if (input == 4)
		SetMeasuredDrive(50, 1600);
}
