#pragma once
#include <Definer.h>
#include "LIST_TYPES.h"
#include <EffectivinenessMesage.h>
//#include <POKEMONS/Pokemon.h>
class Move{

protected:
	int id;
	string nombre;
	int potencia;
	int type;
	bool category;//1 = Fisico //2 = Especial // 3 = Boost

public:
	Move() {}
	Move(int potencia, int type, bool category,int id,string nombre) {
		this->potencia = potencia;
		this->type = type;
		this->category = category;
		this->id = id;
		this->nombre = nombre;
	}
	string GetMoveName(){
		return this->nombre;
	}

	int ExecuteMove(int UserType1, int UserType2, int EnemyType1, int EnemyType2, int UserAtk, int UserSAtk, int EnemyDef, int EnemySDef)
	{
		float damageDone;
		int potencia = this->potencia;
		if (UserType1 == this->type || UserType2 == this->type)
			potencia *= 1.5;
		if (this->category == true)
			damageDone = UserAtk + potencia - EnemyDef;
		else
			damageDone = UserSAtk + potencia - EnemySDef;
		damageDone *= EffectiveMessage(EnemyType1, EnemyType2, this->type);
		if (damageDone < 0)
			damageDone = 0;
		damageDone /= 5;
		return damageDone;
	}

	string GetEffectivenessMessage(int EnemyType1, int EnemyType2){
		int multiplicador = EffectiveMessage(EnemyType1,EnemyType2,this->type);
		if(multiplicador == 0) return "It had no effect whatsoever...";
		else if(multiplicador > 1) return "It's very effective!";
		else if(multiplicador < 1) return "It's not very effective...";
		else "It's effective";
	}
}; 