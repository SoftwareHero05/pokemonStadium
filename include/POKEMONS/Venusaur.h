#pragma once
#include "Pokemon.h"
#include <MOVES/EnergyBall.h>
#include <MOVES/SludgeBomb.h>
#include <MOVES/EarthPower.h>

class Venusaur : public Pokemon{
	public:
 	Venusaur():Pokemon(80, 82, 83, 100, 100, 80){
 		iD = 6;
 		nombre = "Venusaur";
 		Type1 = GRASS;
        Type2 = POISON;
        this->AddMove(EnergyBall());
        this->AddMove(SludgeBomb());
        this->AddMove(EarthPower());
        
	 }
	 ~Venusaur() {
    
    }
};