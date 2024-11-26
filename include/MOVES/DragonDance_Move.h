#pragma once
#include <POKEMONS/Pk_Class.h>
//ID = 10
void DragonDance(Pokemon *User) {
 User->Atk = User->Atk + (User->BAtk * .5);
 User->Speed= User->Speed + (User->BSpeed * .5);
}