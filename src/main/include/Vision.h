/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <networktables/NetworkTable.h>
#include <networktables/NetworkTableInstance.h>
#include <frc/Servo.h>

class Vision {
  public:
    Vision();

    //set up a mode system for vision
    enum visionMode { Driver, Tape, Hatch };
    void SetVisionMode(visionMode Mode);
    visionMode getVisionMode();

    //get values from vision output
    double getTapeYaw();
    double getHatchYaw();
    double getTapeLeftYaw();
    double getTapeRightYaw();

    //get if something is detected
    bool getHatchDetected();
    bool getTapeDetected();
  private:
    visionMode currentMode;
};
