#include "Doctor.hpp"


        //-------------
		// Constructors
		//-------------

        /* Pre: cert */
		/* Post: crea un doctor buit */
        Doctor::Doctor()
        {

        }

        /* Pre: cert */
		/* Post: crea un Doctor amb el nom desitjat */
        Doctor::Doctor(string nom)
        {
            this->nom = nom; 
        }

        //-------------
		// Consultors
		//-------------

        /* Pre: cert */
		/* Post: retorna el nom del doctor */
        string Doctor::getName()const
        {
            return nom;
        }

        /* Pre: cert */
		/* Post: retorna la llista de visites del doctor*/
        list<Visita> Doctor::getList() const
        {
            return visites;
        }

        //-------------
		// Modificadors
		//-------------        

        /* Pre: el nom del pacient que volem baixar */
		/* Post: treu totes les visites del pacient donat*/
        void Doctor::baixa_pacient (string &s){
            list<Visita>::iterator it = visites.begin();
            while(it != visites.end()){
                if(s == it->getPacient().getNom()){
                    it = visites.erase(it);
                }
                else {
                    it++;
                }
            } 
        }

        /* Pre: Una visita i una data */
		/* Post: Insereix una visita a la llista de visites del doctor*/
        void Doctor::insert_visita (const Visita &v,const Data &date){
            list<Visita>::iterator it = visites.begin();
            bool inserted = false;
            if(visites.empty()){
                visites.push_back(v);
            }
            else {
                while (it != visites.end() and !inserted){
                    if(it->getData() <= date){
                        it++;
                    }
                    else {
                        visites.insert(it,v);
                        inserted = true;
                        it++;
                    }
                    
                }
            }
            
        }

        /* Pre: la visita que desitja eliminar de la llista */
		/* Post: elimina la visita de la llista de visites*/
        void Doctor::eliminar_visita (const Visita &v){
            list<Visita>::iterator it = visites.begin();
            bool removed = false;
            if(visites.empty()) cout << " error" << endl;
            else {
                while (it != visites.end() and not removed){
                    //cout << it-> getPacient() << " " << it->getData() << endl; 
                    if (it->getPacient() == v.getPacient()){
                        
                        if(it->getData() == v.getData()){
                            
                            //cout << it->getPacient() <<  " " << it->getData() << endl; 
                            
                            it = visites.erase(it);
                            removed = true;
                            if(removed) return;
                            
                        }
                        
                    }
                    
                    it++;
                }
            
            }
            
        }

        /* Pre: un doctor d*/
        /* Post: el doctor d passa a tenir els atributs llegits pel canal d'entrada (string)*/
        istream& operator>>(istream &is, Doctor &d){
                is >> d.nom;
                return is;
            }
        
        /* Pre: un Doctor d*/
        /* Post: s'ha escrit el nom del doctor "d" al canal de sortida */
        ostream& operator<<(ostream &os, const Doctor &d){
            return os << d.nom;
        }