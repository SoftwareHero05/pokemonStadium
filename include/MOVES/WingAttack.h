#pragma once
#include "Move.h"

class WingAttack: public Move{
	public:
	WingAttack():Move(80,FLYING,true,24,"WingAttack"){
	}
};