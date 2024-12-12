#include <Definer.h>
#include <EquipoPokemon.h>
#include <Juego.h>
class JuegoConsola
{
private:
    list<Pokemon> pokemons;
    list<Pokemon> equipoActual;
    list<Move> moveSetActual;
    Juego juego;
    int dPlayer1, dPlayer2;
    string oP1, oP2, pokemonName;
    int fasterPlayer, slowerPlayer;
    string oPFaster, oPSlower;

public:
    JuegoConsola()
    {
    }
    ~JuegoConsola() {}

    void Start()
    {
        cout << "Inicio del juego" << endl;
        this->ChooseTeam(1);
        this->ChooseTeam(2);
        this->juego.BeginCombat();

        while (true)
        {
            this->juego.BeginTurn();
            dPlayer1 = this->GetPlayerDesicion(1, 2);
            dPlayer2 = this->GetPlayerDesicion(2, 1);
            this->oP1 = this->PrepareDesicion(this->dPlayer1, 1);
            system("pause");
            system("cls");
            this->oP2 = this->PrepareDesicion(this->dPlayer2, 2);
            system("pause");
            system("cls");
            if (this->ExecuteTurn() == false)
                break;
            system("pause");
            system("cls");
        }
    }

    void PrintPokemonNames()
    {
        int i = 0;
        this->pokemons = juego.GetAllPokemons();
        for (auto &&pokemon : this->pokemons)
        {
            cout << i + 1 << ":";
            cout << pokemon.getNombre() << endl;
            i++;
        }
    }

    void ChooseTeam(int jugador)
    {
        bool IsAsignado;
        int opcion;
        this->juego.ChangePlayer(jugador);
        for (int i = 0; i < 6; i)
        {
            cout << "Forma tu equipo Player : " << jugador << endl;
            cout << "Elige el miembro numero: " << i + 1 << endl;
            this->PrintPokemonNames();
            cin >> opcion;
            IsAsignado = this->juego.CanAddPokemonToPlayer(opcion);
            if (IsAsignado == false)
            {
                i++;
            }
            else
            {
                cout << "Pokemon ya escogido escoga otro" << endl;
            }
            system("pause");
            system("cls");
        }
        this->juego.ApplyChangesToPlayer(jugador);
        this->ShowTeam(jugador);
        system("pause");
        system("cls");
    }

    int GetPlayerDesicion(int user, int enemy)
    {
        int desicion;
        this->juego.ChangePlayer(user);
        cout << "Pokemon Actual: ";
        this->PrintPokemon(user);
        this->juego.ChangePlayer(enemy);
        cout << "Pokemon Enemigo: ";
        this->PrintPokemon(enemy);
        cout << "1-Atacar" << endl;
        cout << "Otro numbero-Cambiar de pokemon" << endl;
        cin >> desicion;
        system("pause");
        system("cls");
        return desicion;
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
            this->oPFaster = this->oP1;
            this->oPSlower = this->oP2;
        }
        else
        {
            this->fasterPlayer = 2;
            this->slowerPlayer = 1;
            this->oPFaster = this->oP2;
            this->oPSlower = this->oP1;
        }
        this->ExecuteMove(fasterPlayer, slowerPlayer, oPFaster);
        juego.ChangePlayer(slowerPlayer);
        if (this->juego.GetJugadorActual().GetPokemonInCombat().GetHP() > 0)
        {
            this->ExecuteMove(slowerPlayer, fasterPlayer, oPSlower);
        }
        if (this->juego.IsGameOver(2) == 6)
        {
            cout << "Jugador 2 ya no tiene pokemons, Jugador 1 gana" << endl;
            return false;
        }
        if (juego.IsGameOver(1) == 6)
        {
            cout << "Jugador 1 ya no tiene pokemons, Jugador 2 gana" << endl;
            return false;
        }
        this->IsPokemonFainted(1);
        this->IsPokemonFainted(2);
        system("cls");
        return true;
    }

    string PrepareDesicion(int desicion, int user)
    {
        int chosen;
        this->juego.ChangePlayer(user);
        this->pokemonName = this->juego.GetJugadorActual().GetPokemonInCombat().getNombre();
        if (desicion == 1)
        {
            do
            {
                this->ShowMoveSet(user);
                cin >> chosen;
            } while (chosen < 1 || chosen > 4);
            return juego.ConvertNumberToStringMove(chosen);
        }
        else
        {
            do
            {
                this->ShowTeam(user);
                cin >> chosen;
                pokemonName = juego.ConvertNumberToStringPokemon(chosen);
                if (this->juego.GetJugadorActual().GetPokemonSpecific(pokemonName).GetHP() < 1)
                {
                    cout << "Este pokemon ya esta debilitado escoga otro" << endl;
                    system("pause");
                    system("cls");
                }
                else if (pokemonName == this->juego.GetJugadorActual().GetPokemonInCombat().getNombre())
                {
                    cout << "Pokemon en combate, escoga otro" << endl;
                    system("pause");
                    system("cls");
                }
            } while (pokemonName == this->juego.GetJugadorActual().GetPokemonInCombat().getNombre() || this->juego.GetJugadorActual().GetPokemonSpecific(pokemonName).GetHP() < 1);
            return pokemonName;
        }
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

    void ShowMoveSet(int jugador)
    {
        cout << "Jugador: " << jugador << endl;
        moveSetActual = juego.GetJugadorActual().GetPokemonInCombat().GetMoveSet();
        int i = 0;
        for (auto &moveset : moveSetActual)
        {
            cout << i + 1 << ":";
            cout << moveset.GetMoveName() << endl;
            i++;
        }
    }

    void ShowTeam(int jugador)
    {
        cout << "Jugador: " << jugador << endl;
        int i = 0;
        equipoActual = juego.GetJugadorActual().GetTeam();
        for (auto &pokemon : equipoActual)
        {
            cout << i + 1 << ":";
            cout << pokemon.getNombre() << " :";
            cout << pokemon.GetHP() << endl;
            i++;
        }
    }

    void PrintPokemon(int jugador)
    {
        this->juego.ChangePlayer(jugador);
        cout << this->juego.GetJugadorActual().GetPokemonInCombat().getNombre() << "---HP: ";
        cout << this->juego.GetJugadorActual().GetPokemonInCombat().GetHP() << endl;
        // this->PrintPokemonStats(jugador);
    }

    void PrintPokemonStats(int jugador)
    {
        cout << this->juego.GetJugadorActual().GetPokemonInCombat().GetAtk() << endl;
        cout << this->juego.GetJugadorActual().GetPokemonInCombat().GetDef() << endl;
        cout << this->juego.GetJugadorActual().GetPokemonInCombat().GetSAtk() << endl;
        cout << this->juego.GetJugadorActual().GetPokemonInCombat().GetSDef() << endl;
        cout << this->juego.GetJugadorActual().GetPokemonInCombat().GetSpeed() << endl;
    }

    void IsPokemonFainted(int jugador)
    {
        this->juego.ChangePlayer(jugador);
        if (juego.GetJugadorActual().GetPokemonInCombat().GetHP() < 1)
        {
            cout << this->juego.GetJugadorActual().GetPokemonInCombat().getNombre() << " ha sido debilitado" << endl;
            cout << "escoga otro pokemon" << endl;
            this->ExecuteChange(jugador, this->PrepareDesicion(2, jugador));
            this->juego.ApplyChangesToPlayer(jugador);
            system("pause");
        }
    }
};