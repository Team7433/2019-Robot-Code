/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/SetElevatorBuffer.h"
#include "commands/ElevatorGotoPosition.h"
#include "Robot.h"

SetElevatorBuffer::SetElevatorBuffer(double buffer) {
  m_buffer = buffer;
  // Use Requires() here to declaredsa subsystem dependencies
  // eg. Requires(Robot::chassis.get());
}

// Called once when the command executes
void SetElevatorBuffer::Initialize() {
  Robot::elevator.offset = m_buffer;
  frc::Command* commandToBeExecuted = new ElevatorGotoPosition(Robot::elevator.currentPos);
  commandToBeExecuted->Start();
}
