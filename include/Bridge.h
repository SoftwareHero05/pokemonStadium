#pragma once
#include <Definer.h>
#include <Juego.h>
class Bridge
{
private:
    list<Pokemon> pokemons;
    list<Pokemon> equipoActual;
    list<Move> moveSetActual;
    list<string> stringListAllPokemons;
    list<string> stringListTeam;
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

    Juego& Getjuego() {
        return this->juego;
    }

    void GetAllPokemonNames()
    {
        int i = 0;
        this->pokemons = juego.GetAllPokemons();
        for (auto &&pokemon : this->pokemons)
        {
          this->stringListAllPokemons.emplace_back(pokemon.getNombre());
        }
    }
    
    list<string> getAllPokemonsNamesString(){
        return this->stringListAllPokemons;
    }

    string getSpecificPokemonNameWithInt(int i){
        auto it = this->stringListAllPokemons.begin();
        advance(it, i);
        return *it;  
    }

    bool IsPokemonReal(string nombre){
        for (auto &&pokemon : this->pokemons)
        {
          if(pokemon.getNombre() == nombre) return true;
        }
        return false;
    }

    string getPokemonImageDirectionWithInt(int i, int player){
        if(player == 1) return "POKEMONS_SPRITES/B_" + this->getSpecificPokemonNameWithInt(i) + ".png";
        else return "POKEMONS_SPRITES/F_" + this->getSpecificPokemonNameWithInt(i) + ".png";
    }

    string getPokemonImageDirectionWithString(string nombre, int player){
        if(player == 1) return "POKEMONS_SPRITES/B_" + nombre + ".png";
        else return "POKEMONS_SPRITES/F_" + nombre + ".png";
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

    list <string> getTeamString(int jugador){
        this->stringListTeam.clear();
        this->equipoActual = this->juego.GetJugadorSpecific(jugador).GetTeam();
        for (auto &&pokemon : this->equipoActual)
        {   
            this->stringListTeam.push_back(pokemon.getNombre());
        }
        return this->stringListTeam;
    }

    string GetPokemonActual(int player){
        return this->juego.GetJugadorSpecific(player).GetPokemonInCombat().getNombre();
    }


};
