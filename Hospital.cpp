#include "Hospital.hpp"

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
    /* Post: retorna una llista de Pacient */
    list<Pacient> Hospital::getPacients()
    {
        return pacients;
    }
    
    list<Doctor> Hospital::getDoctors()
    {
        return this->doctors;
    }
    /* Pre: un nom d'un pacient */
    /* Post: retorna true en cas de que existeixi l'usuari, false en cas contrari*/
    bool Hospital::pacientExists (string nom)const
    {
        list<Pacient>::const_iterator it = pacients.begin();
        while (it != pacients.end()) {
            if(nom == pacients.front().getNom()) return true;
            ++it;
        }
        return false;
    }

    bool Hospital::doctorExists(string nom) const 
    {
        list<Doctor>::const_iterator it = doctors.begin();
        while(it != doctors.end()){
            if(nom == doctors.front().getName()) return true;
            ++it;
        }
        return false;
    }

    void Hospital::printPacients()const{
        list<Pacient>::const_iterator it = pacients.begin();
        bool espai = false;
        while (it != pacients.end()){
            if (espai) cout << " ";
            cout << pacients.front();
            it++;
        }
        cout << endl;
    }
    //Modificadors
    /* Pre: una llista de Pacient pacients , i un Pacient p */
    /* Post: afegeix un Pacient al final de la llista */
    void Hospital::addPacient(Pacient &p)
    {
        pacients.push_back(p);
    }
    void Hospital::addDoctor(Doctor &d)
    {
        doctors.push_back(d);
    }
