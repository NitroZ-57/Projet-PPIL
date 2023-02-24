package Interface;

import java.awt.*;

import static java.lang.Math.*;

public class Vecteur2D {

    public double x;
    public double y;

    public Vecteur2D(double x, double y) {
        this.x = x;
        this.y = y;
    }

    public static Vecteur2D creerPolaire(double angle) {
        return new Vecteur2D(cos(angle), sin(angle));
    }

    public static Color getCouleur(String couleur) {
        if(couleur.equals("noir"))
            return Color.BLACK;
        if(couleur.equals("bleu"))
            return Color.BLUE;
        if(couleur.equals("rouge"))
            return Color.RED;
        if(couleur.equals("vert"))
            return Color.GREEN;
        if(couleur.equals("jaune"))
            return Color.YELLOW;
        else
            return Color.CYAN;
    }

    public static Vecteur2D creerString(String v) {
        v = v.trim();
        int pos = v.indexOf(",");
        String x = v.substring(1, pos).trim();
        String y = v.substring(pos+1, v.length()-1).trim(); // pour enlever les parenthèses

        return new Vecteur2D(Double.parseDouble(x), Double.parseDouble(y));
    }

    public Vecteur2D plus(Vecteur2D v) {
        return new Vecteur2D(v.x + x, v.y + y);
    }

    public Vecteur2D fois(double a) {
        return new Vecteur2D(x*a, y*a);
    }

    public Vecteur2D oppose() {
        return new Vecteur2D(-x, -y);
    }

    public Vecteur2D moins(Vecteur2D v) {
        return this.plus(v.oppose());
    }

    @Override
    public String toString() {
        return "Vecteur2D{" +
                "x=" + x +
                ", y=" + y +
                '}';
    }


}
