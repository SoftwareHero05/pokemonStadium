#pragma once
#include "Move.h"

class ShadowBall: public Move{
	public:
	ShadowBall():Move(80,GHOST,false,13,"ShadowBall"){
	}
};