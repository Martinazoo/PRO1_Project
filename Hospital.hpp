#ifndef HOSPITAL_H
#define HOSPITAL_H
#include "Doctor.hpp"
#include "PriorityQueue.hpp"
#include "BST.hpp"
#include "Visita.hpp"

using namespace std; 

class Hospital {
    private:
    /*  Ha de representar tota la informaci ́o necess`aria per gestionar el servei
    d’urg`encies format pel conjunt de pacients, el conjunt de doctors i la llista d’espera, i
    oferir els m`etodes necessaris per poder-hi operar  */
        Queue<Pacient> pacients; //print queue fer una copia de la cua i buidarla
        //list<Pacient> regpacient;
        BST<Pacient> bstpacient;
        list<Doctor> doctors;
        

    public:
        //-------------
		// Constructors
		//-------------

		/* Pre: cert */
		/* Post: crea un hospital buit */
        Hospital();

        //Consultors

        /* Pre: cert */
        /* Post: retorna una llista de Pacient */
        Queue<Pacient> getPacients();

        list<Doctor> getDoctors();
        /* Pre: un nom d'un pacient */
        /* Post: retorna true en cas de que existeixi l'usuari, false en cas contrari*/
        pair<bool, Pacient> pacientExists (const Pacient &p)const;
        bool doctorExists (Doctor d) const;
        void printPacients (Queue<Pacient> &pacients)const;
        //Modificadors
        /* Pre: una llista de Pacient pacients , i un Pacient p */
        /* Post: afegeix un Pacient al final de la llista */
        void addPacient (Pacient &p);
        void addDoctor(Doctor &d);
        void baixa_pacient(string &s);
};
#endif