/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/Subsystem.h>
#include <ctre/phoenix.h>

class BallFloorWrist : public frc::Subsystem {
 private:
  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities
  TalonSRX * m_wristMotor = new TalonSRX{15};
 public:
  BallFloorWrist();
  void InitDefaultCommand() override;
  void manualcontrol(double output);
  void gotoPosition(double position);
  void gotoPositionMM(double position);
  void resetPosition();
  int getPosition();
};
