package ServeurReseaux;

import Interface.Interface;
import ServeurReseaux.Dessin.*;
import Exception.*;

import java.awt.*;
import java.awt.image.BufferStrategy;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.Socket;

public class Interlocuteur extends Thread {

    private int noClient;
    private BufferedReader fluxEntrant;
    private BufferStrategy bs;

    Interlocuteur(Socket client, int noClient) throws IOException {
        if(client == null)
            throw new IllegalArgumentException("Client null\n");
        this.fluxEntrant = new BufferedReader(new InputStreamReader(client.getInputStream()));
        this.noClient = noClient;
    }

    @Override
    public void run() {
        super.run();

        // on récupère d'abord les dimensions de la fenetre
        try {
            String dimension = this.fluxEntrant.readLine();
            int pos = dimension.indexOf(",");
            int pos2 = dimension.indexOf(")");
            String dim1 = dimension.substring(1, pos).trim();
            String dim2 = dimension.substring(pos+1, pos2).trim();
            int width = Integer.parseInt(dim1);
            int height = Integer.parseInt(dim2);

            // on créer l'interface
            Interface.setInterfaceDimensions(width, height);
            Interface i = Interface.getInstance();
            Frame f = i.getFrame();
            bs = f.getBufferStrategy();

            // on peut commencer à traiter les données

            DessinCOR d = new DessinGroupeCOR(null);
            d = new DessinPolygoneCOR(d);
            d = new DessinCercleCOR(d);
            d = new DessinSegmentCOR(d);

            while(!this.isInterrupted()) {
                String ligne = null;
                ligne = this.fluxEntrant.readLine();
                if (ligne != null) {
                    pos = ligne.indexOf("[");
                    String forme = ligne.substring(0, pos).trim();
                    String data = ligne.substring(pos + 1, ligne.length() - 3).trim(); // pour enlever les crochets
                    d.dessine(forme, data, this.bs);
                }
            }

        } catch (IOException | DimensionsFenetreIncorrectes | DimensionFenetreIncomplet | SingletonNonInitialise e) {
            e.printStackTrace();
        } catch (FormatNonReconnuException e) {
            // rien
        }

    }

}
