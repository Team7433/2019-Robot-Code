/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/resetBallWrist.h"
#include "Robot.h"

resetBallWrist::resetBallWrist() {
  // Use Requires() here to declare subsystem dependencies
}

// Called once when the command executes
void resetBallWrist::Initialize() {
  Robot::ballfloorwrist.resetPosition();
}
