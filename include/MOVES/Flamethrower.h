#pragma once
#include "Move.h"

class Flamethrower: public Move{
	public:
	Flamethrower():Move(90,100,0){
		id = 4;
		nombre = "Flamehrower";
	}
	float ExecuteMove(int EnemySDef,int UserSAtk, int EnemyType1, int EnemyType2, int UserType1, int UserType2){
		float DamageDone;
		if(UserType1 == FIRE ||  UserType2 == FIRE) DamageDone = UserSAtk + (this->potencia * 1.5) - EnemySDef;
		else DamageDone = UserSAtk + this->potencia - EnemySDef;
		DamageDone *= EffectiveMessage(EnemyType1,EnemyType2,FIRE);
		return DamageDone/5;
	}
};