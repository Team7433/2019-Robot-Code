/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/Testing/TestBallWrist.h"
#include "commands/ballintakeIn.h"
#include "commands/ballintakeOut.h"
#include "commands/CommandGroupStuff/DelaySec.h"
#include "commands/BallIntake/BallRoller.h"

TestBallWrist::TestBallWrist() {
  AddParallel(new BallRoller(1, 2));
  AddSequential(new ballintakeOut());
  AddSequential(new DelaySec(1));
  AddSequential(new ballintakeIn(0.6));
  AddParallel(new BallRoller(-1,1.5));
  //AddSequential(new ballintakeOut());
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
