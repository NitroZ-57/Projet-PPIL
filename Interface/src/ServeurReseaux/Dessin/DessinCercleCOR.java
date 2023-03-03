package ServeurReseaux.Dessin;

import Interface.Vecteur2D;

import java.awt.*;
import java.awt.image.BufferStrategy;
import java.io.BufferedReader;

/**
 * @brief Maillon de la chaine de responsabilité permettant de reconnaitre et dessiner un cercle
 */
public class DessinCercleCOR extends DessinCOR {

    /**
     * Création d'un maillon de la chaine de responsabilité pour reconnaitre et traiter un cercle
     * @param suivant maillon suivant de la chaine de responsabilité
     */
    public DessinCercleCOR(DessinCOR suivant) {
        super(suivant);
    }

    /**
     * @brief Dessine un cercle si la forme est bien un cercle
     * @param forme le nom de la forme
     * @param c la couleur de la forme
     * @param datas les informations sur les formes
     * @param bs le buffer où dessiner les formes
     * @return vrai si le dessin a été fait et qu'il s'agissait donc d'un cercle, faux sinon
     */
    @Override
    public boolean aDessine(String forme, String c, String datas, BufferStrategy bs) {
        if(forme.equals("cercle")) {
            Graphics g = bs.getDrawGraphics();
            System.out.println(datas);

            String[] coupes = datas.split(";");

            Color couleur = Vecteur2D.getCouleur(c);
            g.setColor(couleur);

            Vecteur2D origine = Vecteur2D.creerString(coupes[0].trim());
            int rayon = (int)Double.parseDouble(coupes[1].trim());

            g.drawOval((int)origine.x-(rayon/2), (int)origine.y-(rayon/2), rayon, rayon);

            bs.show();
            g.dispose();
            return true;
        }
        else
            return false;
    }

}
