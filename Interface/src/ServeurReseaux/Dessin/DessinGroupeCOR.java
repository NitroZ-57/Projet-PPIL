package ServeurReseaux.Dessin;

import Interface.Vecteur2D;

import java.awt.*;
import java.awt.image.BufferStrategy;
import java.io.BufferedReader;
import java.util.ArrayList;
import java.util.Arrays;
import Exception.FormatNonReconnuException;
import ServeurReseaux.Interlocuteur;

/**
 * @brief Maillon de la chaine de responsabilité permettant de reconnaitre et dessiner un groupe de formes
 */
public class DessinGroupeCOR extends DessinCOR {

    /**
     * Création d'un maillon de la chaine de responsabilité pour reconnaitre et traiter un groupe de formes
     * @param suivant maillon suivant de la chaine de responsabilité
     */
    public DessinGroupeCOR(DessinCOR suivant) {
        super(suivant);
    }

    /**
     * @brief Dessine un groupe si la forme est bien un groupe
     * @param forme le nom de la forme
     * @param c la couleur de la forme
     * @param datas les informations sur les formes
     * @param bs le buffer où dessiner les formes
     * @return vrai si le dessin a été fait et qu'il s'agissait donc d'un cercle, faux sinon
     */
    @Override
    public boolean aDessine(String forme, String c, String datas, BufferStrategy bs) throws FormatNonReconnuException {
        if(forme.equals("groupe")) {
            Graphics g = bs.getDrawGraphics();

            g.setColor(Vecteur2D.getCouleur(c));
            ArrayList<String> a = parseurGroupe(datas);

            // on créer la chaine de responsabilité
            DessinCOR d = new DessinGroupeCOR(null);
            d = new DessinPolygoneCOR(d);
            d = new DessinCercleCOR(d);
            d = new DessinSegmentCOR(d);

            for(int i = 0; i < a.size(); i++) {
                ArrayList<String> a2 = Interlocuteur.getFormeDecomposee(a.get(i));
                d.dessine(a2.get(0), c, a2.get(2), bs);
            }

            bs.show();
            g.dispose();
            return true;
        }
        else
            return false;
    }

    /**
     * @brief Cette méthode décompose une chaine de caractère comportant les données d'un groupe en une arraylist de formes du groupe
     * @param msg : chaine de caractère représentant les formes qui sont après la couleur du groupe sous la forme du protocole
     * @return  un ensemble de forme dans des chaines de caractères différentes
     */
    private ArrayList<String> parseurGroupe(String msg) {
        msg += '\\';
        char[] deb = msg.trim().toCharArray();
        ArrayList<String> a = new ArrayList<String>();
        int i = 0;
        int ouvert = 0;
        int debutChaine = 0;
        int index;
        String temp;

        while(i < deb.length) {

            if(deb[i] == '[') {
                ouvert++;
            }
            else if(deb[i] == ']') {
                if(ouvert == 1) {

                    deb[i+2] = '\\';
                    temp = new String(String.valueOf(deb));
                    index = temp.indexOf('\\');
                    temp = temp.substring(debutChaine, index);
                    a.add(temp);
                    deb[i+2] = ' ';
                    debutChaine = i+3;
                    i += 3;
                }
                ouvert--;
            }
            i++;
        }
        return a;
    }

}
