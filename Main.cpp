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
		if (respuesta1 == 1)
		{
			cout << "Que tipo de bender sera?" << endl;
			cout << "1) Air" << endl;
			cout << "2) Earth" << endl;
			cout << "3) Fire" << endl;
			cout << "4) Water" << endl;
		} else if (respuesta1 == 2)
		{
			/* code */
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