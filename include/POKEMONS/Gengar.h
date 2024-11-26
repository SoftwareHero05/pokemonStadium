#pragma once
#include "Pokemon.h"
#include <MOVES/ShadowBall.h>
#include <MOVES/SludgeBomb.h>
#include <MOVES/ThunderBolt.h>



class Gengar : public Pokemon{
	public:

 	Gengar():Pokemon(60, 65, 60,130, 75, 110){
 		iD = 8;
 		nombre = "Gengar";
 		Type1 = GHOST;
        Type2 = POISON;
		this->AddMove(ShadowBall());
		this->AddMove(SludgeBomb());
		this->AddMove(ThunderBolt());
	 }
	 ~Gengar() {
       
    }
};