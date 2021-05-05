int rightMotor = 1;
int leftMotor = 2;

// drive function putting cm into degrees of rotation
void drive(long nMotorRatio, long dist, long power)
{
	int degreeToCm = (360/17.27875959)*dist;
	
	setMotorSyncEncoder(leftMotor, rightMotor, nMotorRatio, degreeToCm, power);
	wait1Msec(100);
	
} // end drive

// turning right function
void turnRight(long nMotorRatio, long power)
{
	setMotorSpeed(leftMotor, power);
	setMotorSpeed(rightMotor, -power);
	sleep(410);
	
}// end right turn 

// turning left function
void turnLeft(long nMotorRatio, long power)
{
	setMotorSpeed(leftMotor, -power);
	setMotorSpeed(rightMotor, power);
	sleep(410);
	
}// end left turn

// when the x starting position is less than the x destination
void xLess(int xStart,int xEnd)
{
	
	// while current x position is less than destination x 
	while (xStart < xEnd)
	{
		wait1Msec(1000);
		drive(0, 15, 50);// moving forward
		wait1Msec(1000);
		xStart = xStart + 1;// increasing x value to new current position 
		wait1Msec(1000);
		
	}// end while
	
}// end xLess

// when the x starting position is greater than the x destination
void xGreater(int xStart,int xEnd)
{
	
	// while the current x value is greater then destination x
	while( xStart > xEnd)
	{
		wait1Msec(1000);
		drive(0, 15, 50);// move
		wait1Msec(1000);
		xStart = xStart - 1;// updating current position
		wait1Msec(1000);
		
	}// end while
	
}// end xGreater

// when the y starting position is less than the y destination
void yLess(int yStart,int yEnd)
{
	
	// while current y position is less than destination y
	while (yStart < yEnd)
	{
		wait1Msec(1000);
		drive(0, 15, 50);// moving forward 
		wait1Msec(1000);
		yStart = yStart + 1;// increasong y position value  
		wait1Msec(1000);
		
	}// end while
	
}// end yLess

// when the y starting position is greater than the y destination
void yGreater(int yStart,int yEnd)
{
	// while current y position is less than destination y
	while (yStart > yEnd)
	{
		wait1Msec(1000);
		drive(0, 15, 50);// moving forward 
		wait1Msec(1000);
		yStart = yStart - 1;// increasong y position value 
		wait1Msec(1000);
		
	}// end while	
	
	
}// end yGreater

// checks if starting x position is greater to x destination 
void xDirection(int start,int end)
{
	if (start > end)
	{
		
		xGreater(start, end);
	}
	
	else 
	{
		xLess(start, end);
	}
	
}// end xDirection

// checks if starting y position is greater to y destination 
void yDirection(int start,int end)
{
	if (start > end)
	{
		yGreater(start, end);
	}
	
	else 
	{
		yLess(start, end );
	}
	
}// end yDirection


task main()
{
	// declaring variables
	int x1 = 0;
	int y1 = 0;
	int x2 = 0;
	int y2 = 0;
	
	// displaying input options 
	displayTextLine(1,"select staring position");
	displayTextLine(3, "up = start[1,1] end[5,5]");
	displayTextLine(5, "right = start[5,5] end[1,1]");
	displayTextLine(7, "left = start[6,6] end[1,6]");
	displayTextLine(9, "down = start[1,6] end[7,1]");
	
	waitForButtonPress();
	
	eraseDisplay();
	
	// starting point 1,1, end point 5,5
	if (getButtonPress(buttonUp))
	{
		// assigning values
		x1 = 1;
		y1 = 1;
		
		x2 = 5;
		y2 = 5;
		
		// calling functions
		xDirection(x1,x2);
		
		turnRight(0, 17);
		
		yDirection(y1,y2);
		
	}// end if
	
	// starting point 5,5 , end point 1,1
	if (getButtonPress(buttonRight))
	{
		// assigning values
		x1 = 5;
		y1 = 5;
		
		x2 = 1;
		y2 = 1;
		
		// calling functions
		turnLeft(0 ,17);
		
		xDirection(x1,x2);
		
		turnLeft(0, 17);
		
		yDirection(y1,y2);
		
	}// end if
	
	// starting point 6,6 , end point 1,6
	if (getButtonPress(buttonLeft))
	{
		// assigning values
		x1 = 6;
		y1 = 6;
		
		x2 = 1;
		y2 = 6;
		
		//calling functions
		turnLeft(0,17);
		
		xDirection(x1,x2);
		
	}// end if
	
	// starting point 1,6 , end point 7,1
	if(getButtonPress(buttonDown))
	{
		// assinging values
		x1 = 1;
		y1 = 6;
		
		x2 = 7;
		y2 = 1;
		
		// calling functions
		turnRight(0, 17.5);
		
		xDirection(x1, x2);
		
		turnRight(0, 17.5);
		
		yDirection(y1,y2);
		
	}// end if
	
}// end main






