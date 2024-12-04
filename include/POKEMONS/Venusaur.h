#pragma once
#include "Pokemon.h"
#include <MOVES/EnergyBall.h>
#include <MOVES/SludgeBomb.h>
#include <MOVES/EarthPower.h>
#include <MOVES/Synthesis.h>

class Venusaur : public Pokemon{
	public:
 	Venusaur():Pokemon(80, 82, 83, 100, 100, 80,6,"Venasaur",GRASS,POISON){
        this->AddMove(EnergyBall());
        this->AddMove(SludgeBomb());
        this->AddMove(EarthPower());
        this->AddMove(Synthesis());
	 }
	 ~Venusaur() {
    
    }
};