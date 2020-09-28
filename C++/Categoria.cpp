/* Funcions Categoria:
        - llistar */

#include <sstream>
#include "Categoria.h"
#include "SentenciaODBC.h"

void Categoria::llistar(ConnexioODBC &connexio)
{
	SentenciaODBC s;
	stringstream stream;

	s.Init(connexio);
	stream << "SELECT * FROM Categoria;" << endl;
	if(!s.Executa(stream.str()))
		s.EscriuError();
	while(s.FilaSortida())
	{
		cout << "Categoria " << s.GetColumnaInt(1) << ": " << s.GetColumnaString(2) << endl;
	}
	cout << endl;
	s.Allibera();
}
