#include "Pacient.hpp"

        //-------------
		// Constructors
		//-------------
		
		/* Pre: cert */
		/* Post: crea un pacient buit */		
		Pacient()
        {

        }

        /* Pre: cert */
		/* Post: crea un pacient de nom 'nom' */	
		Pacient(string nom)
        {
            this->nom = nom;
        }
		
		/* Pre: cert */
		/* Post: crea un pacient amb els valors de 'nom',
           'edat', 'motiu' i 'gravetat' rebuts per paràmetre */
		Pacient(string nom, int edat, string motiu, int gravetat)
        {
            this-> nom = nom;
            this-> edat = edat;
            this-> motiu = motiu;
            this-> gravetat = gravetat;
        }
		
		//-------------
		// Modificadors
		//-------------

		/* Pre: cert */
		/* Post: el valor de gravetat del pacient paràmetre 
		   implícit	passa a ser el valor de 'gravetat' */
		void actualitzaEstat(int gravetat)
        {
            this-> gravetat = gravetat;
        }
		
		//-----------
		// Consultors
		//-----------

		/* Pre: cert */
		/* Post: retorna el nom del pacient paràmetre implicit */
		string getNom() const
        {
            return nom;
        }

		/* Pre: cert */
		/* Post: retorna l'edat del pacient paràmetre implicit */
		int getEdat() const
        {
            return edat;
        }

		/* Pre: cert */
		/* Post: retorna el motiu de l'ingrés del pacient paràmetre 
		   implicit */
		string getMotiu() const
        {
            return motiu;
        }

		/* Pre: cert */
		/* Post: retorna la gravetat de l'estat del pacient paràmetre
		   implicit */		
		int getGravetat() const
        {
            return gravetat;
        }
		
		/* Pre: cert */
		/* Post: retorna un booleà que indica si l'estat de gravetat
		   del pacient paràmetre implícit i el del pacient 'p' són
		   identics (true) o no ho són (false) */
		bool compare(const Pacient &p) const;


		// PODEU AFEGIR ELS MÈTODES QUE NECESSITEU
		
		
		//-----------
		// L/E
		//-----------
		
		/* Pre: estan preparats al canal estàndard d'entrada quatre valors
		   en aquest ordre - string, enter, string i enter */
		/* Post: el pacient 'p' passa a tenir els valors llegits del canal
		   estàndard d'entrada com a nom, edat, motiu i gravetat, 
		   respectivament */			
		friend istream& operator>>(istream &is, Pacient &p);
		
		/* Pre: cert */
		/* Post: s'han escrit els atributs nom, edat, motiu i gravetat del
           pacient 'p' al canal estàndard de sortida */
		friend ostream& operator<<(ostream &os, const Pacient &p);