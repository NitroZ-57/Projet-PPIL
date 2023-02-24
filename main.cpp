#include <iostream>
#include "Formes/Cercle.h"
#include "Formes/Forme.h"
#include "Formes/Groupe.h"
#include "Formes/Polygone.h"
#include "Formes/Segment.h"
#include "Formes/Vecteur2D.h"
#include "Exceptions/QExceptionsGeometrie.h"
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

		Cercle cercle(Forme::BLACK, Vecteur2D(100, 100), Vecteur2D(282, 0));
		cout << "Cercle 1 : \n\t" << cercle << endl;
		cout << "aire : \n\t" << cercle.getAire() << endl;

		Segment segment(Forme::BLUE, Vecteur2D(3, 3), Vecteur2D(120, 140));
		cout << "Segment 1 :\n\t" << segment << endl;
		cout << "aire : \n\t" << segment.getAire() << endl;

		Segment segment2(Forme::GREEN, Vecteur2D(3, 3), Vecteur2D(120, 140));
		cout << "Segment 2 :\n\t" << segment2 << endl;
		cout << "aire : \n\t" << segment2.getAire() << endl;
		Groupe g2(Forme::BLACK);
		g2.ajouter(&segment2);

		vector<Vecteur2D> v;
		v.push_back(Vecteur2D(120, 120));
		v.push_back(Vecteur2D(400, 100));
		v.push_back(Vecteur2D(500, 200));
		v.push_back(Vecteur2D(450, 400));
		v.push_back(Vecteur2D(50, 300));
		Polygone p(Forme::RED, v);
		cout << "Polygone 1 :\n\t" << p << endl;
		cout << "aire : \n\t" << p.getAire() << endl;;

		Groupe g(Forme::YELLOW);
		g.ajouter(&cercle);
		g.ajouter(&segment);
		g.ajouter(&p);
		g.ajouter(&g2);
		cout << "Groupe 1 :\n\t" << g << endl;
		cout << "aire : \n\t" << g.getAire() << endl;
		string s = (string)g;
		const char* s2 = s.c_str();
		s2 += 14;
		vector<char*>t = g.parseurGroupe(s2);

		SauvegardeTxtCOR *sauve = new SauvegardeTxtCORGroupe(nullptr);
		sauve = new SauvegardeTxtCORPolygone(sauve);
		sauve = new SauvegardeTxtCORCercle(sauve);
		sauve = new SauvegardeTxtCORSegment(sauve);

		sauve->setNomFichier("test2.txt");
		vector<Forme*> maSauvegarde;
		/*maSauvegarde.push_back(&segment);
		maSauvegarde.push_back(&g);
		maSauvegarde.push_back(&cercle);
		sauve->ecrireEns(maSauvegarde);
		*/
		maSauvegarde = sauve->lireEns();
		for (int i = 0; i < maSauvegarde.size(); i++) {
			cout << "forme " << i << ": " << * maSauvegarde[i] << endl;
		}


		/*
		vector<Forme*> v2;
		v2.push_back((Forme*) &segment);
		cout << cercle.getRectangleHD() << endl;
		cout << cercle.getRectangleBG() << endl;
		CoordMonde coord(v2, dimensionsFenetre);
		Cercle* cercleTransforme = (Cercle*)cercle.getTransformation(coord);
		Segment* segmentTransforme = (Segment*)segment.getTransformation(coord);
		Polygone* polygoneTransforme = (Polygone*)p.getTransformation(coord);
		Vecteur2D nouvelleOrigine = coord.transformer(cercle.getOrigine());

		cout << endl;
		cout << "P1 :" << coord.P1 << endl << "P2 : " << coord.P2 << endl;
		cout << "P1prime :" << coord.P1prime << endl << "P2prime : " << coord.P2prime << endl;
		cout << "lambda :" << coord.lambda << endl << "ab :" << coord.ab << endl;

		cout << "Fenetre :" << dimensionsFenetre << endl;
		cout << "nouvelle origine :" << nouvelleOrigine << endl;
		cout << "Nouveau cercle" << *cercleTransforme << endl;
		VisiteurDessinJavaAwt visiteur("127.0.0.1", 1, dimensionsFenetre);
		visiteur.dessine(segmentTransforme);
		*/
		/*
		SauvegardeTxtCORGroupe *sauve = new SauvegardeTxtCORGroupe(nullptr);

		char chaine[] = "groupe[noir; cercle[jaune; (12, 88); 12]; segment[rouge; (-3, -3); (5, 10); ]; ];";
		Forme* s = sauve->sousLire(chaine);
		cout << *s << endl; */
		/*
		CoordMonde c;
		c.P1 = Vecteur2D(-1.5, -1.5);
		c.P2 = Vecteur2D(4.5, 4.5);
		c.P1prime = Vecteur2D(0, 500);
		c.P2prime = Vecteur2D(800, 0);

		double e1 = c.calculerE1();
		double e2 = c.calculerE2();
		cout << "e1 :" << e1 << endl;
		cout << "e2 :" << e2 << endl;

		c.calculerLambda(e1, e2);
		cout << "l :" << c.lambda << endl;

		c.calculerAB();
		cout << "a :" << c.ab.x << endl;
		cout << "b :" << c.ab.y << endl;
		*/

	}
	catch (QExceptionsGeometrie* e) {
		cout << e->getCode() << " : " << e->getMessage() << endl;
	}
	

	return 0;
}
