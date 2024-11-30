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

	 /*virtual float ExecuteMove(int UserType1,int UserType2,int EnemyType1,int EnemyType2, int UserAtk, Pokemon Enemy){
		float damageDone;
		int potencia = this->potencia;
		if(User.getType1() == this->type || User.getType1()  == this->type) potencia *= 1.5;
		if(this->category == true) damageDone = User.GetAtk() + potencia - Enemy.GetDef();
		else damageDone = User.GetSAtk() + potencia - Enemy.GetSDef();
		damageDone *= EffectiveMessage(EnemyType1,EnemyType2,this->type);
		return damageDone;}
		*/

}; 