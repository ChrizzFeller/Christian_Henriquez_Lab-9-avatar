#include "Bender.h"
#include <string>

#ifndef WATERBENDERS_H
#define WATERBENDERS_H

using namespace std;

class waterbenders : public Bender {

	private:
		double debilidad;

	public:
		waterbenders();
		waterbenders(string, double, double, double, int);
		double getDebilidad();
		double heal(double, double);
		double ataqueR(double, double, double);
		double ataqueE(Bender*, Bender*);
		
};

#endif