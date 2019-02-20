/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Trunk.h"
#include "subsystems/constants.h"
#include "commands/ManualTrunk.h"
#include "frc/smartdashboard/SmartDashboard.h"

Trunk::Trunk() : Subsystem("ExampleSubsystem") {
  m_TrunkMaster->ConfigFactoryDefault();
  m_TrunkSlave->ConfigFactoryDefault();
  //Make second motor follow first
  m_TrunkSlave->Follow(*m_TrunkMaster);

  //config sensor and make sure its readings are correct
  m_TrunkMaster->ConfigSelectedFeedbackSensor(FeedbackDevice::CTRE_MagEncoder_Relative, kPIDLoopIdx, kTimeoutMs);
	m_TrunkMaster->SetSensorPhase(true);

  //set the peak and nominal(least) outputs
	m_TrunkMaster->ConfigNominalOutputForward(0, kTimeoutMs);
	m_TrunkMaster->ConfigNominalOutputReverse(0, kTimeoutMs);
	m_TrunkMaster->ConfigPeakOutputForward(1.0, kTimeoutMs);
	m_TrunkMaster->ConfigPeakOutputReverse(-1.0, kTimeoutMs);

	// set PID Values
	m_TrunkMaster->Config_kF(kPIDLoopIdx, 1.423, kTimeoutMs);//1.39373
	m_TrunkMaster->Config_kP(kPIDLoopIdx, 3.0, kTimeoutMs);
	m_TrunkMaster->Config_kI(kPIDLoopIdx, 0.0, kTimeoutMs);
	m_TrunkMaster->Config_kD(kPIDLoopIdx, 0.0, kTimeoutMs);

  //config limit switches
  m_TrunkMaster->ConfigForwardLimitSwitchSource(LimitSwitchSource::LimitSwitchSource_FeedbackConnector, LimitSwitchNormal::LimitSwitchNormal_NormallyClosed,kTimeoutMs);
  m_TrunkMaster->ConfigReverseLimitSwitchSource(LimitSwitchSource::LimitSwitchSource_FeedbackConnector, LimitSwitchNormal::LimitSwitchNormal_NormallyOpen,kTimeoutMs);

  //config motion magic with acceleration and cruise velocity 
  m_TrunkMaster->ConfigMotionCruiseVelocity(2000, kTimeoutMs);
	m_TrunkMaster->ConfigMotionAcceleration(1000, kTimeoutMs);

  m_TrunkMaster->Set(ControlMode::MotionMagic, 0);
}

void Trunk::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  //SetDefaultCommand(new ManualTrunk());
}

void Trunk::manualControl(double output) {
  m_TrunkMaster->Set(ControlMode::PercentOutput, output);
}

void Trunk::gotoPosition(double position) {
  m_TrunkMaster->Set(ControlMode::Position, position);
}

void Trunk::gotoPositionMM(double position) {
  m_TrunkMaster->Set(ControlMode::MotionMagic, position);
}

double Trunk::getPosition() {
  return m_TrunkMaster->GetSelectedSensorPosition();
}

void Trunk::resetSensor() {
  m_TrunkMaster->SetSelectedSensorPosition(0);
}

void Trunk::SetMaxSpeeds(double forward, double reverse) {
  m_TrunkMaster->ConfigPeakOutputForward(forward, kTimeoutMs);
  m_TrunkMaster->ConfigPeakOutputReverse(reverse, kTimeoutMs);	
}

void Trunk::UpdateData() {
  frc::SmartDashboard::PutNumber("Trunk/Position", m_TrunkMaster->GetSelectedSensorPosition());
  frc::SmartDashboard::PutNumber("Trunk/Velocity", m_TrunkMaster->GetSelectedSensorVelocity());
  frc::SmartDashboard::PutNumber("Trunk/MotorOutput", m_TrunkMaster->GetMotorOutputPercent());
  frc::SmartDashboard::PutBoolean("Trunk/FwdLimit", m_TrunkMaster->GetSensorCollection().IsFwdLimitSwitchClosed());
  frc::SmartDashboard::PutBoolean("Trunk/RevLimit", m_TrunkMaster->GetSensorCollection().IsRevLimitSwitchClosed());
}
