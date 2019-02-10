/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/ExecuteMotionProfile.h"
#include <Robot.h>

ExecuteMotionProfile::ExecuteMotionProfile(std::string path) {
  m_Path = path;
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
  Requires(&Robot::drivetrain);
}

// Called just before this Command runs the first time
void ExecuteMotionProfile::Initialize() {
  printf("Start Executing Motion Profile \n");
  Robot::drivetrain.StartMP(m_Path);
}

// Called repeatedly when this Command is scheduled to run
void ExecuteMotionProfile::Execute() {
  Robot::drivetrain.MPControl();
  Robot::drivetrain.MPPeriodicTask();
}

// Make this return true when this Command no longer needs to run execute()
bool ExecuteMotionProfile::IsFinished() {
   return Robot::drivetrain.IsFinishedMP(); 
}

// Called once after isFinished returns true
void ExecuteMotionProfile::End() {
  Robot::drivetrain.ResetMP();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ExecuteMotionProfile::Interrupted() {}