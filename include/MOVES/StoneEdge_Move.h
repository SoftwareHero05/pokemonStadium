#pragma once
#include "Move_Class.h"

class StoneEdge: public Move{
	public:
	StoneEdge():Move(90,100,0){
		id = 21;
		nombre = "StoneEdge";
	}
	float ExecuteMove(int EnemyDef,int UserAtk, int EnemyType1, int EnemyType2, int UserType1, int UserType2){
		float DamageDone;
		if(UserType1 == ROCK ||  UserType2 == ROCK) DamageDone = UserAtk + (this->potencia * 1.5) - EnemyDef;
		else DamageDone = UserAtk + this->potencia - EnemyDef;
		DamageDone *= EffectiveMessage(EnemyType1,EnemyType2,ROCK);
		return DamageDone/5;
	}
};