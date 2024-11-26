#pragma once
#include "Pokemon.h"
#include <MOVES/Psychic.h>
#include <MOVES/MoonBlast.h>
#include <MOVES/ShadowBall.h>

class Gardevoir : public Pokemon{
	public:
 	Gardevoir():Pokemon(73, 65, 65, 125, 115, 85){ //+5Speed +5Hp
 		iD = 4;
 		nombre = "Gardevoir";
 		Type1 = PSYCHIC;
        Type2 = FAIRY;
        this->AddMove(ShadowBall());
        this->AddMove(MoonBlast());
        this->AddMove(Psychic());
	 }
	 ~Gardevoir() {
    
    }
};