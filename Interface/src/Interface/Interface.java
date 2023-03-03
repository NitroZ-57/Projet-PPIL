package Interface;
import Exception.*;

import java.awt.*;

/**
 * Cette classe représente l'interface utilisateur, il s'agit d'un singleton
 */
public class Interface {

    private static Interface i = null;
    private static int width = -1;
    private static int height = -1;
    private Frame f = null;

    /**
     * Création de l'interface en privé
     */
    private Interface() {
        Frame f = new Frame("Projet PPIL");
        f.setBounds(30, 30, Interface.width, Interface.height);
        System.out.println(Interface.width + " " + Interface.height);
        f.setVisible(true);
        f.setIgnoreRepaint(true);
        int numBuffer = 2;
        f.createBufferStrategy(numBuffer);
        this.f = f;
    }

    /**
     * Vérification du lancement de l'interface
     * @return vrai si l'interface est lancée, faux sinon
     */
    public static boolean interfaceEstLancee() {
        return i != null;
    }

    /**
     * Retourne l'instance de l'interface du singleton
     * @return l'instance de l'interface
     * @throws DimensionFenetreIncomplet si les dimensions de la fenetre n'ont pas été donné dans setInterfaceDimensions au préalable
     */
    public static Interface getInstance() throws DimensionFenetreIncomplet {
        if(i==null) {
            if(width == -1 || height == -1)
                throw new DimensionFenetreIncomplet("Utilisez setInterfaceDimensions");
            i = new Interface();
        }
        return i;
    }

    /**
     * Fonction servant à définir les dimensions de l'unique fenetre (à appeler avant d'utiliser le singleton)
     * @param width la largeur de la fenetre
     * @param height la hauteur de la fenetre
     * @throws DimensionsFenetreIncorrectes si les dimensions de la fenetre ne sont pas correctes
     */
    public static void setInterfaceDimensions(int width, int height) throws DimensionsFenetreIncorrectes {
        if(height < 0 || width < 0)
            throw new DimensionsFenetreIncorrectes("Les dimensions doivent être positives");
        Interface.height = height;
        Interface.width = width;
    }

    /**
     * @return la Frame du singleton pour faire les dessins
     * @throws SingletonNonInitialise si le singleton n'est pas initialisé
     */
    public Frame getFrame() throws SingletonNonInitialise {
        if(i == null)
            throw new SingletonNonInitialise("Veuillez initialiser le singleton d'abord");
        return f;
    }


}
