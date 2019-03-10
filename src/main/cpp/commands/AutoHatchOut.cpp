/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/AutoHatchOut.h"
#include "commands/SuperstructureControl.h"
#include "commands/ballintakeIn.h"
#include "commands/ballintakeOut.h"

AutoHatchOut::AutoHatchOut() {
  AddSequential(new ballintakeIn(2));
  AddSequential(new SuperstructureControl(iona::Superstructure::autostep1));
  AddParallel(new ballintakeIn(2));
  AddSequential(new SuperstructureControl(iona::Superstructure::autostep3));
}
