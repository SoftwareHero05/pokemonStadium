#pragma once
#include "Move.h"

class SludgeBomb: public Move{
	public:
	SludgeBomb():Move(90,POISON,false,18,"SludgeBomb"){
	}
};