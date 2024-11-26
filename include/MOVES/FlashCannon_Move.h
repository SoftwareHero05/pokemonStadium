#pragma once
#include "Move_Class.h"

class FlashCannon: public Move{
	public:
	FlashCannon():Move(90,100,0){
		id = 14;
		nombre = "FlashCannon";
	}
	float ExecuteMove(int EnemySDef,int UserSAtk, int EnemyType1, int EnemyType2, int UserType1, int UserType2){
		float DamageDone;
		if(UserType1 == STEEL ||  UserType2 == STEEL) DamageDone = UserSAtk + (this->potencia * 1.5) - EnemySDef;
		else DamageDone = UserSAtk + this->potencia - EnemySDef;
		DamageDone *= EffectiveMessage(EnemyType1,EnemyType2,STEEL);
		return DamageDone/5;
	}
};