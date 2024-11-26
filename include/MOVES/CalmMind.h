#pragma once
#include <POKEMONS/Pk_Class.h>
//ID = 9
void CalmMind(Pokemon *User) {
 User->SAtk = User->SAtk + (User->BSAtk * .5);
 User->SDef = User->SDef + (User->BSDef * .5);
}