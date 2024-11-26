#pragma once
#include "Pk_Class.h"
#include <MOVES/Flamethrower_Move.h>
#include <MOVES/DragonPulse_Move.h>
#include <MOVES/AirSlash_Move.h>

class  Charizard : public Pokemon{
	public:
	Flamethrower *flamethrowerMov;
    AirSlash *airSlashMov;
    DragonPulse *dragonPulseMov;
 	Charizard():Pokemon(78, 84, 78, 109, 85, 100){
 		iD = 2;
 		nombre = "Charizard";
 		Type1 = FIRE;
        Type2 = FLYING;
        flamethrowerMov = new Flamethrower();
        airSlashMov = new AirSlash();
        dragonPulseMov = new DragonPulse();
	 }
	 ~Charizard() {
        delete flamethrowerMov;
        delete airSlashMov;
        delete dragonPulseMov;
    }
};
