#pragma once
#include "Move.h"

class Curse: public Move{
	public:
	Curse():Move(0,GHOST,false,28,"Curse"){
	}
};