#pragma once
#include "Move.h"
class CalmMind: public Move{
	public:
	CalmMind():Move(0,PSYCHIC,false,9,"CalmMind"){
	}
    /*void ExecuteMove(Pokemon &User){
        User.boostSAtk();
        User.boostSDef();
    }*/
};