package ServeurReseaux.Dessin;

import Interface.Vecteur2D;

import java.awt.*;
import java.awt.image.BufferStrategy;
import java.io.BufferedReader;
import java.util.Arrays;

public class DessinPolygoneCOR extends DessinCOR {
    public DessinPolygoneCOR(DessinCOR suivant) {
        super(suivant);
    }

    @Override
    public boolean aDessine(String forme, String datas, BufferStrategy bs) {
        if(forme.equals("polygone")) {
            Graphics g = bs.getDrawGraphics();

            String[] coupes = datas.split(";");

            Color couleur = Vecteur2D.getCouleur(coupes[0]);
            g.setColor(couleur);

            long n = Arrays.stream(coupes).count();
            n -= 1; // le dernier ne compte pas
            System.out.println(n);

            for (int i = 1; i < n-1; i++) {
                Vecteur2D origine = Vecteur2D.creerString(coupes[i]);
                Vecteur2D arrivee = Vecteur2D.creerString(coupes[i+1]);
                System.out.println(origine + " " + arrivee);
                g.drawLine((int)origine.x, (int)origine.y, (int)arrivee.x, (int)arrivee.y);
            }
            Vecteur2D origine = Vecteur2D.creerString(coupes[(int)n-1]);
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
