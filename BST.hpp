#ifndef BST_HPP
#define BST_HPP
#include <iostream>

using namespace std;

/** Representació d'un arbre binari cerca o
 *  BST (binary search tree). Un arbre binari 
 *  de cerca és un arbre binari en què el subarbre
 *  esquerre de qualsevol node (si no està buit)
 *  conté valors menors que el que conté aquest node, 
 *  i el subarbre dret (si no està buit) conté valors
 *  més grans.
 */ 


template <typename T>
class BST {
	
private:
	struct Item {
		T data;
		Item *left;
		Item *right;
		Item(const T& d, Item *l, Item *r) {
			data = d;
			left = l;
			right = r;
		}
	};

	Item *root;
	
	
	///--------------------------
	// Mètodes privats auxiliars
	//--------------------------

	/* Pre: cert */
	/* Post: no fa res si item és NULL, sinó allibera
       espai de la jerarquia de nodes apuntada per item */
	void clear(Item *node);

	/* Pre: cert */
	/* Post: afegeix un node amb el valor rebut 
	   per paràmetre a la jerarquia de nodes apuntada
	   per item, mantenint les propietats de BST */
	Item* insert(Item *node, const T& d);
	
	/* Pre: cert */
	/* Post: esborra el node amb el valor rebut 
	   per paràmetre de la jerarquia de nodes apuntada
	   per item, mantenint les propietats de BST */	
	Item* remove(Item *node, const T& d);
	
	/* Pre: la jerarquia de nodes apuntada per item
	   conté un node amb el primer valor rebut per
	   paràmetre (d) */
	/* Post: s'ha modificat el valor del node amb el
	   segon valor rebut per paràmetre (newData), de
       la jerarquia de nodes apuntada per item */
	void setValue(Item *node, const T& d, const T& newData);
		
	//Pre: cert
	//Post: Et retorna la direccio del parametre que busques dins del arbre si el troba, i un bolea que diu si el trobes o no
	//Fita: es criden els fills dels arbres
	void find_aux(Item* r, T& d, bool &trobat) const; //posar al privat


public:

	//-------------
	// Constructors
	//-------------
	
	/* Pre: cert */
	/* Post: el resultat és un bst sense cap element */	
	BST();

	//-------------
	// Destructor
	//-------------
	
	/* esborra automàticament els objectes locals
	   en sortir d'un àmbit de visibilitat */
	~BST();

	//-------------
	// Modificadors
	//-------------

	/* Pre: cert */
	/* Post: afegeix un element, amb el valor rebut
	   per paràmetre, al paràmetre implícit */
	void insert(const T& d);

	/* Pre: cert */
	/* Post: esborra l'element, que té el valor rebut
	   per paràmetre, del paràmetre implícit */
	void remove(const T& d);

	/* Pre: el paràmetre implícit conté un element amb
	   el primer valor rebut per paràmetre (d) */
	/* Post: s'ha modificat el valor de l'element amb
	   el segon valor rebut per paràmetre (newData), del
       paràmetre implícit */
	void setValue(const T& d, const T& newData);
	
	//-----------
	// Consultors
	//-----------
	
	/* Pre: cert */
	/* Post: el primer component del resultat indica
	   si el paràmetre implícit conté un element amb
	   el valor rebut per paràmetre; en cas afirmatiu,
	   el segon component conté l'element del paràmetre
	   implícit amb aquest valor, altrament conté un
	   element buit */
	pair<bool, T> find(const T& d) const;

};

#include "BST.cpp"

#endif