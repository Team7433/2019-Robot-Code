/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/drivetrainManualOutput.h"
#include "Robot.h"

drivetrainManualOutput::drivetrainManualOutput(double left, double right) {
  m_left = left;
  m_right = right;
  // Use Requires() here to declare subsystem dependencies
  Requires(&Robot::drivetrain);
}

// Called just before this Command runs the first time
void drivetrainManualOutput::Initialize() {
  Robot::drivetrain.driveTank(m_left, m_right);
}

// Called repeatedly when this Command is scheduled to run
void drivetrainManualOutput::Execute() {}

// Make this return true when this Command no longer needs to run execute()
bool drivetrainManualOutput::IsFinished() { return false; }

// Called once after isFinished returns true
void drivetrainManualOutput::End() {
  Robot::drivetrain.driveTank(0,0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void drivetrainManualOutput::Interrupted() {}