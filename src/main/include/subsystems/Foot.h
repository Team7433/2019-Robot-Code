/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/Subsystem.h>
#include <ctre/Phoenix.h>

class Foot : public frc::Subsystem {
 private:
  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities
  WPI_TalonSRX * m_footMotor = new WPI_TalonSRX(1);
  CANifier * m_canifier = new CANifier{1};
 public:
  Foot();
  void InitDefaultCommand() override;

  //Control Methods
  void controlManual(double output);
  void gotoPosition(double position);
  void resetEncoder();
  double getFootPosition();
};
