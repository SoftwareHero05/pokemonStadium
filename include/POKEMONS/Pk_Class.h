#pragma once
#include <Definer.h>

class Pokemon{
	public:
	int iD;
	string nombre;
	int Hp, Atk, Def, SAtk, SDef, Speed, Type1,Type2;
	int BAtk,BDef,BSAtk,BSDef,BSpeed, BHp;
	Pokemon(int Hp_, int Atk_, int Def_, int SAtk_, int SDef_, int Speed_){
		Hp = Hp_;
		Atk = Atk_;
		Def = Def_;
		SAtk = SAtk_;
		SDef = SDef_;
		Speed = Speed_;
		BAtk = Atk_;
		BDef = Def;
		BSAtk = SAtk_;
		BSDef = SDef;
		BSpeed = Speed;
		BHp = Hp_;
	}
    // Destructor virtual para hacer que la clase sea polimórfica
    virtual ~Pokemon() {}

    // Método virtual para obtener el nombre, también puede ser redefinido en clases derivadas
    virtual string getNombre() const { return nombre; }

	void RestartStats(){
		this->Atk = this->BAtk;
		this->Def = this->BDef;
		this->SAtk = this->BSAtk;
		this->SDef = this->BSDef;
		this->Speed = this->BSpeed;
	}
};
