#include <iostream>
#include <POKEMONS/Charizard.h>
#include <POKEMONS/Garchomp.h>
#include <Definer.h>
#include <Jugador.h>


int main(int argc, char const *argv[])
{
    // Prueba para verificar la creacion de charizard
    Charizard charizad;
    Garchomp garchomp;
    Jugador jugador1;
    jugador1.AsignarPokemon(garchomp);
    jugador1.AsignarPokemon(charizad);
    list<Pokemon> equipo;
    equipo = jugador1.getTeam();
    for (auto &&equipo: equipo)
        {
            cout << equipo.getNombre()<<endl;
        }

    bool pokemon = jugador1.PokemonAlreadyInTeam("Suicune");
    cout<<pokemon<<endl;
     pokemon = jugador1.PokemonAlreadyInTeam(charizad.getNombre());
    cout<<pokemon<<endl;

    return 0;
}
