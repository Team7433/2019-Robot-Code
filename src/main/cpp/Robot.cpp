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

void Robot::RobotInit() {

}

void Robot::RobotPeriodic() {
  
}

void Robot::DisabledInit() {
  Robot::trunk.manualControl(0);
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

  //update data from subsystems
  foot.UpdateData();
}

void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
