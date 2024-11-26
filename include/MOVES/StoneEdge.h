#pragma once
#include "Move.h"

class StoneEdge: public Move{
	public:
	StoneEdge():Move(90,ROCK,true){
		id = 21;
		nombre = "StoneEdge";
	}
};