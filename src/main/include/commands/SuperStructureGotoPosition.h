/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/Command.h>
#include "positions.h"

class SuperStructureGotoPosition : public frc::Command {
  public:
    SuperStructureGotoPosition(iona::Superstructure position);
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;
    void Interrupted() override;
  private:
    iona::Superstructure m_position;
    double m_elevatorPos; 
    double m_wristPos; 
    double m_shoulderPos; 
};
