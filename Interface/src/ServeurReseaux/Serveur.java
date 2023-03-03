package ServeurReseaux;
import java.awt.*;

import java.awt.image.BufferStrategy;
import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

import Exception.PortInvalideException;

/**
 * @brief cette classe représente le serveur qui va réceptionner toutes les données
 */
public class Serveur {

    private int noClient;
    private ServerSocket serveur;


    /**
     * @brief Création du serveur
     * @param port le port sur lequel arriveront les données
     * @throws IOException Exceptions de lectures ou écritures dans les thread
     * @throws PortInvalideException Exception si le port n'a pas de valeur positive
     */
    public Serveur(int port) throws IOException, PortInvalideException {
        if(port < 0)
            throw new PortInvalideException("Le port doit être positif\n");
        noClient = 1;
        serveur = new ServerSocket(port);
        System.out.println("Serveur lancé\n");
    }

    /**
     * @brief Fonction qui lance le serveur et le met en attente de données
     * Lorsqu'un client se connecte, un interlocuteur le prends en charge
     * @throws IOException
     */
    public void attente() throws IOException {
        while(true) {
            Socket client = serveur.accept();
            Interlocuteur interlocuteur = new Interlocuteur(client, noClient++);
            interlocuteur.start();
        }
    }


}
