/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/BallIntake/manualBallRoller.h"
#include "Robot.h"

manualBallRoller::manualBallRoller() {
  // Use Requires() here to declare subsystem dependencies
  Requires(&Robot::ballfloorintake);
}

// Called just before this Command runs the first time
void manualBallRoller::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void manualBallRoller::Execute() {
  auto& joystick2 = Robot::oi.getJoystick2();
  if(joystick2.GetX() > 0.03 || joystick2.GetX() < -0.03) {
    Robot::ballfloorintake.manual(-joystick2.GetX());
  } else {
    Robot::ballfloorintake.manual(0);
  }
}

// Make this return true when this Command no longer needs to run execute()
bool manualBallRoller::IsFinished() { return false; }

// Called once after isFinished returns true
void manualBallRoller::End() {
  Robot::ballfloorintake.manual(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void manualBallRoller::Interrupted() {}
