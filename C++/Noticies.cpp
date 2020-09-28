/* Funcions Noticies:
        - llistar */

#include <sstream>
#include "Noticies.h"
#include "SentenciaODBC.h"

void Noticies::llistar(ConnexioODBC &connexio)
{
	SentenciaODBC s;
	stringstream stream;

	s.Init(connexio);
	stream << "SELECT * FROM Noticies;" << endl;
	if(!s.Executa(stream.str()))
		s.EscriuError();
	while(s.FilaSortida())
	{
		cout << "Noticia " << s.GetColumnaInt(1) << ": Sobre(idPersona): " << s.GetColumnaString(2) << endl;
		cout << "Diari: " << s.GetColumnaString(3) << endl;
		cout << "\t" << s.GetColumnaString(4) << endl;
	}
	cout << endl;
	s.Allibera();
}

