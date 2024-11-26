#pragma once
#include "Move.h"

class MoonBlast: public Move{
	public:
	MoonBlast():Move(95,FAIRY,false){
		id = 11;
		nombre = "MoonBlast";
	}
};