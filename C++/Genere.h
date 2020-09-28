/* Classe Genere */

#ifndef GENERES_H_
#define GENERES_H_


#include <iostream>
#include "SentenciaODBC.h"


using namespace std;


class Genere
{
private:
	string Genere;
	int idGenere;

public:
	void llistar(ConnexioODBC &connexio);
};


#endif
