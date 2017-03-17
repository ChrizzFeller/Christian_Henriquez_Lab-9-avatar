#include "Bender.h"
#include <string>

#ifndef FIREBENDERS_H
#define FIREBENDERS_H

using namespace std;

class firebenders : public Bender {

	private:
		double debilidad;

	public:
		firebenders();
		firebenders(string, double, double, double, int);
		double getDebilidad();
		double ataqueR(double, double, double);
		double ataqueE(Bender*, Bender*);
		
};

#endif