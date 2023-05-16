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
    list<Visita> Doctor::addvisita(Pacient p, Data d){
         cout << p << d << endl;
         list<Visita> a;
         return a;   
    }