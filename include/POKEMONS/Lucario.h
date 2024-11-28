#pragma once
#include "Pokemon.h"
#include <MOVES/AuraSphere.h>
#include <MOVES/FlashCannon.h>
#include <MOVES/DragonPulse.h>

class Lucario : public Pokemon{
	public:
 	Lucario():Pokemon(70, 110, 70, 120, 70, 95,1,"Lucario",FIGHTING,STEEL){ //+5Speed +5SAtk
        this->AddMove(AuraSphere());
        this->AddMove(FlashCannon());
        this->AddMove(DragonPulse());
        
	 }
	 ~Lucario() {
    }
};