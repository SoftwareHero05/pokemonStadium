#pragma once
#include "Pokemon.h"
#include <MOVES/StoneEdge.h>
#include <MOVES/Crunch.h>
#include <MOVES/Earthquake.h>

class Tyranitar : public Pokemon{
	public:
 	Tyranitar():Pokemon(100, 134, 110, 95, 100, 61){
 		iD = 7;
 		nombre = "Tyranitar";
 		Type1 = ROCK;
        Type2 = DARK;
        this->AddMove(StoneEdge());
        this->AddMove(Crunch());
        this->AddMove(Earthquake());
	 }
	 ~Tyranitar() {
    }
};