#pragma once
#include <Definer.h>
#include <EquipoPokemon.h>
#include <Juego.h>
class Bridge
{
private:
    list<Pokemon> pokemons;
    list<Pokemon> equipoActual;
    list<Move> moveSetActual;
    list<string> stringList;
    Juego juego;
    int DPlayer1, DPlayer2;
    string OP1, OP2, pokemonName;
    int fasterPlayer, slowerPlayer;
    string OPfaster, OpSlower;

public:
    Bridge()
    {
        this->GetAllPokemonNames();
    }
    ~Bridge() {}


    void GetAllPokemonNames()
    {
        int i = 0;
        this->pokemons = juego.GetAllPokemons();
        for (auto &&pokemon : this->pokemons)
        {
          this->stringList.emplace_back(pokemon.getNombre());
        }
    }
    
    list<string> getAllPokemonsNamesString(){
        return this->stringList;
    }

    string getSpecificPokemonName(int i){
        auto it = this->stringList.begin();
        advance(it, i);
        return *it;  
    }

    string getPokemonImageDirection(int i, int player){
        if(player == 1) return "./assets/images/POKEMONS_SPRITES/B_" + this->getSpecificPokemonName(i) + ".png";
        else return "./assets/images/POKEMONS_SPRITES/F_" + this->getSpecificPokemonName(i) + ".png";
    }

    int StringToNumberPokemon(string opcion){
        if(opcion == "Lucario") return 1;
        else if(opcion == "Charizard") return 2;
        else if(opcion == "Garchomp") return 3;
        else if(opcion == "Gardevoir") return 4;
        else if(opcion == "Suicune") return 5;
        else if(opcion == "Venusaur") return 6;
        else if(opcion == "Tyranitar") return 7;
        else if(opcion == "Gengar") return 8;
        else if(opcion == "Dragonite") return 9;
        else if(opcion == "Snorlax") return 10;
        else return 0;
    }

    void AsignTeam(list<int> teamChosen,int jugador){
        this->juego.ChangePlayer(jugador);
        for (auto &pokemon : teamChosen)
        {
            this->juego.CanAddPokemonToPlayer(pokemon);
        }
        this->juego.ApplyChangesToPlayer(jugador);
    }

};
