#ifndef DOCTOR_HPP
#define DOCTOR_HPP
#include <list>
#include "Visita.hpp"
#include "Pacient.hpp"

using namespace std; 

/** Representació d'un doctor.
 *
 *  Consta de quatre atributs per emmagatzemar el nom (string),
 *  edat (enter), motiu de l'ingrés (string) i gravetat de 
 *  l'estat de salut (int) d'un pacient.
 */

class Doctor {

    private:
        string nom;
        list<Visita> visites;

    public:
        //-------------
		// Constructors
		//-------------
		
		/* Pre: cert */
		/* Post: crea un doctor buit */
        Doctor();

        Doctor(string nom);

        //Consultors

        string getName() const;

        list<Visita> getList() const;

        friend istream& operator>>(istream &is, Doctor &d);
        list<Visita> addvisita (Pacient p, Data d);
};
#endif