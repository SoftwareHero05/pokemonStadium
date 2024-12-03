#pragma once
#include "Pokemon.h"
#include <MOVES/Earthquake.h>
#include <MOVES/DragonClaw.h>
#include <MOVES/Crunch.h>
#include <MOVES/DragonDance.h>


class Garchomp : public Pokemon{
	public:
 	Garchomp():Pokemon(108, 130, 95, 80, 85, 102,3,"Garchomp",DRAGON,GROUND){
		this->AddMove(Earthquake());
		this->AddMove(DragonClaw());
		this->AddMove(Crunch());
		//this->AddMove(DragonDance());
	 }
	 ~Garchomp() {
    }
};