#pragma once
#include "Move_Class.h"

class IronHead: public Move{
	public:
	IronHead():Move(80,100,0){
		id = 2;
		nombre = "IronHead";
	}
	float ExecuteMove(int EnemyDef,int UserAtk, int EnemyType1, int EnemyType2, int UserType1, int UserType2){
		float DamageDone;
		if(UserType1 == STEEL ||  UserType2 == STEEL) DamageDone = UserAtk + (this->potencia * 1.5) - EnemyDef;
		else DamageDone = UserAtk + this->potencia - EnemyDef;
		DamageDone *= EffectiveMessage(EnemyType1,EnemyType2,STEEL);
		return DamageDone/5;
	}
	//PRIORIDAD
};