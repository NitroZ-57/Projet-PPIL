package Exception;

/**
 * @brief Classe dérivée d'une exception, cette exception est lancée quand le singleton n'est pas initialisé et ne peut pas être utilisé
 */
public class SingletonNonInitialise extends Exception {

    /**
     * @brief Création d'une SingletonNonInitialise
     * @param msg le message qui décrit l'erreur
     */
    public SingletonNonInitialise(String msg) {
        super(msg);
    }
}
