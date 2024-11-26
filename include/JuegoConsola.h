#include <Definer.h>
#include <Jugador.h>
#include <MovExecuter.h>

class JuegoConsola
{
private:
    Jugador jugador1, jugador2;
    list<Pokemon> pokemons;

public:
    JuegoConsola()
    {
    }
    ~JuegoConsola() {}

    void Iniciar(){
        cout<<"Inicio del juego"<<endl;
    }

    void AlternarJugador(){
       
    }

    void PrintPokemonNames()
    {
        for (auto &&pokemon : pokemons)
        {
            cout << pokemon.getNombre();
        }
    }

    void ChooseTeam(int jugador)
    {
        int i;
        cout << "Forma tu equipo Player : " << jugador << endl;
        cout << "Elige el miembro numero: " << i + 1 << endl;
        this->PrintPokemonNames();
        int opcion;
        cin >> opcion;
    }

    void AsignarPokemon(Jugador &jugador,Pokemon pokemon)
    {
        jugador.AsignarPokemon(pokemon);
    }

    int changePokemon(Pokemon *team[], int actual)
    {
        // int choise;
        // while (true)
        // {
        //     system("cls");
        //     cout << "Seleccione un pokemon para salir a combatir" << endl;
        //     cout << "1: " << team[0]->nombre << "--- Hp: " << team[0]->Hp << endl;
        //     cout << "2: " << team[1]->nombre << "--- Hp: " << team[1]->Hp << endl;
        //     cout << "3: " << team[2]->nombre << "--- Hp: " << team[2]->Hp << endl;
        //     cout << "4: " << team[3]->nombre << "--- Hp: " << team[3]->Hp << endl;
        //     cout << "5: " << team[4]->nombre << "--- Hp: " << team[4]->Hp << endl;
        //     cout << "6: " << team[5]->nombre << "--- Hp: " << team[5]->Hp << endl;
        //     cin >> choise;
        //     if (team[choise - 1]->Hp < 1)
        //     {
        //         cout << "Este pokemon ya no puede combatir" << endl;
        //         cout << "Seleccione otro porfavor" << endl;
        //     }
        //     else if ((choise - 1) == actual)
        //         cout << "Este pokemon ya esta combatiendo" << endl;
        //     else
        //         return choise;
        //     system("pause");
        //     system("cls");
        // }
        return 0;
    }
};