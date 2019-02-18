/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/SwichSide.h"
#include "Robot.h"

SwichSide::SwichSide(Side side) {
  m_side = side;
  // Use Requires() here to declare subsystem dependencies
  Requires(&Robot::wrist);
  Requires(&Robot::elevator);
  Requires(&Robot::shoulder);
}

// Called just before this Command runs the first time
void SwichSide::Initialize() {
  if (m_side == Side::A) {
    if (Robot::shoulder.getAngle() < 180) {
      RightSide = true;
    } else {
      RightSide = false;
      Robot::wrist.GotoAngle(-85);
      Robot::elevator.gotoPosition(0);
    }
  } else {
    if (Robot::shoulder.getAngle() > 180) {
      RightSide = true;
    } else {
      RightSide = false;
      Robot::wrist.GotoAngle(85);
      Robot::elevator.gotoPosition(0);
    }
  }
}

// Called repeatedly when this Command is scheduled to run
void SwichSide::Execute() {
  if (m_side == Side::A) {
    if (RightSide == false) {
      if (Robot::elevator.getPosition() < 500 && Robot::wrist.GetAngle() < -70) {
        Robot::shoulder.GotoAngle(-50);
      } 
      if (Robot::shoulder.getAngle() < 150) {
        RightSide = true;
      }
    }
  } else {
    if (RightSide == false) {
      if (Robot::elevator.getPosition() < 500 && Robot::wrist.GetAngle() > 70) {
        Robot::shoulder.GotoAngle(-325);
      } 
      if (Robot::shoulder.getAngle() > 210) {
        RightSide = true;
      }
    }
  }
}

// Make this return true when this Command no longer needs to run execute()
bool SwichSide::IsFinished() { return RightSide; }

// Called once after isFinished returns true
void SwichSide::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SwichSide::Interrupted() {}
