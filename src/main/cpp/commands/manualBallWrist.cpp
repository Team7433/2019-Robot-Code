/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/manualBallWrist.h"
#include "Robot.h"

manualBallWrist::manualBallWrist() {
  // Use Requires() here to declare subsystem dependencies
  Requires(&Robot::ballfloorwrist);
}

// Called just before this Command runs the first time
void manualBallWrist::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void manualBallWrist::Execute() {
  auto& Joystick2 = Robot::oi.getJoystick2();
  if (Joystick2.GetY() > 0.5 || Joystick2.GetY() < -0.5) {
    Robot::ballfloorwrist.manualcontrol(-Joystick2.GetY()*0.8);
  } else {
    Robot::ballfloorwrist.manualcontrol(0);
  }
}

// Make this return true when this Command no longer needs to run execute()
bool manualBallWrist::IsFinished() { return false; }

// Called once after isFinished returns true
void manualBallWrist::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void manualBallWrist::Interrupted() {}
