#pragma once
#include "Move_Class.h"

class DragonPulse: public Move{
	public:
	DragonPulse():Move(85,100,0){
		id = 3;
		nombre = "DragonPulse";
	}
	float ExecuteMove(int EnemySDef,int UserSAtk, int EnemyType1, int EnemyType2, int UserType1, int UserType2){
		float DamageDone;
		if(UserType1 == DRAGON ||  UserType2 == DRAGON) DamageDone = UserSAtk + (this->potencia * 1.5) - EnemySDef;
		else DamageDone = UserSAtk + this->potencia - EnemySDef;
		DamageDone *= EffectiveMessage(EnemyType1,EnemyType2,DRAGON);
		return DamageDone/5;
	}
};