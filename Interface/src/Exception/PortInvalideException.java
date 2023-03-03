package Exception;

/**
 * @brief Classe dérivée d'une exception, cette exception est lancée quand le port de connexion au serveur est invalide
 */
public class PortInvalideException extends Exception {

    /**
     * @brief Création d'une PortInvalideException
     * @param msg le message qui décrit l'erreur
     */
    public PortInvalideException(String msg) {
        super(msg);
    }
}

