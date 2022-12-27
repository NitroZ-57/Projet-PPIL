package ServeurReseaux;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

import Exception.PortInvalideException;

public class Serveur {

    private int noClient;
    private ServerSocket serveur;

    public Serveur(int port) throws IOException, PortInvalideException {
        if(port < 0)
            throw new PortInvalideException("Le port doit être positif\n");
        noClient = 1;
        serveur = new ServerSocket(port);
        System.out.println("Serveur lancé\n");
    }

    public void attente() throws IOException {
        Socket client = serveur.accept();
        Interlocuteur interlocuteur = new Interlocuteur(client, noClient++);
        interlocuteur.start();
    }


}
