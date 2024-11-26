#pragma once
#include "Move.h"

class Crunch: public Move{
	public:
	Crunch():Move(80,DARK,true){
		id = 8;
		nombre = "Crunch";
	}
};