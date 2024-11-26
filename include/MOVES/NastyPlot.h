#pragma once
#include <POKEMONS/Pokemon.h>
#include "Move.h"
class NastyPlot: public Move{
	public:
	NastyPlot():Move(0,DARK,false){
		id = 23;
		nombre = "DragonDance";
	}
    void ExecuteMove(Pokemon &User){
        User.boostSAtk();
        User.boostSAtk();
    }
};