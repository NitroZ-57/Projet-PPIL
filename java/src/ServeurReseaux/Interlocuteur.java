package ServeurReseaux;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.Socket;

public class Interlocuteur extends Thread {

    private int noClient;
    private BufferedReader fluxEntrant;

    Interlocuteur(Socket client, int noClient) throws IOException {
        this.fluxEntrant = new BufferedReader(new InputStreamReader(client.getInputStream()));
        this.noClient = noClient;
    }

    @Override
    public void run() {
        super.run();

        while(!this.isInterrupted()) {
            String typeForme = null;
            try {
                typeForme = this.fluxEntrant.readLine();
                // lancer COR
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }

}
