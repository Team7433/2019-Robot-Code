/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Elevator.h"
#include "subsystems/constants.h"
#include "commands/manualElevator.h"



Elevator::Elevator() : Subsystem("ExampleSubsystem") {
  m_elevatorMotor->ConfigSelectedFeedbackSensor(FeedbackDevice::QuadEncoder, kPIDLoopIdx, kTimeoutMs);
	m_elevatorMotor->SetSensorPhase(false);

			// set the peak and nominal outputs, 12V means full
	m_elevatorMotor->ConfigNominalOutputForward(0, kTimeoutMs);
	m_elevatorMotor->ConfigNominalOutputReverse(0, kTimeoutMs);
	m_elevatorMotor->ConfigPeakOutputForward(1, kTimeoutMs);
	m_elevatorMotor->ConfigPeakOutputReverse(-1, kTimeoutMs);
	//Elevator_talon_a->ConfigPeakOutputForward(elevatorupmax, kTimeoutMs);
	//Elevator_talon_a->ConfigPeakOutputReverse(elevatordownmax, kTimeoutMs);

			// set closed loop gains in slot0
	m_elevatorMotor->Config_kF(kPIDLoopIdx, 0.0, kTimeoutMs);
	m_elevatorMotor->Config_kP(kPIDLoopIdx, 50.0, kTimeoutMs);
	m_elevatorMotor->Config_kI(kPIDLoopIdx, 0.0, kTimeoutMs);
	m_elevatorMotor->Config_kD(kPIDLoopIdx, 0.0, kTimeoutMs);
}

void Elevator::InitDefaultCommand() {
}
void Elevator::controlManual(double output) {
  m_elevatorMotor->Set(ControlMode::PercentOutput, output);
}

void Elevator::gotoPosition(double position) {
  m_elevatorMotor->Set(ControlMode::Position, position);
}

double Elevator::getPosition() {
	return m_elevatorMotor->GetSelectedSensorPosition();
}