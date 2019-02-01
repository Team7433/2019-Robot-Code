/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Trunk.h"
#include "subsystems/constants.h"

Trunk::Trunk() : Subsystem("ExampleSubsystem") {
  m_TrunkSlave->Follow(*m_TrunkMaster);
  m_TrunkMaster->ConfigSelectedFeedbackSensor(FeedbackDevice::QuadEncoder, kPIDLoopIdx, kTimeoutMs);
	m_TrunkMaster->SetSensorPhase(true);

			// set the peak and nominal outputs, 12V means full
	m_TrunkMaster->ConfigNominalOutputForward(0, kTimeoutMs);
	m_TrunkMaster->ConfigNominalOutputReverse(0, kTimeoutMs);
	m_TrunkMaster->ConfigPeakOutputForward(1, kTimeoutMs);
	m_TrunkMaster->ConfigPeakOutputReverse(-1, kTimeoutMs);
	//Elevator_talon_a->ConfigPeakOutputForward(elevatorupmax, kTimeoutMs);
	//Elevator_talon_a->ConfigPeakOutputReverse(elevatordownmax, kTimeoutMs);

			// set closed loop gains in slot0
	m_TrunkMaster->Config_kF(kPIDLoopIdx, 1.39373, kTimeoutMs);
	m_TrunkMaster->Config_kP(kPIDLoopIdx, 3.0, kTimeoutMs);
	m_TrunkMaster->Config_kI(kPIDLoopIdx, 0.0, kTimeoutMs);
	m_TrunkMaster->Config_kD(kPIDLoopIdx, 0.0, kTimeoutMs);
}

void Trunk::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}

void Trunk::manualControl(double output) {
  m_TrunkMaster->Set(ControlMode::PercentOutput, output);
}

void Trunk::gotoPosition(double position) {
  m_TrunkMaster->Set(ControlMode::Position, position);
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

