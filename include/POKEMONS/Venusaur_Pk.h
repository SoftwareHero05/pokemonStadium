#pragma once
#include "Pk_Class.h"
#include <MOVES/EnergyBall_Move.h>
#include <MOVES/SludgeBomb_Move.h>
#include <MOVES/EarthPower_Move.h>

class Venusaur : public Pokemon{
	public:
	EnergyBall *energyBallMov;
    SludgeBomb *sludgeBombMov;
    EarthPower *earthPowerMov;
 	Venusaur():Pokemon(80, 82, 83, 100, 100, 80){
 		iD = 6;
 		nombre = "Venusaur";
 		Type1 = GRASS;
        Type2 = POISON;
        energyBallMov = new EnergyBall();
        sludgeBombMov = new SludgeBomb();
        earthPowerMov = new EarthPower();
	 }
	 ~Venusaur() {
        delete energyBallMov;
        delete sludgeBombMov;
        delete earthPowerMov;
    }
};