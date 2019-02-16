/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/Subsystem.h>
#include <ctre/Phoenix.h>

class Wrist : public frc::Subsystem {
 private:
  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities

  TalonSRX * m_wristMotor = new TalonSRX{10};
 public:
  Wrist();
  void InitDefaultCommand() override;
  void manualControl(double output);
  void GotoPosition(double position);
  void GotoPositionMM(double position);
  void ResetPosition();
  int GetPosition();
};
