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
        BST<Pacient> bstpacient;
        list<Doctor> doctors;
        //BST<Doctor> bstdoctor;
        

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
        BST<Pacient> getBstPacients();
        list<Doctor> getDoctors();
        /* Pre: un nom d'un pacient */
        /* Post: retorna true en cas de que existeixi l'usuari, false en cas contrari*/
        pair<bool, Pacient> pacientExists (const Pacient &p)const;
        bool grav_range (const int &grav)const;
        bool doctorExists (Doctor d) const;
        void printPacients (Queue<Pacient> &pacients)const;
        //Modificadors
        /* Pre: una llista de Pacient pacients , i un Pacient p */
        /* Post: afegeix un Pacient al final de la llista */
        void addPacient (Pacient &p);
        void addDoctor(Doctor &d);
        void baixa_pacient(string &s);
        void modify_estat_pacient (Pacient &p, int grav); 
        void pop_pacients();
        Pacient get_Pacient(string &s);
        void mostrar_programacio_visites();
        void cancellar_visita(string &u, string &d, Data &date);
        Pacient nametoPacient (string const &s);
        void programar_visita(const Pacient &p, Doctor &d, const Data &date);
};
#endif