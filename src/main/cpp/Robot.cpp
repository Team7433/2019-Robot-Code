/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Robot.h"

#include <frc/commands/Scheduler.h>
#include <frc/smartdashboard/SmartDashboard.h>

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

void Robot::RobotPeriodic() {
  
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

}

void Robot::TeleopPeriodic() { 
  frc::Scheduler::GetInstance()->Run(); 

  auto& joystick1 = oi.getJoystick1();
  auto& joystick2 = oi.getJoystick2();
  auto& joystick3 = oi.getJoystick3();

  if (joystick3.GetRawButton(12) == false) {
    ballfloorintake.manual(1);
  } else if (joystick1.GetRawButton(6) == true) {
    ballfloorintake.manual(-1);
  } else {
    ballfloorintake.manual(0);
  }

  if (joystick2.GetRawButton(1) == true) {
      hand.manual(0.2);
  } else if (joystick2.GetRawButton(2) == true) {
      hand.manual(-0.7);
  } else {
    hand.manual(0);
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
