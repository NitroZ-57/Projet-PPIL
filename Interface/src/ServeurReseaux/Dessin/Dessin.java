package ServeurReseaux.Dessin;
import java.awt.*;

import java.awt.image.BufferStrategy;
import java.io.BufferedReader;
import Exception.FormatNonReconnuException;

public interface Dessin {
    void dessine(String forme, String datas, BufferStrategy bs) throws FormatNonReconnuException;
}
