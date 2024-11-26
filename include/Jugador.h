#include <POKEMONS/Pokemon.h>
class Jugador
{
private:
    list<Pokemon> equipo;
    int NumberOfPokemons = 0;
    int PlayerNumber;

public:
    Jugador(int PlayerNumber) {
        this->PlayerNumber=PlayerNumber;
        equipo.emplace_back(Lucario()); 
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
    