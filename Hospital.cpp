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

        //-------------
        // Consultors
        //-------------

        
        /* Pre: cert */
        /* Post: retorna la cua de pacients del parametre implicit */
        Queue<Pacient> Hospital::getPacients()
        {
            return pacients;
        }

        /* Pre: cert */
        /* Post: retorna l'arbre de pacients del paràmetre implícit */
        BST <Pacient> Hospital::getBstPacients(){
            return bstpacient;
        }    
       
        
        /* Pre: cert */
        /* Post: retorna la llista de doctors del paràmetre implícit*/
        list<Doctor> Hospital::getDoctors()
        {
            return this->doctors;
        }

        /* Pre: cert */
        /* Post: retorna true en cas de que existeixi el Pacient "p", juntament amb el pacient p. False en cas contrari */
        pair<bool,Pacient> Hospital::pacientExists (const Pacient &p)const 
        {
            pair<bool,Pacient> pairpacient(false, p);
            if(bstpacient.find(p).first == true){
                pairpacient.first = true;
                pairpacient.second = p;
            } 
            return pairpacient;
        }

        /* Pre: cert */
        /* Post: retorna un booleà que retorna true si la "grav" es dintre dels limits 1 i 3, false en cas contrari */
        bool Hospital::grav_range (const int &grav)const{
            if ( grav >= 1 and grav <= 3) return true;
            return false;    
        }


        /* Pre: cert */
        /* Post: retorna un booleà que retorna true en cas de que el doctor "d" exixteixi, false en cas contrari */
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



        /* Pre: un doctor d */
        /* Post: retorna un booleà, true en cas de que el Doctor existeixi, false
        en cas contrari */
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
        
        /* Pre: cert */
        /* Post: s'han escrit els pacients de la queue de pacients */
        void Hospital::printPacients(Queue<Pacient> &pacients)const{

            cout << "  "<< pacients.front() << endl;
            pacients.pop();
            if (!pacients.empty())
                printPacients(pacients);
        }
        
        //-------------
		// Modificadors
		//-------------

        //* Pre: un Pacient p */
        /* Post: s' ha afegit el Pacient p a la cua de priotitat juntament al BST de Pacients */
        void Hospital::addPacient(Pacient &p)
        {
            pacients.push(p);
            bstpacient.insert(p);
            
        }

        /* Pre: un Doctor d */
        /* Post: s'ha afegit el Doctor d al final de la llista de doctors */
        void Hospital::addDoctor(Doctor &d)
        {
            doctors.push_back(d);
        }

        /* Pre: un Pacient p */
        /* Post: s'ha esborrat el Pacient p de la cua de prioritat, juntament del BST de Pacients
        i tambè s'han esborrat totes les visites que tenia programades */
        void Hospital::baixa_pacient(Pacient &p){
            pacients.remove(p);
            bstpacient.remove(p);
        
            list<Doctor>::iterator it = doctors.begin();
            while(it != doctors.end()){
                string nom = p.getNom();
                it->baixa_pacient(nom);
                it++;
            }
        }

        /* Pre: un Pacient p, i un enter grav */
        /* Post: s'ha modificat l'estat del Pacient p, amb un nivell de gravetat grav */ 
        void Hospital::modify_estat_pacient (Pacient &p, int grav){ 
            bstpacient.find(p).second;
            pacients.remove(p);
            p.actualitzaEstat(grav);  
            pacients.push(p);
        }

        /* Pre: cert */
        /* Post: en cas de que la cua del paràmetre implícit estigui buida, dona error, en cas contrari 
        s'esborra el primer element de la cua del paràmetre implícit */
        void Hospital::pop_pacients(){
            if(pacients.empty()) cout << "  error" << endl;
            else {
                pacients.pop();
            }
        }

        /* Pre: cert */
        /* Post: s'ha mosrat per pantalla la llista de Doctor del paràmetre implícit, que
        conté cada Doctor amb les seves corresponents visites */
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

        /* Pre: un string u, un Doctor d i una Data date */
        /* Post: en cas de que el nom u del Pacient o el Doctor d no existeixin,
        donarà error. En cas contrari s'haura esborrat la visita del usuari u de la llista del 
        paràmetre implícit amb Data date */
        void Hospital::cancellar_visita(string &u, Doctor &d, Data &date){
            Pacient p = nametoPacient(u);
            Visita v(date, p);
            if(not doctor_is_in_list(d) or not pacientExists(p).first){
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

        /* Pre: un Pacient p, un Doctor d i una Data date */
        /* Post: s'ha afegit una Visita amb data date i Pacient p a la llista de Doctor
        del paràmetre implícit */
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

        /* Pre: un string s */
        /* Post: retorna el pacient corresponent al nom s */
        Pacient Hospital::nametoPacient (string const &s){
            Pacient p(s);
            p = bstpacient.find(p).second;
            return p;
        }