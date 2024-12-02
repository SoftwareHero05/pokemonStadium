#include <Definer.h>
#include "Jugador.h"

class Juego{
    private:
    Jugador jugador1;
    Jugador jugador2;
    Jugador jugadorActual;
    list<Pokemon> pokemons;
    list <Move> moveSetActual;
    list <string> moveSetActualNames;
    Pokemon pokemon;
    list <Pokemon> equipoActual;
    list <string> equipoActualNames;
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
        
    }
    ~Juego() {}

    Pokemon CreatePokemon(int opcion){
        switch (opcion)
        {
        case 1: return Lucario();
        case 2: return Charizard();
        case 3: return Garchomp();
        case 4: return Gardevoir();
        case 5: return Suicune();
        case 6: return Venusaur();
        case 7: return Tyranitar();
        case 8: return Gengar();
        default : return Lucario();
        }
    }
    void AsignarPokemonToPlayer(Pokemon opcion) {
    this->jugadorActual.AsignarPokemon((opcion));
    }

    bool addPokemonToPlayer(int opcion){
        bool notChosen = true;
        Pokemon pokemon = CreatePokemon(opcion);
        notChosen = this->jugadorActual.IsPokemonInTeam(pokemon.getNombre());
        if(notChosen == false) this->AsignarPokemonToPlayer(pokemon);
		
    return notChosen;
    }

    void AlternarJugador(int jugador){
      if(jugador == 1) this->jugadorActual = this->jugador1;
      else this->jugadorActual = jugador2;
    }

    void applyChangesToPlayer(int jugador){
        if(jugador == 1) this->jugador1 = this->jugadorActual;
      else this->jugador2 = this->jugadorActual;
    }

    void AsignarEnemyToPlayer(int jugador){
        if(jugador == 1) this->jugador1.AsignarEnemy(jugador2.GetPokemonInCombat());
        else this->jugador2.AsignarEnemy(jugador1.GetPokemonInCombat());
    }

    list <Pokemon>& getTeam(){
        return jugadorActual.getTeam();
    }

    list <Pokemon>& getAllPokemons(){
        return this->pokemons;
    }

    list <Pokemon>& getTeamSpefic(int jugador){
         if(jugador == 1) return this->jugador1.getTeam();
         else return this->jugador2.getTeam();
    }

    Pokemon GetPokemonLeaderOfPlayer(){
        return this->jugadorActual.GetPokemonLeader();
    }

      Pokemon GetPokemonInCombatOfPlayer(){
        return this->jugadorActual.GetPokemonInCombat();
    }

    void InicioCombate(){
        this->jugador1.AsignarPokemonInCombat(this->jugador1.GetPokemonLeader());
        this->jugador2.AsignarPokemonInCombat(this->jugador2.GetPokemonLeader());
    }

    void BeginTurn(){
        this->AsignarEnemyToPlayer(1);
        this->AsignarEnemyToPlayer(2);
    }

    Jugador getJugador(){
        return this->jugadorActual;
    }

    Jugador getJugadorSpecific(int jugador){
        if(jugador == 1) return this->jugador1;
        else return this->jugador2;
    }

    string getNombrePokemonActual(){
        return this->jugadorActual.GetPokemonInCombatName();
    }
    
    void ExecuteMoveChosen(string nombre,int Enemy,int User){
       int damage = this->jugadorActual.ExecuteMoveChosen(nombre);
       this->AlternarJugador(Enemy);
       this->ApplyDamageToPokemon(damage);
       this->applyChangesToPlayer(Enemy);
       this->AlternarJugador(User);
    }

     list <Move> getMoveset(){
        return this->jugadorActual.getMoveSet();
    }

    string convertNumberToStringMove(int number){
        this->moveSetActualNames.clear();
        this->moveSetActual.clear();
        this->moveSetActual = this->getMoveset();  
        for (auto &&move : this->moveSetActual)
        {
            this->moveSetActualNames.push_back(move.GetMoveName());   
        }
        auto it = this->moveSetActualNames.begin();
        advance(it, number - 1);
        return *it;
    }

    string convertNumberToStringPokemon(int number){
        this->equipoActualNames.clear();
        this->equipoActual.clear();
        this->equipoActual = jugadorActual.getTeam();
        for (auto &&equipo : this->equipoActual)
        {
            this->equipoActualNames.push_back(equipo.getNombre());   
        }
        auto it = this->equipoActualNames.begin();
        advance(it, number - 1);
        return *it;
    }

    void ChangePokemon(string nombre){
            this->jugadorActual.AsignarPokemonInCombat((this->jugadorActual.SearchPokemon(nombre)));
    }

    int getPokemonSpeed(int jugador){
        if(jugador == 1) return jugador1.getSpeed();
        else return jugador2.getSpeed();
    }

    void ApplyDamageToPokemon(int damage){
        this->jugadorActual.ApplyDamageToPokemon(damage);
    }

    int getHpOfPokemon(){
        return this->jugadorActual.getHp();
    }

    int getHpOfSpecificPokemon(string nombre){
        return this->jugadorActual.getSpecificHp(nombre);
    }

    void decreaseQuantityPokemon(){
        this->jugadorActual.decreaseQuantityPokemon();
    }
    int getQuantityPokemon(){
        return this->jugadorActual.getQuantityPokemon();
    }

    
};