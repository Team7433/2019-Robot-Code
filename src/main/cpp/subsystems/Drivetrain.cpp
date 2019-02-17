/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Drivetrain.h"
#include "commands/manualDrive.h"
#include "subsystems/constants.h"

Drivetrain::Drivetrain() : Subsystem("ExampleSubsystem") {}

void Drivetrain::InitDefaultCommand() {
  m_leftMaster->ConfigFactoryDefault(kTimeoutMs);
  m_rightMaster->ConfigFactoryDefault(kTimeoutMs);
  // Set the default command for a subsystem here.
  SetDefaultCommand(new manualDrive());
}

void Drivetrain::driveArcade(double forward, double rotation) {
  m_robotDrive.ArcadeDrive(forward, rotation);
}

void Drivetrain::driveTank(double left, double right) {
  m_robotDrive.TankDrive(left, right);
}

void Drivetrain::driveCurvature(double forward, double curve, bool isQuickTurn) {
  m_robotDrive.CurvatureDrive(forward, curve, isQuickTurn);
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
