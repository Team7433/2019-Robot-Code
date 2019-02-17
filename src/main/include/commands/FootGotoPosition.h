/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/Command.h>

class FootGotoPosition : public frc::Command {
  public:
    enum FootPosition {forward = -2750, start = 0, Back = 5600};
    FootGotoPosition(double position);
    FootGotoPosition(FootPosition position);
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;
    void Interrupted() override;
  private:
    double m_position;

};
