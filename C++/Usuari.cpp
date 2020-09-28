/* Funcions Usuari:
        - llistar
        - llegir
        - afegir
        - esborrar
        - buscar */

#include <sstream>
#include "Usuari.h"
#include "SentenciaODBC.h"

void Usuari::llistar(ConnexioODBC &connexio)
{
	SentenciaODBC s;
	stringstream stream;

	s.Init(connexio);
	stream << "SELECT * FROM Usuari;" << endl;
	if(!s.Executa(stream.str()))
		s.EscriuError();
	while(s.FilaSortida())
	{
		cout << "Usuari " << s.GetColumnaInt(1) << ": " << endl;
		cout << "\t Nom: " << s.GetColumnaString(2) << endl;
		cout << "\t Cognom: " << s.GetColumnaString(3) << endl;
		cout << "\t email: " << s.GetColumnaString(4) << endl;
		cout << "\t Edat: " << s.GetColumnaInt(5) << endl;
		cout << "\t Telefon: " << s.GetColumnaInt(6) << endl;
		cout << "\t Premium: " << s.GetColumnaInt(7) << endl << endl;
	}
	cout << endl;
	s.Allibera();
}

void Usuari::llegir()
{
    cout << "Introdueix un nou usuari!" << endl;
    cout << "IDUsuari: ";
    cin >> idUsuari;
    cout << "Nom: ";
    cin >> nom;
    cout << "Cognom: ";
	cin >> cognom;
	cout << "email: ";
	cin >> email;
	cout << "Edat: ";
	cin >> edat;
	cout << "Tel.: ";
    cin >> tel;
    cout << "Vols ser Premium (0/1)? ";
	cin >> premium;
}

void Usuari::afegir(ConnexioODBC &connexio)
{
    SentenciaODBC s;
	stringstream stream;

	s.Init(connexio);
	stream << "INSERT INTO Usuari" << endl;
	stream << "VALUES (";
	stream << "'" << idUsuari << "', ";
	stream << "'" << nom << "', ";
	stream << "'" << cognom << "', ";
	stream << "'" << email << "', ";
	stream << "'" << edat << "', ";
	stream << "'" << tel << "', ";
	stream << "'" << premium << "');";

	if(!s.Executa(stream.str()))
		s.EscriuError();
	s.Allibera();

	cout << "Usuari afegit correctament!" << endl << endl;

}

void Usuari::buscarpremium(ConnexioODBC &connexio)
{
    SentenciaODBC s;
	stringstream stream;

	s.Init(connexio);

    stream << "SELECT * FROM Usuari WHERE Premium = 1;";

	if(!s.Executa(stream.str()))
		s.EscriuError();
    while(s.FilaSortida())
    {
        cout << "Usuari " << s.GetColumnaInt(1) << ": " << endl;
		cout << "\t Nom: " << s.GetColumnaString(2) << endl;
		cout << "\t Cognom: " << s.GetColumnaString(3) << endl;
		cout << "\t email: " << s.GetColumnaString(4) << endl;
		cout << "\t Edat: " << s.GetColumnaInt(5) << endl;
		cout << "\t Telefon: " << s.GetColumnaInt(6) << endl;
		cout << "\t Premium: " << s.GetColumnaInt(7) << endl << endl;
    }
	s.Allibera();
}

void Usuari::buscaradult(ConnexioODBC &connexio)
{
    SentenciaODBC s;
	stringstream stream;

	s.Init(connexio);

    stream << "SELECT * FROM Usuari where edat >= 18;";

	if(!s.Executa(stream.str()))
		s.EscriuError();
    while(s.FilaSortida())
    {
        cout << "Usuari " << s.GetColumnaInt(1) << ": " << endl;
		cout << "\t Nom: " << s.GetColumnaString(2) << endl;
		cout << "\t Cognom: " << s.GetColumnaString(3) << endl;
		cout << "\t email: " << s.GetColumnaString(4) << endl;
		cout << "\t Edat: " << s.GetColumnaInt(5) << endl;
		cout << "\t Telefon: " << s.GetColumnaInt(6) << endl;
		cout << "\t Premium: " << s.GetColumnaInt(7) << endl << endl;
    }
	s.Allibera();
}

void Usuari::buscar(ConnexioODBC &connexio)
{
    SentenciaODBC s;
	stringstream stream;

	s.Init(connexio);

    stream << "SELECT * FROM Usuari;";

	if(!s.Executa(stream.str()))
		s.EscriuError();
    while(s.FilaSortida())
    {
        cout << "Usuari " << s.GetColumnaInt(1) << ": " << endl;
		cout << "\t Nom: " << s.GetColumnaString(2) << endl;
		cout << "\t Cognom: " << s.GetColumnaString(3) << endl;
		cout << "\t email: " << s.GetColumnaString(4) << endl;
		cout << "\t Edat: " << s.GetColumnaInt(5) << endl;
		cout << "\t Telefon: " << s.GetColumnaInt(6) << endl;
		cout << "\t Premium: " << s.GetColumnaInt(7) << endl << endl;
    }
	s.Allibera();
}

void Usuari::prem(ConnexioODBC &connexio)
{
    SentenciaODBC s;
	stringstream stream;
	int id;

	s.Init(connexio);

    cout << "Id de l'usuari que es vol fer Premium: ";
    cin >> id;

    stream << "UPDATE Usuari SET Premium = '1' Where (idUsuari = '";
    stream << id << "');";

	if(!s.Executa(stream.str()))
		s.EscriuError();
    while(s.FilaSortida())
    {
        cout << "Usuari " << s.GetColumnaInt(1) << ": " << endl;
		cout << "\t Nom: " << s.GetColumnaString(2) << endl;
		cout << "\t Cognom: " << s.GetColumnaString(3) << endl;
		cout << "\t email: " << s.GetColumnaString(4) << endl;
		cout << "\t Edat: " << s.GetColumnaInt(5) << endl;
		cout << "\t Telefon: " << s.GetColumnaInt(6) << endl;
		cout << "\t Premium: " << s.GetColumnaInt(7) << endl << endl;
    }
	s.Allibera();
}

