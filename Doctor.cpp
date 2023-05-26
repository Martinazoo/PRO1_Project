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
        bool trobat = false;
        while(it != visites.end() and not trobat){
            if(s == it->getPacient().getNom()){
                trobat = true;
                visites.erase(it);
            }
            it++;
        }
    }
    void insert_visita (Visita &v, Doctor &d){
        list<Visita> visi = d.getList();
        list<Visita>::iterator it = visi.begin();
        bool insert = false; 
        while (it != visi.end() and not insert){
            if(it->getData() < v.getData()){
                insert = true;
                visi.insert(it,v);
            }
            it++;
        }
        
    }