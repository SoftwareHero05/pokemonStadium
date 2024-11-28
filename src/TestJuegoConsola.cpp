#include <JuegoConsola.h>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    JuegoConsola juego;
    juego.Iniciar();
    //system("pause");
    juego.PrintPokemonNames();
     system("cls");
    juego.ChooseTeam(1);
    system("pause");
    system("cls");
    juego.ChooseTeam(2);

    return 0;
}
