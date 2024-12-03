#pragma once
#include "Pokemon.h"
#include <MOVES/ShadowBall.h>
#include <MOVES/SludgeBomb.h>
#include <MOVES/ThunderBolt.h>
#include <MOVES/NastyPlot.h>



class Gengar : public Pokemon{
	public:

 	Gengar():Pokemon(60, 65, 60,130, 75, 110,8,"Gengar",GHOST,POISON){
		this->AddMove(ShadowBall());
		this->AddMove(SludgeBomb());
		this->AddMove(ThunderBolt());
		this->AddMove(NastyPlot());
	 }
	 ~Gengar() {
       
    }
};