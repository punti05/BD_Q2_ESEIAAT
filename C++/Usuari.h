/* Classe Usuari */

#ifndef USUARI_H_
#define USUARI_H_

#include <iostream>
#include "SentenciaODBC.h"

using namespace std;

class Usuari
{
private:
	string nom, cognom, email;
	int idUsuari, edat, tel, premium;

public:
	void llistar(ConnexioODBC &connexio);
	void llegir();
	void afegir(ConnexioODBC &connexio);
	void prem(ConnexioODBC &connexio);
	void buscarpremium(ConnexioODBC &connexio);
	void buscaradult(ConnexioODBC &connexio);
	void buscar(ConnexioODBC &connexio);
};

#endif
