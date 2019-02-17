/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/BallFloorIntake.h"

BallFloorIntake::BallFloorIntake() : Subsystem("ExampleSubsystem") {}

void BallFloorIntake::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}

void BallFloorIntake::manual(double output) {
  m_intakeMotor->Set(ControlMode::PercentOutput, output);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
