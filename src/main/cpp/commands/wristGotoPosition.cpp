/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/wristGotoPosition.h"
#include "Robot.h"

wristGotoPosition::wristGotoPosition(double position) {
  m_position = position;
  // Use Requires() here to declare subsystem dependencies
  Requires(&Robot::wrist);
}

// Called just before this Command runs the first time
void wristGotoPosition::Initialize() {
  Robot::wrist.GotoAngle(m_position);
}

// Called repeatedly when this Command is scheduled to run
void wristGotoPosition::Execute() {}

// Make this return true when this Command no longer needs to run execute()
bool wristGotoPosition::IsFinished() { return false; }

// Called once after isFinished returns true
void wristGotoPosition::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void wristGotoPosition::Interrupted() {}
