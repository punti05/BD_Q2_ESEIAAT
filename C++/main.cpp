/* Projecte DB: IDBM
    Cristina Punti Alvarez */

#include <iostream>
#include <stdio.h>
#include <sstream>
#include <fstream>

#include "ConnexioODBC.h"
#include "SentenciaODBC.h"
#include "Noticies.h"
#include "Categoria.h"
#include "Genere.h"
#include "Rol.h"
#include "Noticies.h"
#include "Titol.h"
#include "Usuari.h"

using namespace std;

char Menu() {
	int opcio;

	cout << endl << "               IDBM               " << endl;
	cout << "----------------------------------" << endl;
	cout << "------ Escull la teva opcio ------" << endl;
    cout << "----------------------------------" << endl << endl;

    cout << "     1 - Opcions Titol" << endl;
    cout << "     2 - Opcions Usuari" << endl;
	cout << "     3 - Mostrar Categories" << endl;
	cout << "     4 - Mostrar Generes" << endl;
	cout << "     5 - Mostrar Rols" << endl;
	cout << "     6 - Mostrar Noticies" << endl;
	cout << "     7 - Reset" << endl;
	cout << "     0 - Sortir" << endl << endl;

	cout << "Selecciona una opcio:\t";
	cin >> opcio;
	cout << endl;

	return opcio;
}

char MenuTitol() {
	char opcio;

	cout << "----------------------------------" << endl;
	cout << "------------- Titol! -------------" << endl;
	cout << "----------------------------------" << endl << endl;
	cout << "     1 - Llistar titols" << endl;
	cout << "     2 - Afegir titol" << endl;
	cout << "     3 - Esborrar titols nous" << endl;
	cout << "     4 - Buscar titol" << endl;
	cout << "     5 - Buscar titols - director" << endl;
	cout << "     0 - Sortir" << endl;
	cout << endl;
	cout << "Selecciona una opcio:\t";
	cin >> opcio;
	cout << endl;

	return opcio;
}

void TractarTitol(ConnexioODBC &connexio) {
	char opcio;
	Titol t;

	opcio = MenuTitol();
	while(opcio != '0')
	{
		switch(opcio)
		{
		case '1':
            t.llistar(connexio);
			break;
		case '2':
            t.llegir();
            t.afegir(connexio);
			break;
        case '3':
            t.esborrar_nous(connexio);
            break;
        case '4':
            t.buscar(connexio);
			break;
        case '5':
            t.buscardirector(connexio);
			break;
        default:
            cout << "No existeix aquesta opcio!" << endl << endl;
            break;
		}
		opcio = MenuTitol();
	}
}

char MenuUsuari() {
	char opcio;

	cout << "----------------------------------" << endl;
	cout << "------------- Usuari -------------" << endl;
	cout << "----------------------------------" << endl << endl;
	cout << "     1 - Llistar usuaris" << endl;
	cout << "     2 - Afegir usuari" << endl;
	cout << "     3 - Usuari Premium" << endl;
	cout << "     4 - Buscar usuari" << endl;
	cout << "     0 - Sortir" << endl;
	cout << endl;
	cout << "Selecciona una opcio:\t";
	cin >> opcio;
	cout << endl;

	return opcio;
}

char MenuBuscarUsuari() {
	char opcio;

	cout << "----------------------------------" << endl;
	cout << "--------- Buscar  Usuari ---------" << endl;
	cout << "----------------------------------" << endl << endl;
	cout << "     1 - Usuaris premium" << endl;
	cout << "     2 - Usuaris majors d'edat" << endl;
	cout << "     3 - Tots els usuaris" << endl;
	cout << "     0 - Sortir" << endl;
	cout << endl;
	cout << "Selecciona una opcio:\t";
	cin >> opcio;
	cout << endl;

	return opcio;
}

void buscarUsuari(ConnexioODBC &connexio) {
    char opcio;
	Usuari uu;

	opcio = MenuBuscarUsuari();
	while(opcio != '0')
	{
		switch(opcio)
		{
		case '1':
            uu.buscarpremium(connexio);
			break;
		case '2':
            uu.buscaradult(connexio);
			break;
		case '3':
            uu.buscar(connexio);
			break;
        default:
            cout << "No existeix aquesta opcio!" << endl << endl;
            break;
		}
		opcio = MenuBuscarUsuari();
	}
}

void TractarUsuari(ConnexioODBC &connexio) {
	char opcio;
	Usuari u;

	opcio = MenuUsuari();
	while(opcio != '0')
	{
		switch(opcio)
		{
		case '1':
            u.llistar(connexio);
			break;
		case '2':
            u.llegir();
            u.afegir(connexio);
			break;
		case '3':
            u.prem(connexio);
			break;
        case '4':
            buscarUsuari(connexio);
			break;
        default:
            cout << "No existeix aquesta opcio!" << endl << endl;
            break;
		}
		opcio = MenuUsuari();
    }
}

void MostrarCategoria(ConnexioODBC &connexio) {
	char opcio;
	Categoria c;

    c.llistar(connexio);
}

void MostrarGenere(ConnexioODBC &connexio) {
	char opcio;
	Genere g;

    g.llistar(connexio);
}

void MostrarRol(ConnexioODBC &connexio) {
	char opcio;
	Rol r;

    r.llistar(connexio);
}

void MostrarNoticia(ConnexioODBC &connexio) {
	char opcio;
	Noticies n;

    n.llistar(connexio);
}

void Reset(ConnexioODBC &connexio){
    SentenciaODBC s;
    stringstream stream;
    int id;

    s.Init(connexio);

    stream << "call reset()";

    if(!s.Executa(stream.str()))
        s.EscriuError();
    s.Allibera();

    cout << "Base de dades igual que a l'inici!" << endl << endl;
}

int main(){
    ConnexioODBC connexio;        // Connectem el main a la base de dades
    SentenciaODBC sentencia;      //Per executar una sentència: Primer inicialitzo la ruta a la meva font de dades que esta guardada a connex
    int opcio;

    connexio.Connectar("FD");
    opcio = Menu();

    while(opcio != 0) {
		switch(opcio) {
        case 1:
			TractarTitol(connexio);
			break;
        case 2:
			TractarUsuari(connexio);
			break;
        case 3:
			MostrarCategoria(connexio);
			break;
		case 4:
			MostrarGenere(connexio);
			break;
		case 5:
			MostrarRol(connexio);
			break;
		case 6:
			MostrarNoticia(connexio);
			break;
		case 7:
			Reset(connexio);
			break;
        default:
            cout << "No existeix aquesta opcio!" << endl << endl;
            break;
		}
		opcio = Menu();
	}
	connexio.Desconnectar();    //Per desconnectar
}
