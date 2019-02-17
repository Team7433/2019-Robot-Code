/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/ballintakeIn.h"
#include "Robot.h"

ballintakeIn::ballintakeIn() {
  // Use Requires() here to declare subsystem dependencies
  Requires(&Robot::ballfloorwrist);
  
}

// Called just before this Command runs the first time
void ballintakeIn::Initialize() {
  //SetTimeout(2);
  Robot::ballfloorwrist.manualcontrol(-0.6);
}

// Called repeatedly when this Command is scheduled to run
void ballintakeIn::Execute() {}

// Make this return true when this Command no longer needs to run execute()
bool ballintakeIn::IsFinished() { return IsTimedOut(); }

// Called once after isFinished returns true
void ballintakeIn::End() {
  Robot::ballfloorwrist.manualcontrol(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ballintakeIn::Interrupted() {}
