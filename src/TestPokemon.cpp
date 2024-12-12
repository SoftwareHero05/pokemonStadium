#include <iostream>
#include <POKEMONS/Pokemon.h>
#include <MOVES/Move.h>
#include <Definer.h>

int main(int argc, char const *argv[])
{
    // Prueba para verificar que funciona la creacion de un pokemon con un movimiento
    Move movimiento1(10, FAIRY, false, 30, "GAY");
    list<Move> movimientos;

    movimientos.emplace_back(movimiento1);
    Pokemon poke(10, 10, 10, 10, 10, 30, movimientos, 20, "putamon", FIRE, DRAGON);
    cout << poke.GetAtk() << endl;
    cout << poke.GetSpeed() << endl;
    cout << poke.getNombre() << endl;
    cout << poke.getType1() << endl;
    cout << poke.getType2() << endl;

    return 0;
}
