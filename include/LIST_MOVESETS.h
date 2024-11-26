#pragma once
#include "Definer.h"
#include "Definer_Pokemon.h"

int LucarioMoveSet(){
	Lucario *lucario = new Lucario();
	int opcion;
	int id;
	do{
	cout<<"1-AuraSphere"<<endl;
    cout<<"2-FlashCannon"<<endl;
    cout<<"3-DragonPulse"<<endl;
    cout<<"4-CalmMind"<<endl;	
	cin>>opcion;
    system("cls");
	}while(opcion < 1 || opcion > 4);
    switch (opcion){
    	case 1:
    	 	id = lucario->auraSphereMov->id;
    		break;
    	case 2:
    		id = lucario->flashCannonMov->id;
    		break;
    	case 3:
    		id = lucario->dragonPulseMov->id;
    		break;
    	case 4:
			id = 9; //CalmMind
    		break;
	}
	delete lucario;
	return id;
}

int CharizardMoveSet(){
	Charizard *charizard = new Charizard();
	int opcion, id;
	do{
	cout<<"1-Flamethrower"<<endl;
    cout<<"2-AirSlash"<<endl;
    cout<<"3-DragonPulse"<<endl;
    cout<<"4-CalmMind"<<endl;	
	cin>>opcion;
    system("cls");
	}while(opcion < 1 || opcion > 4);
    switch (opcion){
    	case 1:
    		id = charizard->flamethrowerMov->id;
    		break;
    	case 2:
    		id = charizard->airSlashMov->id;
    		break;
    	case 3:
    		id = charizard->dragonPulseMov->id;
    		break;
    	case 4:
			id = 9; //CalmMind
    		break;
	}
	delete charizard;
	return id;
}

int GarchompMoveSet(){
	Garchomp *garchomp = new Garchomp();
	int opcion, id;
	do{
	cout<<"1-Eartquake"<<endl;
    cout<<"2-DragonClaw"<<endl;
    cout<<"3-Crunch"<<endl;
    cout<<"4-DragonDance"<<endl;	
	cin>>opcion;
    system("cls");
	}while(opcion < 1 || opcion > 4);
    switch (opcion){
    	case 1:
    		id = garchomp->earthquakeMov->id;
    		break;
    	case 2:
    		id = garchomp->dragonClawMov->id;
    		break;
    	case 3:
    		id = garchomp->crunchMov->id;
    		break;  
    	case 4:
			id = 10; //DragonDance
    		break;
	}
	delete garchomp;
	return id;
}

int GardevoirMoveSet(){
	Gardevoir *gardevoir = new Gardevoir();
	int opcion, id;
	do{
	cout<<"1-MoonBlast"<<endl;
    cout<<"2-Psychich"<<endl;
    cout<<"3-Shadow"<<endl;
    cout<<"4-CalmMind"<<endl;	
	cin>>opcion;
    system("cls");
	}while(opcion < 1 || opcion > 4);
    switch (opcion){
    	case 1:
    		id = gardevoir->moonBlastMov->id;
    		break;
    	case 2:
    		id = gardevoir->psychicMov->id;
    		break;
    	case 3:
    		id = gardevoir->shadowBallMov->id;
    		break;
    	case 4:
			id = 9; //CalmMind
    		break;
	}
	delete gardevoir;
	return id;
}

int SuicuneMoveSet(){
	Suicune *suicune = new Suicune();
	int opcion, id;
	do{
	cout<<"1-Surf"<<endl;
    cout<<"2-MoonBlast"<<endl;
    cout<<"3-IceBeam"<<endl;
    cout<<"4-CalmMind"<<endl;	
	cin>>opcion;
    system("cls");
	}while(opcion < 1 || opcion > 4);
    switch (opcion){
    	case 1:
    		id = suicune->surfMov->id;
    		break;
    	case 2:
    		id = suicune->moonBlastMov->id;
    		break;
    	case 3:
    		id = suicune->iceBeamMov->id;
    		break;
    	case 4:
			id = 9; //CalmMind
    		break;
	}
	delete suicune;
	return id;
}

int VenusaurMoveSet(){
	Venusaur *venusaur = new Venusaur();
	int opcion, id;
	do{
	cout<<"1-EnergyBall"<<endl;
    cout<<"2-SludgeBomb"<<endl;
    cout<<"3-EarthPower"<<endl;
    cout<<"4-Synthesis"<<endl;	
	cin>>opcion;
    system("cls");
	}while(opcion < 1 || opcion > 4);
    switch (opcion){
    	case 1:
    		id = venusaur->energyBallMov->id;
    		break;
    	case 2:
    		id = venusaur->sludgeBombMov->id;
    		break;
    	case 3:
    		id = venusaur->earthPowerMov->id;
    		break;
    	case 4:
			id = 19; //CalmMind
    		break;
	}
	delete venusaur;
	return id;
}

int TyranitarMoveSet(){
	Tyranitar *tyranitar = new Tyranitar();
	int opcion, id;
	do{
	cout<<"1-StoneEdge"<<endl;
    cout<<"2-Crunch"<<endl;
    cout<<"3-Earthquake"<<endl;
    cout<<"4-DragonDance"<<endl;	
	cin>>opcion;
    system("cls");
	}while(opcion < 1 || opcion > 4);
    switch (opcion){
    	case 1:
    		id = tyranitar->stoneEdgeMov->id;
    		break;
    	case 2:
    		id = tyranitar->crunchMov->id;
    		break;
    	case 3:
    		id = tyranitar->earthQuakeMov->id;
    		break;
    	case 4:
			id = 10; //DragonDance
    		break;
	}
	delete tyranitar;
	return id;
}

int GengarMoveSet(){
	Gengar *gengar = new Gengar();
	int opcion, id;
	do{
	cout<<"1-ShadowBall"<<endl;
    cout<<"2-SludgeBomb"<<endl;
    cout<<"3-ThunderBolt"<<endl;
    cout<<"4-NastyPlot"<<endl;	
	cin>>opcion;
    system("cls");
	}while(opcion < 1 || opcion > 4);
    switch (opcion){
    	case 1:
    		id = gengar->shadowBallMov->id;
    		break;
    	case 2:
    		id = gengar->sludgeBombMov->id;
    		break;
    	case 3:
    		id = gengar->thunderBoltMov->id;
    		break;
    	case 4:
			id = 23; //NastyPlot
    		break;
	}
	delete gengar;
	return id;
}
