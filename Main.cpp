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
			for (int i = 0; i < listaBenders.size(); ++i)
			{
				nombreT = listaBenders.at(i) -> getNombre();
				cout << (i+1) << ") " << nombreT << endl;
			}
		} else if (respuesta1 == 3)
		{
			/* code */
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