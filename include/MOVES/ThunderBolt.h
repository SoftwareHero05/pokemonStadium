#pragma once
#include "Move_Class.h"

class ThunderBolt: public Move{
	public:
	ThunderBolt():Move(90,100,0){
		id = 22;
		nombre = "ThunderBolt";
	}
	float ExecuteMove(int EnemySDef,int UserSAtk, int EnemyType1, int EnemyType2, int UserType1, int UserType2){
		float DamageDone;
		if(UserType1 == ELECTRIC ||  UserType2 == ELECTRIC) DamageDone = UserSAtk + (this->potencia * 1.5) - EnemySDef;
		else DamageDone = UserSAtk + this->potencia - EnemySDef;
		DamageDone *= EffectiveMessage(EnemyType1,EnemyType2,ELECTRIC);
		return DamageDone/5;
	}
};