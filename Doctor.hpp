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

        /* Pre: cert */
		/* Post: crea un Doctor amb el nom desitjat */
        Doctor(string nom);
        
        //Consultors
        
        /* Pre: cert */
		/* Post: retorna el nom del doctor */
        string getName() const;

        /* Pre: cert */
		/* Post: retorna la llista de visites del doctor*/
        list<Visita> getList() const;

        /* Pre: el nom del pacient que volem baixar */
		/* Post: treu totes les visites del pacient donat*/
        void baixa_pacient (string &s);

        /* Pre: Una visita i una data */
		/* Post: Insereix una visita a la llista de visites del doctor*/
        void insert_visita (const Visita &v,const Data &date);

        /* Pre: la visita que desitja eliminar de la llista */
		/* Post: elimina la visita de la llista de visites*/
        void eliminar_visita (const Visita &v);



        friend istream& operator>>(istream &is, Doctor &d);
        friend ostream& operator<<(ostream &os, const Doctor &d);
        

};
#endif