package autochess;

import javax.swing.ImageIcon;

public class MestreLaminas extends Pecas{
    
    public MestreLaminas (int atk, int def, int rA, int life, ImageIcon imagem){
        
        super (atk * 110/100, def, rA, life, 1, 1, 'M', imagem);
    }
}
