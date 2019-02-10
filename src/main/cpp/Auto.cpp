/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Auto.h"
#include <frc/smartdashboard/SmartDashboard.h>

Auto::Auto() {
    frc::SmartDashboard::PutNumber("Routine ID", 0);
    frc::SmartDashboard::PutString("Auto Status", "Not Running");
    frc::SmartDashboard::PutBoolean("Auto Error", false);
}

void Auto::SetRoutine(int routine) {
    m_routineId = routine;
    if (routine == 0) {
        std::cout << "Error: Not Auto Routine is selected";
        frc::SmartDashboard::PutString("Auto Status", "Error");
        frc::SmartDashboard::PutBoolean("Auto Error", true);
        m_Error = true;
        m_isRunningAuto = false;
        return;
    } 
    
    frc::SmartDashboard::PutString("Auto Status", "Selected");
    
}