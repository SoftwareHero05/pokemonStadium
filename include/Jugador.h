#include <POKEMONS/Pokemon.h>

class Jugador
{
private:
    list<Pokemon> equipo;
    int NumberOfPokemons = 6;

public:
    Jugador() {}
    ~Jugador() {}

    void ChooseTeam(list<Pokemon> equipo)
    {
        this->equipo = equipo;
    }

    void AsignarPokemon(Pokemon pokemon){
        equipo.emplace_back(pokemon);
    }
};