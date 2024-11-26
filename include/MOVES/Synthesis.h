#pragma once
#include <POKEMONS/Pokemon.h>
class Synthesis: public Move{
	public:
	Synthesis():Move(0,GRASS,false){
		id = 23;
		nombre = "DragonDance";
	}
    void ExecuteMove(Pokemon &User){
        User.heal50Percent();
    }
};