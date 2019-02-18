/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/EjectHatch.h"
#include "Robot.h"

EjectHatch::EjectHatch() {
  // Use Requires() here to declare subsystem dependencies
  Requires(&Robot::wrist);
}

// Called just before this Command runs the first time
void EjectHatch::Initialize() {
  SetTimeout(0.8);
  if (Robot::wrist.GetAngle() > 0 ) {
    Robot::wrist.manualControl(-0.4);
  } else {
    Robot::wrist.manualControl(0.4);  
  }
}

// Called repeatedly when this Command is scheduled to run
void EjectHatch::Execute() {}

// Make this return true when this Command no longer needs to run execute()
bool EjectHatch::IsFinished() { return false; }

// Called once after isFinished returns true
void EjectHatch::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void EjectHatch::Interrupted() {}
