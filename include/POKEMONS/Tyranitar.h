#pragma once
#include "Pk_Class.h"
#include <MOVES/StoneEdge_Move.h>
#include <MOVES/Crunch_Move.h>
#include <MOVES/Earthquake_Move.h>

class Tyranitar : public Pokemon{
	public:
	StoneEdge *stoneEdgeMov;
    Crunch *crunchMov;
    Earthquake *earthQuakeMov;
 	Tyranitar():Pokemon(100, 134, 110, 95, 100, 61){
 		iD = 7;
 		nombre = "Tyranitar";
 		Type1 = ROCK;
        Type2 = DARK;
        stoneEdgeMov = new StoneEdge();
        crunchMov = new Crunch ();
        earthQuakeMov = new Earthquake ();
	 }
	 ~Tyranitar() {
        delete stoneEdgeMov;
        delete crunchMov;
        delete earthQuakeMov;
    }
};