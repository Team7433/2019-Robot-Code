/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include "iostream"
#include "string"
#include "fstream"
#include <frc/commands/Command.h>

class Auto {
  public:
    Auto();

    //Setup and running of auto
    void SetRoutine(int routine);   //called in automous init
    void ExecuteRoutine();          //called in automous periotic
    
    void StartStep();
    void StartCommand(std::string Function, std::string parameters[], int paramSize);

    int GetRoutineId();


    //void SetupSmartDahboard();
  private:
    int m_routineId;
    int m_routineLength;
    bool m_isRunningAuto = false;
    bool m_Error = false;
    bool m_debug = false;
    std::string * RoutineArray = nullptr;

    frc::Command * m_command = nullptr;

    bool CommandRunning = false;

    int currentStep = 0;
    bool m_startedStep = false;

};
