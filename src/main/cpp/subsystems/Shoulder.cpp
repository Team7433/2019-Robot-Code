/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Shoulder.h"
#include "subsystems/constants.h"
#include "commands/manualSholder.h"
#include "frc/smartdashboard/SmartDashboard.h"

Shoulder::Shoulder() : Subsystem("ExampleSubsystem") {
  m_ShoulderMaster->ConfigFactoryDefault();
  //Make second motor follow first
  //config sensor and make sure its readings are correct
  m_ShoulderMaster->ConfigSelectedFeedbackSensor(FeedbackDevice::QuadEncoder, kPIDLoopIdx, kTimeoutMs);
	m_ShoulderMaster->SetSensorPhase(false);

  //set the peak and nominal(least) outputs
	m_ShoulderMaster->ConfigNominalOutputForward(0, kTimeoutMs);
	m_ShoulderMaster->ConfigNominalOutputReverse(0, kTimeoutMs);
	m_ShoulderMaster->ConfigPeakOutputForward(1.0, kTimeoutMs);
	m_ShoulderMaster->ConfigPeakOutputReverse(-1.0, kTimeoutMs);

	// set PID Values
	m_ShoulderMaster->Config_kF(kPIDLoopIdx, 3.64, kTimeoutMs);//1.39373
	m_ShoulderMaster->Config_kP(kPIDLoopIdx, 30.0, kTimeoutMs);
	m_ShoulderMaster->Config_kI(kPIDLoopIdx, 0.0, kTimeoutMs);
	m_ShoulderMaster->Config_kD(kPIDLoopIdx, 0.0, kTimeoutMs);

  //config limit switches
  //m_ShoulderMaster->ConfigForwardLimitSwitchSource(LimitSwitchSource::LimitSwitchSource_FeedbackConnector, LimitSwitchNormal::LimitSwitchNormal_NormallyClosed,kTimeoutMs);
  //m_ShoulderMaster->ConfigReverseLimitSwitchSource(LimitSwitchSource::LimitSwitchSource_FeedbackConnector, LimitSwitchNormal::LimitSwitchNormal_NormallyOpen,kTimeoutMs);

  //config motion magic with acceleration and cruise velocity 
  m_ShoulderMaster->ConfigMotionCruiseVelocity(400.0, kTimeoutMs);
	m_ShoulderMaster->ConfigMotionAcceleration(200.0, kTimeoutMs);

  m_ShoulderMaster->ConfigNeutralDeadband(0.02, kTimeoutMs);
}

void Shoulder::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  //SetDefaultCommand(new manualSholder());
}

void Shoulder::manualControl(double output) {
  m_ShoulderMaster->Set(ControlMode::PercentOutput, output);
}

void Shoulder::gotoPosition(double position) {
  m_ShoulderMaster->Set(ControlMode::Position, position);
}

void Shoulder::gotoPositionMM(double position) {
  m_ShoulderMaster->Set(ControlMode::MotionMagic, position);
}

double Shoulder::getPosition() {
  return m_ShoulderMaster->GetSelectedSensorPosition();
}

void Shoulder::resetSensor() {
  m_ShoulderMaster->SetSelectedSensorPosition(0);
}

void Shoulder::SetMaxSpeeds(double forward, double reverse) {
  m_ShoulderMaster->ConfigPeakOutputForward(forward, kTimeoutMs);
  m_ShoulderMaster->ConfigPeakOutputReverse(reverse, kTimeoutMs);	
}

void Shoulder::UpdateData() {
  frc::SmartDashboard::PutNumber("Shoulder/Position", m_ShoulderMaster->GetSelectedSensorPosition());
  frc::SmartDashboard::PutNumber("Shoulder/Velocity", m_ShoulderMaster->GetSelectedSensorVelocity());
  frc::SmartDashboard::PutNumber("Shoulder/Output", m_ShoulderMaster->GetMotorOutputPercent());
}

void Shoulder::GotoAngle(double angle) {
  double position = (angle + 19) * 26.8074;
  m_ShoulderMaster->Set(ControlMode::MotionMagic, position);
}

double Shoulder::getAngle() {
  return -((m_ShoulderMaster->GetSelectedSensorPosition() / 26.8074)-19);
}

