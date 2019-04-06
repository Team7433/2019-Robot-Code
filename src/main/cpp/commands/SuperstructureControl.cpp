/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/SuperstructureControl.h"
#include "commands/SuperStructureGotoPosition.h"
#include "commands/SwichSide.h"
#include "commands/ShoulderGotoAngle.h"
#include "commands/WristGoToAngle.h"
#include "commands/ElevatorGotoPosition.h"

SuperstructureControl::SuperstructureControl(iona::Superstructure position) {
  AddParallel(new ElevatorGotoPosition(0));
  AddParallel(new ShoulderGotoAngle(30));
  AddParallel(new WristGoToAngle(0));
  switch (position)
  {
    case iona::Superstructure::idle:
      AddParallel(new ElevatorGotoPosition(8000));
      AddParallel(new ShoulderGotoAngle(25));
      AddParallel(new WristGoToAngle(-20));
      break;
    case iona::Superstructure::cargoAhigh:
      AddParallel(new ElevatorGotoPosition(17000));
      AddParallel(new ShoulderGotoAngle(151));
      AddParallel(new WristGoToAngle(-47));
      break;
    case iona::Superstructure::cargoAmedium:
      AddParallel(new ElevatorGotoPosition(0));
      AddParallel(new ShoulderGotoAngle(123));
      AddParallel(new WristGoToAngle(-19));
      break;
    case iona::Superstructure::cargoAlow:
      AddParallel(new ElevatorGotoPosition(0));
      AddParallel(new ShoulderGotoAngle(36));
      AddParallel(new WristGoToAngle(74));
      break;
    case iona::Superstructure::cargoAtop:
      AddParallel(new ElevatorGotoPosition(0));
      AddParallel(new ShoulderGotoAngle(258));
      AddParallel(new WristGoToAngle(25));
      break;
    case iona::Superstructure::cargoBhigh:
      AddParallel(new ElevatorGotoPosition(17000));
      AddParallel(new ShoulderGotoAngle(209));
      AddParallel(new WristGoToAngle(47));
      break;
    case iona::Superstructure::cargoBmedium:
      AddParallel(new ElevatorGotoPosition(0));
      AddParallel(new ShoulderGotoAngle(237));
      AddParallel(new WristGoToAngle(19));
      break;
    case iona::Superstructure::cargoBlow:
      AddParallel(new ElevatorGotoPosition(0));
      AddParallel(new ShoulderGotoAngle(324));
      AddParallel(new WristGoToAngle(-74));
      break;
    case iona::Superstructure::cargoBtop:
      AddParallel(new ElevatorGotoPosition(0));
      AddParallel(new ShoulderGotoAngle(102));
      AddParallel(new WristGoToAngle(-25));
      break;
    case iona::Superstructure::cargointake:
      AddParallel(new ElevatorGotoPosition(0));
      AddParallel(new ShoulderGotoAngle(24));
      AddParallel(new WristGoToAngle(-2));
    case iona::Superstructure::home:
      AddParallel(new ElevatorGotoPosition(0));
      AddParallel(new ShoulderGotoAngle(19));
      AddParallel(new WristGoToAngle(-19));
      break;
    case iona::Superstructure::hatchintake:
      AddParallel(new ElevatorGotoPosition(5837));
      AddParallel(new ShoulderGotoAngle(337));
      AddParallel(new WristGoToAngle(26));
      break;
    case iona::Superstructure::hatchintake2:
      AddParallel(new ElevatorGotoPosition(15000));
      AddParallel(new ShoulderGotoAngle(337));
      AddParallel(new WristGoToAngle(26));
      break;
    case iona::Superstructure::hatchATop:
      AddParallel(new ElevatorGotoPosition(1425));
      AddParallel(new ShoulderGotoAngle(137));
      AddParallel(new WristGoToAngle(46));
      break;
    case iona::Superstructure::hatchAMiddle:
      AddParallel(new ElevatorGotoPosition(15000));
      AddParallel(new ShoulderGotoAngle(84));
      AddParallel(new WristGoToAngle(-79));
      break;
    case iona::Superstructure::hatchAbottom:
      AddParallel(new ElevatorGotoPosition(2500));
      AddParallel(new ShoulderGotoAngle(46));
      AddParallel(new WristGoToAngle(-42));
      break;
    case iona::Superstructure::hatchBTop:
      AddParallel(new ElevatorGotoPosition(0));
      AddParallel(new ShoulderGotoAngle(205));
      AddParallel(new WristGoToAngle(-28));
      break;
    case iona::Superstructure::hatchBMiddle:
      AddParallel(new ElevatorGotoPosition(14900));
      AddParallel(new ShoulderGotoAngle(265));
      AddParallel(new WristGoToAngle(80));
      break;
    case iona::Superstructure::hatchBbottom:
      AddParallel(new ElevatorGotoPosition(2884));
      AddParallel(new ShoulderGotoAngle(321));
      AddParallel(new WristGoToAngle(40));
      break;
    case iona::Superstructure::climb:
      AddParallel(new ElevatorGotoPosition(0));
      AddParallel(new ShoulderGotoAngle(67));
      AddParallel(new WristGoToAngle(-15));
      break;
    case iona::Superstructure::autostep1:
      AddParallel(new ElevatorGotoPosition(4000));
      AddParallel(new ShoulderGotoAngle(50));
      AddParallel(new WristGoToAngle(-19));
      break;
    case iona::Superstructure::autostep3:
      AddParallel(new ElevatorGotoPosition(0));
      AddParallel(new ShoulderGotoAngle(29));
      AddParallel(new WristGoToAngle(0));
      break;
    default:
      break;
  }
}
