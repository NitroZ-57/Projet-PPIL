package ServeurReseaux.Dessin;

import java.io.BufferedReader;
import Exception.FormatNonReconnuException;

public interface Dessin {
    void dessine(String forme, BufferedReader fluxEntrant) throws FormatNonReconnuException;
}
