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
  Robot::wrist.WristSpeed(4000,4000);
  m_previousPosition = Robot::wrist.GetAngle();
  SetTimeout(0.8);
  Robot::wrist.GotoAngle(0);
}

// Called repeatedly when this Command is scheduled to run
void EjectHatch::Execute() {}

// Make this return true when this Command no longer needs to run execute()
bool EjectHatch::IsFinished() { 
  if (-5 < Robot::wrist.GetAngle() && 5 > Robot::wrist.GetAngle()) {
    //return true;
  }
  return false;
}

// Called once after isFinished returns true
void EjectHatch::End() {
  Robot::wrist.WristSpeed(180,70);
  Robot::wrist.GotoAngle(Robot::wrist.LastAngle);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void EjectHatch::Interrupted() {
  End();
}
