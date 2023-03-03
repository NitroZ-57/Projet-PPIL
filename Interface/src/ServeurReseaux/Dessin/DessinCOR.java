package ServeurReseaux.Dessin;

import java.awt.*;
import java.awt.image.BufferStrategy;
import java.io.BufferedReader;
import Exception.FormatNonReconnuException;

/**
 * Classe abstraite permettant de lancer une chaine de responsabilité pour dessiner des formes
 */
public abstract class DessinCOR implements Dessin {

    private DessinCOR suivant;

    /**
     * Création d'un maillon de la chaine de responsabilité
     * @param suivant maillon suivant de la chaine de responsabilité
     */
    DessinCOR(DessinCOR suivant) {
        this.suivant = suivant;
    }

    /**
     * @brief dessine une forme sur l'interface
     * @param forme le nom de la forme
     * @param c la couleur de la forme
     * @param datas les informations sur les formes
     * @param bs le buffer où dessiner les formes
     * @throws FormatNonReconnuException si le format de la forme n'est pas reconnu
     */
    @Override
    public void dessine(String forme, String c, String datas, BufferStrategy bs) throws FormatNonReconnuException {
        if(!this.aDessine(forme, c, datas, bs)) {
            if(suivant != null) {
                suivant.dessine(forme, c, datas, bs);
            }
            else
                throw new FormatNonReconnuException("La forme n'a pas ete reconnu");
        }
        // Ici le dessin a été fait
    }


    public abstract boolean aDessine(String forme, String c, String datas, BufferStrategy bs) throws FormatNonReconnuException;
}
