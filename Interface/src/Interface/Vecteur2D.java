package Interface;

import java.awt.*;

import static java.lang.Math.*;

/**
 * @brief Cette classe sert principalement à utiliser des petites fonctionnalités pour traiter des Vecteur2D coté Java
 */
public class Vecteur2D {

    public double x;
    public double y;

    /**
     * Création d'un Vecteur2D
     * @param x l'abscisse du vecteur
     * @param y l'ordonnée du vecteur
     */
    public Vecteur2D(double x, double y) {
        this.x = x;
        this.y = y;
    }

    /**
     * Fonction statique qui retourne le code de la couleur associé à sa chaine de caractère
     * @param couleur la chaine de caractère de la couleur
     * @return le code associé à la chaine de caractère
     */
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


    @Override
    public String toString() {
        return "Vecteur2D{" +
                "x=" + x +
                ", y=" + y +
                '}';
    }


}
