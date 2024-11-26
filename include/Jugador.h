#include <POKEMONS/Pokemon.h>

class Jugador
{
private:
    list<Pokemon> equipo;

public:
    Jugador() {}
    ~Jugador() {}

    void ChooseTeam(list<Pokemon> equipo)
    {
        this->equipo = equipo;
    }

    void AsignarPokemon(int casilla, Pokemon pokemon){
        // equipo.emplace(pokemon);
    }
};