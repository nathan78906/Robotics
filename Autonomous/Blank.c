#pragma config(Sensor, in1,    leftArmPotent,  sensorPotentiometer)
#pragma config(Sensor, in2,    rightArmPotent, sensorPotentiometer)
#pragma config(Sensor, dgtl1,  limitswitchlift, sensorTouch)
#pragma config(Motor,  port2,           frontRight,    tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor,  port3,           backRight,     tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor,  port4,           frontLeft,     tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port5,           backLeft,      tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port6,           intake1,       tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port7,           claw,          tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port8,           lift1,         tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor,  port9,           lift2,         tmotorServoContinuousRotation, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

//open claw 5 5/8th
#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(15)
#pragma userControlDuration(105)

#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!

const int FORWARD = 1;
 const int BACKWARD = 2;
 const int LEFT = 3;
 const int RIGHT = 4;
 const int SPINR = 5;
 const int SPINL = 6;
 const int STOP = 7;

 void driveMove( int direction ) {
	switch( direction ) {

case FORWARD: 				 //Void statement for moving forward. (sets command in brackets to call it by name later)
  motor [frontRight] = 64;  //Sets all motors to go at 127 forward (allows robot to move forward)
  motor [frontLeft]  = 64;
  motor [backRight]  = 64;
  motor [backLeft]   = 64;
  break;
case BACKWARD :				  //Void statement for moving backwards. (sets command in brackets to call it by name later)
  motor [frontRight] = -64;  // sets all motors to go at 127 backwards (allows robots to move backwards)
  motor [frontLeft]  = -64;
  motor [backRight]  = -64;
  motor [backLeft]   = -64;
  break;
case LEFT:               //Void statement for moving left. (sets command in brackets to call it by name later)
  motor [frontRight] =  64;   // Sets front motors and back motors to go in opposite directions to move left
  motor [frontLeft]  = -64;
  motor [backRight]  = -64;
  motor [backLeft]   =  64;

  break;
case RIGHT:             //Void statement for moving right. (sets command in brackets to call it by name later)
  motor [frontRight] = -64;  //Sets front motors and back motors to go in opposite directions to move right
  motor [frontLeft]  =  64;
  motor [backRight]  =  64;
  motor [backLeft]   = -64;
  break;
case SPINR:             //Void statement for rotating right. (sets command in brackets to call it by name later)
  motor [frontRight] = -64;  //Sets left motors and right motors to go in opposite directions to move right
  motor [frontLeft]  =  64;
  motor [backRight]  = -64;
  motor [backLeft]   =  64;
  break;
case SPINL:  //Void statement for rotating left. (sets command in brackets to call it by name later)
  motor [frontRight] =  64;  //Sets left motors and right motors to go in opposite directions to move right
  motor [frontLeft]  = -64;
  motor [backRight]  =  64;
  motor [backLeft]   = -64;
  break;
case STOP:
	motor[frontRight]  = 0;
	motor[frontLeft]   = 0;
	motor[backRight]   = 0;
	motor[backLeft]    = 0;
 break;
}
}

void liftup1 ()  //Void statement for bringing the lift up
 {
   motor [lift1] = 127;  //sets the lift motors at a power of 127 forward (moves them up)
   motor [lift2] = 127;
}

void liftdown1 () //Void statement for bringing the lift down
 {
   motor [lift1] = -90; //sets the lift motors at a power of 90 backwards (moves them down)
   motor [lift2] = -90;
}
void inup1 ()       //Void statements for bringing the intake up
 {
   motor [intake1] = 127; //sets the intake motors at a power of 127 forward (to take in cubes)
}
void indown1 () //Void statement for bringing the intake down
 {
   motor [intake1] = -127; //sets the intake motors to power of 127 backwards (to put down cubes)
}

void liftup2 () //Void statement for bringing the lift up
 {
   motor [lift1] = 60; //sets the lift motors at a power of 30 forward (moves them up)
   motor [lift2] = 60;
}
void liftdown2 () //Void statement for bringing the lift down
 {
   motor [lift1] = -60; //sets the lift motors at a power of 30 backwards (moves them down)
   motor [lift2] = -60;
}

void inup2 ()       //Void statements for bringing the intake up
 {
   motor [intake1] = 30; //sets the intake motors at a power of 30 forward (to take in cubes)
}

void indown2 () //Void statement for bringing the intake down
 {
   motor [intake1] = -30; //sets the intake motors to power of 30 backwards (to put down cubes)
}

void liftstop ()
 {
   motor [lift1] = 0;
   motor [lift2] = 0;
 }

void clawopen() //void statement for opening the claw
 {
  motor[claw] = 127;
}

void clawclose() //void statement for closing the claw
  {
  	motor[claw] = -100;
}
void clawstop()
{
	motor[claw] = 0;
}


void armStablize( int leftPotential, int rightPotential ) {
	if( SensorValue(leftArmPotent) + 1 < leftPotential )
  	motor[lift1] = (leftPotential - SensorValue(leftArmPotent));
	else if( SensorValue(leftArmPotent) - 2 > leftPotential )
  	motor[lift1] = 3;
 	else
 		motor[lift1] = 0;

	//int rightPotential = leftPotential - deltaPotential;
	if( SensorValue(rightArmPotent) + 1 < rightPotential )
  	motor[lift2] = (rightPotential - SensorValue(rightArmPotent));
	else if( SensorValue(rightArmPotent) - 2 > rightPotential )
  	motor[lift2] = 3;
 	else
 		motor[lift2] = 0;
}
/////////////////////////////////////////////////////////////////////////////////////////
//
//                          Pre-Autonomous Functions
//
// You may want to perform some actions before the competition starts. Do them in the
// following function.
//
/////////////////////////////////////////////////////////////////////////////////////////

void pre_auton()
{
  // Set bStopTasksBetweenModes to false if you want to keep user created tasks running between
  // Autonomous and Tele-Op modes. You will need to manage all user created tasks if set to false.
  bStopTasksBetweenModes = true;

	// All activities that occur before the competition starrts
	// Example: clearing encoders, setting servo positions, ...
}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 Autonomous Task
//`
// This task is used to control your robot during the autonomous phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////
	bool checkTimeAction( int init, int final, int current ) {
	if ( init <= current && final > current )
		return true;

		return false;
	}

		task autonomous(){
	if (checkTimeAction (0, 15000, time1[T1] ) ) {
		driveMove(STOP);

}
}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 User Control Task
//
// This task is used to control your robot during the user control phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////

task usercontrol()
{
//Create "deadzone" variables. Adjust threshold value to increase/decrease deadzone. Also adds variables for lift and intake.
	int X2 = 0, Y1 = 0, X1 = 0, threshold = 15, speedtake = 1, speedlift = 1;
	int leftPotential = SensorValue(leftArmPotent);
	int rightPotential = SensorValue(rightArmPotent);

//Infinite loop for driver control
while(1 == 1)
{
//Create "deadzone" for Y1/Ch3
	if(abs(vexRT[Ch3]) > threshold)
		Y1 = vexRT[Ch3];
	else
		Y1 = 0;
	//Create "deadzone" for X1/Ch4
	if(abs(vexRT[Ch4]) > threshold)
		X1 = vexRT[Ch4];
	else
		X1 = 0;
	//Create "deadzone" for X2/Ch1
	if(abs(vexRT[Ch1]) > threshold)
		X2 = vexRT[Ch1];
	else
		X2 = 0;


	//Remote Control Commands
		motor[frontRight] =  Y1 - X2 - X1;  //Sets movement for frontright motor
		motor[backRight]  =  Y1 - X2 + X1;  //Sets movement for backright motor
		motor[frontLeft]  =  Y1 + X2 + X1;  //Sets movement for frontleft motor
		motor[backLeft]   =  Y1 + X2 - X1;  //Sets movement for backLeft motor

	//---------------------------------------------------------DO NOT TOUCH ANY CODE ABOVE THIS LINE--------------------------------------------------------------------------------------------


	if (vexRT[Btn7D] == 1 && speedtake == 1) { //Raises the variable for the speed of the intake
			speedtake ++; 											  //when the Button 7U is pressed.
		}
		else if (vexRT[Btn7U] == 1 && speedtake == 2) { //lowers the variable for the speed of the intake
			speedtake --;																	 //when the Button 7D is pressed.
		}
		else {      //Space left blank intentionally.
    }

  if (vexRT[Btn5U] == 1 && speedtake == 1) {   //If the variable for the intake is 1 and button 5U is pressed, intake moves at 127
				inup1();
		}
			else if (vexRT[Btn5U] == 1 && speedtake == 2 )  //If the variable for the intake is 2 moves the motors for the intake at 30 when button 5 is pressed
				{
				inup2();
		}
		else if ( vexRT[Btn5D] == 1 && speedtake == 1) {    //brings the intake down when button 5D is pressed at a level is 127
			indown1();

	  }
		else if ( vexRT [Btn5D] == 1 && speedtake == 2) { //whiile the variable speedtake is 2, motor runs at a power of 30 backwards.
			indown2();
	  }
	else {                      //turns the motors off it nothing else is done.
			motor[intake1] = 0;
		}

	//coding for Lift from line 197 - 232
	if (vexRT[Btn8D] == 1 && speedlift == 1) { //changes the variable for the speed of the lift (increases speed)
		speedlift ++;																								//if Button 8 up is pressed
	  }
	else if (vexRT[Btn8U] == 1 && speedlift == 2 ) { // changes the variable for the speed of the lift (decreases speed)
		speedlift --;																									//if Button 8 down is pressed
	  }
	else {

	}


 if (vexRT[Btn6U] == 1 && speedlift == 1 ) {   //If the variable speedlift is 1, motor runs at a power of 127 forward
			liftup1();
			leftPotential = SensorValue(leftArmPotent);
	    rightPotential = SensorValue(rightArmPotent);

	}
		else if (vexRT[Btn6U] == 1 && speedlift == 2) { //If the variable speedlift is 2, motor runs at a power of 30 forward
			liftup2();
			leftPotential = SensorValue(leftArmPotent);
	    rightPotential = SensorValue(rightArmPotent);
	}

    else if (vexRT[Btn6D] == 1 && speedlift == 1) { 	//While the variable speedlift is 1, motor runs at a power of 127 backwards.
			liftdown1();
			leftPotential = SensorValue(leftArmPotent);
	    rightPotential = SensorValue(rightArmPotent);
	}
		else if (vexRT[Btn6D] == 1 && speedlift == 2) { //While the variable speedlift is 2, motor runs at a power of 30 backwards.
			liftdown2();
			leftPotential = SensorValue(leftArmPotent);
	    rightPotential = SensorValue(rightArmPotent);
	}
	else {                        // turns the motor off if the button is not pressed
			motor[lift1] = 0;
			motor[lift2] = 0;
			armStablize( leftPotential, rightPotential );
		}

   if (vexRT[Btn8L] == 1) { //if the button 8L is pressed, the claw opens
    clawopen();
   }
   else if (vexRT[Btn8R] == 1) { //if the button 8R is pressed, the claw closes
     clawclose();
   }
   else {
  motor [claw] = 0; //otherwise, stop all actions on the claw
	}

	}
 }
