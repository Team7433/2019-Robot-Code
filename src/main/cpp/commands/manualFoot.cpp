/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/manualFoot.h"
#include "Robot.h"
#include <iostream>

manualFoot::manualFoot() {
  Requires(&Robot::foot);
}

// Called just before this Command runs the first time
void manualFoot::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void manualFoot::Execute() {
  auto& joystick = Robot::oi.getJoystick1();
  Robot::foot.controlManual(joystick.GetY());
}

// Make this return true when this Command no longer needs to run execute()
bool manualFoot::IsFinished() { return false; }

// Called once after isFinished returns true
void manualFoot::End() {
  std::cout << "Done \n";
  Robot::foot.controlManual(0.00);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void manualFoot::Interrupted() {}
