/* Funcions Titol:
        - llistar
        - llegir
        - afegir
        - esborrar
        - buscar */

#include <sstream>
#include "Titol.h"
#include "SentenciaODBC.h"

void Titol::llistar(ConnexioODBC &connexio)
{
	SentenciaODBC s;
	stringstream stream;

	s.Init(connexio);
	stream << "SELECT * FROM Titol;" << endl;
	if(!s.Executa(stream.str()))
		s.EscriuError();
	while(s.FilaSortida())
	{
	    cout << endl;
		cout << "Titol " << s.GetColumnaInt(1) << ": " << s.GetColumnaString(2) << endl;
		cout << "\tAny: " << s.GetColumnaInt(3) << endl;
		cout << "\tGenere (idGenere): " << s.GetColumnaInt(4) << endl;
		cout << "\tIdioma: " << s.GetColumnaString(5) << endl;
		cout << "\tDurada: " << s.GetColumnaInt(6) << " segons" << endl;
		cout << "\tCategoria (idCategoria): " << s.GetColumnaInt(7) << endl;
		cout << "\tResum: " << s.GetColumnaString(8) << endl;
		cout << "\tDirector (idDirector): " << s.GetColumnaInt(9) << endl << endl;
	}
	cout << endl;
	s.Allibera();
}

/* Suposem que la persona que introdueix els valors coneix la base de dades i, per tant, no hi hauran errors */

void Titol::llegir()
{
    cout << "Introdueix un titol!" << endl;
    cout << "IDTitol: ";
    cin >> idTitol;
    cout << "Titol: ";
    cin >> Titol;
    cout << "Any: ";
	cin >> any;
	cout << "Genere (idGenere): ";
	cin >> genere;
	cout << "Idioma: ";
	cin >> idioma;
	cout << "Durada: ";
    cin >> durada;
    cout << "Categoria (idCategoria): ";
	cin >> categoria;
    cout << "Resum: ";
    cin >> resum;
    cout << "Director (idDirector): ";
    cin >> director;
}

void Titol::afegir(ConnexioODBC &connexio)
{
    SentenciaODBC s;
	stringstream stream;

	s.Init(connexio);
	stream << "INSERT INTO Titol(idTitol, Titol, any, genere, idioma, durada, categoria, resum, director)" << endl;
	stream << "VALUES (";
	stream << "'" << idTitol << "', ";
	stream << "'" << Titol << "', ";
	stream << "'" << any << "', ";
	stream << "'" << genere << "', ";
	stream << "'" << idioma << "', ";
	stream << "'" << durada << "', ";
	stream << "'" << categoria << "', ";
	stream << "'" << resum << "', ";
	stream << "'" << director << "');";

	if(!s.Executa(stream.str()))
		s.EscriuError();
	s.Allibera();

	cout << "Titol afegit correctament!" << endl << endl;

}


void Titol::esborrar_nous(ConnexioODBC &connexio)
{
    SentenciaODBC s;
	stringstream stream;

	s.Init(connexio);

    stream << "call esborrar_nous()";

	if(!s.Executa(stream.str()))
		s.EscriuError();
	s.Allibera();

	cout << "Titols nous esborrats correctament!" << endl << endl;

}

void Titol::buscar(ConnexioODBC &connexio)
{
    SentenciaODBC s;
	stringstream stream;
    int id;

	s.Init(connexio);

    cout << "Id del titol que es vol buscar: ";
    cin >> id;

    stream << "SELECT * FROM Titol WHERE idTitol = '";
    stream << id << "';";

	if(!s.Executa(stream.str()))
		s.EscriuError();
    while(s.FilaSortida())
    {
        cout << endl;
        cout << "Titol " << s.GetColumnaInt(1) << ": " << s.GetColumnaString(2) << endl;
		cout << "\tAny: " << s.GetColumnaInt(3) << endl;
		cout << "\tGenere (idGenere): " << s.GetColumnaInt(4) << endl;
		cout << "\tIdioma: " << s.GetColumnaString(5) << endl;
		cout << "\tDurada: " << s.GetColumnaInt(6) << " segons" << endl;
		cout << "\tCategoria (idCategoria): " << s.GetColumnaInt(7) << endl;
		cout << "\tResum: " << s.GetColumnaString(8) << endl;
		cout << "\tDirector (idDirector): " << s.GetColumnaInt(9) << endl << endl;
    }
	s.Allibera();
}

void Titol::buscardirector(ConnexioODBC &connexio)
{
    SentenciaODBC s;
	stringstream stream;
    string nom, cognom;

	s.Init(connexio);

    cout << "Nom del director: ";
    cin >> nom;
    cout << "Cognom del director: ";
    cin >> cognom;

    stream << "SELECT p.nom, p.cognom, t.titol, t.any FROM titol as t JOIN Persones as p ON t.director = p.idpersones WHERE p.nom Like '";
    stream << nom << "' AND p.cognom like '";
    stream << cognom << "'";

	if(!s.Executa(stream.str()))
		s.EscriuError();
    while(s.FilaSortida())
    {
        cout << endl;
        cout << s.GetColumnaString(1) << " " << s.GetColumnaString(2) << endl;
		cout << "\tTitol: " << s.GetColumnaString(3) << endl;
		cout << "\tAny: " << s.GetColumnaInt(4) << endl << endl;
    }
	s.Allibera();
}
