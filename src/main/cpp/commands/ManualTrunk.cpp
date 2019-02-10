/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/ManualTrunk.h"
#include "Robot.h"
#include "frc/smartdashboard/SmartDashboard.h"

ManualTrunk::ManualTrunk() {
  // Use Requires() here to declare subsystem dependencies
  Requires(&Robot::trunk);
}

// Called just before this Command runs the first time
void ManualTrunk::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void ManualTrunk::Execute() {
  auto& joystick = Robot::oi.getJoystick2();
  Robot::trunk.manualControl(joystick.GetY());
  frc::SmartDashboard::PutNumber("Trunk Position", Robot::trunk.getPosition());
  frc::SmartDashboard::PutBoolean("TrunkManual", true);
}

// Make this return true when this Command no longer needs to run execute()
bool ManualTrunk::IsFinished() { return false; }

// Called once after isFinished returns true
void ManualTrunk::End() {
  frc::SmartDashboard::PutBoolean("TrunkManual", false);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ManualTrunk::Interrupted() {}
