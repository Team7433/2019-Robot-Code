/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/ElevatorMoveRelitive.h"
#include "robot.h"

ElevatorMoveRelitive::ElevatorMoveRelitive(double distance) {
  m_distance = distance;
  // Use Requires() here to declare subsystem dependencies
  Requires(&Robot::elevator);
}

// Called just before this Command runs the first time
void ElevatorMoveRelitive::Initialize() {
  Robot::elevator.offset = m_distance;

  if (-Robot::elevator.getPosition() + m_distance > 20000) {
    Robot::trunk.gotoPositionMM(-20000);
  } else if (-Robot::elevator.getPosition() + m_distance < 0) {
    Robot::elevator.gotoPosition(0);
  } else {
    Robot::elevator.gotoPosition(-(- + m_distance));
  }
}

// Called repeatedly when this Command is scheduled to run
void ElevatorMoveRelitive::Execute() {}

// Make this return true when this Command no longer needs to run execute()
bool ElevatorMoveRelitive::IsFinished() { return false; }

// Called once after isFinished returns true
void ElevatorMoveRelitive::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ElevatorMoveRelitive::Interrupted() {}
