/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/




Elevator::Elevator() : Subsystem("ExampleSubsystem") {

  //Make second motor follow first
  m_ElevatorSlave->Follow(*m_ElevatorMaster);

  //config sensor and make sure its readings are correct
  m_ElevatorMaster->ConfigSelectedFeedbackSensor(FeedbackDevice::QuadEncoder, kPIDLoopIdx, kTimeoutMs);
	m_ElevatorMaster->SetSensorPhase(true);

  //set the peak and nominal(least) outputs
	m_ElevatorMaster->ConfigNominalOutputForward(0, kTimeoutMs);
	m_ElevatorMaster->ConfigNominalOutputReverse(0, kTimeoutMs);
	m_ElevatorMaster->ConfigPeakOutputForward(0.5, kTimeoutMs);
	m_ElevatorMaster->ConfigPeakOutputReverse(-0.5, kTimeoutMs);

	// set PID Values
	m_ElevatorMaster->Config_kF(kPIDLoopIdx, 1.423, kTimeoutMs);//1.39373
	m_ElevatorMaster->Config_kP(kPIDLoopIdx, 1.0, kTimeoutMs);
	m_ElevatorMaster->Config_kI(kPIDLoopIdx, 0.0, kTimeoutMs);
	m_ElevatorMaster->Config_kD(kPIDLoopIdx, 0.0, kTimeoutMs);

  //config limit switches
  m_ElevatorMaster->ConfigForwardLimitSwitchSource(LimitSwitchSource::LimitSwitchSource_FeedbackConnector, LimitSwitchNormal::LimitSwitchNormal_NormallyClosed,kTimeoutMs);
  m_ElevatorMaster->ConfigReverseLimitSwitchSource(LimitSwitchSource::LimitSwitchSource_FeedbackConnector, LimitSwitchNormal::LimitSwitchNormal_NormallyOpen,kTimeoutMs);

  //config motion magic with acceleration and cruise velocity 
  m_ElevatorMaster->ConfigMotionCruiseVelocity(600.2, kTimeoutMs);
	m_ElevatorMaster->ConfigMotionAcceleration(380.8, kTimeoutMs);
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

