#include "Bender.h"
#include <string>
#include <iostream>

#ifndef EARTHBENDERS_H
#define EARTHBENDERS_H

using namespace std;

class earthbenders : public Bender {

	private:
		double debilidad;

	public:
		earthbenders();
		earthbenders(string, double, double, double, int);
		double getDebilidad();
		void espiar(Bender*);
		double ataqueR(double, double, double);
		double ataqueE(Bender*, Bender*);

};

#endif