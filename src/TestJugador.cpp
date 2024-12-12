#include <iostream>
#include <POKEMONS/Charizard.h>
#include <POKEMONS/Garchomp.h>
#include <Definer.h>
#include <EquipoPokemon.h>

int main(int argc, char const *argv[])
{
    // Prueba para verificar la creacion de charizard
    Charizard charizad;
    Garchomp garchomp;
    EquipoPokemon jugador1;
    jugador1.AddPokemon(garchomp);
    jugador1.AddPokemon(charizad);
    list<Pokemon> equipo;
    equipo = jugador1.GetTeam();
    for (auto &&equipo : equipo)
    {
        cout << equipo.getNombre() << endl;
    }

    bool pokemon = jugador1.IsPokemonInTeam("Suicune");
    cout << pokemon << endl;
    pokemon = jugador1.IsPokemonInTeam(charizad.getNombre());
    cout << pokemon << endl;

    return 0;
}
