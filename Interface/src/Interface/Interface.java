package Interface;
import Exception.*;

import java.awt.*;

// DP : Singleton
public class Interface {

    private static Interface i = null;
    private static int width = -1;
    private static int height = -1;
    private Frame f = null;

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

    public static Interface getInstance() throws DimensionFenetreIncomplet {
        if(i==null) {
            if(width == -1 || height == -1)
                throw new DimensionFenetreIncomplet("Utilisez setInterfaceDimensions");
            i = new Interface();
        }
        return i;
    }

    public static void setInterfaceDimensions(int width, int height) throws DimensionsFenetreIncorrectes {
        if(height < 0 || width < 0)
            throw new DimensionsFenetreIncorrectes("Les dimensions doivent être positives");
        Interface.height = height;
        Interface.width = width;
    }

    public Frame getFrame() throws SingletonNonInitialise {
        if(i == null)
            throw new SingletonNonInitialise("Veuillez initialiser le singleton d'abord");
        return f;
    }


}
