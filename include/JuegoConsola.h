#include <Definer.h>
#include <Jugador.h>
#include <Juego.h>
class JuegoConsola
{
private:
    list<Pokemon> pokemons;
    list <Pokemon> equipoActual;
    list <Move> moveSetActual;
    Juego juego;
    int DPlayer1,DPlayer2;
    string OP1,OP2,pokemonName;
    int fasterPlayer,slowerPlayer;
    string OPfaster,OpSlower;

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
        this->juego.BeginTurn();
        DPlayer1 = this->PlayerTurn(1,2);
        DPlayer2 = this->PlayerTurn(2,1);
        this->OP1 = this->PrepareDesicion(this->DPlayer1,1,2);
        system("pause");
        system("cls");
        this->OP2 = this->PrepareDesicion(this->DPlayer2,2,1);
        system("pause");
        system("cls");
        this->BattleExecuter();
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
        this->ShowEquipo();
        system("pause");
        system("cls");

    }

    int PlayerTurn(int User, int Enemy){
        int desicion;
        this->juego.AlternarJugador(User);
        cout<<"Pokemon Actual: "<<this->juego.getNombrePokemonActual()<<endl;
        this->juego.AlternarJugador(Enemy);
        cout<<"Pokemon Enemigo: "<<this->juego.getNombrePokemonActual()<<endl;
        cout<<"1-Atacar"<<endl;
        cout<<"Otro numbero-Cambiar de pokemon"<<endl;
        cin>>desicion;
        system("pause");
        system("cls");
        return desicion;
    
    }

    void BattleExecuter(){
        if(this->DPlayer1 != 1) {
        this->ExecuteChange(1,OP1);
        this->juego.applyChangesToPlayer(1);
        }
        if(this->DPlayer2 != 1) {
        this->ExecuteChange(2,OP2);
        this->juego.applyChangesToPlayer(2);
        }

        if(this->juego.getPokemonSpeed(1) >= this->juego.getPokemonSpeed(2))
        {
        this->fasterPlayer = 1;
        this->slowerPlayer = 2;
        this->OPfaster = this->OP1;
        this->OpSlower = this->OP2;
        }
        else {
        this->fasterPlayer = 2;
        this->slowerPlayer = 1;
        this->OPfaster = this->OP2;
        this->OpSlower = this->OP1;
        }
        this->ExecuteMove(fasterPlayer,slowerPlayer,OPfaster);
        this->PrintPokemon(slowerPlayer);
        this->ExecuteMove(slowerPlayer,fasterPlayer,OpSlower);
        this->PrintPokemon(fasterPlayer);
        system("cls");

    }

    string PrepareDesicion(int desicion,int User,int Enemy){
        int chosen ;
        this->juego.AlternarJugador(User);
        this->pokemonName = this->juego.getNombrePokemonActual();
        if(desicion == 1){
            do{
            this->ShowMoveSet();
            cin>>chosen;
            }while(chosen < 1 || chosen > 3);
            return juego.convertNumberToStringMove(chosen);   
        }
        else{
            do{
            this->ShowEquipo();
            cin>>chosen;
            pokemonName = juego.convertNumberToStringPokemon(chosen);
            if(pokemonName == this->juego.getNombrePokemonActual()) cout<<"Pokemon en combate, escoga otro"<<endl;
            }while(pokemonName == this->juego.getNombrePokemonActual());
            return pokemonName;
        }
    }

    bool ExecuteChange(int User,string nombre) {
        this->juego.AlternarJugador(User);
        if (this->juego.ChangePokemon(nombre) == true ) return true;
        else {
            cout<<"Pokemon ya en combate eliga otro"<<endl;
            return false;
        }
    }

    void ExecuteMove(int User, int Enemy, string nombre){
        this->juego.AlternarJugador(User);
        this->juego.ExecuteMoveChosen(nombre,Enemy,User);
    }
    
    
    void ShowMoveSet(){
       moveSetActual = juego.getMoveset();
       int i = 0;
        for (auto& moveset : moveSetActual) { 
            cout<<i+1<<":";
            cout<<moveset.GetMoveName()<<endl;
            i++;
        }
    }

     void ShowEquipo(){
       int i = 0;
        equipoActual = juego.getTeam();
        for (auto& pokemon : equipoActual) {
             cout<<i+1<<":"; 
            cout<<pokemon.getNombre()<<endl;
             i++;
            }
    }

    void PrintPokemon(int jugador){
        this->juego.AlternarJugador(jugador);
        cout<<this->juego.getNombrePokemonActual()<<endl;
        cout<<this->juego.getHpOfPokemon()<<endl;
        system("pause");
    }
    
  
    
};