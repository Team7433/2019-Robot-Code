/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/BallWristGotoPosition.h"
#include "Robot.h"

BallWristGotoPosition::BallWristGotoPosition(double position) {
  m_position = position;
  // Use Requires() here to declare subsystem dependencies
  Requires(&Robot::ballfloorwrist);
}

// Called just before this Command runs the first time
void BallWristGotoPosition::Initialize() {
  Robot::ballfloorwrist.gotoPosition(m_position);
}

// Called repeatedly when this Command is scheduled to run
void BallWristGotoPosition::Execute() {}

// Make this return true when this Command no longer needs to run execute()
bool BallWristGotoPosition::IsFinished() { return false; }

// Called once after isFinished returns true
void BallWristGotoPosition::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void BallWristGotoPosition::Interrupted() {}
