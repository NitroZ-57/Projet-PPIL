package ServeurReseaux.Dessin;

import java.io.BufferedReader;

public class DessinGroupeCOR extends DessinCOR {
    DessinGroupeCOR(DessinCOR suivant) {
        super(suivant);
    }

    @Override
    public boolean aDessine(String forme, BufferedReader fluxEntrant) {
        if(forme.equals("groupe")) {
            /*
            traiter la forme
             */
            return true;
        }
        else
            return false;
    }
}
