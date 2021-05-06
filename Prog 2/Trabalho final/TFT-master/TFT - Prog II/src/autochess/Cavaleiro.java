package autochess;

import javax.swing.ImageIcon;

public class Cavaleiro extends Pecas {
    public Cavaleiro (int atk, int def, int rA, int life, ImageIcon imagem){
        
        super (atk, def * 110/100, rA, life, 0, 2, 'C', imagem);
    }
    
}