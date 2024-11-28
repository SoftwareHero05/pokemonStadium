#pragma once
#include "Move.h"

class IceBeam: public Move{
	public:
	IceBeam():Move(90,ICE,false,15,"IceBeam"){
	}
};