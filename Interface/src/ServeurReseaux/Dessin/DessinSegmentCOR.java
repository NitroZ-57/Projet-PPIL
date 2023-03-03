package ServeurReseaux.Dessin;

import Interface.Vecteur2D;

import java.awt.*;
import java.awt.image.BufferStrategy;
import java.io.BufferedReader;
import java.io.IOException;

/**
 * @brief Maillon de la chaine de responsabilité permettant de reconnaitre et dessiner un segment
 */
public class DessinSegmentCOR extends DessinCOR {

    /**
     * Création d'un maillon de la chaine de responsabilité pour reconnaitre et traiter un segment
     * @param suivant maillon suivant de la chaine de responsabilité
     */
    public DessinSegmentCOR(DessinCOR suivant) {
        super(suivant);
    }

    /**
     * @brief Dessine un segment si la forme est bien un segment
     * @param forme le nom de la forme
     * @param c la couleur de la forme
     * @param datas les informations sur les formes
     * @param bs le buffer où dessiner les formes
     * @return vrai si le dessin a été fait et qu'il s'agissait donc d'un cercle, faux sinon
     */
    @Override
    public boolean aDessine(String forme, String c, String datas, BufferStrategy bs) {
        if(forme.equals("segment")) {
            Graphics g = bs.getDrawGraphics();

            String[] coupes = datas.split(";");

            Color couleur = Vecteur2D.getCouleur(c);
            g.setColor(couleur);

            Vecteur2D origine = Vecteur2D.creerString(coupes[0]);
            Vecteur2D arrivee = Vecteur2D.creerString(coupes[1]);

            g.drawLine((int)origine.x, (int)origine.y, (int)arrivee.x, (int)arrivee.y);

            bs.show();
            g.dispose();
            return true;
        }
        else
            return false;

    }
}
