#pragma once
#include "Pokemon.h"
#include <MOVES/Earthquake.h>
#include <MOVES/DragonClaw.h>
#include <MOVES/Crunch.h>


class Garchomp : public Pokemon{
	public:
 	Garchomp():Pokemon(108, 130, 95, 80, 85, 102){
 		iD = 3;
 		nombre = "Garchomp";
 		Type1 = DRAGON;
        Type2 = GROUND;
		this->AddMove(Earthquake());
		this->AddMove(DragonClaw());
		this->AddMove(Crunch());
	 }
	 ~Garchomp() {
    }
};