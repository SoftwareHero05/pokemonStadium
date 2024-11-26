#pragma once
#include <POKEMONS/Pk_Class.h>
//ID = 19
void Synthesis(Pokemon *User) {
 User->Hp = User->Hp + (User->BHp * .5);
 if(User->Hp > User->BHp) User->Hp = User->BHp;
}