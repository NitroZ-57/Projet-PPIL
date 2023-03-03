#include "SauvegardeTxt.h"
#include <fstream>
#include "../Exceptions/QExceptionsSauvegarde.h"

#define CHAR_MAX_FICHIER 256

SauvegardeTxt::SauvegardeTxt() {
	nomFichier = nullptr;
}

void SauvegardeTxt::setNomFichier(const char* nomFichier) {
	this->nomFichier = _strdup(nomFichier);
}

SauvegardeTxt::~SauvegardeTxt() {
	if (nomFichier != nullptr)
		delete nomFichier;
}

Forme*& SauvegardeTxt::lire() const
{
	throw new QExceptionsLectureSimpleImpossible("lecture dans fichier texte impossible pour une seule forme");
}

bool SauvegardeTxt::ecrire(const Forme*& forme) const {
	throw new QExceptionsEcritureSimpleImpossible("ecriture dans fichier texte impossible pour une seule forme");
}

vector<Forme*> SauvegardeTxt::lireEns() const {

	if (nomFichier == nullptr)
		throw new QExceptionsFichierNonDefini("Utiliser setNomFichier d'abord");

	if (strlen(nomFichier) > LONGEUR_MAX_NOM_FICHIER)
		throw new QExceptionsNomFichierTropLong("Nom de fichier superieur a 100 caracteres");

	ifstream fichier;
	string nomFichierstr = (string)nomFichier;
	string s = "data/" + nomFichierstr;
	fichier.open(s);

	char ligne[CHAR_MAX_FICHIER];

	vector<Forme*> formes;

	while (fichier) {
		fichier.getline(ligne, CHAR_MAX_FICHIER - 1);
		Forme* f = lire(ligne);
		if(f != nullptr)
			formes.push_back(f);
	}

	fichier.close();
	return formes;
}
bool SauvegardeTxt::ecrireEns(const vector<Forme*>& formes) const {

	if (nomFichier == nullptr)
		throw new QExceptionsFichierNonDefini("Utiliser setNomFichier d'abord");

	ofstream fichier;
	string nomFichierstr = (string)nomFichier;
	string s = "data/"+nomFichierstr;
	fichier.open(s);
	vector<Forme*>::const_iterator it;

	for (it = formes.begin(); it < formes.end(); it++) {
		const string strmsg = (string)(**it);
		const char *msg = strmsg.c_str();
		fichier.write(msg, strlen(msg));
		fichier.write("\n", 1);
	}

	fichier.close();
	return true;
}