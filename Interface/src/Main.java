import ServeurReseaux.Serveur;
import java.awt.*;
import java.awt.image.BufferStrategy;
import java.io.IOException;
import Exception.PortInvalideException;

public class Main {

    public static void main(String[] args) throws PortInvalideException, IOException {
        try {
            System.out.println("Hello World");



            Thread.sleep(150);
            Serveur serv = new Serveur(1);
            while(true) {
                serv.attente();
            }
        }
        catch(InterruptedException i) {
            // rien
        }
        catch(Exception e) {
            e.printStackTrace();
        }


    }



}
