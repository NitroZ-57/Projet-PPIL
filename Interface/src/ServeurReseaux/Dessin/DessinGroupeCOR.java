package ServeurReseaux.Dessin;

import Interface.Vecteur2D;

import java.awt.*;
import java.awt.image.BufferStrategy;
import java.io.BufferedReader;
import java.util.Arrays;
import Exception.FormatNonReconnuException;

public class DessinGroupeCOR extends DessinCOR {
    public DessinGroupeCOR(DessinCOR suivant) {
        super(suivant);
    }

    @Override
    public boolean aDessine(String forme, String datas, BufferStrategy bs) throws FormatNonReconnuException {
        if(forme.equals("groupe")) {
            Graphics g = bs.getDrawGraphics();

            String[] coupes = datas.split(";");

            Color couleur = Vecteur2D.getCouleur(coupes[0]);
            g.setColor(couleur);
            System.out.println(coupes[0]);
            System.out.println(coupes[1]);
            coupes = coupes[1].split("#");


            long n = Arrays.stream(coupes).count();
            n -= 1; // le dernier ne compte pas
            System.out.println(n);

            // on créer la chaine de responsabilité
            DessinCOR d = new DessinGroupeCOR(null);
            d = new DessinPolygoneCOR(d);
            d = new DessinCercleCOR(d);
            d = new DessinSegmentCOR(d);

            for (int i = 1; i < n; i++) {
                int pos = coupes[i].indexOf("[");
                String forme2 = coupes[i].substring(0, pos).trim();
                String datas2 = coupes[i].substring(pos+1, coupes[i].length()-3).trim(); // pour enlever les crochets

                System.out.println(forme2 + "..." + datas2);

                d.dessine(forme2, datas2, bs);
            }
            bs.show();
            g.dispose();
            return true;
        }
        else
            return false;
    }

}
