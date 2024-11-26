#pragma once
#include <POKEMONS/Pokemon.h>
#include <MOVES/Flamethrower.h>
#include <MOVES/DragonPulse.h>
#include <MOVES/AirSlash.h>

class Charizard : public Pokemon
{
public:
    Charizard() : Pokemon(78, 84, 78, 109, 85, 100)
    {
        iD = 2;
        nombre = "Charizard";
        Type1 = FIRE;
        Type2 = FLYING;

        this->AddMove(Flamethrower());
        this->AddMove(AirSlash());
        this->AddMove(DragonPulse());
    }
    ~Charizard()
    {
    }
};
