/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/WristGoToAngle.h"
#include "Robot.h"

WristGoToAngle::WristGoToAngle(double angle) {
  m_angle = angle;
  // Use Requires() here to declare subsystem dependencies
  Requires(&Robot::wrist);
}

// Called just before this Command runs the first time
void WristGoToAngle::Initialize() {
  Robot::wrist.GotoAngle(m_angle);
  Robot::wrist.LastAngle = m_angle;
}

// Called repeatedly when this Command is scheduled to run
void WristGoToAngle::Execute() {}

// Make this return true when this Command no longer needs to run execute()
bool WristGoToAngle::IsFinished() { 
  if (abs(m_angle-Robot::wrist.GetAngle()) < 5) {
    return true;
  }
  return false; 
}

// Called once after isFinished returns true
void WristGoToAngle::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void WristGoToAngle::Interrupted() {}
