#pragma once
#include "Move.h"

class IronHead: public Move{
	public:
	IronHead():Move(80,STEEL,true){
		id = 2;
		nombre = "IronHead";
	}
};