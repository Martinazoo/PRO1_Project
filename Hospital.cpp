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
    BST <Pacient> Hospital::getBstPacients(){
        return bstpacient;
    }    
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
        if ( grav >= 1 and grav <= 3) return true;
        return false;    
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

        cout << "  "<< pacients.front() << endl;
        pacients.pop();
        if (!pacients.empty())
            printPacients(pacients);
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
        list<Doctor>::iterator it = doctors.begin();
        while(it != doctors.end()){
            list<Visita>::iterator it1 = it->getList().begin();
            while(it1 != it->getList().end()){
                if(it1->getPacient().getNom() == s) it1 = it->getList().erase(it1);
                else {
                    it1++;
                }
            }
            it++;
        }

    }
    void Hospital::modify_estat_pacient (Pacient &p, int grav){ 
        bstpacient.find(p).second;
        pacients.remove(p);
        p.actualitzaEstat(grav);  
        pacients.push(p);
    }
    void Hospital::pop_pacients(){
        pacients.pop();
    }
    Pacient Hospital::get_Pacient(string &s){
        Pacient ss = bstpacient.find(s).second;
        cout << bstpacient.find(s).first << endl;
        cout << ss.getGravetat() << endl;
        return ss;
       
    }
    void Hospital::mostrar_programacio_visites(){
        list<Doctor>::iterator it = doctors.begin();
        while(it != doctors.end()){
            cout << it->getName() << endl;
            list<Visita>::iterator it1 = it->getList().begin();
            while(it1 != it->getList().end()){
                cout << "  "<< it1->getData() << " " << it1->getPacient() << endl;
                ++it1;
            }
            ++it;
        }
    }
    void Hospital::cancellar_visita(string &u, string &d, Data &date){
        if(not doctorExists(d) and not pacientExists(u).first){
            cout << " error" << endl;
        }
        else {
            list<Doctor>::iterator it = doctors.begin();
            bool find = false;
            while(it != doctors.end() and not find){
                if(it->getName() == d){
                    list<Visita>::iterator it1 = it->getList().begin();
                    while(it1 != it->getList().end()){
                        if(it1->getPacient().getNom() == u and it1->getData() == date){
                            find = true;
                            it->getList().erase(it1);
                        }
                        it1++;
                    }
                }
                it++;
            }
        }
    }

    Pacient Hospital::nametoPacient (string const &s){
        Pacient p(s);
        p = bstpacient.find(p).second;
        return p;
    }
    void Hospital::programar_visita(const Pacient &p, const Doctor &d, const Data &date){
        list<Doctor>::const_iterator it = doctors.begin();
        bool find = false;
        while (it != doctors.end() and not find){
            if(it->getName() == d.getName()){
                list<Visita> visites = it->getList();
                list<Visita>::const_iterator it1 = visites.begin();
                Visita v(date, p);
                if(it1->getData() < date){
                    visites.insert(++it1, v);
                } 
                else {
                    it1++;
                }
            }
            it++;
        }
    }