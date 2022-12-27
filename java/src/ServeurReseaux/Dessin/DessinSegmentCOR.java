package ServeurReseaux.Dessin;

import java.io.BufferedReader;

public class DessinSegmentCOR extends DessinCOR {
    DessinSegmentCOR(DessinCOR suivant) {
        super(suivant);
    }

    @Override
    public boolean aDessine(String forme, BufferedReader fluxEntrant) {
        if(forme.equals("segment")) {
            /*
            traiter la forme
             */
            return true;
        }
        else
            return false;
    }
}
