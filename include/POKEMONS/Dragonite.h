#pragma once
#include "Pokemon.h"
#include <MOVES/DragonClaw.h>
#include <MOVES/WingAttack.h>
#include <MOVES/WaterFall.h>
#include <MOVES/DragonDance.h>
class Dragonite : public Pokemon
{

public:
    Dragonite() : Pokemon(91, 134, 95, 100, 100, 80,9,"Dragonite",DRAGON,FLYING)
    {
        this->AddMove(DragonClaw());
        this->AddMove(WingAttack());
        this->AddMove(WaterFall());
        this->AddMove(DragonDance());
    }
    ~Dragonite()
    {
    }
};