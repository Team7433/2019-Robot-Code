/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Robot.h"

#include <frc/commands/Scheduler.h>
#include <frc/smartdashboard/SmartDashboard.h>
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
  std::cout << "Hi" << "\n";
}

void Robot::TeleopPeriodic() { 
  frc::Scheduler::GetInstance()->Run(); 

  //get joystick objects from oi
  auto& joystick1 = oi.getJoystick1();
  auto& joystick2 = oi.getJoystick2();
  auto& joystick3 = oi.getJoystick3();

  //floor intake controls
  if(joystick2.GetY() > 0.03 || joystick2.GetY() < -0.03) {
    ballfloorintake.manual(-joystick2.GetX());
  } else {
    if(joystick3.GetRawButton(2) == false) {
      if (joystick3.GetRawButton(12) == false) {
        ballfloorintake.manual(1);
      } else {
        ballfloorintake.manual(0);
      }
    } else {
      //ballfloorintake.manual(-1);
    }
  }

  /*if (joystick2.GetY() > 0.5 || joystick2.GetY() < -0.5) {
    ballfloorwrist.manualcontrol(-joystick2.GetY()*0.8);
  } else {
    ballfloorwrist.manualcontrol(0);
  }*/

  //hand controls
  if (joystick2.GetRawButton(1) == true) {
      hand.manual(0.4);
  } else if (joystick1.GetRawButton(4) == true) {
      hand.manual(-0.7);
  } else {
    hand.manual(0);
  }

  //superstructure controls
  if (joystick3.GetRawButton(10) == true) { //cargo mode
    if (oi.getPow3(1) == true && oi.getPow3Last(1) == false) {
      frc::Command* commandToBeExecuted = new SuperstructureControl(iona::Superstructure::cargoAhigh);
      commandToBeExecuted->Start();
    }
    if (joystick3.GetRawButton(9) == true && oi.joystickButtonLast(oi.joystickNum::joy3, 9) == false) {
      frc::Command* commandToBeExecuted = new SuperstructureControl(iona::Superstructure::cargoBhigh);
      commandToBeExecuted->Start();
    }
    if (joystick3.GetRawButton(6) == true && oi.joystickButtonLast(oi.joystickNum::joy3, 6) == false) {
      frc::Command* commandToBeExecuted = new SuperstructureControl(iona::Superstructure::cargoAmedium);
      commandToBeExecuted->Start();
    }
    if (joystick3.GetRawButton(5) == true && oi.joystickButtonLast(oi.joystickNum::joy3, 5) == false) {
      frc::Command* commandToBeExecuted = new SuperstructureControl(iona::Superstructure::cargoBmedium);
      commandToBeExecuted->Start();
    }
    if (joystick3.GetRawButton(2) == true && oi.joystickButtonLast(oi.joystickNum::joy3, 2) == false) {
      frc::Command* commandToBeExecuted = new SuperstructureControl(iona::Superstructure::cargoAlow);
      commandToBeExecuted->Start();
    }
    if (joystick3.GetRawButton(1) == true && oi.joystickButtonLast(oi.joystickNum::joy3, 1) == false) {
      frc::Command* commandToBeExecuted = new SuperstructureControl(iona::Superstructure::cargoBlow);
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
      frc::Command* commandToBeExecuted = new SuperstructureControl(iona::Superstructure::cargoAtop);
      commandToBeExecuted->Start();
    }
    if (joystick3.GetRawButton(8) == true && oi.joystickButtonLast(oi.joystickNum::joy3, 8) == false) {
      frc::Command* commandToBeExecuted = new SuperstructureControl(iona::Superstructure::cargoBtop);
      commandToBeExecuted->Start();
    }
  } else { //hatch mode
    if (joystick3.GetRawButton(3) == true && oi.joystickButtonLast(oi.joystickNum::joy3, 3) == false) {
      frc::Command* commandToBeExecuted = new SuperstructureControl(iona::Superstructure::hatchintake);
      commandToBeExecuted->Start();
    }
    if (oi.getPow3(1) == true && oi.getPow3Last(1) == false) {
      frc::Command* commandToBeExecuted = new SuperstructureControl(iona::Superstructure::hatchATop);
      commandToBeExecuted->Start();
    }
    if (joystick3.GetRawButton(9) == true && oi.joystickButtonLast(oi.joystickNum::joy3, 9) == false) {
      frc::Command* commandToBeExecuted = new SuperstructureControl(iona::Superstructure::hatchBTop);
      commandToBeExecuted->Start();
    }
    if (joystick3.GetRawButton(6) == true && oi.joystickButtonLast(oi.joystickNum::joy3, 6) == false) {
      frc::Command* commandToBeExecuted = new SuperstructureControl(iona::Superstructure::hatchAMiddle);
      commandToBeExecuted->Start();
    }
    if (joystick3.GetRawButton(5) == true && oi.joystickButtonLast(oi.joystickNum::joy3, 5) == false) {
      frc::Command* commandToBeExecuted = new SuperstructureControl(iona::Superstructure::hatchBMiddle);
      commandToBeExecuted->Start();
    }
    if (joystick3.GetRawButton(2) == true && oi.joystickButtonLast(oi.joystickNum::joy3, 2) == false) {
      frc::Command* commandToBeExecuted = new SuperstructureControl(iona::Superstructure::hatchAbottom);
      commandToBeExecuted->Start();
    }
    if (joystick3.GetRawButton(1) == true && oi.joystickButtonLast(oi.joystickNum::joy3, 1) == false) {
      frc::Command* commandToBeExecuted = new SuperstructureControl(iona::Superstructure::hatchBbottom);
      commandToBeExecuted->Start();
    }
    if (joystick3.GetRawButton(4) == true && oi.joystickButtonLast(oi.joystickNum::joy3, 4) == false) {
      frc::Command* commandToBeExecuted = new SuperstructureControl(iona::Superstructure::home);
      commandToBeExecuted->Start();
    }
  }
  if (oi.getPow3(2) == true && oi.getPow3Last(2) == false) {
    frc::Command* commandToBeExecuted = new SuperstructureControl(iona::Superstructure::climb);
    commandToBeExecuted->Start();
  }
  //if (joystick2.GetRawButton(7) == true && oi.joystickButtonLast(oi.joystickNum::joy2, 7) == false) {
  //  frc::Command* commandToBeExecuted = new SuperstructureControl(iona::Superstructure::autostep1);
  //  commandToBeExecuted->Start();
  //}

  //update buttons
  oi.UpdateButtons();
  oi.UpdatePOV();


  //update data from subsystems
  foot.UpdateData();
  elevator.UpdateData();
  shoulder.UpdateData();
  wrist.UpdateData();
  trunk.UpdateData();
  
}

double Map(double x, double in_min, double in_max, double out_min, double out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
