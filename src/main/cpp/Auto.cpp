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

    //Get routineline from document
    std::string Routineline;
    std::string line;
    std::ifstream AutoRoutines("U/AutoRoutines.txt");
    if (AutoRoutines.is_open()) {
        int i = 1;
        while (getline(AutoRoutines, line)) {
            if (m_debug == true) {std::cout << "i: " << i << "\t Routine" << routine << "\n";}
            if (i == routine) { Routineline = line; break;}
            i++;     
        }
        AutoRoutines.close();
    }
    std::cout << "Routine Line: " << Routineline << "\n";

    //Find how many commands there are in the array
    int routineLength = 0;
    std::string LineRemainder = Routineline;
    while (LineRemainder.find(';') != std::string::npos) {
        int colinPos = LineRemainder.find(';');
        if (m_debug == true) {std::cout << "remaineder: \t" << LineRemainder << " Colin Pos: " << colinPos << "\n";}
        LineRemainder = LineRemainder.substr(colinPos+1, std::string::npos);
        routineLength++;
    }
    m_routineLength = routineLength;
    std::cout << "Routine Length:" << routineLength << "\n";

    //initalise global array to store thease items in
    RoutineArray = new std::string[routineLength];

    //reset lineremainer without routine number at the start
    int LineNumberColin = Routineline.find(':');
    LineRemainder = Routineline.substr(LineNumberColin+1, std::string::npos);

    //Fill the array of commmands
    for (int i = 0; i < routineLength; i++) {
        int colinPos = LineRemainder.find(';');
        RoutineArray[i] = LineRemainder.substr(0, colinPos);
        //std::cout << "Line Length" << LineRemainder.length() << "Maths:" << colinPos+1 + LineRemainder.length()-colinPos-2 << "\n";
        LineRemainder = LineRemainder.substr(colinPos+1, std::string::npos);
    }
    
    for(int i = 0; i < routineLength; i++) {
        std::cout << "Item" << i << ":" << RoutineArray[i] << "\n";
    }
    
}