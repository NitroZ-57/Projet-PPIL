import Interface.Vecteur2D;
import ServeurReseaux.Dessin.DessinGroupeCOR;
import ServeurReseaux.Serveur;
import java.awt.*;
import java.awt.image.BufferStrategy;
import java.io.IOException;
import java.util.ArrayList;

import Exception.PortInvalideException;

public class Main {

    public static void main(String[] args) throws PortInvalideException, IOException {
        try {
            Serveur serv = new Serveur(1);
            while(true) {
                serv.attente();
            }
        }
        catch(Exception e) {
            e.printStackTrace();
        }


    }



}
