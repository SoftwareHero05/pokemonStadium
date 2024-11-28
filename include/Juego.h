#include <Definer.h>
#include <POKEMONS/Pokemon.h>
#include "Jugador.h"

class Juego{
    private:
    Jugador jugador1;
    Jugador jugador2;
    Jugador jugadorActual;
     list<Pokemon> pokemons = {Lucario(),Charizard(),Garchomp(),Gardevoir(),
        Suicune(),Venusaur()};
    public:
    Juego()
    {
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
        }
    }
    void AsignarPokemonToPlayer(int opcion) {
    jugadorActual.AsignarPokemon(CreatePokemon(opcion));
    }
    bool VerifyChosenPokemon(int opcion){
        bool notChosen;
        Pokemon pokemon = CreatePokemon(opcion);
        notChosen = jugadorActual.PokemonAlreadyInTeam(pokemon.getNombre());
		if(notChosen == true) this->AsignarPokemonToPlayer(opcion);
		
    return notChosen;
    }

    void addPokemon(int opcion){
        bool j = false;
        while (j == false){
            j = VerifyChosenPokemon(opcion);
        }
    AsignarPokemonToPlayer(opcion);
    }

    void AlternarJugador(int jugador){
      
    }

    list <Pokemon>& getTeam(){
        return jugadorActual.getTeam();
    }


};