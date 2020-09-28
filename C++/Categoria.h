/* Classe Categoria */

#ifndef CATEGORIA_H_
#define CATEGORIA_H_


#include <iostream>
#include "SentenciaODBC.h"


using namespace std;


class Categoria
{
private:
	string Tipus;
	int idCategoria;

public:
	void llistar(ConnexioODBC &connexio);
};


#endif
