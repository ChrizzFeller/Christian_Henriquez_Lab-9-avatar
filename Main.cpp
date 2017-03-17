#include <iostream>
#include "Bender.h"
#include "airbenders.h"
#include "earthbenders.h"
#include "firebenders.h"
#include "waterbenders.h"
#include <string>
#include <vector>
#include <typeinfo>

using namespace std;

int main() {

	vector<Bender*> listaBenders;

	listaBenders.push_back(new earthbenders("Toph", 400, 30, 50, 8));
	listaBenders.push_back(new firebenders("Zuko", 350, 30, 55, 4));
	listaBenders.push_back(new waterbenders("Katara", 300, 35, 38, 6));

	bool seguir = true;

	while (seguir == true) {
		cout << endl;
		cout << "-----Menu-----" << endl;
		cout << "1) Crear Bender" << endl;
		cout << "2) Listar Benders" << endl;
		cout << "3) Simular Pelea" << endl;
		cout << "4) Salir" << endl;
		int respuesta1;
		cin >> respuesta1;
		while (respuesta1 < 1 || respuesta1 > 4) {
			cout << "Numero invalido, ingrese su opcion de nuevo!" << endl;
			cin >> respuesta1;
		}
		if (respuesta1 == 1)
		{
			string nombre;
			double HP;
			double ofensa;
			double defensa;
			int nivelDS;
			cout << "Ingrese nombre del bender: " << endl;
			cin >> nombre;
			cout << "Ingrese el HP del bender: " << endl;
			cin >> HP;
			while (HP < 0) {
				cout << "HP invalido, ingrese el HP de nuevo!";
				cin >> HP;
			}
			cout << "Ingrese la ofensa del bender: " << endl;
			cin >> ofensa;
			while (ofensa < 0 || ofensa > 60) {
				cout << "Ofensa invalida, ingrese la ofensa de nuevo!";
				cin >> ofensa;
			}
			cout << "Ingrese la defensa del bender: " << endl;
			cin >> defensa;
			while (defensa < 0) {
				cout << "Defensa invalida, ingrese la defensa de nuevo!";
				cin >> defensa;
			}
			cout << "Ingrese el nivel de suerte: " << endl;
			cin >> nivelDS;
			while (nivelDS < 0 || nivelDS > 10) {
				cout << "Nivel de suerte invalido, ingrese el nivel de suerte de nuevo!" << endl;
				cin >> nivelDS;
			}
 			cout << "Que tipo de bender sera?" << endl;
			cout << "1) Air" << endl;
			cout << "2) Earth" << endl;
			cout << "3) Fire" << endl;
			cout << "4) Water" << endl;
			int respuesta2;
			cin >> respuesta2;
			while (respuesta2 < 1 || respuesta2 > 4) {
				cout << "Numero invalido, ingrese su opcion de nuevo!" << endl;
				cin >> respuesta2;
			}
			if (respuesta2 == 1)
			{
				listaBenders.push_back(new airbenders(nombre, HP, ofensa, defensa, nivelDS));
				cout << "Airbender agregado exitosamente!" << endl;
			} else if (respuesta2 == 2)
			{
				listaBenders.push_back(new earthbenders(nombre, HP, ofensa, defensa, nivelDS));
				cout << "Earthbender agregado exitosamente!" << endl;
			} else if (respuesta2 == 3)
			{
				listaBenders.push_back(new firebenders(nombre, HP, ofensa, defensa, nivelDS));
				cout << "Firebender agregado exitosamente!" << endl;
			} else 
			{
				listaBenders.push_back(new waterbenders(nombre, HP, ofensa, defensa, nivelDS));
				cout << "Waterbender agregado exitosamente!" << endl;
			}
		} else if (respuesta1 == 2)
		{
			string nombreT;
			cout << "Los benders disponibles son: " << endl;
			for (int i = 0; i < listaBenders.size(); ++i)
			{
				nombreT = listaBenders.at(i) -> getNombre();
				cout << (i+1) << ") " << nombreT << endl;
			}
		} else if (respuesta1 == 3)
		{
			string nombreT;
			cout << "Escoga el primer bender." << endl;
			for (int i = 0; i < listaBenders.size(); ++i)
			{
				nombreT = listaBenders.at(i) -> getNombre();
				cout << (i) << ") " << nombreT << endl;
			}
			int player1;
			cin >> player1;
			while (player1 < 0 || player1 > listaBenders.size() - 1) {
				cout << "Numero invalido, ingrese su opcion de nuevo!" << endl;
				cin >> player1;
			}

			cout << "Escoga el segundo bender." << endl;
			for (int i = 0; i < listaBenders.size(); ++i)
			{
				nombreT = listaBenders.at(i) -> getNombre();
				cout << (i) << ") " << nombreT << endl;
			}
			int player2;
			cin >> player2;
			while (player2 < 0 || player2 > listaBenders.size() - 1 || player2 == player1) {
				cout << "Numero invalido, ingrese su opcion de nuevo!" << endl;
				cin >> player2;
			}

			bool fight = true;
			while (fight == true) {
				cout << "Es el turno de: " << listaBenders.at(player1) -> getNombre() << endl;
				cout << "Que desea hacer?" << endl;
				int respP;
				if (typeid(listaBenders.at(player1))==typeid(earthbenders))
				{
					cout << "1) Atacar" << endl << "2) Usar Ataque Especial" << endl << "3) Espiar" << endl << "4) Huir" << endl;
					cin >> respP;
				} else if (typeid(listaBenders.at(player1))==typeid(waterbenders))
				{
					cout << "1) Atacar" << endl << "2) Usar Ataque Especial" << endl << "3) Curarse" << endl << "4) Huir" << endl;
					cin >> respP;
				} else {
					cout << "1) Atacar" << endl << "2) Usar Ataque Especial" << endl << "3) Huir" << endl;
					cin >> respP;
				}

				if (typeid(listaBenders.at(player1))==typeid(earthbenders))
				{
					if (respP == 1)
					{
						double atk1 = listaBenders.at(player1) -> getOfensa();
						double def2 = listaBenders.at(player2) -> getDefensa();
						double hp2 = listaBenders.at(player2) -> getHP();
						cout << "Vida del player 2: " << hp2 << endl;
						hp2 = listaBenders.at(player1) -> ataqueR(atk1, def2, hp2);
						listaBenders.at(player2) -> setHP(hp2);
						cout << "Vida del player 2 despues del ataque: " << hp2 << endl;
						cout << "Ataque hecho!" << endl;
					} else if (respP == 2)
					{
						double hp2;
						cout << "Vida del player 2: " << hp2 << endl;
						hp2 = listaBenders.at(player1) -> ataqueE((listaBenders.at(player1)), (listaBenders.at(player2)));
						listaBenders.at(player2) -> setHP(hp2);
						cout << "Vida del player 2 despues del ataque especial: " << hp2 << endl;
						cout << "Ataque especial terminado!" << endl;
					} else if (respP == 3)
					{
						(dynamic_cast<earthbenders*>(listaBenders.at(player1))) -> espiar(listaBenders.at(player2));
						cout << "Espiar terminado!" << endl;
					} else {
						fight = false;
						cout << "El primer jugador ha escapado!" << endl;
					}
				} else if (typeid(listaBenders.at(player1))==typeid(waterbenders))
				{
					if (respP == 1)
					{
						double atk1 = listaBenders.at(player1) -> getOfensa();
						double def2 = listaBenders.at(player2) -> getDefensa();
						double hp2 = listaBenders.at(player2) -> getHP();
						cout << "Vida del player 2: " << hp2 << endl;
						hp2 = listaBenders.at(player1) -> ataqueR(atk1, def2, hp2);
						listaBenders.at(player2) -> setHP(hp2);
						cout << "Vida del player 2 despues del ataque: " << hp2 << endl;
						cout << "Ataque hecho!" << endl;
					} else if (respP == 2)
					{
						double hp2;
						cout << "Vida del player 2: " << hp2 << endl;
						hp2 = listaBenders.at(player1) -> ataqueE((listaBenders.at(player1)), (listaBenders.at(player2)));
						listaBenders.at(player2) -> setHP(hp2);
						cout << "Vida del player 2 despues del ataque especial: " << hp2 << endl;
						cout << "Ataque especial terminado!" << endl;
					} else if (respP == 3)
					{
						listaBenders.at(player1) -> setHP((dynamic_cast<waterbenders*>(listaBenders.at(player1))) -> heal(listaBenders.at(player1) -> getOfensa(), listaBenders.at(player1) -> getHP()));
						cout << "Heal terminado!" << endl;
					} else {
						fight = false;
						cout << "El primer jugador ha escapado!" << endl;
					}
				} else {
					if (respP == 1)
					{
						double atk1 = listaBenders.at(player1) -> getOfensa();
						double def2 = listaBenders.at(player2) -> getDefensa();
						double hp2 = listaBenders.at(player2) -> getHP();
						cout << "Vida del player 2: " << hp2 << endl;
						hp2 = listaBenders.at(player1) -> ataqueR(atk1, def2, hp2);
						listaBenders.at(player2) -> setHP(hp2);
						cout << "Vida del player 2 despues del ataque: " << hp2 << endl;
						cout << "Ataque hecho!" << endl;
					} else if (respP == 2)
					{
						double hp2;
						cout << "Vida del player 2: " << hp2 << endl;
						hp2 = listaBenders.at(player1) -> ataqueE((listaBenders.at(player1)), (listaBenders.at(player2)));
						listaBenders.at(player2) -> setHP(hp2);
						cout << "Vida del player 2 despues del ataque especial: " << hp2 << endl;
						cout << "Ataque especial terminado!" << endl;
					} else {
						fight = false;
						cout << "El primer jugador ha escapado!" << endl;
					}
				}

				//-------------------------------------------------------------------------------

				cout << "Es el turno de: " << listaBenders.at(player2) -> getNombre() << endl;
				cout << "Que desea hacer?" << endl;
				if (typeid(listaBenders.at(player2))==typeid(earthbenders))
				{
					cout << "1) Atacar" << endl << "2) Usar Ataque Especial" << endl << "3) Espiar" << endl << "4) Huir" << endl;
					cin >> respP;
				} else if (typeid(listaBenders.at(player2))==typeid(waterbenders))
				{
					cout << "1) Atacar" << endl << "2) Usar Ataque Especial" << endl << "3) Curarse" << endl << "4) Huir" << endl;
					cin >> respP;
				} else {
					cout << "1) Atacar" << endl << "2) Usar Ataque Especial" << endl << "3) Huir" << endl;
					cin >> respP;
				}

				if (typeid(listaBenders.at(player2))==typeid(earthbenders))
				{
					if (respP == 1)
					{
						double atk1 = listaBenders.at(player2) -> getOfensa();
						double def2 = listaBenders.at(player1) -> getDefensa();
						double hp2 = listaBenders.at(player1) -> getHP();
						cout << "Vida del player 1: " << hp2 << endl;
						hp2 = listaBenders.at(player2) -> ataqueR(atk1, def2, hp2);
						listaBenders.at(player1) -> setHP(hp2);
						cout << "Vida del player 1 despues del ataque: " << hp2 << endl;
						cout << "Ataque hecho!" << endl;
					} else if (respP == 2)
					{
						double hp2;
						cout << "Vida del player 1: " << hp2 << endl;
						hp2 = listaBenders.at(player2) -> ataqueE((listaBenders.at(player2)), (listaBenders.at(player1)));
						listaBenders.at(player1) -> setHP(hp2);
						cout << "Vida del player 1 despues del ataque especial: " << hp2 << endl;
						cout << "Ataque especial terminado!" << endl;
					} else if (respP == 3)
					{
						(dynamic_cast<earthbenders*>(listaBenders.at(player2))) -> espiar(listaBenders.at(player1));
						cout << "Espiar terminado!" << endl;
					} else {
						fight = false;
						cout << "El segundo jugador ha escapado!" << endl;
					}
				} else if (typeid(listaBenders.at(player2))==typeid(waterbenders))
				{
					if (respP == 1)
					{
						double atk1 = listaBenders.at(player2) -> getOfensa();
						double def2 = listaBenders.at(player1) -> getDefensa();
						double hp2 = listaBenders.at(player1) -> getHP();
						cout << "Vida del player 1: " << hp2 << endl;
						hp2 = listaBenders.at(player2) -> ataqueR(atk1, def2, hp2);
						listaBenders.at(player1) -> setHP(hp2);
						cout << "Vida del player 1 despues del ataque: " << hp2 << endl;
						cout << "Ataque hecho!" << endl;
					} else if (respP == 2)
					{
						double hp2;
						cout << "Vida del player 1: " << hp2 << endl;
						hp2 = listaBenders.at(player2) -> ataqueE((listaBenders.at(player2)), (listaBenders.at(player1)));
						listaBenders.at(player1) -> setHP(hp2);
						cout << "Vida del player 2 despues del ataque especial: " << hp2 << endl;
						cout << "Ataque especial terminado!" << endl;
					} else if (respP == 3)
					{
						listaBenders.at(player2) -> setHP((dynamic_cast<waterbenders*>(listaBenders.at(player2))) -> heal(listaBenders.at(player2) -> getOfensa(), listaBenders.at(player2) -> getHP()));
						cout << "Heal terminado!" << endl;
					} else {
						fight = false;
						cout << "El segundo jugador ha escapado!" << endl;
					}
				} else {
					if (respP == 1)
					{
						double atk1 = listaBenders.at(player1) -> getOfensa();
						double def2 = listaBenders.at(player2) -> getDefensa();
						double hp2 = listaBenders.at(player2) -> getHP();
						cout << "Vida del player 2: " << hp2 << endl;
						hp2 = listaBenders.at(player1) -> ataqueR(atk1, def2, hp2);
						listaBenders.at(player2) -> setHP(hp2);
						cout << "Vida del player 2 despues del ataque: " << hp2 << endl;
						cout << "Ataque hecho!" << endl;
					} else if (respP == 2)
					{
						double hp2;
						cout << "Vida del player 2: " << hp2 << endl;
						hp2 = listaBenders.at(player1) -> ataqueE((listaBenders.at(player1)), (listaBenders.at(player2)));
						listaBenders.at(player2) -> setHP(hp2);
						cout << "Vida del player 2 despues del ataque especial: " << hp2 << endl;
						cout << "Ataque especial terminado!" << endl;
					} else {
						fight = false;
						cout << "El primer jugador ha escapado!" << endl;
					}
				}

				//-------------------------------------------------------------------------------
			}
		} else {
			seguir = false;
			cout << "Nos vemos luego!" << endl;
		}
	}

	//Borrar vector
	for (int i=0; i< listaBenders.size(); i++){
		listaBenders.erase(listaBenders.begin() + i);
	}
	listaBenders.clear();

	return 0;
}