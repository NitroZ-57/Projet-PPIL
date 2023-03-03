package Exception;

/**
 * @brief Classe dérivée d'une exception, cette exception est lancée quand les dimensions de la fenetre ne sont pas donnée pour créer le singleton
 */
public class DimensionFenetreIncomplet extends Exception{

    /**
     * @brief Création d'une DimensionFenetreIncomplet
     * @param msg le message qui décrit l'erreur
     */
    public DimensionFenetreIncomplet(String msg) {
        super(msg);
    }
}
