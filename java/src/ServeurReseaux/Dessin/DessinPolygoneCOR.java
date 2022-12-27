package ServeurReseaux.Dessin;

import java.io.BufferedReader;

public class DessinPolygoneCOR extends DessinCOR {
    DessinPolygoneCOR(DessinCOR suivant) {
        super(suivant);
    }

    @Override
    public boolean aDessine(String forme, BufferedReader fluxEntrant) {
        if(forme.equals("polygone")) {
            /*
            traiter la forme
             */
            return true;
        }
        else
            return false;
    }
}
