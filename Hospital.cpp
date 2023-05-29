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

    bool Hospital::visitaExists (const Visita&v){
        list<Doctor>::iterator it = doctors.begin();
        while(it != doctors.end()){
            if(it->visita_is_in_list(v)) return true;
            it++;
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
            it->baixa_pacient(s);
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
        if(pacients.empty()) cout << "  error" << endl;
        else {
            pacients.pop();
        }
    }
    Pacient Hospital::get_Pacient(string &s){
        Pacient ss = bstpacient.find(s).second;
        cout << bstpacient.find(s).first << endl;
        cout << ss.getGravetat() << endl;
        return ss;
       
    }
    void Hospital::mostrar_programacio_visites(){
        for(list<Doctor>::iterator it = doctors.begin(); it != doctors.end(); ++it ){
            cout << "  " << it->getName() << endl; 
            list<Visita>::iterator it1;
            list<Visita> visites = it->getList();
            for(it1 = visites.begin(); it1 != visites.end(); ++it1){
                cout << "  " << *it1; 
            }
        }
    }
    void Hospital::cancellar_visita(string &u, Doctor &d, Data &date){
        Pacient p = nametoPacient(u);
        Visita v(date, p);
        /*cout << v.getData() << "es la data " << endl;
        cout << doctor_is_in_list(d) << endl;
        cout << pacientExists(p).first << endl; 
        cout << d.visita_is_in_list(v) << endl; 
        */
        //cout << doctor_is_in_list(d) << " " << d.pacient_is_in_list(p) << " " << visitaExists(v) << endl;
        if(not doctor_is_in_list(d) or not pacientExists(p).first /*or not d.visita_is_in_list(v)*/){
            cout << "  error" << endl;
        }
        else {
            list<Doctor>::iterator it = doctors.begin();
            bool find = false;
            while(it != doctors.end() and not find){
                if(it->getName() == d.getName()){
                    find = true; 
                    it->eliminar_visita(v);
                }
            }    
        }
    }

    

    Pacient Hospital::nametoPacient (string const &s){
        Pacient p(s);
        p = bstpacient.find(p).second;
        return p;
    }
    void Hospital::programar_visita(const Pacient &p,const Doctor &d, Data &date){
        Visita v(date,p);
        list<Doctor>::iterator it = doctors.begin();
        bool find = false;
        while(it != doctors.end() and not find){
            if(it->getName() == d.getName()){
                it->insert_visita(v, date);
            }
            it++;
        }
        
    }

    bool Hospital::doctor_is_in_list (const Doctor&d) {
        list<Doctor>::iterator it = doctors.begin();
        while (it != doctors.end()){
            if(d.getName() == it->getName()){
                return true;
            }
            it++;
        }
        return false;

    }
    
