package ServeurReseaux.Dessin;

import java.io.BufferedReader;

public class DessinTriangleCOR extends DessinCOR {
    DessinTriangleCOR(DessinCOR suivant) {
        super(suivant);
    }

    @Override
    public boolean aDessine(String forme, BufferedReader fluxEntrant) {
        if(forme.equals("triangle   ")) {
            /*
            traiter la forme
             */
            return true;
        }
        else
            return false;
    }
}
