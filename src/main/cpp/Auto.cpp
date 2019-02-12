/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Auto.h"
#include <frc/smartdashboard/SmartDashboard.h>
#include "Robot.h"

//commands
#include "commands/autostuff/CountTest.h"
#include "commands/autostuff/OtherCommand.h"

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
    m_isRunningAuto = true;
    
}

void Auto::ExecuteRoutine() {
    try
    {
        frc::SmartDashboard::PutNumber("Current Step", currentStep);
        if (m_isRunningAuto == false) {
            std::cout << "Running Auto is false\n";
            return;
        }
        std::cout << "m_startedStep = " << m_startedStep << "\n";
        if (m_startedStep == false) {
            std::cout << "Not started step" << "\n";
            StartStep();
        }
        if (m_command->IsCompleted() == true) {
            currentStep++;
            m_startedStep = false;
            m_command = nullptr;
        }
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
}

void Auto::StartStep() {
    if (currentStep >= m_routineLength) {
        m_isRunningAuto = false;
        return;
    }
    std::string StepFunction = RoutineArray[currentStep];
    int OpenBracketPos = StepFunction.find('(');
    int ClosedBracketPos = StepFunction.find(')');
    std::string functionName = StepFunction.substr(0, OpenBracketPos);
    std::string parametersStr = StepFunction.substr(OpenBracketPos+1, ClosedBracketPos-OpenBracketPos-1);
    std::string LineRemainder = parametersStr;
    int NumberOfParameters = 1;
    while (LineRemainder.find(',') != std::string::npos) {
        int commaPos = LineRemainder.find(',');
        LineRemainder = LineRemainder.substr(commaPos+1, std::string::npos);
        NumberOfParameters++;
    }
    std::string parameters[NumberOfParameters];
    LineRemainder = parametersStr;
    for (int i = 0; i < NumberOfParameters; i++) {
        int colinPos = LineRemainder.find(',');
        parameters[i] = LineRemainder.substr(0, colinPos);
        //std::cout << "Line Length" << LineRemainder.length() << "Maths:" << colinPos+1 + LineRemainder.length()-colinPos-2 << "\n";
        LineRemainder = LineRemainder.substr(colinPos+1, std::string::npos);
    }
    StartCommand(functionName, parameters, NumberOfParameters);
    if (m_command != nullptr) {
        m_startedStep = true;
        m_command->Start();
        frc::SmartDashboard::PutString("Auto Status", "Started");
    } else {
        std::cout << "No Command Selected";
        frc::SmartDashboard::PutString("Auto Status", "Error");
    }
}

void Auto::StartCommand(std::string FunctionName, std::string parameters[], int paramSize) {
    if (FunctionName == "CountTest") {
        std::cout << "Function = CountTest(" << parameters[0] <<") \n";
        m_command = new CountTest(std::stoi(parameters[0]));
    } else if (FunctionName == "OtherCommand") {
        std::cout << "Function = OtherCommand() \n";
        m_command = new OtherCommand();
    } else {
        std::cout << "Function Name Not recognised: FunctionName = " << FunctionName;
    }
}