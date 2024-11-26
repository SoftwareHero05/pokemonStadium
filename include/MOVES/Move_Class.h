#pragma once
#include <Definer.h>
#include "LIST_TYPES.h"
#include <EffectivinenessMesage.h>

class Move{
	public:
	int id;
	string nombre;
	int potencia;
	int precision;
	int prioridad;
		
	Move(int potencia_, int precision_, int prioridad_) {
		potencia = potencia_;
		precision = precision_;
		prioridad = prioridad_;
	}
};