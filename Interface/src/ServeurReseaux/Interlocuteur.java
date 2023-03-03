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
import java.util.ArrayList;

/**
 * @brief Classe servant à recevoir les informations venant d'un socket
 * Cette classe implémente un thread
 */
public class Interlocuteur extends Thread {

    private int noClient;
    private BufferedReader fluxEntrant;
    private BufferStrategy bs;

    /**
     * @brief Création d'un interlocuteur
     * @param client Le socket dans lequel le client va envoyer les données
     * @param noClient le numéro du client
     * @throws IOException si il y a une erreur lors de l'ecriture ou de la lecture dans le socket
     */
    Interlocuteur(Socket client, int noClient) throws IOException {
        if(client == null)
            throw new IllegalArgumentException("Client null\n");
        this.fluxEntrant = new BufferedReader(new InputStreamReader(client.getInputStream()));
        this.noClient = noClient;
    }

    /**
     * @brief Lancement du Thread, ici on attends un envoie d'un ensemble de forme du socket et une fois qu'on à l'ordre de s'arreter on arrete
     */
    @Override
    public void run() {
        super.run();


        try {
            // on récupère d'abord les dimensions de la fenetre si l'interface n'est pas encore lancée
            if(!Interface.interfaceEstLancee()) {
                String dimension = this.fluxEntrant.readLine();
                int pos = dimension.indexOf(",");
                int pos2 = dimension.indexOf(")");
                String dim1 = dimension.substring(1, pos).trim();
                String dim2 = dimension.substring(pos+1, pos2).trim();
                int width = Integer.parseInt(dim1);
                int height = Integer.parseInt(dim2);

                // on créer l'interface
                Interface.setInterfaceDimensions(width, height);


            }
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
                    if(ligne.equals("end")) {
                        System.out.println("fin");
                        this.interrupt();
                    }
                    else {
                        ArrayList<String> a = getFormeDecomposee(ligne);
                        if(a != null)
                            d.dessine(a.get(0), a.get(1), a.get(2), this.bs);
                    }

                }
            }

        } catch (IOException | DimensionsFenetreIncorrectes | DimensionFenetreIncomplet | SingletonNonInitialise e) {
            e.printStackTrace();
        } catch (FormatNonReconnuException e) {
            // rien
        }
    }


    /**
     * @brief Cette fonction sert à décomposer une forme en 3 parties :
     * [0] Le type de la forme
     * [1] Sa couleur
     * [2] Ses données
     * @param forme la forme en chaine de caractère à décomposer
     * @return un ensemble de chaine de caractère contenant les différentes données
     */
    public static ArrayList<String> getFormeDecomposee(String forme) {
        int pos = forme.indexOf("[");
        if(pos == -1)
            return null;
        String f = forme.substring(0, pos).trim(); // on récupère le type de forme
        String data = forme.substring(pos + 1, forme.length() - 3).trim(); // pour enlever les crochets
        int pos2 = data.indexOf(";");
        if(pos2 == -1)
            return null;
        String couleur = data.substring(0, pos2);
        data = data.substring(pos2+2, data.length());

        ArrayList<String> a = new ArrayList<String>();
        a.add(f);
        a.add(couleur);
        a.add(data);
        return a;
    }

}
