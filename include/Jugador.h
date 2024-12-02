#pragma once
#include <POKEMONS/Pokemon.h>
#include <POKEMONS/Pokemon.h>
#include <POKEMONS/Charizard.h>
#include <POKEMONS/Garchomp.h>
#include <POKEMONS/Suicune.h>
#include <POKEMONS/Lucario.h>
#include <POKEMONS/Gengar.h>
#include <POKEMONS/Gardevoir.h>
#include <POKEMONS/Venusaur.h>
#include <POKEMONS/Tyranitar.h>

class Jugador
{
private:
    list<Pokemon> equipo;
    int NumberOfPokemons = 0;
    int PlayerNumber;
    Pokemon pokemonActual;
    Pokemon EnemyPokemon;
    bool IsMove,IsAtacking;

public:
    Jugador() {
        
    }
    ~Jugador() {}  

    list <Pokemon>& getTeam(){
        return this->equipo;
    }
    
    
    void AsignarPokemon(Pokemon pokemon){
        this->equipo.emplace_back(pokemon);
        this->NumberOfPokemons++;
    }

    void AsignarEnemy(Pokemon Enemy){
        this->EnemyPokemon = Enemy;
    }

    Pokemon SearchPokemon(string nombre) {
    for (auto& pokemon : this->equipo) { 
         if (pokemon.getNombre() == nombre) { 
                return pokemon;
            }
        }
        return Lucario();
    }

   bool IsPokemonInTeam(string nombre) {
    for (auto& pokemon : this->equipo) { 
         if (pokemon.getNombre() == nombre) { 
                return true;
            }
        }
        return false;
    }

    Pokemon GetPokemonInCombat(){
        return this->pokemonActual;
    }

   string GetPokemonInCombatName(){
        return this->pokemonActual.getNombre();
    }

    void AsignarPokemonInCombat(Pokemon pokemon){
        this->pokemonActual = pokemon;
    }

    Pokemon GetPokemonLeader(){
        return this->equipo.front();
    }

    int ExecuteMoveChosen(string nombre){
        this->IsMove = this->pokemonActual.IsMoveInMoveSet(nombre);
        if(this->IsMove == true) return this->pokemonActual.ExecuteMoveChosen(nombre,this->EnemyPokemon);
        else return 0;
    }    

    list <Move> getMoveSet(){
        return this->pokemonActual.GetMoveSet();
    }
};
    