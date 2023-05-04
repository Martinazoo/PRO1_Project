#include <iostream>
#include "Hospital.hpp"

using namespace std;

/** Programa principal
 *
 * main() crea l'hospital, fa la lectura d'instruccions i
 * l'escriptura de resultats. Les operacions estan definides i
 * implementades en les classes Hospital, Pacient, Doctor, Visita,
   Data, PriorityQueue i BST
 */

int main() {
	// Crear un hospital
	Hospital h;
	// Processar instruccions
    string inst;
    while ((cin >> inst) and (inst != "fi")) {
        if (inst == "alta_pacient") { 
          Pacient p;
          cin >> p; 
          cout << p << endl;
          if(!h.pacientExists(p));
          else {
            cout << "Error: " << endl;
          }
			

        } else if (inst == "baixa_pacient") {
          string name;
          cin >> name;
          if (not h.pacientExists(name)) cout << "Error: " << endl;
          else {
          
          }

        } else if (inst == "alta_doctor") {
          Doctor d; 
          cin >> d;
          if(h.doctorExists(d)) cout << "Error: " << endl;
          else {
            h.addDoctor(d);
          }

        } else if (inst == "llista_espera"){
          h.printPacients();
        } else if (inst == "tractar_seguent_pacient"){
          /* code */
        } else if (inst == "modificar_estat_pacient"){
          string name;
          cin >> name ;
          //if(h.pacientExists()) h.getPacients(). //pair amb iterator?? o com sabem en quina posicio de la llista esta el pacient
          //despres fem un actualitzar estat del pacient
        } else if (inst == "programar_visita"){
          /* code */
        } else if (inst == "cancellar_visita"){
          /* code */
        } else if (inst == "mostrar_programacio_visites"){
          /* code */
        }
        
        
        
        
        
		
    }
    cout << "fi" << endl;
}

	
