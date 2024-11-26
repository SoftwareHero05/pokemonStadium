#pragma once
#include "Move_Class.h"

class EnergyBall: public Move{
	public:
	EnergyBall():Move(90,100,0){
		id = 17;
		nombre = "EnergyBall";
	}
	float ExecuteMove(int EnemySDef,int UserSAtk, int EnemyType1, int EnemyType2, int UserType1, int UserType2){
		float DamageDone;
		if(UserType1 == GRASS ||  UserType2 == GRASS) DamageDone = UserSAtk + (this->potencia * 1.5) - EnemySDef;
		else DamageDone = UserSAtk + this->potencia - EnemySDef;
		DamageDone *= EffectiveMessage(EnemyType1,EnemyType2,GRASS);
		return DamageDone/5;
	}
};