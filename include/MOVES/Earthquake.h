#pragma once
#include "Move_Class.h"

class Earthquake: public Move{
	public:
	Earthquake():Move(100,100,0){
		id = 7;
		nombre = "Earthquake";
	}
	float ExecuteMove(int EnemyDef,int UserAtk, int EnemyType1, int EnemyType2, int UserType1, int UserType2){
		float DamageDone;
		if(UserType1 == GROUND ||  UserType2 == GROUND) DamageDone = UserAtk + (this->potencia * 1.5) - EnemyDef;
		else DamageDone = UserAtk + this->potencia - EnemyDef;
		DamageDone *= EffectiveMessage(EnemyType1,EnemyType2,GROUND);
		return DamageDone/5;
	}
};