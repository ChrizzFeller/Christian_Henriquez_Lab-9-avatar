#include "Bender.h"
#include <string>

#ifndef EARTHBENDERS_H
#define EARTHBENDERS_H

using namespace std;

class earthbenders : Bender {

	private:
		double debilidad;

	public:
		earthbenders();
		earthbenders(string, double, double, double, int);
		double getDebilidad();
		void espiar(Bender*);

};

#endif