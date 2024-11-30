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

     Pokemon SearchPokemon(string nombre) {
    for (auto& pokemon : this->equipo) { 
         if (pokemon.getNombre() == nombre) { 
                return pokemon;
            }
        }
    }

   bool PokemonAlreadyInTeam(string nombre) {
    for (auto& pokemon : this->equipo) { 
         if (pokemon.getNombre() == nombre) { 
                return true;
            }
        }
        return false;
    }
    
};
    