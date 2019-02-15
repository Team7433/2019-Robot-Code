/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/Subsystem.h>
#include <ctre/Phoenix.h>

class Shoulder : public frc::Subsystem {
 private:
  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities

  WPI_TalonSRX * m_ShoulderMaster = new WPI_TalonSRX{8};
  //WPI_TalonSRX * m_ShoulderSlave = new WPI_TalonSRX{3};
 public:
  Shoulder();
  void InitDefaultCommand() override;
  void manualControl(double output);
  void gotoPosition(double position);
  void gotoPositionMM(double position);
  void resetSensor();
  double getPosition();
  void SetMaxSpeeds(double forward, double reverse);
};