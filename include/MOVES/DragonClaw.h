#pragma once
#include "Move.h"


class DragonClaw: public Move{
	public:
	DragonClaw():Move(80,DRAGON,true){
		id = 6;
		nombre = "DragonClaw";
	}
};