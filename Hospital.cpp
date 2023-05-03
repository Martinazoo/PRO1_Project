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
    bool Hospital::pacientExists (Pacient p)const
    {
        list<Pacient>::const_iterator it = pacients.begin();
        while (it != pacients.end()) {
            /*
            bool cond1 = p.getNom() == it->getNom();
            bool cond2 = p.getEdat() == it->getEdat();
            bool cond3 = p.getMotiu() == it->getMotiu();
            bool cond4 = p.getGravetat() == it->getGravetat();
            if (cond1 and cond2 and cond3 and cond4) return true;
            */
            if(p.getNom() == it->getNom()){
                if(p.getEdat() == it->getEdat()){
                    if(p.getMotiu() == it->getMotiu()){
                        if(p.getGravetat() == it->getGravetat()) return true;
                    }
                }
            }
            ++it;
        }
        return false;
    }

    bool Hospital::doctorExists(Doctor d) const 
    {
        list<Doctor>::const_iterator it = doctors.begin();
        while(it != doctors.end()){
            /*
            bool cond1 = d.getName() == it->getName();
            bool cond2 = d.getList() == it->getList();
            if(cond1 and cond2) return true;
            */
            if(d.getName() == it->getName()){
                if(d.getList() == it->getList()) return true;
            }
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
