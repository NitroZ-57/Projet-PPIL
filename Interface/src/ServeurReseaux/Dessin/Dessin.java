package ServeurReseaux.Dessin;
import java.awt.*;

import java.awt.image.BufferStrategy;
import java.io.BufferedReader;
import Exception.FormatNonReconnuException;

/**
 * @brief Interface à implémenter pour permettre de dessiner des formes
 */
public interface Dessin {
    /**
     * @brief dessine une forme sur une interface graphique
     * @param forme le nom de la forme
     * @param c la couleur de la forme
     * @param datas les informations sur les formes
     * @param bs le buffer où dessiner les formes
     * @throws FormatNonReconnuException si le format de la forme n'est pas reconnu
     */
    void dessine(String forme, String c, String datas, BufferStrategy bs) throws FormatNonReconnuException;
}
