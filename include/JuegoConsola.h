#include <Definer.h>
#include <Jugador.h>
#include <Juego.h>
#include <POKEMONS/Charizard.h>
#include <POKEMONS/Garchomp.h>
class JuegoConsola
{
private:
    list<Pokemon> pokemons;
    list <Pokemon> equipoActual;
    list <Move> moveSetActual;
    Juego juego;
   int desicion,DPlayer1,DPlayer2;

public:
  
    JuegoConsola()
    {
    }
    ~JuegoConsola() {}

    void MainFuction(){
        cout<<"Inicio del juego"<<endl;
        this->ChooseTeam(1);
        this->ChooseTeam(2);
        this->juego.InicioCombate();
        while(true) {
        DPlayer1 = this->PlayerTurn(1,2);
        DPlayer2 = this->PlayerTurn(2,1);
        }
        
    }

    void PrintPokemonNames()
    {   
        int i = 0; 
        this->pokemons = juego.getAllPokemons();
        for (auto &&pokemon : this->pokemons)
        {
            cout<<i+1<<":";
            cout << pokemon.getNombre()<<endl;
            i++;
        }
    }

    void ChooseTeam(int jugador)
    {
        bool IsAsignado;
        int opcion;
        this->juego.AlternarJugador(jugador);
        for(int i=0;i<6;i) {
        cout << "Forma tu equipo Player : " << jugador << endl;
        cout << "Elige el miembro numero: " << i + 1 << endl;
        this->PrintPokemonNames();
        cin>>opcion;
        IsAsignado = this->juego.addPokemonToPlayer(opcion);
        if(IsAsignado == false) {i++;}
        else {cout<<"Pokemon ya escogido escoga otro"<<endl;}
        system("pause");
        system("cls");
        }
        this->juego.applyChangesToPlayer(jugador);
        equipoActual = juego.getTeam();
        for (auto& pokemon : equipoActual) { 
            cout<<pokemon.getNombre()<<endl;
            }
        system("pause");
        system("cls");

    }

    int PlayerTurn(int User, int Enemy){
        this->juego.AlternarJugador(User);
        cout<<"Pokemon Actual: "<<this->juego.getNombrePokemonActual()<<endl;
        this->juego.AlternarJugador(Enemy);
        cout<<"Pokemon Enemigo: "<<this->juego.getNombrePokemonActual()<<endl;
        cout<<"1-Atacar"<<endl;
        cout<<"Otro numbero-Cambiar de pokemon"<<endl;
        cin>>this->desicion;
        system("pause");
        system("cls");
        return this->desicion;
    
    }
    void ExecuteDesicion(int desicion,int User,int Enemy){

    }
    

    void ShowMoveSet(){
       moveSetActual = juego.getMoveset();
        for (auto& moveset : moveSetActual) { 
            cout<<moveset.GetMoveName()<<endl;
            }

        
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