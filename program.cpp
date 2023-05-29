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
          cout << inst << " " << name << endl; 
          if (not h.pacientExists(name).first) cout << "  error" << endl;
          else {
            h.baixa_pacient(name);
          }

        } else if (inst == "alta_doctor") { //comparar gravetat valida
          Doctor d; 
          cin >> d;
          cout << "alta_doctor " << d << endl;
          if(h.doctorExists(d)) cout << "  error" << endl;
          else {
            h.addDoctor(d);
          }

        } else if (inst == "llista_espera"){
          cout << inst << endl;
          Queue<Pacient> paci;
          paci = h.getPacients();
          if(!h.getPacients().empty()){
            h.printPacients(paci);
          }

        } else if (inst == "tractar_seguent_pacient"){
          cout << inst << endl;
          h.pop_pacients();
        } else if (inst == "modificar_estat_pacient"){
          string name;
          int grav;
          cin >> name >> grav; 
          Pacient p = h.nametoPacient(name);
          cout << inst << " " << name << " " << grav << endl;
          if((h.pacientExists(p).first == 0) or (h.grav_range(grav) == 0)){
            cout << "  error" << endl;
          }else {
            
            h.modify_estat_pacient(p, grav);

          }
        } else if (inst == "programar_visita"){
          string namep;
          Doctor d;
          Data date;
          cin >> namep >> d >> date;
          Pacient p = h.nametoPacient(namep);
          cout << "programar_visita " << namep << " " << d << " " << date << endl; 
          if((h.pacientExists(namep).first == 0) or (h.doctorExists(d) == 0)) cout << "  error" << endl;
          else{
            h.programar_visita(p, d, date);
          }

        } else if (inst == "cancellar_visita"){
          string pacient;
          Doctor d;
          Data date;
          cin >> pacient >> d >> date;
          cout << inst << " " << pacient << " " << d << " " << date << endl;
          h.cancellar_visita(pacient, d, date); 
          
        } else if (inst == "mostrar_programacio_visites"){
          cout << inst << " " << endl; 
          h.mostrar_programacio_visites();
        }
        else {
          cout << inst << endl;
          cout << "  error" << endl; 
        }
        
        
        
        
		
    }
    cout << "fi" << endl;
}

	

