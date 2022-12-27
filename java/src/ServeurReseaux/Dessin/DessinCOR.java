package ServeurReseaux.Dessin;

import java.io.BufferedReader;
import Exception.FormatNonReconnuException;

public abstract class DessinCOR implements Dessin {

    private DessinCOR suivant;


    DessinCOR(DessinCOR suivant) {
        this.suivant = suivant;
    }

    @Override
    public void dessine(String forme, BufferedReader fluxEntrant) throws FormatNonReconnuException {
        if(!this.aDessine(forme, fluxEntrant)) {
            if(suivant != null) {
                suivant.dessine(forme, fluxEntrant);
            }
            else
                throw new FormatNonReconnuException("La forme n'a pas ete reconnu");
        }
        // Ici le dessin a été fait
    }


    public abstract boolean aDessine(String forme, BufferedReader fluxEntrant);
}
