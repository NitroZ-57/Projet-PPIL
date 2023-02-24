#include "VisiteurDessinJavaAwt.h"
#include "../ClientReseaux/WinsocketLib.h"
#include "../ClientReseaux/WinsocketSocket.h"
#include <cstring>

bool VisiteurDessinJavaAwt::dessine(const Forme* forme) const {
	string s = (string)(*forme);
	const char* msg = (s.c_str());
	sock->write(msg, strlen(msg));
	return true;
}

bool VisiteurDessinJavaAwt::dessine(const Segment* segment) const {
	return dessine((Forme*)(segment));
}
bool VisiteurDessinJavaAwt::dessine(const Cercle* cercle) const {
	return dessine((Forme*)(cercle));
}
bool VisiteurDessinJavaAwt::dessine(const Polygone* polygone) const {
	return dessine((Forme*)(polygone));
}
bool VisiteurDessinJavaAwt::dessine(const Groupe* groupe) const {
	return dessine((Forme*)(groupe));
}