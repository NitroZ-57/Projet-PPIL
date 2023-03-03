package Exception;

/**
 * @brief Classe dérivée d'une exception, cette exception est lancée quand les dimensions de la fenetre n'ont pas de valeurs correctes
 */
public class DimensionsFenetreIncorrectes extends Exception {

    /**
     * @brief Création d'une DimensionsFenetreIncorrectes
     * @param msg le message qui décrit l'erreur
     */
    public DimensionsFenetreIncorrectes(String msg) {
        super(msg);
    }
}
