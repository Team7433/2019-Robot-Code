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
#include "commands/Testing/AutoStart.h"
#include <iostream>
#include <fstream>

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
  chooser.SetDefaultOption("LLHP-FLR1", new AutoStart("LLHP-FLR1"));
  //chooser.AddOption("BCHP-FCC0", new AutoStart("BCHP-FCC0"));
  chooser.AddOption("BLHP-FLC1", new AutoStart("BLHP-FLC1"));
  chooser.AddOption("BCHP-FLC1", new AutoStart("BCHP-FLC1"));
  //chooser.AddOption("BLHP-FLR3", new AutoStart("BLHP-FLR3"));
  chooser.AddOption("BCHP-FLR3", new AutoStart("BCHP-FLR3"));
  //chooser.AddOption("FLC1-BLLS", new AutoStart("FLC1-BLLS"));
  chooser.AddOption("FLHP-FLR3", new AutoStart("FLHP-FLR3"));
  chooser.AddOption("BCHP-FLC0", new AutoStart("BCHP-FLC0"));
  //chooser.AddOption("BCHP-FL0", new AutoStart("FLHP-FLR3"));
  chooser.AddOption("BCHP-FRC0", new AutoStart("BCHP-FRC0"));
  frc::SmartDashboard::PutData("Auto Chooser", &chooser);
  oi.SetupPathChooser();
}

void Robot::RobotPeriodic() {
  frc::SmartDashboard::PutNumber("Superstructure/Elevator", -elevator.getPosition());
  frc::SmartDashboard::PutNumber("Superstructure/Wrist", wrist.GetAngle());
  frc::SmartDashboard::PutNumber("Superstructure/Shoulder", shoulder.getAngle());
  oi.UpdatePathChooser();
}

void Robot::DisabledInit() {
  Robot::trunk.manualControl(0);
  Robot::foot.controlManual(0);
}

void Robot::DisabledPeriodic() { 
  frc::Scheduler::GetInstance()->Run(); 
}

void Robot::AutonomousInit() {
  foot.gotoPosition(0);
 autonomousCommand.reset(chooser.GetSelected());
 if (autonomousCommand.get() != nullptr) {
   autonomousCommand->Start();
 }
}

void Robot::AutonomousPeriodic() { 
  frc::Scheduler::GetInstance()->Run(); 
  oi.DriveControl();
}

void Robot::TeleopInit() {
  trunk.gotoPositionMM(0);
  if (autonomousCommand != nullptr) {
    autonomousCommand->Cancel();
    autonomousCommand = nullptr;
  }
}

void Robot::TeleopPeriodic() { 
  frc::Scheduler::GetInstance()->Run(); 
  oi.DriveControl(); //Command Control
  oi.ShowSubsystems(); //Show Subsystem Data on dashboard
}

void Robot::TestPeriodic() {}

double Map(double x, double in_min, double in_max, double out_min, double out_max)  {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
