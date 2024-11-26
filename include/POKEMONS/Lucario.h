#pragma once
#include "Pk_Class.h"
#include <MOVES/AuraSphere_Move.h>
#include <MOVES/FlashCannon_Move.h>
#include <MOVES/DragonPulse_Move.h>

class Lucario : public Pokemon{
	public:
	AuraSphere *auraSphereMov;
    FlashCannon *flashCannonMov;
    DragonPulse *dragonPulseMov; 
 	Lucario():Pokemon(70, 110, 70, 120, 70, 95){ //+5Speed +5SAtk
 		iD = 1;
 		nombre = "Lucario";
 		Type1 = FIGHTING;
        Type2 = STEEL;
        auraSphereMov = new AuraSphere();
        flashCannonMov = new FlashCannon();
        dragonPulseMov = new DragonPulse();
	 }
	 ~Lucario() {
        delete auraSphereMov;
        delete flashCannonMov;
        delete dragonPulseMov;
    }
};