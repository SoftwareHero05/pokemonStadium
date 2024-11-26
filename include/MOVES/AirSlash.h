#pragma once
#include "Move.h"
class AirSlash: public Move{
	public:
	AirSlash():Move(75,FLYING,false,5,"AirSlash"){
	}
};