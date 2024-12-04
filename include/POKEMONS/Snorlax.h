#pragma once
#include "Pokemon.h"
#include <MOVES/Curse.h>
#include <MOVES/BodySlam.h>
#include <MOVES/IcePunch.h>
#include <MOVES/IronHead.h>

class Snorlax : public Pokemon{
	public:
	
 	Snorlax():Pokemon(160, 110, 65, 65, 110,30,10,"Snorlax",NORMAL,0){
        this->AddMove(BodySlam());
        this->AddMove(IronHead());
        this->AddMove(IcePunch());
        this->AddMove(Curse());
	 }
	 ~Snorlax() {
      
    }
};