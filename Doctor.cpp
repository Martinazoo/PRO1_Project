#include "Doctor.hpp"

    Doctor::Doctor()
    {

    }

    Doctor::Doctor(string nom)
    {
        this->nom = nom; 
    }

    //Consultors

    string Doctor::getName()const
    {
        return nom;
    }

    list<Visita> Doctor::getList() const
    {
        return visites;
    }

    istream& operator>>(istream &is, Doctor &d){
			is >> d.nom;
			return is;
		}
    
    ostream& operator<<(ostream &os, const Doctor &d){
        return os << d.nom;
    }
    list<Visita> Doctor::addvisita(Pacient p, Data d){
         cout << p << d << endl;
         list<Visita> a;
         return a;   
    }
    void Doctor::baixa_pacient (string &s){
        list<Visita>::iterator it = visites.begin();
        while(it != visites.end()){
            if(s == it->getPacient().getNom()){
                it = visites.erase(it);
            }
            //cout << "sumo" << endl;
            else {
                it++;
            }
        } 
    }
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

    bool Doctor::pacient_is_in_list(const Pacient &p){
    list<Visita>::iterator it = visites.begin();
    while (it != visites.end()){
        if(it->getPacient().getNom() == p.getNom()){
            return true;
        }
        it++;
    }
    return false;
    
    }
    bool Doctor::visita_is_in_list(const Visita &v){
       list<Visita>::iterator it = visites.begin();
       while(it != visites.end()){
        if(it->getData() == v.getData()) return true;
        it++;
       }
       return false;
    }
    