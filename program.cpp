#include <iostream>
#include "Hospital.hpp"
#include "PriorityQueue.hpp"
#include "BST.hpp"
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
          cout << inst << " " << p << endl;
          if(!h.pacientExists(p).first){
            h.addPacient(p);
          }
          else {
            cout << "  error" << endl;
          }
			

        } else if (inst == "baixa_pacient") {
          string name;
          cin >> name;
          if (not h.pacientExists(name).first) cout << "  error" << endl;
          else {
            h.baixa_pacient(name);
          }

        } else if (inst == "alta_doctor") {
          Doctor d; 
          cin >> d;
          cout << "alta_doctor " << d << endl;
          if(h.doctorExists(d)) cout << "  error" << endl;
          else {
            h.addDoctor(d);
          }

        } else if (inst == "llista_espera"){
          cout << "llista_espera" << endl;
          Queue<Pacient> paci;
          paci = h.getPacients();
          h.printPacients(paci);
        } else if (inst == "tractar_seguent_pacient"){
          cout << "tractar_seguent_pacient" << endl;
          h.getPacients().pop();
        } else if (inst == "modificar_estat_pacient"){
          string name;
          int grav;
          cin >> name >> grav ;
          if(not h.pacientExists(name).first or not h.grav_range(grav)){
            cout << " error" << endl;
          }
          else {
            h.modify_estat_pacient(h.pacientExists(name).second, grav);
          }
        } else if (inst == "programar_visita"){
          string namep, named;
          Data d;
          cin >> namep >> named >> d;
          if(!(h.pacientExists(namep).first) or !h.doctorExists(named)) cout << "  error" << endl;
          else{
            
          }

        } else if (inst == "cancellar_visita"){
          /* code */
        } else if (inst == "mostrar_programacio_visites"){
          /* code */
        }
        else {
          cout << "  error" << endl; 
        }
        
        
        
        
		
    }
    cout << "fi" << endl;
}

	

