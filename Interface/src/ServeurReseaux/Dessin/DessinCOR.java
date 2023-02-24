package ServeurReseaux.Dessin;

import java.awt.*;
import java.awt.image.BufferStrategy;
import java.io.BufferedReader;
import Exception.FormatNonReconnuException;

public abstract class DessinCOR implements Dessin {

    private DessinCOR suivant;


    DessinCOR(DessinCOR suivant) {
        this.suivant = suivant;
    }

    @Override
    public void dessine(String forme, String datas, BufferStrategy bs) throws FormatNonReconnuException {
        if(!this.aDessine(forme, datas, bs)) {
            if(suivant != null) {
                suivant.dessine(forme, datas, bs);
            }
            else
                throw new FormatNonReconnuException("La forme n'a pas ete reconnu");
        }
        // Ici le dessin a été fait
    }


    public abstract boolean aDessine(String forme, String datas, BufferStrategy bs) throws FormatNonReconnuException;
}
