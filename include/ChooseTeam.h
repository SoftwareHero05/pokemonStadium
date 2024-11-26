#pragma once
#include <POKEMONS/Pk_Class.h>
#include <Definer_Pokemon.h>

void AsignarPokemon(Pokemon *equipo[], int id, int posicion){
	switch(id){
		case 1: //Lucario
				equipo[posicion] = new Lucario();
			break;
		case 2: //Charizard
				equipo[posicion] = new Charizard();
			break;
		case 3: //Garchomp
				equipo[posicion] = new Garchomp();
			break;
		case 4:
				equipo[posicion] = new Gardevoir();
			break;
		case 5:
				equipo[posicion] = new Suicune();
			break;
		case 6:
				equipo[posicion] = new Venusaur();
			break;
		case 7:
				equipo[posicion] = new Tyranitar();
			break;
		case 8:
				equipo[posicion] = new Gengar();
			break;

		
	}
}

void ChooseTeam(Pokemon *equipo[], int jugador){
	int opcion;
	int chosenAlready[6];
	bool notChosen;
	for(int i = 0; i < 6; i) {
	notChosen = true;
	cout<<"Forma tu equipo Player : "<<jugador<<endl;
	cout<<"Elige el miembro numero: "<<i+1<<endl;
	cout<<"1-Lucario"<<endl;
	cout<<"2-Charizard"<<endl;
	cout<<"3-Garchomp"<<endl;
	cout<<"4-Gardevoir"<<endl;
	cout<<"5-Suicune"<<endl;
	cout<<"6-Venusaur"<<endl;
	cout<<"7-Tyranitar"<<endl;
	cout<<"8-Gengar"<<endl;
	cin>>opcion;
		for(int j = 0; j < i;j++) {
			if(chosenAlready[j] == opcion ) {
			notChosen = false;
			break;
			} 
		}
		if(notChosen == true) {
		AsignarPokemon(equipo, opcion,i);
		chosenAlready[i] = opcion;
		i++;
		}
		else cout<<"Pokemon ya elegido, eliga otro porfavor"<<endl;
		system("pause");
		system("cls");
	}
}