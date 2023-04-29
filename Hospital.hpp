#ifndef HOSPITAL_H
#define HOSPITAL_H
#include "Pacient.hpp"
#include "Data.hpp"
#include "Visita.hpp"
#include "PriorityQueue.hpp"
#include "BST.hpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std; 

class Hospital {
    private:
    /*  Ha de representar tota la informaci ́o necess`aria per gestionar el servei
    d’urg`encies format pel conjunt de pacients, el conjunt de doctors i la llista d’espera, i
    oferir els m`etodes necessaris per poder-hi operar  */
        vector <Pacient> pacients;
        //vector <Doctors> doctors
        //vector <

    public:
        //-------------
		// Constructors
		//-------------

		/* Pre: cert */
		/* Post: crea un hospital buit */
    Hospital();


};
#endif