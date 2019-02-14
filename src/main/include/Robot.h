/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/TimedRobot.h>
#include <frc/commands/Command.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <iostream>

//Modules
#include "OI.h"
#include "Vision.h"

//Subsystems
#include "subsystems/Foot.h"
#include "subsystems/Trunk.h"
#include "subsystems/Drivetrain.h"
#include "subsystems/Shoulder.h"

class Robot : public frc::TimedRobot {
 public:

  //Modules
  static OI oi;
  static Vision vision;
  static Drivetrain drivetrain;

  //Subsystems
  static Foot foot;
  static Trunk trunk;
  static Shoulder shoulder;

  void RobotInit() override;
  void RobotPeriodic() override;
  void DisabledInit() override;
  void DisabledPeriodic() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;
  void TestPeriodic() override;

 private:
  // Have it null by default so that if testing teleop it
  // doesn't have undefined behavior and potentially crash.

};
