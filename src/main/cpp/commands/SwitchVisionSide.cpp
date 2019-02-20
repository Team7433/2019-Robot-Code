/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/SwitchVisionSide.h"
#include "Robot.h"

SwitchVisionSide::SwitchVisionSide() {
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
}

// Called once when the command executes
void SwitchVisionSide::Initialize() {
  std::cout << "" << "\n";
  if (Robot::vision.GetVisionCamera() == 0) {
    Robot::vision.SetCamera(1);
  } else {
    Robot::vision.SetCamera(0);
  }
}
