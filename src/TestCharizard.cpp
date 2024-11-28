#include <iostream>
#include <POKEMONS/Charizard.h>
#include <POKEMONS/Garchomp.h>
#include <Definer.h>


int main(int argc, char const *argv[])
{
    // Prueba para verificar la creacion de charizard
    Charizard charizad;
    cout<<charizad.GetAtk()<<endl;
    cout<<charizad.GetDef()<<endl;
    cout<<charizad.getType1()<<endl;
    cout<<charizad.getNombre()<<endl;
    Garchomp garchomp;
    cout<<"----"<<endl;
    cout<<garchomp.GetAtk()<<endl;
    garchomp.boostAtk();
    cout<<garchomp.GetAtk()<<endl;
    return 0;
}
