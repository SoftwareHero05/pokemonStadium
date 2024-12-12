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
    list<string> stringMoveSet;
    list<string> stringFainted;
    Juego juego;
    int dPlayer1, dPlayer2;
    string oP1, oP2, pokemonName;
    int fasterPlayer, slowerPlayer;
    string oPfaster, opSlower;

public:
    Bridge()
    {
        this->GetAllPokemonNames();
    }
    ~Bridge() {}

    Juego &Getjuego()
    {
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

    list<string> GetAllPokemonsNamesString()
    {
        return this->stringListAllPokemons;
    }

    string GetSpecificPokemonNameWithInt(int i)
    {
        auto it = this->stringListAllPokemons.begin();
        advance(it, i);
        return *it;
    }

    string GetSpecificPokemonNameOfTeamWithIndex(int i)
    {
        auto it = this->stringListTeam.begin();
        advance(it, i);
        return *it;
    }

    bool IsPokemonReal(string nombre)
    {
        for (auto &&pokemon : this->pokemons)
        {
            if (pokemon.getNombre() == nombre)
                return true;
        }
        return false;
    }

    string GetPokemonImageDirectionWithInt(int i, int player)
    {
        if (player == 1)
            return "POKEMONS_SPRITES/B_" + this->GetSpecificPokemonNameWithInt(i) + ".png";
        else
            return "POKEMONS_SPRITES/F_" + this->GetSpecificPokemonNameWithInt(i) + ".png";
    }

    string GetPokemonImageDirectionWithString(string nombre, int player)
    {
        if (player == 1)
            return "POKEMONS_SPRITES/B_" + nombre + ".png";
        else
            return "POKEMONS_SPRITES/F_" + nombre + ".png";
    }

    int ChangeStringToNumberPokemon(string opcion)
    {
        if (opcion == "Lucario")
            return 1;
        else if (opcion == "Charizard")
            return 2;
        else if (opcion == "Garchomp")
            return 3;
        else if (opcion == "Gardevoir")
            return 4;
        else if (opcion == "Suicune")
            return 5;
        else if (opcion == "Venusaur")
            return 6;
        else if (opcion == "Tyranitar")
            return 7;
        else if (opcion == "Gengar")
            return 8;
        else if (opcion == "Dragonite")
            return 9;
        else if (opcion == "Snorlax")
            return 10;
        else
            return 0;
    }

    void AsignTeam(list<int> teamChosen, int jugador)
    {
        this->juego.ChangePlayer(jugador);
        for (auto &pokemon : teamChosen)
        {
            this->juego.CanAddPokemonToPlayer(pokemon);
        }
        this->juego.ApplyChangesToPlayer(jugador);
    }

    list<string> GetTeamString(int jugador)
    {
        this->stringListTeam.clear();
        this->equipoActual = this->juego.GetJugadorSpecific(jugador).GetTeam();
        for (auto &&pokemon : this->equipoActual)
        {
            this->stringListTeam.push_back(pokemon.getNombre());
        }
        return this->stringListTeam;
    }

    string GetPokemonActual(int player)
    {
        return this->juego.GetJugadorSpecific(player).GetPokemonInCombat().getNombre();
    }

    void SetPlayerDecision(int jugador, int eleccion, string nombre)
    {
        if (jugador == 1)
        {
            this->dPlayer1 = eleccion;
            this->oP1 = nombre;
        }
        else
        {
            this->dPlayer2 = eleccion;
            this->oP2 = nombre;
        }
    }

    bool ExecuteTurn()
    {
        if (this->dPlayer1 != 1)
        {
            this->ExecuteChange(1, oP1);
            this->juego.ApplyChangesToPlayer(1);
        }
        if (this->dPlayer2 != 1)
        {
            this->ExecuteChange(2, oP2);
            this->juego.ApplyChangesToPlayer(2);
        }
        this->juego.BeginTurn();
        if (this->juego.GetJugadorSpecific(1).GetPokemonInCombat().GetSpeed() >= this->juego.GetJugadorSpecific(2).GetPokemonInCombat().GetSpeed())
        {
            this->fasterPlayer = 1;
            this->slowerPlayer = 2;
            this->oPfaster = this->oP1;
            this->opSlower = this->oP2;
        }
        else
        {
            this->fasterPlayer = 2;
            this->slowerPlayer = 1;
            this->oPfaster = this->oP2;
            this->opSlower = this->oP1;
        }

        this->ExecuteMove(fasterPlayer, slowerPlayer, oPfaster);
        juego.ChangePlayer(slowerPlayer);
        if (this->juego.GetJugadorActual().GetPokemonInCombat().GetHP() > 0)
        {
            this->ExecuteMove(slowerPlayer, fasterPlayer, opSlower);
        }
        return true;
    }

    void ExecuteChange(int user, string nombre)
    {
        this->juego.ChangePlayer(user);
        this->juego.ChangePokemon(nombre);
    }

    void ExecuteMove(int user, int enemy, string nombre)
    {
        this->juego.ChangePlayer(user);
        this->juego.ExecuteMoveChosen(nombre, enemy, user);
    }

    string GetHP(int jugador)
    {
        return std::to_string(this->juego.GetJugadorSpecific(jugador).GetPokemonInCombat().GetHP());
    }

    list<string> GetMoveSet(int jugador)
    {
        this->stringMoveSet.clear();
        this->moveSetActual = this->juego.GetJugadorSpecific(jugador).GetPokemonInCombat().GetMoveSet();
        for (auto &move : moveSetActual)
        {
            this->stringMoveSet.push_back(move.GetMoveName());
        }
        return this->stringMoveSet;
    }

    list<string> GetFaintedPokemon(int jugador)
    {
        this->stringFainted.clear();
        this->equipoActual = this->juego.GetJugadorSpecific(jugador).GetTeam();
        for (auto &pokemon : this->equipoActual)
        {
            if (pokemon.GetHP() < 1)
                this->stringFainted.push_back(pokemon.getNombre());
        }
        return this->stringFainted;
    }

    bool IsGameOver(int jugador)
    {
        if (this->juego.IsGameOver(jugador) == 6)
            return true;
        else
            return false;
    }

    int GetDecisionPlayer(int player)
    {
        if (player == 1)
            return this->dPlayer1;
        else
            return this->dPlayer2;
    }

    bool IsPlayer1Faster()
    {
        if (this->juego.GetJugadorSpecific(1).GetPokemonInCombat().GetSpeed() >= this->juego.GetJugadorSpecific(2).GetPokemonInCombat().GetSpeed())
            return true;
        else
            return false;
    }

    string GetMoveName(int player)
    {
        if (player == 1)
            return this->oP1;
        else
            return this->oP2;
    }

    string GetMoveEffectivenes(int user, string nombre)
    {
        this->juego.ChangePlayer(user);
        return this->juego.GetEffectivenesMessage(nombre);
    }
};
