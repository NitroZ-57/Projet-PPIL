#include <iostream>
#include "Formes/Cercle.h"
#include "Formes/Forme.h"
#include "Formes/Groupe.h"
#include "Formes/Polygone.h"
#include "Formes/Segment.h"
#include "Formes/Vecteur2D.h"
#include "Exceptions/QExceptionsGeometrie.h"
#include "Exceptions/QExceptionsCoordMonde.h"
#include "Exceptions/QExceptionsReseaux.h"
#include "Exceptions/QExceptionsSauvegarde.h"
#include "Exceptions/QExceptionsVisiteur.h"
#include "ClientReseaux/WinsocketLib.h"
#include "ClientReseaux/WinsocketSocket.h"
#include "Sauvegardes/SauvegardeTxtCORSegment.h"
#include "Sauvegardes/SauvegardeTxtCORCercle.h"
#include "Sauvegardes/SauvegardeTxtCORGroupe.h"
#include "Sauvegardes/SauvegardeTxtCORPolygone.h"
#include "Sauvegardes/SauvegardeTxtCORSegment.h"
#include "Sauvegardes/Sauvegarde.h"
#include "Sauvegardes/SauvegardeTxt.h"
#include "Sauvegardes/SauvegardeTxtCOR.h"
#include "CoordMonde/CoordMonde.h"
#include "VisiteursForme/VisiteurDessin.h"
#include "VisiteursForme/VisiteurDessinJavaAwt.h"

#include <vector>

using namespace std;

int main() {
	
	try {
		const WinsocketLib *l = WinsocketLib::DEMARRER();
		Vecteur2D dimensionsFenetre(500, 500); 

		SauvegardeTxtCOR *sauve = new SauvegardeTxtCORGroupe(nullptr);
		sauve = new SauvegardeTxtCORPolygone(sauve);
		sauve = new SauvegardeTxtCORCercle(sauve);
		sauve = new SauvegardeTxtCORSegment(sauve);

		sauve->setNomFichier("test.txt");
		vector<Forme*> maSauvegarde = sauve->lireEns();


		CoordMonde coord(maSauvegarde, dimensionsFenetre);

		cout << coord;


		coord.transformer(maSauvegarde);
		

		VisiteurDessinJavaAwt visiteur("127.0.0.1", 1, dimensionsFenetre);
		
		visiteur.dessine(maSauvegarde);
		visiteur.finDessin();
		
	}
	catch (QExceptionsGeometrie* e) {
		cout << "Exception de Geometrie : " << endl;
		cout << e->getCode() << " : " << e->getMessage() << endl;
	}
	catch (QExceptionsCoordMonde* e) {
		cout << "Exception de Cordonnee monde : " << endl;
		cout << e->getCode() << " : " << e->getMessage() << endl;
	}
	catch (QExceptionsReseaux* e) {
		cout << "Exception de Reseaux : " << endl;
		cout << e->getCode() << " : " << e->getMessage() << endl;
	}
	catch (QExceptionsSauvegarde* e) {
		cout << "Exception de Sauvegarde : " << endl;
		cout << e->getCode() << " : " << e->getMessage() << endl;
	}
	catch (QExceptionsVisiteur* e) {
		cout << "Exception de Visiteur : " << endl;
		cout << e->getCode() << " : " << e->getMessage() << endl;
	}

	

	return 0;
}
