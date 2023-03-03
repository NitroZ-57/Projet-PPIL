package Exception;

/**
 * @brief Classe dérivée d'une exception, cette exception est lancée quand le format d'une forme n'est pas reconnu
 */
public class FormatNonReconnuException extends Exception {

    /**
     * @brief Création d'une FormatNonReconnuException
     * @param msg le message qui décrit l'erreur
     */
    public FormatNonReconnuException(String msg) {
        super(msg);
    }
}
