#pragma once
#include <POKEMONS/Pokemon.h>
class DragonDance: public Move{
	public:
	DragonDance():Move(0,DRAGON,false){
		id = 10;
		nombre = "DragonDance";
	}
    void ExecuteMove(Pokemon &User){
        User.boostAtk();
        User.boostSpeed();
    }
};