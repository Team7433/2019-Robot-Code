/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/manualWrist.h"
#include "Robot.h"

manualWrist::manualWrist() {
  // Use Requires() here to declare subsystem dependencies
  Requires(&Robot::wrist);
}

// Called just before this Command runs the first time
void manualWrist::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void manualWrist::Execute() {
  auto& joystick = Robot::oi.getJoystick2();
  Robot::wrist.manualControl(joystick.GetX());
}

// Make this return true when this Command no longer needs to run execute()
bool manualWrist::IsFinished() { return false; }

// Called once after isFinished returns true
void manualWrist::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void manualWrist::Interrupted() {}
