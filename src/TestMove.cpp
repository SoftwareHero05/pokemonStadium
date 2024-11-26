
#include <MOVES/Move.h>
#include <Moves/AuraSphere.h>
#include <Definer.h>



int main(int argc, char const *argv[])
{
    // Prueba para verificar que funciona la creacion de un pokemon con un movimiento
    Move movimiento1(10,FAIRY,false,50,"PUTA");
    AuraSphere movimiento2;
    cout<<movimiento2.GetMoveName()<<endl;
    return 0;
}
