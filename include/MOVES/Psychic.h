#pragma once
#include "Move_Class.h"

class Psychic: public Move{
	public:
	Psychic():Move(90,100,0){
		id = 12;
		nombre = "Psychic";
	}
	float ExecuteMove(int EnemySDef,int UserSAtk, int EnemyType1, int EnemyType2, int UserType1, int UserType2){
		float DamageDone;
		if(UserType1 == PSYCHIC ||  UserType2 == PSYCHIC) DamageDone = UserSAtk + (this->potencia * 1.5) - EnemySDef;
		else DamageDone = UserSAtk + this->potencia - EnemySDef;
		DamageDone *= EffectiveMessage(EnemyType1,EnemyType2,PSYCHIC);
		return DamageDone/5;
	}
};