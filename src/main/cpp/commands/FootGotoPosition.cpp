/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/FootGotoPosition.h"
#include "Robot.h"

// Create FootGotoPosition with a double position @param double posiition 
FootGotoPosition::FootGotoPosition(double position) {
  m_position = position;
  // Use Requires() here to declare subsystem dependencies
  Requires(&Robot::foot);
}

// Create FootGotoPosition with a position @param FootPosition position
FootGotoPosition::FootGotoPosition(FootPosition position) {
  m_position = position;
  Requires(&Robot::foot);
}

// Called just before this Command runs the first time
void FootGotoPosition::Initialize() {
  Robot::foot.gotoPosition(m_position);
}

// Called repeatedly when this Command is scheduled to run
void FootGotoPosition::Execute() {}

// Make this return true when this Command no longer needs to run execute()
bool FootGotoPosition::IsFinished() { 
 if (m_position-3 < Robot::foot.getFootPosition() && m_position+3 > Robot::foot.getFootPosition()) {
   return true;
 }
 if (Robot::foot.OnlimitSwitch() == true) {
   return true;
 }
 return false;
}

// Called once after isFinished returns true
void FootGotoPosition::End() {
  Robot::foot.controlManual(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void FootGotoPosition::Interrupted() {}
