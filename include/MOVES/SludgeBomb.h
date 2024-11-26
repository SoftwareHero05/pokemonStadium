#pragma once
#include "Move_Class.h"

class SludgeBomb: public Move{
	public:
	SludgeBomb():Move(90,100,0){
		id = 18;
		nombre = "SludgeBomb";
	}
	float ExecuteMove(int EnemySDef,int UserSAtk, int EnemyType1, int EnemyType2, int UserType1, int UserType2){
		float DamageDone;
		if(UserType1 == POISON ||  UserType2 == POISON) DamageDone = UserSAtk + (this->potencia * 1.5) - EnemySDef;
		else DamageDone = UserSAtk + this->potencia - EnemySDef;
		DamageDone *= EffectiveMessage(EnemyType1,EnemyType2,POISON);
		return DamageDone/5;
	}
};