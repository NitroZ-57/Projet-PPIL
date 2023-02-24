#include "Forme.h"
#include "../VisiteursForme/VisiteurDessin.h"
#include "../Exceptions/QExceptionsGeometrie.h"

vector<string> Forme::str_coul = {"noir", "bleu", "rouge", "vert", "jaune", "cyan"};

using namespace std;

// en minuscule
int Forme::getIntCouleur(const char* c) {
	std::vector<string>::iterator itr = find(Forme::str_coul.begin(), Forme::str_coul.end(), c);

	if (itr != Forme::str_coul.cend()) {
		return distance(Forme::str_coul.begin(), itr);
	}

	return -1;
}


Forme::Forme(const int& couleur, const Vecteur2D& origine)
{
	setCouleur(couleur);
	setOrigine(origine);
	appartientGroupe = false;
}

void Forme::setCouleur(const int& couleur)
{
	if (couleur < 0 || couleur > couleurMax)
		throw new QExceptionsCouleurInexistance("Couleur inexistance");
	this->couleur = couleur;
}

void Forme::setOrigine(const Vecteur2D& origine)
{
	this->origine = origine;
}

void Forme::estAjouteGroupe()
{
	if (appartientGroupe)
		throw new QExceptionsEstDejaDansUnGroupe("La forme est déjà dans un groupe");
	appartientGroupe = true;
}

void Forme::estRetireGroupe()
{
	appartientGroupe = false;
}

string Forme::getCouleur() const
{
	return str_coul[couleur];
}

int Forme::getIntCouleur() const {
	return couleur;
}

Vecteur2D Forme::getOrigine() const
{
	return origine;
}

bool Forme::estDansUnGroupe() const
{
	return false;
}

bool Forme::accepte(const VisiteurDessin* visiteurDessin)
{
	return visiteurDessin->dessine(this);
}

