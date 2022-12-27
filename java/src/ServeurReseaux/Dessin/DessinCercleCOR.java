package ServeurReseaux.Dessin;

import java.io.BufferedReader;

public class DessinCercleCOR extends DessinCOR {
    DessinCercleCOR(DessinCOR suivant) {
        super(suivant);
    }

    @Override
    public boolean aDessine(String forme, BufferedReader fluxEntrant) {
        if(forme.equals("cercle")) {
            /*
            traiter la forme
             */
            return true;
        }
        else
            return false;
    }
}
