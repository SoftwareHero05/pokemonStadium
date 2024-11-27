#pragma once
#include "Pokemon.h"
#include <MOVES/Psychic.h>
#include <MOVES/MoonBlast.h>
#include <MOVES/ShadowBall.h>

class Gardevoir : public Pokemon{
	public:
 	Gardevoir():Pokemon(73, 65, 65, 125, 115, 85,4,"Gardevoir",PSYCHIC,FAIRY){ //+5Speed +5Hp
        this->AddMove(ShadowBall());
        this->AddMove(MoonBlast());
        this->AddMove(Psychic());
	 }
	 ~Gardevoir() {
    
    }
};