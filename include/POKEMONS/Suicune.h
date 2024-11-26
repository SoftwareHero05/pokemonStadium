#pragma once
#include "Pk_Class.h"
#include <MOVES/Surf_Move.h>
#include <MOVES/IceBeam_Move.h>
#include <MOVES/MoonBlast_Mov.h>

class Suicune : public Pokemon{
	public:
	Surf *surfMov;
    IceBeam *iceBeamMov;
    MoonBlast *moonBlastMov;
 	Suicune():Pokemon(100, 75, 115, 90, 115, 85){
 		iD = 5;
 		nombre = "Suicune";
 		Type1 = WATER;
        Type2 = FAIRY;
        surfMov = new Surf();
        iceBeamMov = new IceBeam();
        moonBlastMov = new MoonBlast();
	 }
	 ~Suicune() {
        delete surfMov;
        delete iceBeamMov;
        delete moonBlastMov;
    }
};