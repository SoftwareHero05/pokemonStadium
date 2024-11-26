#pragma once
#include "Move_Class.h"

class AirSlash: public Move{
	public:
	AirSlash():Move(75,95,0){
		id = 5;
		nombre = "AirSlash";
	}
	float ExecuteMove(int EnemySDef,int UserSAtk, int EnemyType1, int EnemyType2, int UserType1, int UserType2){
		//efecto secundario
		//ACERTAR
		float DamageDone;
		if(UserType1 == FLYING ||  UserType2 == FLYING) DamageDone = UserSAtk + (this->potencia * 1.5) - EnemySDef;
		else DamageDone = UserSAtk + this->potencia - EnemySDef;
		DamageDone *= EffectiveMessage(EnemyType1,EnemyType2,FLYING);
		return DamageDone/5;
	}
	
};