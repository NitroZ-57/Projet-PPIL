import ServeurReseaux.Serveur;

import java.io.IOException;
import Exception.PortInvalideException;

public class Main {

    public static void main(String[] args) throws PortInvalideException, IOException {
        System.out.println("Hello World");
        Serveur serv = new Serveur(1);

        while(true) {
            serv.attente();
        }

    }



}
