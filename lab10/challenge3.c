// Program Author- Isaac Barry
// question 6 of lab 10-12

int leftMotor = 1;
int rightMotor = 2;
int i = 0;
void Drive(long,long,long,long);
void turn90Left();
void turn90Right();
void goal(int,int,int,int);

task main()
{
	int x_cord = 0;
	int y_cord = 0;
	int finishing_point_x = 0;
	int finishing_point_y = 0;
	int looping_element = 0;
	
	SensorType[S1] = sensorEV3_Touch; //Setting up touch sensor to hit and touch the wall
	SensorType[S2]= sensorEV3_Gyro; //Port to Sensor
	
	while (looping_element != 2)
	{
		sleep(200);

		// The way the button press works is as follows, 
		//You will run the program, it will then execute and you will click the up arrow to indicate the x and then click the right arrow too indicate the Y,
		// once satisfied with the first variation, click the main enter button and repeat the co-ordinates there it will drive too the final place.
		if (looping_element == 0)
		{
			if (getButtonPress(buttonUp)) //when button up is pressed
			{			
				x_cord = x_cord + 1;
				displayCenteredBigTextLine(4, "X is %d Y is %d", x_cord,y_cord);	
				
			}
			else if (getButtonPress(buttonRight)) // when right button is pressed
			{
				y_cord = y_cord + 1;	
				displayCenteredBigTextLine(4, "X is %d Y is %d", x_cord,y_cord);	
			}	
			else if (getButtonPress(buttonDown)) //when down button is pressed
			{
				
				x_cord = x_cord - 1;
				displayCenteredBigTextLine(4, "X is %d Y is %d", x_cord,y_cord);		
			}
			else if (getButtonPress(buttonLeft))//when left button is pressed
			{
				y_cord = y_cord - 1;	
				displayCenteredBigTextLine(4, "X is %d Y is %d", x_cord,y_cord);	
			}
			else if (getButtonPress(buttonEnter))//when left button is pressed
			{
				looping_element = 1;
				sleep(200);
				displayCenteredBigTextLine(4, "X is %d Y is %d", finishing_point_x,finishing_point_y);		
			}
		}
		if(looping_element == 1)
		{
			
			
			if (getButtonPress(buttonUp)) //when button up is pressed
			{			
				finishing_point_x = finishing_point_x + 1;
				displayCenteredBigTextLine(4, "X is %d Y is %d", finishing_point_x,finishing_point_y);	
				
			}
			else if (getButtonPress(buttonRight)) // when right button is pressed
			{
				finishing_point_y = finishing_point_y + 1;	
				displayCenteredBigTextLine(4, "X is %d Y is %d", finishing_point_x,finishing_point_y);	
			}	
			else if (getButtonPress(buttonDown)) //when down button is pressed
			{
				
				finishing_point_x = finishing_point_x - 1;
				displayCenteredBigTextLine(4, "X is %d Y is %d", finishing_point_x,finishing_point_y);		
			}
			else if (getButtonPress(buttonLeft))//when left button is pressed
			{
				finishing_point_y = finishing_point_y - 1;	
				displayCenteredBigTextLine(4, "X is %d Y is %d", finishing_point_x,finishing_point_y);	
			}
			else if (getButtonPress(buttonEnter))//when left button is pressed
			{
				looping_element = 2;
				break;
			}
		}
	}
	if (x_cord >= 1 && y_cord >= 1 && finishing_point_x >= 1 && finishing_point_y >= 1 )
	{
		displayCenteredBigTextLine(6, "succesful");
		goal(x_cord,y_cord,finishing_point_x,finishing_point_y);
	}
	else
	{
		displayCenteredBigTextLine(6, "cant be negative");
		sleep(2000);
	}
	
}

//turn 90 with gyro function, it will turn on the square so it is more acurate
void Drive(long nmotorratio, long encoderRatio, long power,long dist)
{
	//500 for encoderratio is equal to just around 30 cm
	setMotorSyncEncoder(leftMotor,rightMotor,nmotorratio,encoderRatio,power);
	sleep(500*dist/25);
	setMotorSpeed(leftMotor,0);
	setMotorSpeed(rightMotor,0);	
	resetMotorEncoder(leftMotor);
	resetMotorEncoder(rightMotor);
}

//turn 90 with gyro function, it will turn on the square so it is more acurate
void turn90Left(){
	
	wait1Msec(100);
	
	resetGyro(S2);
	
	wait1Msec(100);
	
	while(abs(getGyroDegrees(S2))<90)
	{
		setMotorSpeed(leftMotor, -10);
		setMotorSpeed(rightMotor, 10);
	}
	
	setMotorSpeed(leftMotor, 0);
	setMotorSpeed(rightMotor, 0);
	wait1Msec(1000);
}

void turn90Right(){
	
	wait1Msec(100);
	
	resetGyro(S2);
	
	wait1Msec(100);
	
	while(abs(getGyroDegrees(S2))<90)
	{
		setMotorSpeed(leftMotor, 10);
		setMotorSpeed(rightMotor, -10);
	}
	
	setMotorSpeed(leftMotor, 0);
	setMotorSpeed(rightMotor, 0);
	wait1Msec(1000);
}


void goal(int x_cord, int y_cord,int finishing_point_x,int finishing_point_y)
{
	int offsetx = finishing_point_x - x_cord;
	int offsety = finishing_point_y - y_cord;
	int point_one;
	int point_two;
	int point_up;
	int point_down;
	int remaining_value = 0;
	int flag = 0;
	offsetx = abs(offsetx);
	offsety = abs(offsety);
	
	if(finishing_point_x == 7 && finishing_point_y == 1)
	{
		offsety = offsety-2;
		offsetx = offsetx;
	}
	
	if (finishing_point_x == 1 && finishing_point_y == 1)
	{
		offsety = offsety-1;
	}
	
	
	if (x_cord > finishing_point_x)
	{
		point_two = 1;
		turn90Left();
		turn90Left();
		for(i=0;i< offsetx;i++)
		{
			if(SensorValue[S1] == 1)
			{
				if (y_cord >= finishing_point_y)
				{
					Drive(50, 100, 50, 100); 
					i = i-1;
					remaining_value = offsetx - i;
					flag = 1;
					break;
					
					
				}
				else if (y_cord < finishing_point_y)
				{
					Drive(-50, 100, 50, 100); 
					i = i-1;
					remaining_value = offsetx - i;
					flag = 1;
					break;
				}
				
			}
			else
			{
				Drive(0,300, 50,100); 
			}
			
		}
		
	}
	else
	{
		point_one = 1;
		for(i=0;i< offsetx;i++)
		{
			if(SensorValue[S1] == 1)
			{
				if (y_cord > finishing_point_y)
				{
					Drive(-50, 100, 50, 100); 
					i = i-1;
					remaining_value = offsetx - i;
					flag = 1;
					break;
					
					
				}
				else if (y_cord < finishing_point_y)
				{
					Drive(50, 100, 50, 100); 
					i = i-1;
					remaining_value = offsetx - i;
					flag = 1;
					break;
				}
				
			}
			else
			{
				Drive(0,300, 50,100);  
			} 
		}
		
	}
	// checks if y_cord is bigger than finishing_point_y
	if (y_cord >= finishing_point_y)
	{
		//if its bigger its going upwards
		point_up = 1;
		
		
	}
	else if (y_cord < finishing_point_y)
	{
		// if its smaller its going down
		point_down = 1;
	}
	// determines which way the robot should move to navigate on y axis
	if(point_one == 1 && point_down == 1)
	{
		turn90Left();
		Drive(0,150, 50,50); 
		
	}
	else if(point_one == 1 && point_up == 1)
	{
		turn90Right();
		
		
	}
	else if (point_two == 1 && point_down == 1)
	{
		turn90Right();
		Drive(0,150, 50,50); 
	}
	else if (point_two == 1 && point_up == 1)
	{
		turn90Left();
		if (finishing_point_x == 1 && finishing_point_y == 6)
		{
			
		}
		else{
			Drive(0,300, 50,100); 
			Drive(0,150, 50,50); 
		}
	}
	
	
	
	for(i=0;i< offsety;i++)
	{
		Drive(0,300, 50,100);   
	}
	
	// This flag system is for determining the main way of traveling on the X axis
	if (flag == 1)
	{
		if (point_one == 1 && point_down == 1)
		{
			turn90Right();
		}
		else if (point_one == 1 && point_up == 1)
		{
			turn90Left();
		}
		else if (point_two == 1 && point_down == 1)
		{
			turn90Left();
		}
		else if (point_two == 1 && point_up == 1)
		{
			turn90Right();
		}
		
		
		for (i = 0; i < remaining_value; i++)
		{
			Drive(0, 300, 50, 100);
		}
		
		
		if(finishing_point_x == 7 && finishing_point_y == 1)
		{
			turn90Right();
			Drive(0, 300, 50, 100);
			Drive(0, 300, 50, 100);
			Drive(0,150, 50,50); 
		}
	}
	else
	{
		// do nothing, finishing call of function
	}
}