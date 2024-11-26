#pragma once
#include <Definer.h>
#include <MOVES/Move.h>
/*
#include <POKEMONS/Lucario.h>
#include <POKEMONS/Charizard.h>
#include <POKEMONS/Garchomp.h>
#include <POKEMONS/Gardevoir.h>
#include <POKEMONS/Suicune.h>
#include <POKEMONS/Venusaur.h>
#include <POKEMONS/Tyranitar.h>
#include <POKEMONS/Gengar.h>
*/

class Pokemon
{
protected:
	int iD;
	string nombre;
	int Hp, Atk, Def, SAtk, SDef, Speed, Type1, Type2;
	int BAtk, BDef, BSAtk, BSDef, BSpeed, BHp;
	list<Move> moves;

public:
	Pokemon(int Hp, int Atk, int Def, int SAtk, int SDef, int Speed,
	int id, string nombre,int Type1,int Type2)
	{
		Pokemon(Hp, Atk, Def, SAtk, SDef, Speed, list<Move>(),id,nombre,Type1,Type2);
	}
	Pokemon(int Hp, int Atk, int Def, int SAtk, int SDef, int Speed, list<Move> moves,
	int iD,string nombre, int Type1,int Type2)
	{	
		this->Atk = Atk;
		this->Def = Def;
		this->SAtk = SAtk;
		this->SDef = SDef;
		this->Speed = Speed;
		this->BAtk = Atk;
		this->BDef = Def;
		this->BSAtk = SAtk;
		this->BSDef = SDef;
		this->BSpeed = Speed;
		this->BHp = Hp;
		this->moves = moves;
		this->iD = iD;
		this->nombre = nombre;
		this->Type1 = Type1;
		this->Type2 = Type2;
	}
	// Destructor virtual para hacer que la clase sea polimórfica
	virtual ~Pokemon() {}

	// Método virtual para obtener el nombre, también puede ser redefinido en clases derivadas
	virtual string getNombre() const { return nombre; }

	void RestartStats()
	{
		this->Atk = this->BAtk;
		this->Def = this->BDef;
		this->SAtk = this->BSAtk;
		this->SDef = this->BSDef;
		this->Speed = this->BSpeed;
	}

	list<Move> GetMoveSet()
	{
		return this->moves;
	}

	void AddMove(Move move)
	{
		this->moves.emplace_back(move);
	}
	

	int GetAtk(){
		return this->Atk;
	}
	int GetDef(){
		return this->Def;
	}
	int GetSAtk(){
		return this->SAtk;
	}
	int GetSDef(){
		return this->SDef;
	}
	int GetSpeed(){
		return this->Speed;
	}
	int getType1(){
		return this->Type1;
	}
	int getType2(){
		return this->Type2;
	}

	void boostAtk(){
	this->Atk += this->BAtk;
	}
	void boostDef(){
	this->Def += this->BDef;
	}
	void boostSAtk(){
	this->SAtk += this->BSAtk;
	}
	void boostSDef(){
	this->SDef += this->BSDef;
	}
	void boostSpeed(){
	this->Speed += this->BSpeed;
	}
	void heal50Percent(){
		this->Hp+=this->BHp;
		if(this->Hp > this->BHp) this->Hp = this->BHp;
	}
};
	
