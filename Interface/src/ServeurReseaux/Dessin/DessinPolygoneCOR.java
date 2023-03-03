package ServeurReseaux.Dessin;

import Interface.Vecteur2D;

import java.awt.*;
import java.awt.image.BufferStrategy;
import java.io.BufferedReader;
import java.util.Arrays;

/**
 * @brief Maillon de la chaine de responsabilité permettant de reconnaitre et dessiner un polygone
 */
public class DessinPolygoneCOR extends DessinCOR {

    /**
     * Création d'un maillon de la chaine de responsabilité pour reconnaitre et traiter un polygone
     * @param suivant maillon suivant de la chaine de responsabilité
     */
    public DessinPolygoneCOR(DessinCOR suivant) {
        super(suivant);
    }

    /**
     * @brief Dessine un polygone si la forme est bien un polygone
     * @param forme le nom de la forme
     * @param c la couleur de la forme
     * @param datas les informations sur les formes
     * @param bs le buffer où dessiner les formes
     * @return vrai si le dessin a été fait et qu'il s'agissait donc d'un cercle, faux sinon
     */
    @Override
    public boolean aDessine(String forme, String c, String datas, BufferStrategy bs) {
        if(forme.equals("polygone")) {
            Graphics g = bs.getDrawGraphics();

            String[] coupes = datas.split(";");

            Color couleur = Vecteur2D.getCouleur(c);
            g.setColor(couleur);

            long n = Arrays.stream(coupes).count();
            n -= 1; // le dernier ne compte pas
            System.out.println(n);

            for (int i = 0; i < n-1; i++) {
                Vecteur2D origine = Vecteur2D.creerString(coupes[i].trim());
                Vecteur2D arrivee = Vecteur2D.creerString(coupes[i+1].trim());
                System.out.println(origine + " " + arrivee);
                g.drawLine((int)origine.x, (int)origine.y, (int)arrivee.x, (int)arrivee.y);
            }
            Vecteur2D origine = Vecteur2D.creerString(coupes[(int)n-1]);
            Vecteur2D arrivee = Vecteur2D.creerString(coupes[0]);
            g.drawLine((int)origine.x, (int)origine.y, (int)arrivee.x, (int)arrivee.y);



            bs.show();
            g.dispose();
            return true;
        }
        else
            return false;
    }
}
