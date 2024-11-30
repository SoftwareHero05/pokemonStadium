#include <Juego.h>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    Juego juego;
    Pokemon pokemon = juego.CreatePokemon(1);
    cout<<pokemon.getNombre()<<endl;
    Pokemon pokemon2 = juego.CreatePokemon(2);
    cout<<pokemon2.getNombre()<<endl;
    return 0;
}
