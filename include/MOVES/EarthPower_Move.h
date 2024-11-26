#pragma once
#include "Move_Class.h"

class EarthPower: public Move{
	public:
	EarthPower():Move(90,100,0){
		id = 20;
		nombre = "EarthPower";
	}
	float ExecuteMove(int EnemySDef,int UserSAtk, int EnemyType1, int EnemyType2, int UserType1, int UserType2){
		float DamageDone;
		if(UserType1 == GROUND ||  UserType2 == GROUND) DamageDone = UserSAtk + (this->potencia * 1.5) - EnemySDef;
		else DamageDone = UserSAtk + this->potencia - EnemySDef;
		DamageDone *= EffectiveMessage(EnemyType1,EnemyType2,GROUND);
		return DamageDone/5;
	}
};