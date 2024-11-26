#pragma once
#include "Pk_Class.h"
#include <MOVES/Psychic_Move.h>
#include <MOVES/MoonBlast_Mov.h>
#include <MOVES/ShadowBall_Move.h>

class Gardevoir : public Pokemon{
	public:
	Psychic *psychicMov;
    MoonBlast *moonBlastMov;
    ShadowBall *shadowBallMov;
 	Gardevoir():Pokemon(73, 65, 65, 125, 115, 85){ //+5Speed +5Hp
 		iD = 4;
 		nombre = "Gardevoir";
 		Type1 = PSYCHIC;
        Type2 = FAIRY;
        psychicMov = new Psychic();
        moonBlastMov = new MoonBlast();
        shadowBallMov = new ShadowBall();
	 }
	 ~Gardevoir() {
        delete psychicMov;
        delete  moonBlastMov;
        delete  shadowBallMov;
    }
};