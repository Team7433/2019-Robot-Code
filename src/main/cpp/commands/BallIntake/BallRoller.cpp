/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/BallIntake/BallRoller.h"
#include "Robot.h"

BallRoller::BallRoller(double speed, double time) {
  m_time = time;
  m_speed = speed;
  // Use Requires() here to declare subsystem dependencies
  Requires(&Robot::ballfloorintake);
}

// Called just before this Command runs the first time
void BallRoller::Initialize() {
  SetTimeout(m_time);
  Robot::ballfloorintake.manual(m_speed);
}

// Called repeatedly when this Command is scheduled to run
void BallRoller::Execute() {}

// Make this return true when this Command no longer needs to run execute()
bool BallRoller::IsFinished() { return IsTimedOut(); }

// Called once after isFinished returns true
void BallRoller::End() {
  Robot::ballfloorintake.manual(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void BallRoller::Interrupted() {
  End();
}
