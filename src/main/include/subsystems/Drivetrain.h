/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

//General Librarys
#include <string>

//WPI Librays
#include <frc/commands/Subsystem.h>
#include <frc/Drive/DifferentialDrive.h> 
#include <frc/Notifier.h> 

//Motor Controller Librarys
#include <ctre/Phoenix.h>

class Drivetrain : public frc::Subsystem {
 private:
  WPI_TalonSRX * m_LeftMaster = new WPI_TalonSRX(1);
  WPI_TalonSRX * m_RightMaster = new WPI_TalonSRX(2);
  //WPI_TalonSRX * m_LeftSlave = new WPI_TalonSRX(3);
  //WPI_TalonSRX * m_RightSlave = new WPI_TalonSRX(4);

  frc::DifferentialDrive m_RobotDrive{*m_LeftMaster, *m_RightMaster};
  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities

  double talon_kf = 0.45;
  double talon_kp = 1.0;
  double talon_ki = 0.0;
  double talon_kd = 20.0;
 

  std::string m_MpPathId;

  SetValueMotionProfile _setValueLeft =  SetValueMotionProfile::Disable;
  SetValueMotionProfile _setValueRight =  SetValueMotionProfile::Disable;

  MotionProfileStatus _statusLeft, _statusRight;

  int _state = 0;
  int _loopTimeout = -1;

  bool _bstart = false;

  static const int KMinPointsInTalon = 30;
  static const int KNumLoopsTimeout = 10;

  //frc::Notifier m_notifier;

 public:
  Drivetrain();
  void InitDefaultCommand() override;

  //Drive Methods
  void DriveArcade(double forward, double Rotation);
  void DriveTank(double left, double right);
  void DriveCurvature(double forward, double curve, bool isQuickTurn);

  //Motion Profile Methods
  void StartMP(std::string Profile);
  void MPPeriodicTask();
  void MPControl();
  void StartFilling();        // Fills the Talon with profile points
  void ResetMP();             // Resets The Motion Profile Code 
  bool IsFinishedMP();        // check when the motion profile has finished so the command nows to move on
  
  //Reset Sensors
  void resetGyro();
  void resetLeftEncoder();
  void resetRightEncoder();

  //Get Sensor Values from the Drivetrain
  double GetLeftDistance();
  double GetRightDistance();
  double GetLeftVelocity();
  double GetRightVelocity();
  double GetHeading();

  //update stats and sensor values onto to the dashboard
  void UpdateDasboard();
};