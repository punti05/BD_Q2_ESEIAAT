/* Classe Noticies */

#ifndef NOTICIES_H_
#define NOTICIES_H_

#include <iostream>
#include "SentenciaODBC.h"


using namespace std;


class Noticies
{
private:
	string Diari, Noticia  ;
	int idNoticies, idPersona;

public:
	void llistar(ConnexioODBC &connexio);
};


#endif
