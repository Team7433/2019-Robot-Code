#pragma once

//Put this in the iona namespace
namespace iona {

    enum Superstructure {
        idle,
        cargointake,
        hatchintake,
        hatchAbottom,   
        hatchBbottom,
        hatchAMiddle,   
        hatchBMiddle,
        hatchATop,   
        hatchBTop,
        cargoAlow,
        cargoAmedium,
        cargoAhigh,
        cargoAtop,
        cargoBlow,
        cargoBmedium,
        cargoBhigh,
        cargoBtop,
        cargoTest,
        home,
        climb,
    };

    //Put in the position namespace
    namespace positions {

        //setup Elevator positions
        enum Elevator {
            Top = 5000,
            Bottom = 0,
            center = 2500
        };

        //setup Sholder positions
        enum Sholder {
            BallIntake = 0,
            BottomHatch = 30
        };

        //setup Sholder positions
        enum Wrist {
            Strait = 0,
            Forward = 30
        };

        
    }
}