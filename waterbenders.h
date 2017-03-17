#include "Bender.h"
#include <string>

#ifndef WATERBENDERS_H
#define WATERBENDERS_H

using namespace std;

class waterbenders : Bender {

	private:
		double debilidad;

	public:
		waterbenders();
		waterbenders(string, double, double, double, int);
		double getDebilidad();
		double heal(double, double);
		
};

#endif