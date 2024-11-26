#pragma once
#include "Pokemon.h"
#include <MOVES/AuraSphere.h>
#include <MOVES/FlashCannon.h>
#include <MOVES/DragonPulse.h>

class Lucario : public Pokemon{
	public:
 	Lucario():Pokemon(70, 110, 70, 120, 70, 95){ //+5Speed +5SAtk
 		iD = 1;
 		nombre = "Lucario";
 		Type1 = FIGHTING;
        Type2 = STEEL;
        this->AddMove(AuraSphere());
        this->AddMove(FlashCannon());
        this->AddMove(DragonPulse());
        
	 }
	 ~Lucario() {
    }
};