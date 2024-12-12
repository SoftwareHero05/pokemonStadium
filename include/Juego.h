#pragma once
#include "EquipoPokemon.h"

class Juego
{
private:
    EquipoPokemon jugador1;
    EquipoPokemon jugador2;
    EquipoPokemon jugadorActual;
    list<Pokemon> pokemons;
    list<Move> moveSetActual;
    list<string> moveSetActualNames;
    Pokemon pokemon;
    list<Pokemon> equipoActual;
    list<string> equipoActualNames;

public:
    Juego()
    {
        this->pokemons.emplace_back(Lucario());
        this->pokemons.emplace_back(Charizard());
        this->pokemons.emplace_back(Garchomp());
        this->pokemons.emplace_back(Gardevoir());
        this->pokemons.emplace_back(Suicune());
        this->pokemons.emplace_back(Venusaur());
        this->pokemons.emplace_back(Tyranitar());
        this->pokemons.emplace_back(Gengar());
        this->pokemons.emplace_back(Dragonite());
        this->pokemons.emplace_back(Snorlax());
    }
    ~Juego() {}

    Pokemon CreatePokemon(int opcion)
    {
        switch (opcion)
        {
        case 1:
            return Lucario();
        case 2:
            return Charizard();
        case 3:
            return Garchomp();
        case 4:
            return Gardevoir();
        case 5:
            return Suicune();
        case 6:
            return Venusaur();
        case 7:
            return Tyranitar();
        case 8:
            return Gengar();
        case 9:
            return Dragonite();
        case 10:
            return Snorlax();
        default:
            return Lucario();
        }
    }

    void AddPokemonToPlayer(Pokemon opcion)
    {
        this->jugadorActual.AddPokemon((opcion));
    }

    bool CanAddPokemonToPlayer(int opcion)
    {
        bool notChosen = true;
        Pokemon pokemon = CreatePokemon(opcion);
        notChosen = this->jugadorActual.IsPokemonInTeam(pokemon.getNombre());
        if (notChosen == false)
            this->AddPokemonToPlayer(pokemon);

        return notChosen;
    }

    void ChangePlayer(int jugador)
    {
        if (jugador == 1)
            this->jugadorActual = this->jugador1;
        else
            this->jugadorActual = jugador2;
    }

    void ApplyChangesToPlayer(int jugador)
    {
        if (jugador == 1)
            this->jugador1 = this->jugadorActual;
        else
            this->jugador2 = this->jugadorActual;
    }

    void AssignEnemyToPlayer(int jugador)
    {
        if (jugador == 1)
            this->jugador1.AssignEnemy(jugador2.GetPokemonInCombat());
        else
            this->jugador2.AssignEnemy(jugador1.GetPokemonInCombat());
    }

    list<Pokemon> &GetAllPokemons()
    {
        return this->pokemons;
    }

    list<Pokemon> &GetTeamSpefic(int jugador)
    {
        if (jugador == 1)
            return this->jugador1.GetTeam();
        else
            return this->jugador2.GetTeam();
    }

    void BeginCombat()
    {
        this->jugador1.AssignPokemonInCombat(this->jugador1.GetPokemonLeader());
        this->jugador2.AssignPokemonInCombat(this->jugador2.GetPokemonLeader());
    }

    void BeginTurn()
    {
        this->AssignEnemyToPlayer(1);
        this->AssignEnemyToPlayer(2);
    }

    EquipoPokemon GetJugador()
    {
        return this->jugadorActual;
    }

    EquipoPokemon GetJugadorSpecific(int jugador)
    {
        if (jugador == 1)
            return this->jugador1;
        else
            return this->jugador2;
    }

    void ExecuteMoveChosen(string nombre, int Enemy, int User)
    {
        int damage = this->jugadorActual.ExecuteMoveChosen(nombre);
        this->ApplyChangesToPlayer(User);
        this->ChangePlayer(Enemy);
        this->ApplyDamageToPokemon(damage);
        this->ApplyChangesToPlayer(Enemy);
        this->ChangePlayer(User);
    }

    string ConvertNumberToStringMove(int number)
    {
        this->moveSetActualNames.clear();
        this->moveSetActual.clear();
        this->moveSetActual = this->jugadorActual.GetPokemonInCombat().GetMoveSet();
        for (auto &&move : this->moveSetActual)
        {
            this->moveSetActualNames.push_back(move.GetMoveName());
        }
        auto it = this->moveSetActualNames.begin();
        advance(it, number - 1);
        return *it;
    }

    string ConvertNumberToStringPokemon(int number)
    {
        this->equipoActualNames.clear();
        this->equipoActual.clear();
        this->equipoActual = jugadorActual.GetTeam();
        for (auto &&equipo : this->equipoActual)
        {
            this->equipoActualNames.push_back(equipo.getNombre());
        }
        auto it = this->equipoActualNames.begin();
        advance(it, number - 1);
        return *it;
    }

    void ChangePokemon(string nombre)
    {
        this->jugadorActual.GetPokemonInCombat().RestartStats();
        this->jugadorActual.AssignPokemonInCombat((this->jugadorActual.SearchPokemon(nombre)));
    }

    void ApplyDamageToPokemon(int damage)
    {
        this->jugadorActual.ApplyDamageToPokemon(damage);
    }

    EquipoPokemon GetJugadorActual()
    {
        return this->jugadorActual;
    }

    int IsGameOver(int jugador)
    {
        int i = 0;
        for (auto &team : this->GetJugadorSpecific(jugador).GetTeam())
        {
            if (team.GetHP() < 1)
                i++;
        }
        return i;
    }

    string GetEffectivenesMessage(string nombre)
    {
        return this->jugadorActual.GetEffectivenessMessage(nombre);
    }
};