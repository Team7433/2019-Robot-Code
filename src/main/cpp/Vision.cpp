/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Vision.h"
#include <frc/smartdashboard/SmartDashboard.h>

//This is for all raspberry pi interfacing and vision control
Vision::Vision() {
    visionTable = nt::NetworkTableInstance::GetDefault().GetTable("ChickenVision");
}

void Vision::SetVisionMode(visionMode mode) {
    m_currentMode =  mode;
    switch (mode)
    {
        case Driver:
            visionTable->PutBoolean("Driver", true);
            frc::SmartDashboard::PutString("VisionMode", "Driver");
            break;
        case Tape:
            visionTable->PutBoolean("Driver", false);
            visionTable->PutBoolean("Tape", true);
            frc::SmartDashboard::PutString("VisionMode", "Tape");
            break;
        case Hatch:
            visionTable->PutBoolean("Driver", false);
            visionTable->PutBoolean("Tape", false);
            frc::SmartDashboard::PutString("VisionMode", "Hatch");
            break;
    
        default:
            frc::SmartDashboard::PutString("VisionMode", "Error: set to defult");
            break;
    }
}

int Vision::getVisionMode() {
    return m_currentMode;
}

bool Vision::getHatchDetected() {
    return visionTable->GetBoolean("HatchDetected", false);
}

bool Vision::getTapeDetected() {
    return visionTable->GetBoolean("TapeDetected", false);
}

double Vision::getHatchYaw() {
    return visionTable->GetNumber("hatchYaw", 0.0);
}

double Vision::getTapeYaw() {
    return visionTable->GetNumber("tapeYaw", 0.0);
}

double Vision::getTapeLeftYaw(){
    return visionTable->GetNumber("tapeLeftYaw", 0.0);
}

double Vision::getTapeRightYaw() {
    return visionTable->GetNumber("tapeRightYaw", 0.0);
}