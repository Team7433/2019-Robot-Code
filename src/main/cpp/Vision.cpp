/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Vision.h"

//This is for all raspbeery pi interfacing and vision control
Vision::Vision() {

}

void Vision::SetVisionMode(visionMode mode) {
    switch (mode)
    {
        case Driver:
            
            break;
        case Tape:
            
            break;
        case Hatch:
            
            break;
    
        default:
            break;
    }
}