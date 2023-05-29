#include "Visita.hpp"

//-------------
// Constructors
//-------------

/* Pre: cert */
/* Post: crea una visita de data 'd' i pacient 'p' */
Visita::Visita(const Data &data, const Pacient &pacient) 
{
    this->data = data;
    this->pacient = pacient;
}

//-----------
// Consultors
//-----------

/* Pre: cert */
/* Post: retorna la data de la visita paràmetre implícit */
Data Visita::getData() const 
{
    return data;
}

/* Pre: cert */
/* Post: retorna el pacient de la visita paràmetre implícit */
Pacient Visita::getPacient() const 
{
    return pacient;
}


void Visita::modify_visita (Data &date){
    this->data = date;    
}

ostream& operator<<(ostream &os, const Visita &v){
    os << v.getData().getDia() <<"/"<< v.getData().getMes() <<"/" << v.getData().getAny() << " " << v.getPacient().getNom() << endl; 
    return os;
}