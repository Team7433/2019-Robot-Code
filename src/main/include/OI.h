/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/Joystick.h>
#include <frc/buttons/JoystickButton.h>

class OI {
  public:
    OI();
    enum joystickNum {joy1, joy2};
    //create methods to get joysticks
    frc::Joystick& getJoystick1();
    frc::Joystick& getJoystick2();
    frc::Joystick& getJoystick3();
    bool joystickButtonLast(joystickNum,int button);
    bool joystickButton(joystickNum,int button);
    void UpdateButtons();
  private:
    bool buttonslast1[12] = {false, false, false, false,false, false, false, false,false, false, false, false};
    bool buttonslast2[12] = {false, false, false, false,false, false, false, false,false, false, false, false};
    //create joysticks
    frc::Joystick m_joy1{0};
    frc::Joystick m_joy2{1};
    frc::Joystick m_joy3{2};

    //create Joystick buttons

      //joystick 1
      frc::JoystickButton m_joystick1button1{&m_joy1, 1};
      frc::JoystickButton m_joystick1button2{&m_joy1, 2};
      frc::JoystickButton m_joystick1button3{&m_joy1, 3};
      frc::JoystickButton m_joystick1button4{&m_joy1, 4};
      frc::JoystickButton m_joystick1button5{&m_joy1, 5};
      frc::JoystickButton m_joystick1button6{&m_joy1, 6};
      frc::JoystickButton m_joystick1button7{&m_joy1, 7};
      frc::JoystickButton m_joystick1button8{&m_joy1, 8};
      frc::JoystickButton m_joystick1button9{&m_joy1, 9};
      frc::JoystickButton m_joystick1button10{&m_joy1, 10};
      frc::JoystickButton m_joystick1button11{&m_joy1, 11};
      frc::JoystickButton m_joystick1button12{&m_joy1, 12};

      //joystick 2
      frc::JoystickButton m_joystick2button1{&m_joy2, 1};
      frc::JoystickButton m_joystick2button2{&m_joy2, 2};
      frc::JoystickButton m_joystick2button3{&m_joy2, 3};
      frc::JoystickButton m_joystick2button4{&m_joy2, 4};
      frc::JoystickButton m_joystick2button5{&m_joy2, 5};
      frc::JoystickButton m_joystick2button6{&m_joy2, 6};
      frc::JoystickButton m_joystick21button7{&m_joy2, 7};
      frc::JoystickButton m_joystick2button8{&m_joy2, 8};
      frc::JoystickButton m_joystick2button9{&m_joy2, 9};
      frc::JoystickButton m_joystick2button10{&m_joy2, 10};
      frc::JoystickButton m_joystick2button11{&m_joy2, 11};
      frc::JoystickButton m_joystick2button12{&m_joy2, 12};


};
