package ServeurReseaux.Dessin;

import Interface.Vecteur2D;

import java.awt.*;
import java.awt.image.BufferStrategy;
import java.io.BufferedReader;
import java.io.IOException;

public class DessinSegmentCOR extends DessinCOR {
    public DessinSegmentCOR(DessinCOR suivant) {
        super(suivant);
    }

    @Override
    public boolean aDessine(String forme, String datas, BufferStrategy bs) {
        if(forme.equals("segment")) {
            Graphics g = bs.getDrawGraphics();

            String[] coupes = datas.split(";");

            Color couleur = Vecteur2D.getCouleur(coupes[0]);
            g.setColor(couleur);

            Vecteur2D origine = Vecteur2D.creerString(coupes[1]);
            Vecteur2D arrivee = Vecteur2D.creerString(coupes[2]);

            g.drawLine((int)origine.x, (int)origine.y, (int)arrivee.x, (int)arrivee.y);

            bs.show();
            g.dispose();
            return true;
        }
        else
            return false;

    }
}
