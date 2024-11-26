#pragma once
#include "Pk_Class.h"
#include <MOVES/Earthquake_Move.h>
#include <MOVES/DragonClaw_Move.h>
#include <MOVES/Crunch_Move.h>


class Garchomp : public Pokemon{
	public:
	Earthquake *earthquakeMov;
    DragonClaw *dragonClawMov;
    Crunch *crunchMov;
 	Garchomp():Pokemon(108, 130, 95, 80, 85, 102){
 		iD = 3;
 		nombre = "Garchomp";
 		Type1 = DRAGON;
        Type2 = GROUND;
		earthquakeMov = new Earthquake();
		dragonClawMov = new DragonClaw();
		crunchMov = new Crunch();
	 }
	 ~Garchomp() {
        delete earthquakeMov;
        delete dragonClawMov;
        delete crunchMov;
    }
};