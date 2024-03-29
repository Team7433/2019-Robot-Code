/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/TrunkGotoPosition.h"
#include "Robot.h"
#include "frc/smartdashboard/SmartDashboard.h"
#include "iostream"

TrunkGotoPosition::TrunkGotoPosition(double position) {
  m_position = position;
  // Use Requires() here to declare subsystem dependencies
  Requires(&Robot::trunk);
}

// Called just before this Command runs the first time
void TrunkGotoPosition::Initialize() {
  Robot::trunk.gotoPositionMM(m_position);
}

// Called repeatedly when this Command is scheduled to run
void TrunkGotoPosition::Execute() {
  frc::SmartDashboard::PutNumber("Trunk Position", Robot::trunk.getPosition());
}

// Make this return true when this Command no longer needs to run execute()
bool TrunkGotoPosition::IsFinished() { 
  if (m_position-m_tolerence < Robot::trunk.getPosition() && m_position+m_tolerence > Robot::trunk.getPosition()) {
    return true;
  }
  return false;
}

// Called once after isFinished returns true
void TrunkGotoPosition::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TrunkGotoPosition::Interrupted() {
}
