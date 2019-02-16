/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/BallFloorWrist.h"
#include "subsystems/constants.h"

BallFloorWrist::BallFloorWrist() : Subsystem("ExampleSubsystem") {
  m_wristMotor->ConfigFactoryDefault();
  //Make second motor follow first
  //config sensor and make sure its readings are correct
  m_wristMotor->ConfigSelectedFeedbackSensor(FeedbackDevice::QuadEncoder, kPIDLoopIdx, kTimeoutMs);
	m_wristMotor->SetSensorPhase(false);

  //set the peak and nominal(least) outputs
	m_wristMotor->ConfigNominalOutputForward(0, kTimeoutMs);
	m_wristMotor->ConfigNominalOutputReverse(0, kTimeoutMs);
	m_wristMotor->ConfigPeakOutputForward(1.0, kTimeoutMs);
	m_wristMotor->ConfigPeakOutputReverse(-1.0, kTimeoutMs);

	// set PID Values
	m_wristMotor->Config_kF(kPIDLoopIdx, 2.17, kTimeoutMs);//1.39373
	m_wristMotor->Config_kP(kPIDLoopIdx, 25.0, kTimeoutMs);
	m_wristMotor->Config_kI(kPIDLoopIdx, 0.0, kTimeoutMs);
	m_wristMotor->Config_kD(kPIDLoopIdx, 0.0, kTimeoutMs);

  //config limit switches
  //m_ShoulderMaster->ConfigForwardLimitSwitchSource(LimitSwitchSource::LimitSwitchSource_FeedbackConnector, LimitSwitchNormal::LimitSwitchNormal_NormallyClosed,kTimeoutMs);
  //m_ShoulderMaster->ConfigReverseLimitSwitchSource(LimitSwitchSource::LimitSwitchSource_FeedbackConnector, LimitSwitchNormal::LimitSwitchNormal_NormallyOpen,kTimeoutMs);

  //config motion magic with acceleration and cruise velocity 
  m_wristMotor->ConfigMotionCruiseVelocity(200.0, kTimeoutMs);
	m_wristMotor->ConfigMotionAcceleration(200.0, kTimeoutMs);
}

void BallFloorWrist::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}

void BallFloorWrist::manualcontrol(double output) {
  m_wristMotor->Set(ControlMode::PercentOutput, output);
}

void BallFloorWrist::gotoPosition(double position) {
  m_wristMotor->Set(ControlMode::Position, position);
}

void BallFloorWrist::gotoPositionMM(double position) {
  m_wristMotor->Set(ControlMode::MotionMagic, position);
}

void BallFloorWrist::resetPosition() {
  m_wristMotor->SetSelectedSensorPosition(0);
}

int BallFloorWrist::getPosition() {
  return m_wristMotor->GetSelectedSensorPosition();
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
