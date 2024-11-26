#include <Definer.h>
#include <POKEMONS/Pk_Class.h>
#include <LIST_MOVESETS.h>
#include <MovExecuter.h>
#include <ChangePokemon.h>
#include <ChooseTeam.h>

int MoveSet(Pokemon *EnCombate){
	int idMov;
	switch(EnCombate->iD) {
 		case 1: 
 		idMov = LucarioMoveSet();
 			break;
 		case 2: 
 		idMov = CharizardMoveSet();
 			break;
		case 3:
		idMov = GarchompMoveSet();
			break;
		case 4:
		idMov = GardevoirMoveSet();
			break; 	
		case 5:
		idMov = SuicuneMoveSet();
			break; 
		case 6:
		idMov = VenusaurMoveSet();
			break;
		case 7:
		idMov = TyranitarMoveSet();
			break; 
		case 8:
		idMov = GengarMoveSet();
			break; 

		}
	return idMov;
}

int main(int argc, char** argv) {
	int NPkmPlayer1 = 6,NPkmPlayer2 = 6;
	int pokemonActual1 = 0, pokemonActual2 = 0;
	int opcionPlayer1,opcionPlayer2;
	Pokemon *equipo1[6];
	Pokemon *equipo2[6];
	int MovPlayer1, MovPlayer2, MovFaster, MovSlower;
	ChooseTeam(equipo1,1);
	ChooseTeam(equipo2,2);	
	Pokemon *EnCombate1 = equipo1[pokemonActual1];
	Pokemon *EnCombate2 = equipo2[pokemonActual2];
	Pokemon *Faster;
	Pokemon *Slower;
	int damageDone;
	int speedPlayer1, speedPlayer2;
	bool rolTurnos, Atk1IsTrue, Atk2IsTrue, AtkFasterIsTrue, AtkSlowerIsTrue; // rolTurnos == true el player 1 fue mas rapido false player 2 fue mas rapido

	while(NPkmPlayer1 > 0 && NPkmPlayer2 > 0){
		//Elegir movimientos
		cout<<"Elige que haras Jugador 1"<<endl;
		cout<<"Pokemon actual: "<<EnCombate1->nombre<<endl;
		cout<<"Pokemon enemigo: "<<EnCombate2->nombre<<endl;
		cout<<"-----------------"<<endl;
		cout<<"1-Atacar"<<endl;
		cout<<"Cualquier otro numero-Cambiar de Pokemon"<<endl;
		cin>>opcionPlayer1;
		system("cls");

		cout<<"Elige que haras Jugador 2"<<endl;
		cout<<"Pokemon actual: "<<EnCombate2->nombre<<endl;
		cout<<"Pokemon enemigo: "<<EnCombate1->nombre<<endl;
		cout<<"-----------------"<<endl;
		cout<<"1-Atacar"<<endl;
		cout<<"Cualquier otro numero-Cambiar de Pokemon"<<endl;
		cin>>opcionPlayer2;
		system("cls");


		if(opcionPlayer1 == 1) {
			cout<<"Elige movimiento Player 1 "<<endl;
			MovPlayer1 = MoveSet(EnCombate1);
			Atk1IsTrue = true;
		}
		else {
			EnCombate1->RestartStats();
			pokemonActual1 = changePokemon(equipo1,pokemonActual1) - 1 ;
			EnCombate1 = equipo1[pokemonActual1];
			Atk1IsTrue = false;
		}
		
		if(opcionPlayer2 == 1) {
			cout<<"Elige movimiento Player 2 "<<endl;
			MovPlayer2 = MoveSet(EnCombate2);
			Atk2IsTrue = true;
		}
		else {
			EnCombate2->RestartStats();
			pokemonActual2 = changePokemon(equipo2,pokemonActual2) - 1 ;
			EnCombate2 = equipo2[pokemonActual2];
			Atk2IsTrue = false;
		};
		system("cls");

		//movimientos de prioridad
		speedPlayer1 = EnCombate1->Speed;
		speedPlayer2 = EnCombate2->Speed;
		//Asignar turno
		if(speedPlayer1 >= speedPlayer2){
			Faster = EnCombate1;
			Slower = EnCombate2;
			AtkFasterIsTrue = Atk1IsTrue;
			MovFaster = MovPlayer1;
			MovSlower = MovPlayer2;
			AtkSlowerIsTrue = Atk2IsTrue;
			rolTurnos = true;
		}
		else {
			Faster = EnCombate2;
			Slower = EnCombate1;
			AtkFasterIsTrue = Atk2IsTrue;
			MovFaster = MovPlayer2;
			MovSlower = MovPlayer1;
			AtkSlowerIsTrue = Atk1IsTrue;
			rolTurnos = false;
		}
		
		//Efectuar movimiento del pokemos mas rapido
			if(AtkFasterIsTrue == true ) damageDone = MovExecuter(MovFaster,Faster,Slower);
			else damageDone = 0;
			Slower->Hp -= damageDone;
		
			if(Slower->Hp > 1) {//Efectuar movimiento del otro pokemon 
			if(AtkSlowerIsTrue == true) damageDone = MovExecuter(MovSlower,Slower,Faster);
			else damageDone = 0;
			Faster->Hp -= damageDone;
			}
			//pasar Caracteristicas de Faster y slower a pokemon originales
			if(rolTurnos == true){
				EnCombate1 = Faster;
				EnCombate2 = Slower;
			}
			else{
				EnCombate2 = Faster;
				EnCombate1 = Slower;
			}
			cout<<"Equipo 1: Salud del Pokemon "<<EnCombate1->nombre<<": "<<EnCombate1->Hp<<endl;
			cout<<"Equipo 2: Salud del Pokemon "<<EnCombate2->nombre<<": "<<EnCombate2->Hp<<endl;
			system("pause");

			if(EnCombate1->Hp < 1 ) {
			cout<<"Equipo 1: "<<EnCombate1->nombre<<" fue debilitado"<<endl;
			system("pause");
			NPkmPlayer1--;
			if(NPkmPlayer1 != 0){
				pokemonActual1 = changePokemon(equipo1,pokemonActual1) - 1;
				EnCombate1 = equipo1[pokemonActual1];
				}
				else {
					cout<<"El jugador 1 ya no tiene pokemons, el jugador 2 gana"<<endl;
					system("pause");
				}
			}

			if(EnCombate2->Hp < 1 ) {
			cout<<"Equipo 2: "<<EnCombate2->nombre<<" fue debilitado"<<endl;
			system("pause");
			NPkmPlayer2--;
			if(NPkmPlayer2 != 0){
				pokemonActual2 = changePokemon(equipo2,pokemonActual2) - 1 ;
				EnCombate2 = equipo2[pokemonActual2];
				}
				else cout<<"El jugador 2 ya no tiene pokemons, el jugador 1 gana"<<endl;
				system("pause");
			}
			system("cls");
	}
	return 0;
}
	
	

