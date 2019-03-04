/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/FillMotionProfile.h"
#include "Robot.h"

FillMotionProfile::FillMotionProfile(std::string path) {
  m_path = path;
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
}

// Called once when the command executes
void FillMotionProfile::Initialize() {
  Robot::drivetrain.StartFilling(m_path);
}
