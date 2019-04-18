/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

//Header File
#include "subsystems/Drivetrain.h"

//constants
#include "subsystems/constants.h"

//WPI Librarys
#include <frc/Notifier.h>
#include <frc/smartdashboard/SmartDashboard.h>

//Motor Controler Libray
#include "ctre/Phoenix.h"

//C++ Librarys
#include <iostream>
#include <fstream>

//Default Command
#include "commands/manualDrive.h"

Drivetrain::Drivetrain() : Subsystem("DriveTrain"), m_notifier(&Drivetrain::MPPeriodicTask, this) {
  //Initialisation Code

  m_LeftMaster->ConfigFactoryDefault();
  m_RightMaster->ConfigFactoryDefault();

  //Make the slave Talons follow the Master Talons
  //m_LeftSlave->Follow(*m_LeftMaster);
  //m_RightSlave->Follow(*m_RightMaster);

  //Add Motors To Dashboard
  AddChild("Left", m_LeftMaster);
  AddChild("Right", m_RightMaster);

  //Set Up Encoders
  m_LeftMaster->ConfigSelectedFeedbackSensor(FeedbackDevice::CTRE_MagEncoder_Relative, 0, kTimeoutMs);
  m_RightMaster->ConfigSelectedFeedbackSensor(FeedbackDevice::CTRE_MagEncoder_Relative, 0, kTimeoutMs);

  //Reverse Encoder Output
  m_LeftMaster->SetSensorPhase(true);
  m_RightMaster->SetSensorPhase(true);

  //Set Mininum Output For Forward And Reverse
  /*m_LeftMaster->ConfigNominalOutputForward(0, kTimeoutMs);
  m_LeftMaster->ConfigNominalOutputReverse(0, kTimeoutMs);
  m_RightMaster->ConfigNominalOutputForward(0, kTimeoutMs);
  m_RightMaster->ConfigNominalOutputReverse(0, kTimeoutMs);

  //Set Maximum Output Fot Forward And Reverse
  m_LeftMaster->ConfigPeakOutputForward(1, kTimeoutMs);
  m_LeftMaster->ConfigPeakOutputReverse(-1, kTimeoutMs);
  m_RightMaster->ConfigPeakOutputForward(1, kTimeoutMs);
  m_RightMaster->ConfigPeakOutputReverse(-1, kTimeoutMs);
  */

  //Set K
  m_LeftMaster->Config_kP(kSlotIdx, talon_kp, kTimeoutMs);
  m_RightMaster->Config_kP(kSlotIdx, talon_kp, kTimeoutMs);

  //Set I
  m_LeftMaster->Config_kI(kSlotIdx, talon_ki, kTimeoutMs);
  m_RightMaster->Config_kI(kSlotIdx, talon_ki, kTimeoutMs);

  //Set D
  m_LeftMaster->Config_kD(kSlotIdx, talon_kd, kTimeoutMs);
  m_RightMaster->Config_kD(kSlotIdx, talon_kd, kTimeoutMs);

  //Set F
  m_LeftMaster->Config_kF(kSlotIdx, talon_kf, kTimeoutMs);
  m_RightMaster->Config_kF(kSlotIdx, talon_kf, kTimeoutMs);

  m_LeftMaster->ChangeMotionControlFramePeriod(5);
  m_RightMaster->ChangeMotionControlFramePeriod(5);

  m_RobotDrive.SetSafetyEnabled(false);

  //m_LeftMaster->ConfigNeutralDeadband(0.01, kTimeoutMs);
  //m_RightMaster->ConfigNeutralDeadband(0.01, kTimeoutMs);

  m_LeftMaster->SetStatusFramePeriod(StatusFrameEnhanced::Status_10_MotionMagic,10,kTimeoutMs);
  m_RightMaster->SetStatusFramePeriod(StatusFrameEnhanced::Status_10_MotionMagic,10,kTimeoutMs);


  //current limit
  m_LeftMaster->ConfigPeakCurrentLimit(45, kTimeoutMs);
  m_LeftMaster->ConfigPeakCurrentDuration(500, kTimeoutMs); /* this is a necessary call to avoid errata. */
  m_LeftMaster->ConfigContinuousCurrentLimit(40, kTimeoutMs);
  m_LeftMaster->EnableCurrentLimit(true); /* honor initial setting */

  m_RightMaster->ConfigPeakCurrentLimit(45, kTimeoutMs);
  m_RightMaster->ConfigPeakCurrentDuration(500, kTimeoutMs); /* this is a necessary call to avoid errata. */
  m_RightMaster->ConfigContinuousCurrentLimit(40, kTimeoutMs);
  m_RightMaster->EnableCurrentLimit(true); /* honor initial setting */
}

void Drivetrain::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  SetDefaultCommand(new manualDrive());
}

//Arcade Drive
void Drivetrain::DriveArcade(double forward, double rotation) {
  m_RobotDrive.ArcadeDrive(forward, rotation);
}

//Tank Drive
void Drivetrain::DriveTank(double left, double right) {
  m_RobotDrive.TankDrive(left, right);
}

//Arcade Drive
void Drivetrain::DriveCurvature(double forward, double curve, bool isQuickTurn) {
  m_RobotDrive.CurvatureDrive(forward, curve, isQuickTurn);
}

//Reset Left Encoder
void Drivetrain::resetLeftEncoder() {
  m_LeftMaster->SetSelectedSensorPosition(0, 0,kTimeoutMs);
}

//Reset Right Encoder
void Drivetrain::resetRightEncoder() {
  m_RightMaster->SetSelectedSensorPosition(0, 0,kTimeoutMs);
}

void Drivetrain::ResetMP() {
  printf("MP Reset \n");
  //clear Trajectories
  m_LeftMaster->ClearMotionProfileTrajectories();
  m_RightMaster->ClearMotionProfileTrajectories();

  //reset Varibles
  _state = 0;
  _loopTimeout = -1;
  _bstart = false;
  _setValueLeft = SetValueMotionProfile::Disable;
  _setValueRight = SetValueMotionProfile::Disable;
  m_loadedPath = "null";

  //Set Output to nothing
  m_LeftMaster->Set(ControlMode::PercentOutput, 0.0);
  m_RightMaster->Set(ControlMode::PercentOutput, 0.0);
}

//The Part of the code has been based of an example and does not fit our needs exactly and could be written better
void Drivetrain::MPControl() {
  //Set to motion profile in disabled mode
  m_LeftMaster->Set(ControlMode::MotionProfile, _setValueLeft);
  m_RightMaster->Set(ControlMode::MotionProfile, _setValueRight);

  //Make Sure we never get stuck
  if (_loopTimeout < 0) {
    //All Good do nothing
  } else {
    if (_loopTimeout == 0) {
      //Something is wrong
    } else {
      --_loopTimeout;
    }
  }


  if (m_LeftMaster->GetControlMode() != ControlMode::MotionProfile) {
    //If for some Reason we are not in Motion Control Mode Don't do much
    printf("ERROR: Not in Motion Profile Control Mode");
    _state = 0;
    _loopTimeout = -1;

  } else {
    //We are in motion profile control mode
    switch (_state) {
      case 0:
        if (_bstart) {
          printf("BStart = true \n");
          //Set _bstart to false so we don't continously call this code
          _bstart = false;

          //Set Motion Profile To Disable
          _setValueLeft = SetValueMotionProfile::Disable;
          _setValueRight = SetValueMotionProfile::Disable;

          if (m_MpPathId != m_loadedPath) {
             m_notifier.StartPeriodic(0.005);
            //Start filling the profile 
            StartFilling(m_MpPathId);
          }

          //Start the notifier
          //m_notifier.StartPeriodic(0.005);


          _state = 1; //Set The state To the next case statement for the next loop 
          _loopTimeout = KNumLoopsTimeout;  //Sets a amount of loops for the profiler to timeout
        }
        break;
      case 1:
        //printf("Case 1 \n");
        //Waiting for enough points in talon to start the profile

        //Checks if the buffer count from the end of last run is enough to start the profile
        if((_statusLeft.btmBufferCnt > KMinPointsInTalon) && (_statusRight.btmBufferCnt > KMinPointsInTalon)) {

          //Start (once) the motion profile 
          _setValueLeft = SetValueMotionProfile::Enable;
          _setValueRight = SetValueMotionProfile::Enable;

          _state = 2; //Set The State to Continue To the next phase
          _loopTimeout =  KNumLoopsTimeout; //Sets a amount of loops for the profiler to timeout
        }
        break;
      case 2:
        printf("Case 2 \n");
        //This is called while the profile is being run

        if ((_statusLeft.isUnderrun == false) | (_statusRight.isUnderrun == false)) {
          _loopTimeout = KNumLoopsTimeout; //Sets a amount of loops for the profiler to timeout

        } else {
          // loop Timeout has not been reset and would have been decreased
          printf("Has Underrun");
        }

        if (_statusLeft.activePointValid &&_statusLeft.isLast)  {
          _setValueLeft = SetValueMotionProfile::Hold;
          _setValueRight = SetValueMotionProfile::Hold;
          _state = 3;
          _loopTimeout = -1;
          m_notifier.Stop();
          m_loadedPath = "null";
        }
        break;
    }

    //Get The Statis from the talon about the motio profile every loop
    m_LeftMaster->GetMotionProfileStatus(_statusLeft);
    m_RightMaster->GetMotionProfileStatus(_statusRight);

  }
}

void Drivetrain::StartFilling(std::string path) {
  m_loadedPath = path;
  printf("Start Filling \n");

  //Creates points to store the data for each point
  TrajectoryPoint pointLeft;
  TrajectoryPoint pointRight;

  //Check if we underrun then tell us (IDK why we do this)
  if (_statusLeft.hasUnderrun)  {

    m_LeftMaster->ClearMotionProfileHasUnderrun(kTimeoutMs);
    m_RightMaster->ClearMotionProfileHasUnderrun(kTimeoutMs);
  }

  //Clear Trajectorys that might have acidentally stayed in the talon
  m_LeftMaster->ClearMotionProfileTrajectories();
  m_RightMaster->ClearMotionProfileTrajectories();

  //Sets Base trjectory Perod
  m_LeftMaster->ConfigMotionProfileTrajectoryPeriod(0, kTimeoutMs);
  m_RightMaster->ConfigMotionProfileTrajectoryPeriod(0, kTimeoutMs);

  //Read Profile From File

  //Find The length of the profile
  int profileLength = 0;
  std::string line;
  std::ifstream profileforlength("home/lvuser/Profiles/" + m_loadedPath + ".csv");
  if (profileforlength.is_open()) {
    //std::cout << "Found File" << "\n";
    while (getline(profileforlength, line)) {
      profileLength++;
    }
    printf("Profile Length: %i \n", profileLength);
    profileforlength.close();
  }
  std::ifstream myfile ("home/lvuser/Profiles/" + m_loadedPath + ".csv");
  if (myfile.is_open()) {
    int i =0;
    while (getline (myfile, line)) {        //Repeat through each line in the code and set the varible line to the current line
      int dataPoints = 7;                   //The Ammout of data points in a line
      double lineData [dataPoints];         //Array with the data points in it
      //bool endOfLine = false;             //I don't think this is used so i commened it out
      std::string shortenedLine = line;           //Set the String that we will iterate though to the line from the file
      for (int c =0; c < dataPoints; c++) { //Repeat though all of the data points in the line and save them to the array
        //Find the first Comma (This is after the current data point)
        int comma_first = shortenedLine.find(',');

        //Using the point in the sting the comma is at get a sub string of the current data point in string form
        std::string dataPoint_str = shortenedLine.substr(0, comma_first);

        //Convert the sting to a double
        double dataPoint = std::stod(dataPoint_str);

        //Add this to the array corosponding to where it was in the line
        lineData [c] = dataPoint;

        //Shorten the string taking out the data point we just got and the comma
        shortenedLine = shortenedLine.substr(comma_first+1, shortenedLine.length()-comma_first-1);
      };

      //Grab data from the array
      double positionRotLeft  = lineData[0];
      double VelocityRPMLeft  = lineData[1];
      double positionRotRight  = lineData[2];
      double VelocityRPMRight  = lineData[3];

      //Print Where we are up to in the sending (This could probably be at the top of the loop)
      printf("Sending point %i of %i\n", i, profileLength);
      frc::SmartDashboard::PutNumber("Sent Point", i);

      //For each point, fill our structure and pass it to API
      pointLeft.position = positionRotLeft * 4096; //Covert Revolutions to Units
      pointLeft.velocity = VelocityRPMLeft * 4096 / 60; //Covert RPM to Units/100ms
      pointLeft.headingDeg = 0; //Furture feature Not Used
      pointLeft.profileSlotSelect0 = 0; //Idk
      pointLeft.profileSlotSelect1 = 0; //Furture feature Not Used
      pointLeft.timeDur = 20; //Set how long you want the talon to stay on this point in ms
      pointLeft.zeroPos = false;
      pointLeft.isLastPoint = false;

      pointRight.position = -positionRotRight * 4096; //Covert Revolutions to Units
      pointRight.velocity = -VelocityRPMRight * 4096 / 60; //Covert RPM to Units/100ms
      pointRight.headingDeg = 0; //Furture feature Not Used
      pointRight.profileSlotSelect0 = 0; //Idk
      pointRight.profileSlotSelect1 = 0; //Furture feature Not Used
      pointRight.timeDur = 20; //Set how long you want the talon to stay on this point in ms
      pointRight.zeroPos = false;
      pointRight.isLastPoint = false;

      if (i == 0) {
        //Set this true only on the first point
        pointLeft.zeroPos = true; 
        pointRight.zeroPos = true; 
      }

      //if last point set last point to true
      if ((i+1) == profileLength) {
        pointLeft.isLastPoint = true;
        pointRight.isLastPoint = true;
      }

      //Set The Points to the talon
      m_LeftMaster->PushMotionProfileTrajectory(pointLeft);
      m_RightMaster->PushMotionProfileTrajectory(pointRight);

      //Increment while loop
      i++;
    };
    myfile.close();
    
  }
}

void Drivetrain::StartMP(std::string Profile) {
  m_MpPathId = Profile;

  _state = 0;
  _bstart = true;
}

bool Drivetrain::IsFinishedMP() {
  if (_state == 3)  {
    return true;
  } else{
    return false;
  }
}

void Drivetrain::MPPeriodicTask() {

  //Move points from rio buffer to talon buffer
  m_LeftMaster->ProcessMotionProfileBuffer();
  m_RightMaster->ProcessMotionProfileBuffer();
}

void Drivetrain::StartPerioticTask() {
  m_notifier.StartPeriodic(0.005);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
