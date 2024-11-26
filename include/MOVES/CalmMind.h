#pragma once
#include <POKEMONS/Pokemon.h>
class CalmMind: public Move{
	public:
	CalmMind():Move(0,PSYCHIC,false){
		id = 9;
		nombre = "CalmMind";
	}
    void ExecuteMove(Pokemon &User){
        User.boostSAtk();
        User.boostSDef();
    }
};