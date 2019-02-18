/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "OI.h"

#include <frc/WPILib.h>

#include "positions.h"

//commands
#include "commands/FootGotoPosition.h"
#include "commands/TrunkGotoPosition.h"
#include "commands/ResetTrunkPosition.h"
#include "commands/ResetFootEncoder.h"
#include "commands/shoulderGoToPosition.h"
#include "commands/resetElevatorPosition.h"
#include "commands/ElevatorGotoPosition.h"
#include "commands/wristGotoPosition.h"
#include "commands/ballintakeIn.h"
#include "commands/ballintakeOut.h"
#include "commands/SuperStructureGotoPosition.h"
#include "commands/EjectHatch.h"

//climb commands
#include "commands/climb/ClimbSetup.h"
#include "commands/climb/ClimbLift.h"
#include "commands/climb/ClimbFinish.h"
#include "commands/climb/ClimbReset.h"

//reset comands
#include "commands/resetShoulder.h"
#include "commands/resetWrist.h"
#include "commands/resetBallWrist.h"


OI::OI() {

  //Setup joystick buttons to commands
    //joystick 1
    //m_joystick1button1.WhenPressed(new command());
    //m_joystick1button2.WhenPressed(new resetWrist());
    m_joystick1button3.WhileHeld(new EjectHatch());
    //m_joystick2button4.WhenPressed(new ballintakeOut());
    //m_joystick1button5.WhenPressed(new resetBallWrist());
    //m_joystick1button6.WhenPressed(new resetWrist());
    m_joystick1button7.WhenPressed(new ClimbSetup());
    m_joystick1button8.WhenPressed(new ClimbLift());
    m_joystick1button9.WhenPressed(new ClimbFinish());
    m_joystick1button10.WhenPressed(new ClimbReset()); 
    //m_joystick1button11.WhenPressed(new SuperStructureGotoPosition(iona::Superstructure::cargoBhigh)); 
    //m_joystick1button12.WhenPressed(new shoulderGoToPosition(-20));

    //joystick 2
    //m_joystick2button1.WhenPressed(new command());
    //m_joystick2button2.WhenPressed(new command());
    m_joystick2button3.WhileHeld(new ballintakeIn());
    m_joystick2button4.WhileHeld(new ballintakeOut());
    //m_joystick2button5.WhileActive(new IntakeIn());
    //m_joystick2button6.WhileActive(new IntakeOut());
    /*m_joystick2button7.WhenPressed(new SuperStructureGotoPosition(iona::Superstructure::cargoBhigh));
    m_joystick2button8.WhenPressed(new SuperStructureGotoPosition(iona::Superstructure::cargoAhigh));
    m_joystick2button9.WhenPressed(new SuperStructureGotoPosition(iona::Superstructure::cargoBmedium));
    m_joystick2button10.WhenPressed(new SuperStructureGotoPosition(iona::Superstructure::cargoAmedium));
    m_joystick2button11.WhenPressed(new SuperStructureGotoPosition(iona::Superstructure::cargoBlow));
    m_joystick2button12.WhenPressed(new SuperStructureGotoPosition(iona::Superstructure::cargoAlow));
    */
    //joystick 3
    //m_joystick3button1.WhenPressed(new command());
    //m_joystick3button2.WhenPressed(new command());
    //m_joystick3button3.WhileHeld(new SuperStructureGotoPosition(iona::Superstructure::idle));
    //m_joystick3button4.WhenPressed(new SuperStructureGotoPosition(iona::Superstructure::home));
    //m_joystick3button5.WhileActive(new IntakeIn());
    //m_joystick3button6.WhileActive(new IntakeOut());
    //m_joystick3button7.WhenPressed(new SuperStructureGotoPosition(iona::Superstructure::cargoBtop));
    //m_joystick3button8.WhenPressed(new SuperStructureGotoPosition(iona::Superstructure::cargoAtop));
    //m_joystick3button9.WhenPressed(new command());
    //m_joystick3button10.WhenPressed(new ElevatorGotoPosition(-10000));
    //m_joystick3button11.WhenPressed(new command());
    //m_joystick3button12.WhenPressed(new ElevatorGotoPosition(-20000));
}

frc::Joystick& OI::getJoystick1() {
  return m_joy1;
}

frc::Joystick& OI::getJoystick2() {
  return m_joy2;
}

frc::Joystick& OI::getJoystick3() {
  return m_joy3;
}

void OI::UpdateButtons() {
  for(int i = 0; i < 12; i++) {
    buttonslast1[i] = m_joy1.GetRawButton(i+1);
  }
  for(int i = 0; i < 12; i++) {
    buttonslast2[i] = m_joy2.GetRawButton(i+1);
  }
  for(int i = 0; i < 12; i++) {
    buttonslast3[i] = m_joy3.GetRawButton(i+1);
  }

}

bool OI::joystickButtonLast(joystickNum joy,int button) {
  if (joy = joy1) {
    return buttonslast1[button-1];
  } else if (joy = joy2) {
    return buttonslast2[button-1];
  } else {
    return buttonslast3[button-1];
  }
}

bool OI::joystickButton(joystickNum joy,int button) {
  if (joy = joy1) {
    return m_joy1.GetRawButton(button);
  } else if  (joy = joy2) {
    return m_joy2.GetRawButton(button);
  } else {
    return m_joy3.GetRawButton(button);
  }
  
}

