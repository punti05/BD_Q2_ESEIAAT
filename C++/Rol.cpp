/* Funcions Rol:
        - llistar */

#include <sstream>
#include "Rol.h"
#include "SentenciaODBC.h"


void Rol::llistar(ConnexioODBC &connexio)
{

	SentenciaODBC s;
	stringstream stream;

	s.Init(connexio);
	stream << "SELECT * FROM Rol;" << endl;
	if(!s.Executa(stream.str()))
		s.EscriuError();
	while(s.FilaSortida())
	{
		cout << "Rol " << s.GetColumnaInt(1) << ": " << s.GetColumnaString(2) << endl;
	}
	cout << endl;
	s.Allibera();
}
