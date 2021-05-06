package autochess;

import javax.swing.Icon;
import javax.swing.ImageIcon;
public abstract class Pecas {     

    private ImageIcon image;
    private int ataque, defesa, rateAtk, vida, codPec, preco, dps;  
    private String img;  
    private char id;
    private Pecas vet[] = new Pecas [4];         
    
    
    public Pecas (int atk, int def, int rate, int life, int cod, int preco, char id, ImageIcon imagem){
        
        ataque = atk;
        defesa = def;
        rateAtk = rate;
        vida = life;
        codPec = cod;
        this.preco = preco;
        this.id = id;
        dps = rate * atk;
        image = imagem;
    }
    
   
    
    public int getCod(){
        
        return codPec;
    }
    
    public int getPreco(){
        
        return preco;
    }
   
    public char getId(){
        
        return id;
    }
    
    public ImageIcon getImage (){
        
        return image;
    }
    
    public char getID(){
        
        return id;
    }
}