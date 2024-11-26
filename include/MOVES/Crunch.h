#pragma once
#include "Move_Class.h"

class Crunch: public Move{
	public:
	Crunch():Move(80,100,0){
		id = 8;
		nombre = "Crunch";
	}
	float ExecuteMove(int EnemyDef,int UserAtk, int EnemyType1, int EnemyType2, int UserType1, int UserType2){
		float DamageDone;
		if(UserType1 == DRAGON ||  UserType2 == DRAGON) DamageDone = UserAtk + (this->potencia * 1.5) - EnemyDef;
		else DamageDone = UserAtk + this->potencia - EnemyDef;
		DamageDone *= EffectiveMessage(EnemyType1,EnemyType2,DARK);
		return DamageDone/5;
	}
};