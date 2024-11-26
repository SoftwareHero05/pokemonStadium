#include <iostream>
#include <POKEMONS/Pokemon.h>
#include <MOVES/Move.h>
#include <Definer.h>


int main(int argc, char const *argv[])
{
    // Prueba para verificar que funciona la creacion de un pokemon con un movimiento
    Move movimiento1(10,10,10);
    list<Move> movimientos;

    movimientos.emplace_back(movimiento1);
    Pokemon poke(10,10,10,10,10,10,movimientos);

    return 0;
}
