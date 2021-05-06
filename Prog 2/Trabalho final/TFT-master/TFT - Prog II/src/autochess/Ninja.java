package autochess;

import javax.swing.ImageIcon;

public class Ninja extends Pecas {
    public Ninja (int atk, int def, int rA, int life, ImageIcon imagem){
        
        super (atk, def, rA * 110/100, life, 2, 3, 'N', imagem);
    }   
}