#pragma once
#include "Move_Class.h"

class MoonBlast: public Move{
	public:
	MoonBlast():Move(95,100,0){
		id = 11;
		nombre = "MoonBlast";
	}
	float ExecuteMove(int EnemySDef,int UserSAtk, int EnemyType1, int EnemyType2, int UserType1, int UserType2){
		float DamageDone;
		if(UserType1 == FAIRY ||  UserType2 == FAIRY) DamageDone = UserSAtk + (this->potencia * 1.5) - EnemySDef;
		else DamageDone = UserSAtk + this->potencia - EnemySDef;
		DamageDone *= EffectiveMessage(EnemyType1,EnemyType2,FAIRY);
		return DamageDone/5;
	}
};