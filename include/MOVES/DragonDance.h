#pragma once
#include <Move.h>

class DragonDance: public Move{
	public:
	DragonDance():Move (0,DRAGON,false,10,"DragonDance"){
	} /*
    void ExecuteMove(Pokemon &User){
        User.boostAtk();
        User.boostSpeed();
    }*/
};