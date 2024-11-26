#pragma once
#include <Definer.h>
#include "LIST_TYPES.h"
#include <EffectivinenessMesage.h>

class Move{

protected:
	int id;
	string nombre;
	int potencia;
	int precision;
	int prioridad;

public:
	Move(int potencia_, int precision_, int prioridad_) {
		potencia = potencia_;
		precision = precision_;
		prioridad = prioridad_;
	}

	string GetMoveName(){
		return this->nombre;
	}
};