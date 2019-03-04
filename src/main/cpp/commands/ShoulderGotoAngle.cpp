/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/ShoulderGotoAngle.h"
#include "robot.h"

ShoulderGotoAngle::ShoulderGotoAngle(double angle) {
  m_angle = -angle;
  // Use Requires() here to declare subsystem dependencies
  Requires(&Robot::shoulder);
}

// Called just before this Command runs the first time
void ShoulderGotoAngle::Initialize() {
  Robot::shoulder.GotoAngle(m_angle);
}

// Called repeatedly when this Command is scheduled to run
void ShoulderGotoAngle::Execute() {}

// Make this return true when this Command no longer needs to run execute()
bool ShoulderGotoAngle::IsFinished() {
  if (abs(m_angle+Robot::shoulder.getAngle()) < 5) {
    return true;
  }
  return false;
}

// Called once after isFinished returns true
void ShoulderGotoAngle::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ShoulderGotoAngle::Interrupted() {}
