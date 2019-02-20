/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/manualDrive.h"
#include "Robot.h"
#include "frc/smartdashboard/SmartDashboard.h"

manualDrive::manualDrive() {
  // Use Requires() here to declare subsystem dependencies
  Requires(&Robot::drivetrain);
}

// Called just before this Command runs the first time
void manualDrive::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void manualDrive::Execute() {

  //Get the joystick
  auto& joystick = Robot::oi.getJoystick1();

  frc::SmartDashboard::PutBoolean("TapeDetected", Robot::vision.getTapeDetected());
  frc::SmartDashboard::PutNumber("TapeYaw", Robot::vision.getTapeYaw());
  //check if we want to vision align and there is a target
  if (joystick.GetRawButton(2) == true && Robot::vision.getTapeDetected()) {

    //driver wants to vision align
    frc::SmartDashboard::PutString("Drive Mode", "Vision Target");

    //get yaw then map it to rotation output
    double inputYaw = Robot::vision.getTapeYaw();
    double TurnValue = 0;
    if (inputYaw > 0) {
      //if yaw is positive do positive map
      TurnValue = Map(inputYaw, 0 , 20, 0.3, 0.5);
    } else {
      //if yaw is negative do negative yaw
      TurnValue = Map(inputYaw, 0 , -20, -0.4, -0.5);
    }

    //put into drive output

    Robot::drivetrain.driveArcade(-joystick.GetY(), TurnValue);
    if (joystick.GetRawAxis(3) > 0 ) {
      Robot::drivetrain.driveArcade(joystick.GetY(), TurnValue);
      Robot::vision.SetCamera(1);
    } else {
      Robot::drivetrain.driveArcade(-joystick.GetY(), TurnValue);
      Robot::vision.SetCamera(0);
    }

    frc::SmartDashboard::PutNumber("Turn Value", TurnValue);
  } else {
    frc::SmartDashboard::PutString("Drive Mode", "Normal Drive");
    double rotation = 0;
    if (!joystick.GetRawButton(1) == true) {
      rotation = joystick.GetZ()*0.6;
    } else {
      rotation = joystick.GetZ();
    }
    if (joystick.GetRawAxis(3) > 0 ) {
      Robot::drivetrain.driveCurvature(joystick.GetY(),rotation, !joystick.GetRawButton(1));
      Robot::vision.SetCamera(1);
    } else {
      Robot::drivetrain.driveCurvature(-joystick.GetY(),rotation, !joystick.GetRawButton(1));
      Robot::vision.SetCamera(0);
    }
  }
}

// Make this return true when this Command no longer needs to run execute()
bool manualDrive::IsFinished() { return false; }

// Called once after isFinished returns true
void manualDrive::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void manualDrive::Interrupted() {}
