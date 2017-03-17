#include "Bender.h"
#include <string>

#ifndef AIRBENDERS_H
#define AIRBENDERS_H

using namespace std;

class airbenders : public Bender {

	private:
		double debilidad;

	public:
		airbenders();
		airbenders(string, double, double, double, int);
		double getDebilidad();
		double ataqueR(double, double, double);
		double ataqueE(Bender*, Bender*);

};

#endif