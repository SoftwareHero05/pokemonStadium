#pragma once
#include "Pokemon.h"
#include <MOVES/Surf.h>
#include <MOVES/IceBeam.h>
#include <MOVES/MoonBlast.h>

class Suicune : public Pokemon{
	public:
	
 	Suicune():Pokemon(100, 75, 115, 90, 115, 85,5,"Suicune",WATER,FAIRY){
        this->AddMove(Surf());
        this->AddMove(IceBeam());
        this->AddMove(MoonBlast());
        this->AddMove(CalmMind());
	 }
	 ~Suicune() {
      
    }
};