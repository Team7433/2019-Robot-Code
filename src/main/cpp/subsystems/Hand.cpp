/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Hand.h"

Hand::Hand() : Subsystem("ExampleSubsystem") {}

void Hand::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}

void Hand::manual(double output) {
  m_intakeLeft->Set(ControlMode::PercentOutput, output);
  m_intakeRight->Set(ControlMode::PercentOutput, output);
}
