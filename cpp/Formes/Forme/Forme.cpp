#include "Forme.h"
#include "../../VisiteursForme/VisiteurForme/VisiteurForme.h"

const string Forme::BLACK = "black";
const string Forme::BLUE = "blue";
const string Forme::RED = "red";
const string Forme::GREEN = "green";
const string Forme::YELLOW = "yellow";
const string Forme::CYAN = "cyan";

Forme::Forme(const string& couleur, const Vecteur2D& origine)
{
	setCouleur(couleur);
	setOrigine(origine);
}

void Forme::setCouleur(const string& couleur)
{
	if (couleur != BLACK && couleur != BLUE && couleur != RED && couleur != YELLOW && couleur != GREEN && couleur != CYAN)
		return; // exception
	this->couleur = couleur;
}

void Forme::setOrigine(const Vecteur2D& origine)
{
	this->origine = origine;
}

void Forme::estAjouteGroupe()
{
	if (appartientGroupe)
		return; // exception
	appartientGroupe = true;
}

void Forme::estRetireGroupe()
{
	appartientGroupe = false;
}

string Forme::getCouleur() const
{
	return couleur;
}

Vecteur2D Forme::getOrigine() const
{
	return origine;
}

bool Forme::estDansUnGroupe() const
{
	return estDansUnGroupe;
}

Forme::operator string() const
{
	return "Forme";
}

const Forme Forme::accepte(const VisiteurForme* visiteurForme)
{
	return visiteurForme->visite(this);
}

