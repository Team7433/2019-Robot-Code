/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "OI.h"

#include <frc/WPILib.h>

//commands
#include "commands/FootGotoPosition.h"
#include "commands/TrunkGotoPosition.h"
#include "commands/ResetTrunkPosition.h"
#include "commands/resetElevatorPosition.h"
#include "commands/ElevatorGotoPosition.h"


OI::OI() {

  //Setup joystick buttons to commands
    //joystick 1
    //m_joystick1button1.WhenPressed(new command());
    //m_joystick1button2.WhenPressed(new ElevatorGotoPosition());
    //m_joystick1button3.WhenPressed(new ElevatorGotoPosition());
    //m_joystick1button4.WhenPressed(new ElevatorGotoPosition());
    m_joystick1button5.WhenPressed(new ResetTrunkPosition());
    //m_joystick1button6.WhenPressed(new command());
    m_joystick1button7.WhenPressed(new FootGotoPosition(6332));
    m_joystick1button8.WhenPressed(new TrunkGotoPosition(0));
    m_joystick1button9.WhenPressed(new FootGotoPosition(0));
    m_joystick1button10.WhenPressed(new TrunkGotoPosition(3000));
    m_joystick1button11.WhenPressed(new FootGotoPosition(-1622));
    m_joystick1button12.WhenPressed(new TrunkGotoPosition(6178));

    //joystick 2
    //m_joystick2button1.WhenPressed(new command());
    //m_joystick2button2.WhenPressed(new command());
    //m_joystick2button3.WhenPressed(new command());
    //m_joystick2button4.WhenPressed(new command());
    m_joystick2button5.WhenPressed(new resetElevatorPosition());
    //m_joystick2button6.WhenPressed(new command());
    //m_joystick2button7.WhenPressed(new command());
    m_joystick2button8.WhenPressed(new ElevatorGotoPosition(0));
    //m_joystick2button9.WhenPressed(new command());
    m_joystick2button10.WhenPressed(new ElevatorGotoPosition(-10000));
    //m_joystick2button11.WhenPressed(new command());
    m_joystick2button12.WhenPressed(new ElevatorGotoPosition(-20000));


}

frc::Joystick& OI::getJoystick1() {
  return m_joy1;
}

frc::Joystick& OI::getJoystick2() {
  return m_joy2;
}

