#pragma once
#include "Move_Class.h"

class ShadowBall: public Move{
	public:
	ShadowBall():Move(80,100,0){
		id = 13;
		nombre = "ShadowBall";
	}
	float ExecuteMove(int EnemySDef,int UserSAtk, int EnemyType1, int EnemyType2, int UserType1, int UserType2){
		float DamageDone;
		if(UserType1 == GHOST ||  UserType2 == GHOST) DamageDone = UserSAtk + (this->potencia * 1.5) - EnemySDef;
		else DamageDone = UserSAtk + this->potencia - EnemySDef;
		DamageDone *= EffectiveMessage(EnemyType1,EnemyType2,GHOST);
		return DamageDone/5;
	}
};