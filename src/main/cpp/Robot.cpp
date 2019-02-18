/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Robot.h"

#include <frc/commands/Scheduler.h>
#include <frc/smartdashboard/SmartDashboard.h>
//#include "commands/SuperstructureControl.h"
#include "commands/SuperstructureControl.h"
#include "positions.h"

//Modules
OI Robot::oi;
Vision Robot::vision;

//Subsystems
Foot Robot::foot;
Trunk Robot::trunk;
Drivetrain Robot::drivetrain;
Shoulder Robot::shoulder;
Elevator Robot::elevator;
Wrist Robot::wrist;
Hand Robot::hand;
BallFloorWrist Robot::ballfloorwrist;
BallFloorIntake Robot::ballfloorintake;


void Robot::RobotInit() {

}

void Robot::RobotPeriodic() {//(angle + 19) * 26.8074;
  frc::SmartDashboard::PutNumber("Superstructure/Elevator", -elevator.getPosition());
  frc::SmartDashboard::PutNumber("Superstructure/Wrist", wrist.GetAngle());
  frc::SmartDashboard::PutNumber("Superstructure/Shoulder", shoulder.getAngle());
}

void Robot::DisabledInit() {
  Robot::trunk.manualControl(0);
  Robot::foot.controlManual(0);
}

void Robot::DisabledPeriodic() { 
  frc::Scheduler::GetInstance()->Run(); 
}

void Robot::AutonomousInit() {

}

void Robot::AutonomousPeriodic() { 
  frc::Scheduler::GetInstance()->Run(); 
}

void Robot::TeleopInit() {
  trunk.gotoPositionMM(0);
}

void Robot::TeleopPeriodic() { 
  frc::Scheduler::GetInstance()->Run(); 

  auto& joystick1 = oi.getJoystick1();
  auto& joystick2 = oi.getJoystick2();
  auto& joystick3 = oi.getJoystick3();

  if(joystick3.GetRawButton(2) == false) {
    if (joystick3.GetRawButton(12) == false) {
      ballfloorintake.manual(1);
    } else {
      ballfloorintake.manual(0);
    }
  } else {
    ballfloorintake.manual(-1);
  }

  if (joystick2.GetRawButton(1) == true) {
      hand.manual(0.4);
  } else if (joystick1.GetRawButton(2) == true) {
      hand.manual(-0.7);
  } else {
    hand.manual(0);
  }
  if (joystick3.GetRawButton(10) == true) { //cargo mode
    if (joystick2.GetRawButton(7) == true && oi.joystickButtonLast(oi.joystickNum::joy2, 7) == false) {
      frc::Command* commandToBeExecuted = new SuperstructureControl(iona::Superstructure::cargoBhigh);
      commandToBeExecuted->Start();
    }
    if (joystick2.GetRawButton(8) == true && oi.joystickButtonLast(oi.joystickNum::joy2, 8) == false) {
      frc::Command* commandToBeExecuted = new SuperstructureControl(iona::Superstructure::cargoAhigh);
      commandToBeExecuted->Start();
    }
    if (joystick2.GetRawButton(9) == true && oi.joystickButtonLast(oi.joystickNum::joy2, 9) == false) {
      frc::Command* commandToBeExecuted = new SuperstructureControl(iona::Superstructure::cargoBmedium);
      commandToBeExecuted->Start();
    }
    if (joystick2.GetRawButton(10) == true && oi.joystickButtonLast(oi.joystickNum::joy2, 10) == false) {
      frc::Command* commandToBeExecuted = new SuperstructureControl(iona::Superstructure::cargoAmedium);
      commandToBeExecuted->Start();
    }
    if (joystick2.GetRawButton(11) == true && oi.joystickButtonLast(oi.joystickNum::joy2, 11) == false) {
      frc::Command* commandToBeExecuted = new SuperstructureControl(iona::Superstructure::cargoBlow);
      commandToBeExecuted->Start();
    }
    if (joystick2.GetRawButton(12) == true && oi.joystickButtonLast(oi.joystickNum::joy2, 12) == false) {
      frc::Command* commandToBeExecuted = new SuperstructureControl(iona::Superstructure::cargoAlow);
      commandToBeExecuted->Start();
    }
    if (joystick3.GetRawButton(3) == true && oi.joystickButtonLast(oi.joystickNum::joy3, 3) == false) {
      frc::Command* commandToBeExecuted = new SuperstructureControl(iona::Superstructure::idle);
      commandToBeExecuted->Start();
    }
    if (joystick3.GetRawButton(4) == true && oi.joystickButtonLast(oi.joystickNum::joy3, 4) == false) {
      frc::Command* commandToBeExecuted = new SuperstructureControl(iona::Superstructure::home);
      commandToBeExecuted->Start();
    }
    if (joystick3.GetRawButton(7) == true && oi.joystickButtonLast(oi.joystickNum::joy3, 7) == false) {
      frc::Command* commandToBeExecuted = new SuperstructureControl(iona::Superstructure::cargoBtop);
      commandToBeExecuted->Start();
    }
    if (joystick3.GetRawButton(8) == true && oi.joystickButtonLast(oi.joystickNum::joy3, 8) == false) {
      frc::Command* commandToBeExecuted = new SuperstructureControl(iona::Superstructure::cargoAtop);
      commandToBeExecuted->Start();
    }
  } else { //hatch mode
    if (joystick3.GetRawButton(3) == true && oi.joystickButtonLast(oi.joystickNum::joy3, 3) == false) {
      frc::Command* commandToBeExecuted = new SuperstructureControl(iona::Superstructure::hatchintake);
      commandToBeExecuted->Start();
    }
    if (joystick2.GetRawButton(7) == true && oi.joystickButtonLast(oi.joystickNum::joy2, 7) == false) {
      frc::Command* commandToBeExecuted = new SuperstructureControl(iona::Superstructure::hatchBTop);
      commandToBeExecuted->Start();
    }
    if (joystick2.GetRawButton(8) == true && oi.joystickButtonLast(oi.joystickNum::joy2, 8) == false) {
      frc::Command* commandToBeExecuted = new SuperstructureControl(iona::Superstructure::hatchATop);
      commandToBeExecuted->Start();
    }
    if (joystick2.GetRawButton(9) == true && oi.joystickButtonLast(oi.joystickNum::joy2, 9) == false) {
      frc::Command* commandToBeExecuted = new SuperstructureControl(iona::Superstructure::hatchBMiddle);
      commandToBeExecuted->Start();
    }
    if (joystick2.GetRawButton(10) == true && oi.joystickButtonLast(oi.joystickNum::joy2, 10) == false) {
      frc::Command* commandToBeExecuted = new SuperstructureControl(iona::Superstructure::hatchAMiddle);
      commandToBeExecuted->Start();
    }
    if (joystick2.GetRawButton(11) == true && oi.joystickButtonLast(oi.joystickNum::joy2, 11) == false) {
      frc::Command* commandToBeExecuted = new SuperstructureControl(iona::Superstructure::hatchBbottom);
      commandToBeExecuted->Start();
    }
    if (joystick2.GetRawButton(12) == true && oi.joystickButtonLast(oi.joystickNum::joy2, 12) == false) {
      frc::Command* commandToBeExecuted = new SuperstructureControl(iona::Superstructure::hatchAbottom);
      commandToBeExecuted->Start();
    }
    if (joystick3.GetRawButton(4) == true && oi.joystickButtonLast(oi.joystickNum::joy3, 4) == false) {
      frc::Command* commandToBeExecuted = new SuperstructureControl(iona::Superstructure::home);
      commandToBeExecuted->Start();
    }
  }
  


  //update buttons
  oi.UpdateButtons();

  //update data from subsystems
  foot.UpdateData();
  elevator.UpdateData();
  shoulder.UpdateData();
  wrist.UpdateData();
  
}

void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
