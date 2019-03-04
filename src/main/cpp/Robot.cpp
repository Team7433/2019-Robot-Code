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

void Robot::RobotPeriodic() {
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
  oi.DriveControl(); //Command Control
  oi.ShowSubsystems(); //Show Subsystem Data on dashboard
}

double Map(double x, double in_min, double in_max, double out_min, double out_max)  {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
