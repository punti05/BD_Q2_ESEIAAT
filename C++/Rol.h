/* Classe Rol */

#ifndef ROL_H_
#define ROL_H_

#include <iostream>
#include "SentenciaODBC.h"

using namespace std;


class Rol {
private:
	string rol;
	int idrol;

public:
	void llistar(ConnexioODBC &connexio);
};

#endif
