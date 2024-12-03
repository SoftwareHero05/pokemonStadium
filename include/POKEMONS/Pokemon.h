#pragma once
#include <Definer.h>
#include <MOVES/Move.h>
#include <MOVES/AuraSphere.h>

class Pokemon
{
protected:
	int iD;
	string nombre;
	int Hp, Atk, Def, SAtk, SDef, Speed, Type1, Type2;
	int BAtk, BDef, BSAtk, BSDef, BSpeed, BHp;
	list<Move> moves;
	Move chosen;

public:
	// constructor con movimientos
	Pokemon(int Hp, int Atk, int Def, int SAtk, int SDef, int Speed, list<Move> moves,
			int iD, string nombre, int Type1, int Type2) : Hp{Hp}, Atk{Atk}, Def{Def}, SAtk{SAtk}, SDef{SDef},
														   Speed{Speed}, BAtk{Atk}, BDef{Def}, BSAtk{SAtk}, BSDef{SDef}, BSpeed{Speed}, BHp{Hp}, moves{moves},
														   iD{iD}, nombre{nombre}, Type1{Type1}, Type2{Type2}
	{
	}
	// constructor sin movimientos
	Pokemon(int Hp, int Atk, int Def, int SAtk, int SDef, int Speed,
			int id, string nombre, int Type1, int Type2) : Pokemon(Hp, Atk, Def, SAtk, SDef, Speed, list<Move>(), id, nombre, Type1, Type2)
	{}
	// constructor vacio
	Pokemon() {}
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

	Move SearchMove(string nombre) {
    for (auto& move : this->moves) { 
         if (move.GetMoveName() == nombre) { 
                return move;
            }
        }
		return AuraSphere();
    }

	bool IsMoveInMoveSet(string nombre) {
    for (auto& move : this->moves) { 
         if (move.GetMoveName() == nombre) { 
                return true;
            }
        }
        return false;
    }

	int ExecuteMoveChosen(string nombre, Pokemon Enemy)
	{
		if (nombre == "DragonDance" || nombre == "NastyPlot" || nombre == "CalmMind" || nombre == "Synthesis" || nombre == "Curse")
		{
			this->ExecuteBoostMove(nombre);
			return 0;
		}
		else
		{
			this->chosen = this->SearchMove(nombre);
			return chosen.ExecuteMove(this->getType1(), this->getType2(),
									  Enemy.getType1(), Enemy.getType2(), this->GetAtk(), this->GetSAtk(),
									  Enemy.GetDef(), Enemy.GetSDef());
		}
	}

	void ExecuteBoostMove(string nombre){
		if(nombre == "DragonDance") this->MoveDragonDance();
		else if(nombre == "CalmMind") this->MoveCalmMind();
		else if(nombre == "NastyPlot") this->MoveNastyPlot();
		else if(nombre == "Synthesis") this->MoveSynthesis();
		else if(nombre == "Curse") this->MoveCurse();
	}

	int GetHP()
	{
		return this->Hp;
	}
	int GetAtk()
	{
		return this->Atk;
	}
	int GetDef()
	{
		return this->Def;
	}
	int GetSAtk()
	{
		return this->SAtk;
	}
	int GetSDef()
	{
		return this->SDef;
	}
	int GetSpeed()
	{
		return this->Speed;
	}
	int getType1()
	{
		return this->Type1;
	}
	int getType2()
	{
		return this->Type2;
	}

	void boostAtk()
	{
		this->Atk = this->Atk + (this->BAtk * .5);
	}
	void boostDef()
	{
		this->Def = this->Def + (this->BDef * .5);
	}
	void boostSAtk()
	{
		this->SAtk = this->SAtk + (this->BSAtk * .5);
	}
	void boostSDef()
	{
		this->SDef = this->SDef + (this->BSDef * .5);
	}
	void boostSpeed()
	{
		this->Speed = this->Speed + (this->BSpeed * .5);
	}
	void heal50Percent()
	{
		this->Hp += (this->BHp * .5);
		if (this->Hp > this->BHp) this->Hp = this->BHp;
	}
	void ApplyDamageToPokemon(int damage){
		this->Hp -= damage;
	}

	void MoveDragonDance(){
		this->boostAtk();
		this->boostSpeed();
	}
	void MoveCalmMind(){
		this->boostSAtk();
		this->boostSDef();
	}
	void MoveNastyPlot(){
		this->boostSAtk();
		this->boostSAtk();
	}
	void MoveSynthesis(){
		this->heal50Percent();
		
	}
	void MoveCurse(){
		this->boostAtk();
		this->boostDef();
	}
};
