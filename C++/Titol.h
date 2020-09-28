/* Classe Titol */

#ifndef TITOL_H_
#define TITOL_H_


#include <iostream>
#include "SentenciaODBC.h"


using namespace std;


class Titol
{
private:
	string Titol, idioma, resum;
	int idTitol, any, genere, durada, categoria, director;

public:
	void llistar(ConnexioODBC &connexio);
	void llegir();
	void afegir(ConnexioODBC &connexio);
	void esborrar_nous(ConnexioODBC &connexio);
	void buscar(ConnexioODBC &connexio);
	void buscardirector(ConnexioODBC &connexio);
};


#endif
