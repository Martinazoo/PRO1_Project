#include "Hospital.hpp"
#include <stack>
#include <queue>
    //-------------
	// Constructors
	//-------------

	/* Pre: cert */
	/* Post: crea un hospital buit */
    Hospital::Hospital()
    {
        
    }

    //Consultors
        
    /* Pre: cert */
    /* Post: retorna la cua de pacients del privat */
    Queue<Pacient> Hospital::getPacients()
    {
        return pacients;
    }
    
    /* Pre: cert */
    /* Post: retorna la llista de doctors del privat */
    list<Doctor> Hospital::getDoctors()
    {
        return this->doctors;
    }

    /* Pre: un nom d'un pacient */
    /* Post: retorna un pair, un dels elements del pair es un boolea d'existència del pacient p, i l'altre el Pacient p en questió */
    pair<bool,Pacient> Hospital::pacientExists (const Pacient &p)const //Aixo haura de ser un pair
    {
        pair<bool,Pacient> pairpacient(false, p);
        if(bstpacient.find(p).first == true){
            pairpacient.first = true;
            pairpacient.second = p;
        } 
        return pairpacient;
    }

    /* Pre: un int de gravetat */
    /* Post: retorna true en cas de que el nombre de gravetat sigui correcte, fals en cas contrari */
    bool Hospital::grav_range (const int &grav)const{
        return ((grav <= 3) and (grav >= 1));
    }


    /* Pre: un Doctor d */
    /* Post: retorna un boole (true) en cas de que el Doctor ja existeix, (false) en cas contrari */
    bool Hospital::doctorExists(Doctor d) const 
    {
        list<Doctor>::const_iterator it = doctors.begin();
        while(it != doctors.end()){
            if(d.getName() == it->getName())
                return true;
            ++it;
        }
        return false;
    }
    
    void Hospital::printPacients(Queue<Pacient> &pacients)const{
        Pacient p = pacients.front();
            pacients.pop();
        if (!pacients.empty())
            printPacients(pacients);
        
        cout << "  "<< p << endl;
        //cout << pacients << "a" << endl; 
    }
    //Modificadors
    /* Pre: una llista de Pacient pacients , i un Pacient p */
    /* Post: afegeix un Pacient al final de la llista */
    void Hospital::addPacient(Pacient &p)
    {
        pacients.push(p);
        bstpacient.insert(p);
        
    }
    void Hospital::addDoctor(Doctor &d)
    {
        doctors.push_back(d);
    }
    void Hospital::baixa_pacient(string &s){
        pacients.remove(s);
        bstpacient.remove(s);

        //FER ULTIM CHEQUEIG comprovar que funcioni bé
        list<Doctor>::iterator it = doctors.begin();
        bool trobat = false;
        while(it != doctors.end() and not trobat){
            list<Visita>::iterator it1 = it->getList().begin();
            while(it1 != it->getList().end() and not trobat){
                if(it1->getPacient().getNom() == s) trobat = true;
                else {
                    it1++;
                }
            }
            it++;
        }

    }
    void Hospital::modify_estat_pacient (Pacient p, int grav){
        p.actualitzaEstat(grav); 
        pacients.remove(p.getNom());
        pacients.push(p);
    }
    void Hospital::pop_pacients(){
        pacients.remove(pacients.back());
    }