/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/SuperstructureControl.h"
#include "commands/SuperStructureGotoPosition.h"
#include "commands/SwichSide.h"

SuperstructureControl::SuperstructureControl(iona::Superstructure position) {
  if (position == iona::Superstructure::hatchATop || 
      position == iona::Superstructure::cargoAhigh || 
      position == iona::Superstructure::cargoAmedium || 
      position == iona::Superstructure::cargoBtop || 
      position == iona::Superstructure::cargoAlow || 
      position == iona::Superstructure::hatchAMiddle || 
      position == iona::Superstructure::hatchAbottom || 
      position == iona::Superstructure::idle || 
      position == iona::Superstructure::home) {
    AddSequential(new SwichSide(SwichSide::Side::A));
  } else {
    AddSequential(new SwichSide(SwichSide::Side::B));
  }
  AddSequential(new SuperStructureGotoPosition(position));
  // Add Commands here:
  // e.g. AddSequential(new Command1());
  //      AddSequential(new Command2());
  // these will run in order.

  // To run multiple commands at the same time,
  // use AddParallel()
  // e.g. AddParallel(new Command1());
  //      AddSequential(new Command2());
  // Command1 and Command2 will run in parallel.

  // A command group will require all of the subsystems that each member
  // would require.
  // e.g. if Command1 requires chassis, and Command2 requires arm,
  // a CommandGroup containing them would require both the chassis and the
  // arm.
}
