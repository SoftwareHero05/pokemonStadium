#pragma once
#include "Move_Class.h"

class Surf: public Move{
	public:
	Surf():Move(90,100,0){
		id = 16;
		nombre = "Surf";
	}
	float ExecuteMove(int EnemySDef,int UserSAtk, int EnemyType1, int EnemyType2, int UserType1, int UserType2){
		float DamageDone;
		if(UserType1 == ICE ||  UserType2 == ICE) DamageDone = UserSAtk + (this->potencia * 1.5) - EnemySDef;
		else DamageDone = UserSAtk + this->potencia - EnemySDef;
		DamageDone *= EffectiveMessage(EnemyType1,EnemyType2,WATER);
		return DamageDone/5;
	}
};