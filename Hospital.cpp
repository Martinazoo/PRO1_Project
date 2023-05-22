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
    Queue<Pacient> Hospital::getPacients()
    {
        return pacients;
    }
    
    list<Doctor> Hospital::getDoctors()
    {
        return this->doctors;
    }
    /* Pre: un nom d'un pacient */
    /* Post: retorna true en cas de que existeixi l'usuari, false en cas contrari*/
    pair<bool,Pacient> Hospital::pacientExists (const Pacient &p)const //Aixo haura de ser un pair
    {
        pair<bool,Pacient> pairpacient(false, p);
        if(bstpacient.find(p).first == true){
            pairpacient.first = true;
            pairpacient.second = p;
        } 
        return pairpacient;
    }
    bool Hospital::grav_range (const int &grav)const{
        return ((grav <= 3) or (grav >= 1));
    }

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
        
        cout << " " << p << endl;
        
        

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

        //buscar el pacient dintre de la llista de doctors-> dintre de visites-> dintre de pacients
        /*list<Doctor>::iterator it = doctors.begin();
        bool trobat = false;
        while(it != doctors.end() and not trobat){
            it->visites.front().getPacient().getNom();
        }
        */
    }
    void Hospital::modify_estat_pacient (Pacient p, int grav){
        p.actualitzaEstat(grav); 
        pacients.remove(p.getNom());
        pacients.push(p);
    }