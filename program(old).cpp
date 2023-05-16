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

  BST<int> bst;
  bst.insert(5);
  bst.insert(7);
  bst.insert(22);
  bst.insert(3);
  bst.insert(10);
  bst.insert(2);

  cout << bst.find(22).first << " " << bst.find(22).second << endl;


}
