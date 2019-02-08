/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/Subsystem.h>
#include <ctre/Phoenix.h>
#include <frc/drive/DifferentialDrive.h>

class Drivetrain : public frc::Subsystem {
 private:
  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities
  WPI_TalonSRX * m_leftMaster = new WPI_TalonSRX{3};
  //WPI_TalonSRX * m_leftSlave = new WPI_TalonSRX{3};
  
  WPI_TalonSRX * m_rightMaster = new WPI_TalonSRX{4};
  //WPI_TalonSRX * m_rightSlave = new WPI_TalonSRX{4};

  frc::DifferentialDrive m_robotDrive{*m_leftMaster, *m_rightMaster};
 public:
  Drivetrain();
  void InitDefaultCommand() override;
  void driveArcade(double forward, double rotation);
  void driveCurvature(double forward, double curve, bool isQuickTurn);
};
