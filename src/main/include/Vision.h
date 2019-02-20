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

double Map(double x, double in_min, double in_max, double out_min, double out_max);

class Vision {
  public:
    Vision();

    //set up a mode system for vision
    enum visionMode { Driver, Tape };
    void SetVisionMode(visionMode Mode);
    int getVisionMode();

    //get values from vision output
    double getTapeYaw();
    double getHatchYaw();
    double getTapeLeftYaw();
    double getTapeRightYaw();

    //get if something is detected
    bool getHatchDetected();
    bool getTapeDetected();

    void SetCamera(int camera);

    int m_VisionSide = 0;
  private:
    std::shared_ptr<NetworkTable> visionTable;
    //Store current vision mode
    visionMode m_currentMode;
};
