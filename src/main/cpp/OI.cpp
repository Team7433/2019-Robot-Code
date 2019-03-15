/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "OI.h"

#include <frc/WPILib.h>

#include "positions.h"
#include "Robot.h"

//commands
#include "commands/FootGotoPosition.h"
#include "commands/TrunkGotoPosition.h"
#include "commands/ResetTrunkPosition.h"
#include "commands/ResetFootEncoder.h"
#include "commands/resetElevatorPosition.h"
#include "commands/ElevatorGotoPosition.h"
#include "commands/wristGotoPosition.h"
#include "commands/SuperstructureControl.h"
#include "commands/SuperStructureGotoPosition.h"
#include "commands/EjectHatch.h"
#include "commands/AutoHatchOut.h"
#include "commands/ExecuteMotionProfile.h"
#include "commands/Testing/TestBallWrist.h"
#include "commands/Testing/MotionPTest.h"
#include "Commands/Testing/AutoStart.h"
#include "commands/FillMotionProfile.h"
#include "commands/SetElevatorBuffer.h"

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
    m_joystick1button3.WhileHeld(new SetElevatorBuffer(0));
    //m_joystick2button4.WhenPressed(new ballintakeOut());
    m_joystick1button5.WhenPressed(new SetElevatorBuffer(4000));
    //m_joystick1button6.WhenPressed(new resetWrist());
    m_joystick1button7.WhenPressed(new ClimbSetup());
    m_joystick1button8.WhenPressed(new ClimbLift(true));
    m_joystick1button9.WhenPressed(new ClimbFinish());
    m_joystick1button10.WhenPressed(new ClimbReset()); 
    //m_joystick1button11.WhenPressed(new AutoStart());
    m_joystick1button12.WhenPressed(new ClimbLift(false));

    //joystick 2
    //m_joystick2button1.WhenPressed(new command());
    //m_joystick2button2.WhenPressed();
    m_joystick2button3.WhileHeld(new SetElevatorBuffer(0));
    //m_joystick2button4.WhenPressed(new ballintakeOut());
    m_joystick2button5.WhenPressed(new SetElevatorBuffer(4000));
    //m_joystick2button6.WhileActive(new IntakeOut());
    //m_joystick2button7.WhenPressed(new SuperStructureGotoPosition(iona::Superstructure::autostep1));
    m_joystick2button8.WhenPressed(new AutoHatchOut());
    //m_joystick2button9.WhenPressed(new SuperStructureGotoPosition(iona::Superstructure::autostep3));
    //m_joystick2button10.WhenPressed(new SuperStructureGotoPosition(iona::Superstructure::cargoAmedium));
    //m_joystick2button11.WhenPressed(new SuperStructureGotoPosition(iona::Superstructure::cargoBlow));
    //m_joystick2button12.WhenPressed(new TestBallWrist());
    
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

bool OI::getPow3(int buttonid) {
  switch (buttonid)
  {
    case 1:
        if (m_joy3.GetPOV() == 315 || m_joy3.GetPOV() == 0 || m_joy3.GetPOV() == 45) {
          return true;
        }
      break;
    case 2:
        if (m_joy3.GetPOV() == 45 || m_joy3.GetPOV() == 90 || m_joy3.GetPOV() == 135) {
          return true;
        }        
      break;
    case 3:
        if (m_joy3.GetPOV() == 135 || m_joy3.GetPOV() == 180 || m_joy3.GetPOV() == 225) {
          return true;
        }  
      break;
    case 4:
        if (m_joy3.GetPOV() == 225 || m_joy3.GetPOV() == 270 || m_joy3.GetPOV() == 315) {
          return true;
        }  
      break;          
  }
  return false;
}

bool OI::getPow3Last(int button) {
  return POVLast3[button-1];
}
bool OI::getPow1(int buttonid) {
  switch (buttonid)
  {
    case 1:
        if (m_joy1.GetPOV() == 0) {
          return true;
        }
      break;
    case 2:
        if (m_joy1.GetPOV() == 90) {
          return true;
        }        
      break;
    case 3:
        if (m_joy1.GetPOV() == 180) {
          return true;
        }  
      break;
    case 4:
        if (m_joy1.GetPOV() == 270) {
          return true;
        }  
      break;          
  }
  return false;
}

bool OI::getPow1Last(int button) {
  return POVLast1[button-1];
}

void OI::UpdatePOV() {
  for(int i = 0; i < 4; i++)  {
    POVLast3[i] = getPow3(i+1);
  }
  for(int i = 0; i < 4; i++)  {
    POVLast1[i] = getPow1(i+1);
  }
  if (m_joy1.GetPOV() == 0) {
    LastPovForward = true;
  } else {
    LastPovForward = false;
  }
}

void OI::DriveControl() {
  //hand controls
  if (m_joy2.GetRawButton(1) == true) {
      Robot::hand.manual(0.4);
  } else if (m_joy1.GetRawButton(4) == true) {
      Robot::hand.manual(-0.7);
  } else {
    Robot::hand.manual(0);
  }

  //superstructure controls
  if (m_joy3.GetRawButton(10) == true) { //cargo mode
    if (getPow3(1) == true && getPow3Last(1) == false) {
      frc::Command* commandToBeExecuted = new SuperstructureControl(iona::Superstructure::cargoAhigh);
      commandToBeExecuted->Start();
    }
    if (m_joy3.GetRawButton(9) == true && joystickButtonLast(joystickNum::joy3, 9) == false) {
      frc::Command* commandToBeExecuted = new SuperstructureControl(iona::Superstructure::cargoBhigh);
      commandToBeExecuted->Start();
    }
    if (m_joy3.GetRawButton(6) == true && joystickButtonLast(joystickNum::joy3, 6) == false) {
      frc::Command* commandToBeExecuted = new SuperstructureControl(iona::Superstructure::cargoAmedium);
      commandToBeExecuted->Start();
    }
    if (m_joy3.GetRawButton(5) == true && joystickButtonLast(joystickNum::joy3, 5) == false) {
      frc::Command* commandToBeExecuted = new SuperstructureControl(iona::Superstructure::cargoBmedium);
      commandToBeExecuted->Start();
    }
    if (m_joy3.GetRawButton(2) == true && joystickButtonLast(joystickNum::joy3, 2) == false) {
      frc::Command* commandToBeExecuted = new SuperstructureControl(iona::Superstructure::cargoAlow);
      commandToBeExecuted->Start();
    }
    if (m_joy3.GetRawButton(1) == true && joystickButtonLast(joystickNum::joy3, 1) == false) {
      frc::Command* commandToBeExecuted = new SuperstructureControl(iona::Superstructure::cargoBlow);
      commandToBeExecuted->Start();
    }
    if (m_joy3.GetRawButton(3) == true && joystickButtonLast(joystickNum::joy3, 3) == false) {
      frc::Command* commandToBeExecuted = new SuperstructureControl(iona::Superstructure::idle);
      commandToBeExecuted->Start();
    }
    if (m_joy3.GetRawButton(4) == true && joystickButtonLast(joystickNum::joy3, 4) == false) {
      frc::Command* commandToBeExecuted = new SuperstructureControl(iona::Superstructure::home);
      commandToBeExecuted->Start();
    }
    if (m_joy3.GetRawButton(7) == true && joystickButtonLast(joystickNum::joy3, 7) == false) {
      frc::Command* commandToBeExecuted = new SuperstructureControl(iona::Superstructure::cargoAtop);
      commandToBeExecuted->Start();
    }
    if (m_joy3.GetRawButton(8) == true && joystickButtonLast(joystickNum::joy3, 8) == false) {
      frc::Command* commandToBeExecuted = new SuperstructureControl(iona::Superstructure::cargoBtop);
      commandToBeExecuted->Start();
    }
  } else { //hatch mode
    if (m_joy3.GetRawButton(3) == true && joystickButtonLast(joystickNum::joy3, 3) == false) {
      frc::Command* commandToBeExecuted = new SuperstructureControl(iona::Superstructure::hatchintake);
      commandToBeExecuted->Start();
    }
    if (getPow3(1) == true && getPow3Last(1) == false) {
      frc::Command* commandToBeExecuted = new SuperstructureControl(iona::Superstructure::hatchATop);
      commandToBeExecuted->Start();
    }
    if (m_joy3.GetRawButton(9) == true && joystickButtonLast(joystickNum::joy3, 9) == false) {
      frc::Command* commandToBeExecuted = new SuperstructureControl(iona::Superstructure::hatchBTop);
      commandToBeExecuted->Start();
    }
    if (m_joy3.GetRawButton(6) == true && joystickButtonLast(joystickNum::joy3, 6) == false) {
      frc::Command* commandToBeExecuted = new SuperstructureControl(iona::Superstructure::hatchAMiddle);
      commandToBeExecuted->Start();
    }
    if (m_joy3.GetRawButton(5) == true && joystickButtonLast(joystickNum::joy3, 5) == false) {
      frc::Command* commandToBeExecuted = new SuperstructureControl(iona::Superstructure::hatchBMiddle);
      commandToBeExecuted->Start();
    }
    if (m_joy3.GetRawButton(2) == true && joystickButtonLast(joystickNum::joy3, 2) == false) {
      frc::Command* commandToBeExecuted = new SuperstructureControl(iona::Superstructure::hatchAbottom);
      commandToBeExecuted->Start();
    }
    if (m_joy3.GetRawButton(1) == true && joystickButtonLast(joystickNum::joy3, 1) == false) {
      frc::Command* commandToBeExecuted = new SuperstructureControl(iona::Superstructure::hatchBbottom);
      commandToBeExecuted->Start();
    }
    if (m_joy3.GetRawButton(4) == true && joystickButtonLast(joystickNum::joy3, 4) == false) {
      frc::Command* commandToBeExecuted = new SuperstructureControl(iona::Superstructure::home);
      commandToBeExecuted->Start();
    }
  }
  if (getPow3(2) == true && getPow3Last(2) == false) {
    frc::Command* commandToBeExecuted = new SuperstructureControl(iona::Superstructure::climb);
    commandToBeExecuted->Start();
  }
  if (getPow1(1) == true && getPow1Last(1) == false) {
    frc::Command* commandToBeExecuted = new ExecuteMotionProfile("Chooser");
    commandToBeExecuted->Start();
  }
  if (getPow1(4) == true && getPow1Last(4) == false) {
    frc::Command* commandToBeExecuted = new ExecuteMotionProfile("BLCS-BLLS");
    commandToBeExecuted->Start();
  }
  if (getPow1(2) == true && getPow1Last(2) == false) {
    frc::Command* commandToBeExecuted = new ExecuteMotionProfile("BRCS-BRLS");
    commandToBeExecuted->Start();
  }
  //update buttons

  UpdateButtons();
  UpdatePOV();
}


void OI::ShowSubsystems() {
  //Robot::foot.UpdateData();
  Robot::elevator.UpdateData();
  Robot::shoulder.UpdateData();
  Robot::wrist.UpdateData();
  //Robot::trunk.UpdateData();
}

std::string OI::GetPickedPath() {
  return m_pickedPath;
}

bool OI::IsPathPicked() {
  return m_isPathPicked;
}

void OI::SetPathPicked(std::string path) {
  m_pickedPath = path;
}

void OI::UpdatePathChooser() {
  bool ButtonsCurrent[k_PathPoints];
  bool PathPicked = false;
  for(int i = 0; i < k_PathPoints; i++) {
    ButtonsCurrent[i] = frc::SmartDashboard::GetBoolean("Path " + std::to_string(i), false);
    if (ButtonsCurrent[i] == true && PathButtonsLast[i] == false) {
      for(int j = 0; j < k_PathPoints; j++) {
        if (j != i) {
          frc::SmartDashboard::PutBoolean("Path " + std::to_string(j), false);
        }
      }
      m_pickedPath = "Path " + std::to_string(i);
      PathPicked = true;
    } else if (ButtonsCurrent[i] == false) {
      if (m_pickedPath == "Path " + std::to_string(i)) {
        m_pickedPath = "null";
        PathPicked = false;
      }
    }
  }
  m_isPathPicked = PathPicked;
  frc::SmartDashboard::PutString("Picked Path", m_pickedPath);
  for(int i = 0; i < k_PathPoints; i++) {
    PathButtonsLast[i] = ButtonsCurrent[i];
  }
  
}

void OI::SetupPathChooser() {
  for(int i = 0; i < k_PathPoints; i++) {
    frc::SmartDashboard::PutBoolean("Path " + std::to_string(i), false);
  }
}
