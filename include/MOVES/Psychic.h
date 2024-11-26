#pragma once
#include "Move.h"

class Psychic: public Move{
	public:
	Psychic():Move(90,PSYCHIC,false){
		id = 12;
		nombre = "Psychic";
	}
};