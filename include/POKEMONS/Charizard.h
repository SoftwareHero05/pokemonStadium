#pragma once
#include <POKEMONS/Pokemon.h>
#include <MOVES/Flamethrower.h>
#include <MOVES/DragonPulse.h>
#include <MOVES/AirSlash.h>
#include <MOVES/CalmMind.h>
class Charizard : public Pokemon
{

public:
    Charizard() : Pokemon(78, 84, 78, 109, 85, 100,2,"Charizard",FIRE,FLYING)
    {
        this->AddMove(Flamethrower());
        this->AddMove(AirSlash());
        this->AddMove(DragonPulse());
        this->AddMove(CalmMind());
    }
    ~Charizard()
    {
    }
};
