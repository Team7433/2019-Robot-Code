/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/SuperStructureGotoPosition.h"
#include "Robot.h"
#include "frc/smartdashboard/SmartDashboard.h"

SuperStructureGotoPosition::SuperStructureGotoPosition(iona::Superstructure position) {
  m_position = position;
  // Use Requires() here to declare subsystem dependencies
  Requires(&Robot::elevator);
  Requires(&Robot::wrist);
  Requires(&Robot::shoulder);
}

// Called just before this Command runs the first time
void SuperStructureGotoPosition::Initialize() {
  switch (m_position)
  {
    case iona::Superstructure::idle:
      m_elevatorPos = 8000;
      m_shoulderPos = 25;
      m_wristPos = -17;
      break;
    case iona::Superstructure::cargoAhigh:
      m_elevatorPos = 17000;
      m_shoulderPos = 151;
      m_wristPos = -47;
      break;
    case iona::Superstructure::cargoAmedium:
      m_elevatorPos = 0;
      m_shoulderPos = 123;
      m_wristPos = -19;
      break;
    case iona::Superstructure::cargoAlow:
      m_elevatorPos = 0;
      m_shoulderPos = 36;
      m_wristPos = 74;
      break;
    case iona::Superstructure::cargoAtop:
      m_elevatorPos = 0;
      m_shoulderPos = 258;
      m_wristPos = 25;
      break;
    case iona::Superstructure::cargoBhigh:
      m_elevatorPos = 17000;
      m_shoulderPos = 209;
      m_wristPos = 47;
      break;
    case iona::Superstructure::cargoBmedium:
      m_elevatorPos = 0;
      m_shoulderPos = 237;
      m_wristPos = 19;
      break;
    case iona::Superstructure::cargoBlow:
      m_elevatorPos = 0;
      m_shoulderPos = 324;
      m_wristPos = -74;
      break;
    case iona::Superstructure::cargoBtop:
      m_elevatorPos = 0;
      m_shoulderPos = 102;
      m_wristPos = -25;
      break;
    case iona::Superstructure::cargointake:
      m_elevatorPos = 0;
      m_shoulderPos = 24;
      m_wristPos = -2;
    case iona::Superstructure::home:
      m_elevatorPos = 0;
      m_shoulderPos = 19;
      m_wristPos = -19;
      break;
    case iona::Superstructure::hatchintake:
      m_elevatorPos = 5837;
      m_shoulderPos = 337;
      m_wristPos = 26;
      break;
    case iona::Superstructure::hatchATop:
      m_elevatorPos = 7000;
      m_shoulderPos = 118;
      m_wristPos = 74;
      break;
    case iona::Superstructure::hatchAMiddle:
      m_elevatorPos = 15000;
      m_shoulderPos = 84;
      m_wristPos = -79;
      break;
    case iona::Superstructure::hatchAbottom:
      m_elevatorPos = 2500;
      m_shoulderPos = 46;
      m_wristPos = -42;
      break;
    case iona::Superstructure::hatchBTop:
      m_elevatorPos = 0;
      m_shoulderPos = 205;
      m_wristPos = -28;
      break;
    case iona::Superstructure::hatchBMiddle:
      m_elevatorPos = 19600;
      m_shoulderPos = 285;
      m_wristPos = 67;
      break;
    case iona::Superstructure::hatchBbottom:
      m_elevatorPos = 2884;
      m_shoulderPos = 321;
      m_wristPos = 40;
      break;
    case iona::Superstructure::climb:
      m_elevatorPos = 0;
      m_shoulderPos = 67;
      m_wristPos = -15;
      break;
    case iona::Superstructure::autostep1:
      m_elevatorPos = 4000;
      m_shoulderPos = 68;
      m_wristPos = -19;
      break;
    case iona::Superstructure::autostep2:
      m_elevatorPos = 0;
      m_shoulderPos = 68;
      m_wristPos = 0;
      break;
    case iona::Superstructure::autostep3:
      m_elevatorPos = 0;
      m_shoulderPos = 29;
      m_wristPos = 0;
      break;
    default:
      break;
  }
  m_shoulderPos = -m_shoulderPos;
  m_elevatorPos = -m_elevatorPos;
  Robot::shoulder.GotoAngle(m_shoulderPos);
  Robot::wrist.GotoAngle(m_wristPos);
  Robot::elevator.gotoPosition(m_elevatorPos);
  Robot::wrist.LastAngle = m_wristPos;
}

// Called repeatedly when this Command is scheduled to run
void SuperStructureGotoPosition::Execute() {}

// Make this return true when this Command no longer needs to run execute()
bool SuperStructureGotoPosition::IsFinished() { 
  //frc::SmartDashboard::PutNumber("Shoulder Error", Robot::shoulder.getAngle());
  //frc::SmartDashboard::PutNumber("Wrist Error", Robot::wrist.GetAngle()- m_wristPos);
  //frc::SmartDashboard::PutNumber("Elevator Error", Robot::elevator.getPosition()+ m_elevatorPos);
  frc::SmartDashboard::PutBoolean("IF1",  abs(m_shoulderPos-Robot::shoulder.getAngle()) < m_shoulderTolerence);
  frc::SmartDashboard::PutBoolean("IF2",  abs(m_elevatorPos-Robot::elevator.getPosition()) < m_elevatorTolerence);
  frc::SmartDashboard::PutBoolean("IF3",  abs(m_wristPos-Robot::wrist.GetAngle()) < m_wristTolerence);
  if (abs(m_shoulderPos+Robot::shoulder.getAngle()) < m_shoulderTolerence) {
    if (abs(m_elevatorPos-Robot::elevator.getPosition()) < m_elevatorTolerence) {
      if (abs(m_wristPos-Robot::wrist.GetAngle()) < m_wristTolerence) {
        return true;
      }
    }
  }
  return false; 
}

// Called once after isFinished returns true
void SuperStructureGotoPosition::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SuperStructureGotoPosition::Interrupted() {}
