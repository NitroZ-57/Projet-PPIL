package ServeurReseaux.Dessin;

import Interface.Vecteur2D;

import java.awt.*;
import java.awt.image.BufferStrategy;
import java.io.BufferedReader;

public class DessinCercleCOR extends DessinCOR {
    public DessinCercleCOR(DessinCOR suivant) {
        super(suivant);
    }

    @Override
    public boolean aDessine(String forme, String datas, BufferStrategy bs) {
        if(forme.equals("cercle")) {
            Graphics g = bs.getDrawGraphics();
            System.out.println(datas);

            String[] coupes = datas.split(";");

            Color couleur = Vecteur2D.getCouleur(coupes[0]);
            g.setColor(couleur);

            Vecteur2D origine = Vecteur2D.creerString(coupes[1]);
            int rayon = (int)Double.parseDouble(coupes[2]);

            g.drawOval((int)origine.x+rayon, (int)origine.y+rayon, rayon, rayon);

            bs.show();
            g.dispose();
            return true;
        }
        else
            return false;
    }

}
