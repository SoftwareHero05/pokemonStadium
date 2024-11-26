#pragma once
#include "Move.h"
class Synthesis: public Move{
	public:
	Synthesis():Move(0,GRASS,false,23,"Synthesis"){
	}
    /*void ExecuteMove(Pokemon &User){
        User.heal50Percent();
    }*/
};