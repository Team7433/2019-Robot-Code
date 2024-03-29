/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/shoulderGoToPosition.h"
#include "Robot.h"

shoulderGoToPosition::shoulderGoToPosition(double position) {
  m_position = position;
  // Use Requires() here to declare subsystem dependencies
  Requires(&Robot::shoulder);
}

// Called just before this Command runs the first time
void shoulderGoToPosition::Initialize() {
    Robot::shoulder.GotoAngle(m_position);
}

// Called repeatedly when this Command is scheduled to run
void shoulderGoToPosition::Execute() {}

// Make this return true when this Command no longer needs to run execute()
bool shoulderGoToPosition::IsFinished() { return false; }

// Called once after isFinished returns true
void shoulderGoToPosition::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void shoulderGoToPosition::Interrupted() {}
