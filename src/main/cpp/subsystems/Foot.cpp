/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Foot.h"
#include "subsystems/constants.h"

#include "commands/manualFoot.h"

Foot::Foot() : Subsystem("ExampleSubsystem") {
  m_footMotor->ConfigRemoteFeedbackFilter(1, RemoteSensorSource::RemoteSensorSource_CANifier_Quadrature, 0, 0);
	m_footMotor->ConfigSelectedFeedbackSensor(FeedbackDevice::RemoteSensor0, 0, 0);
	m_footMotor->SetSensorPhase(false);

			// set the peak and nominal outputs, 12V means full
	m_footMotor->ConfigNominalOutputForward(0, kTimeoutMs);
	m_footMotor->ConfigNominalOutputReverse(0, kTimeoutMs);
	m_footMotor->ConfigPeakOutputForward(1, kTimeoutMs);
	m_footMotor->ConfigPeakOutputReverse(-1, kTimeoutMs);
	//Elevator_talon_a->ConfigPeakOutputForward(elevatorupmax, kTimeoutMs);
	//Elevator_talon_a->ConfigPeakOutputReverse(elevatordownmax, kTimeoutMs);

			// set closed loop gains in slot0
	m_footMotor->Config_kF(kPIDLoopIdx, 0.0, kTimeoutMs);
	m_footMotor->Config_kP(kPIDLoopIdx, 50.0, kTimeoutMs);
	m_footMotor->Config_kI(kPIDLoopIdx, 0.0, kTimeoutMs);
	m_footMotor->Config_kD(kPIDLoopIdx, 0.0, kTimeoutMs);
}

void Foot::InitDefaultCommand() {
  //SetDefaultCommand(new manualFoot());
}

void Foot::controlManual(double output) {
  m_footMotor->Set(ControlMode::PercentOutput, output);
}

void Foot::gotoPosition(double position) {
  m_footMotor->Set(ControlMode::Position, position);
}

double Foot::getFootPosition() {
	return m_footMotor->GetSelectedSensorPosition();
}