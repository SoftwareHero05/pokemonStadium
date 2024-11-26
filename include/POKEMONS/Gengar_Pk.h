#pragma once
#include "Pk_Class.h"
#include <MOVES/ShadowBall_Move.h>
#include <MOVES/SludgeBomb_Move.h>
#include <MOVES/ThunderBolt_Move.h>



class Gengar : public Pokemon{
	public:
	ShadowBall *shadowBallMov;
    SludgeBomb *sludgeBombMov;
    ThunderBolt *thunderBoltMov;
 	Gengar():Pokemon(60, 65, 60,130, 75, 110){
 		iD = 8;
 		nombre = "Gengar";
 		Type1 = GHOST;
        Type2 = POISON;
		shadowBallMov = new ShadowBall();
		sludgeBombMov = new SludgeBomb();
		thunderBoltMov = new ThunderBolt();
	 }
	 ~Gengar() {
        delete shadowBallMov;
        delete sludgeBombMov;
        delete thunderBoltMov;
    }
};