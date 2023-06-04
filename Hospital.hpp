#ifndef HOSPITAL_H
#define HOSPITAL_H
#include "Doctor.hpp"
#include "PriorityQueue.hpp"
#include "BST.hpp"
#include "Visita.hpp"

using namespace std; 

class Hospital {
    private:
        Queue<Pacient> pacients; 
        BST<Pacient> bstpacient;
        list<Doctor> doctors;

    public:

        //-------------
		// Constructors
		//-------------

		/* Pre: cert */
		/* Post: crea un hospital buit */
        Hospital();

        //-------------
		// Consultors
		//-------------

        /* Pre: cert */
        /* Post: retorna la cua de pacients del paràmetre impícit */
        Queue<Pacient> getPacients();

        /* Pre: cert */
        /* Post: retorna l'arbre de pacients del paràmetre implícit */
        BST<Pacient> getBstPacients();

        /* Pre: cert */
        /* Post: retorna la llista de doctors del paràmetre implícit*/
        list<Doctor> getDoctors();

        /* Pre: cert */
        /* Post: retorna true en cas de que existeixi el Pacient "p", juntament amb el pacient p. False en cas contrari */
        pair<bool, Pacient> pacientExists (const Pacient &p)const;

        /* Pre: cert */
        /* Post: retorna un booleà que retorna true si la "grav" es dintre dels limits 1 i 3, false en cas contrari */
        bool grav_range (const int &grav)const;

        /* Pre: cert */
        /* Post: retorna un booleà que retorna true en cas de que el doctor "d" exixteixi, false en cas contrari */
        bool doctorExists (Doctor d) const;

        /* Pre: cert */
        /* Post: retorna un booleà, true en cas de que "d" estigui a la llista de Doctor del paràmetre implícit, false
        en cas contrari */
        bool doctor_is_in_list (const Doctor&d);

        /* Pre: cert */
        /* Post: s'han escrit els pacients de la queue de pacients */
        void printPacients (Queue<Pacient> &pacients)const;

        //-------------
		// Modificadors
		//-------------

        /* Pre: un Pacient p */
        /* Post: s' ha afegit el Pacient p a la cua de priotitat juntament al BST de Pacients */
        void addPacient (Pacient &p);

        /* Pre: un Doctor d */
        /* Post: s'ha afegit el Doctor d al final de la llista de doctors */
        void addDoctor(Doctor &d);

        /* Pre: un Pacient p */
        /* Post: s'ha esborrat el Pacient p de la cua de prioritat, juntament del BST de Pacients
        i tambè s'han esborrat totes les visites que tenia programades */
        void baixa_pacient(Pacient &p);

        /* Pre: un Pacient p, i un enter grav */
        /* Post: s'ha modificat l'estat del Pacient p, amb un nivell de gravetat grav */
        void modify_estat_pacient (Pacient &p, int grav); 

        /* Pre: cert */
        /* Post: en cas de que la cua del paràmetre implícit estigui buida, dona error, en cas contrari 
        s'esborra el primer element de la cua del paràmetre implícit */
        void pop_pacients();

        /* Pre: cert */
        /* Post: s'ha mosrat per pantalla la llista de Doctor del paràmetre implícit, que
        conté cada Doctor amb les seves corresponents visites */
        void mostrar_programacio_visites();

        /* Pre: un string u, un Doctor d i una Data date */
        /* Post: en cas de que el nom u del Pacient o el Doctor d no existeixin,
        donarà error. En cas contrari s'haura esborrat la visita del usuari u de la llista del 
        paràmetre implícit amb Data date */
        void cancellar_visita(string &u, Doctor &d, Data &date);

        /* Pre: un Pacient p, un Doctor d i una Data date */
        /* Post: s'ha afegit una Visita amb data date i Pacient p a la llista de Doctor
        del paràmetre implícit */
        void programar_visita(const Pacient &p,const Doctor &d, Data &date);

        /* Pre: un string s */
        /* Post: retorna el pacient corresponent al nom s */
        Pacient nametoPacient (string const &s);
};
#endif