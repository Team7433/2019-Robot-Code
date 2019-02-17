/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/manualSholder.h"
#include "Robot.h"

manualSholder::manualSholder() {
  // Use Requires() here to declare subsystem dependencies
  Requires(&Robot::shoulder);
}

// Called just before this Command runs the first time
void manualSholder::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void manualSholder::Execute() {
  auto & Joystick = Robot::oi.getJoystick2();
  Robot::shoulder.manualControl(Joystick.GetY());
}

// Make this return true when this Command no longer needs to run execute()
bool manualSholder::IsFinished() { return false; }

// Called once after isFinished returns true
void manualSholder::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void manualSholder::Interrupted() {}
