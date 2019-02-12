/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/autostuff/CountTest.h"
#include <frc/smartdashboard/SmartDashboard.h>

CountTest::CountTest(int Time) {
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
  SetTimeout(Time);
}

// Called just before this Command runs the first time
void CountTest::Initialize() {
  m_timer.Start();
}

// Called repeatedly when this Command is scheduled to run
void CountTest::Execute() {
  frc::SmartDashboard::GetNumber("CommandTime", m_timer.Get());
}

// Make this return true when this Command no longer needs to run execute()
bool CountTest::IsFinished() { return false; }

// Called once after isFinished returns true
void CountTest::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CountTest::Interrupted() {}
