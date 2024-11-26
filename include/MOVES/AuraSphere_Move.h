#pragma once
#include "Move_Class.h"

class AuraSphere: public Move{
	public:
	AuraSphere():Move(80,100,0){
		id = 1;
		nombre = "AuraSphere";
	}
	float ExecuteMove(int EnemySDef,int UserSAtk, int EnemyType1, int EnemyType2, int UserType1, int UserType2){
		float DamageDone;
		if(UserType1 == FIGHTING ||  UserType2 == FIGHTING) DamageDone = UserSAtk + (this->potencia * 1.5) - EnemySDef;
		else DamageDone = UserSAtk + this->potencia - EnemySDef;
		DamageDone *= EffectiveMessage(EnemyType1,EnemyType2,FIGHTING);
		return DamageDone/5;
	}
};