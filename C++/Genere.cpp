/* Funcions Genere:
        - llistar */

#include <sstream>
#include "Genere.h"
#include "SentenciaODBC.h"

void Genere::llistar(ConnexioODBC &connexio)
{
	SentenciaODBC s;
	stringstream stream;

	s.Init(connexio);
	stream << "SELECT * FROM Genere;" << endl;
	if(!s.Executa(stream.str()))
		s.EscriuError();
	while(s.FilaSortida())
	{
		cout << "Genere " << s.GetColumnaInt(1) << ": " << s.GetColumnaString(2) << endl;
	}
	cout << endl;
	s.Allibera();
}
