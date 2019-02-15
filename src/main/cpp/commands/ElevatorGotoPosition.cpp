/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/ElevatorGotoPosition.h"
#include "Robot.h"

ElevatorGotoPosition::ElevatorGotoPosition(double position) {
   m_position = position;
  // Use Requires() here to declare subsystem dependencies
   Requires(&Robot::elevator);
}

// Called just before this Command runs the first time
void ElevatorGotoPosition::Initialize() {
   Robot::elevator.gotoPosition(m_position);
}

// Called repeatedly when this Command is scheduled to run
void ElevatorGotoPosition::Execute() {}

// Make this return true when this Command no longer needs to run execute()
bool ElevatorGotoPosition::IsFinished() { 
 if (m_position-3 < Robot::elevator.getPosition() && m_position+3 > Robot::elevator.getPosition()) {
   return true;
 }
 return false;
}

// Called once after isFinished returns true
void ElevatorGotoPosition::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ElevatorGotoPosition::Interrupted() {}
