#pragma once
#include "Move.h"

class ThunderBolt: public Move{
	public:
	ThunderBolt():Move(90,ELECTRIC,false){
		id = 22;
		nombre = "ThunderBolt";
	}
};