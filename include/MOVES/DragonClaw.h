#pragma once
#include "Move_Class.h"


class DragonClaw: public Move{
	public:
	DragonClaw():Move(80,100,0){
		id = 6;
		nombre = "DragonClaw";
	}
	float ExecuteMove(int EnemyDef,int UserAtk, int EnemyType1, int EnemyType2, int UserType1, int UserType2){
		float DamageDone;
		if(UserType1 == DRAGON ||  UserType2 == DRAGON) DamageDone = UserAtk + (this->potencia * 1.5) - EnemyDef;
		else DamageDone = UserAtk + this->potencia - EnemyDef;
		DamageDone *= EffectiveMessage(EnemyType1,EnemyType2,DRAGON);
		return DamageDone/5;
	}
};