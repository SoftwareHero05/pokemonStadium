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

class EquipoPokemon
{
private:
    // Clase Equipo
    list<Pokemon> equipo;
    Pokemon pokemonActual;
    bool IsMove, IsAtacking;
    Pokemon EnemyPokemon;

public:
    EquipoPokemon()
    {
    }
    ~EquipoPokemon() {}

    list<Pokemon> &GetTeam()
    {
        return this->equipo;
    }

    void AddPokemon(Pokemon pokemon)
    {
        this->equipo.emplace_back(pokemon);
    }

    void AsingEnemy(Pokemon Enemy)
    {
        this->EnemyPokemon = Enemy;
    }

    Pokemon SearchPokemon(string nombre)
    {
        for (auto &pokemon : this->equipo)
        {
            if (pokemon.getNombre() == nombre)
            {
                return pokemon;
            }
        }
        return Lucario();
    }

    void ApplyDamageToSpecifiPokemon(string nombre, int damage)
    {
        for (auto &pokemon : this->equipo)
        {
            if (pokemon.getNombre() == nombre)
            {
                pokemon.ApplyDamageToPokemon(damage);
            }
        }
    }

    bool IsPokemonInTeam(string nombre)
    {
        for (auto &pokemon : this->equipo)
        {
            if (pokemon.getNombre() == nombre)
            {
                return true;
            }
        }
        return false;
    }

    Pokemon GetPokemonInCombat()
    {
        return this->pokemonActual;
    }

    Pokemon GetPokemonSpecific(string nombre){
        return this->SearchPokemon(nombre);
    }
    void AsingPokemonInCombat(Pokemon pokemon)
    {
        this->pokemonActual = pokemon;
    }

    Pokemon GetPokemonLeader()
    {
        return this->equipo.front();
    }

    int ExecuteMoveChosen(string nombre)
    {
        this->IsMove = this->pokemonActual.IsMoveInMoveSet(nombre);
        if (this->IsMove == true)
            return this->pokemonActual.ExecuteMoveChosen(nombre, this->EnemyPokemon);
        else
            return 0;
    }

    void ApplyDamageToPokemon(int damage)
    {
        this->pokemonActual.ApplyDamageToPokemon(damage);
        this->ApplyDamageToSpecifiPokemon(this->pokemonActual.getNombre(), damage);
    }
};
