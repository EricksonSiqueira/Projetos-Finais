package autochess;
import java.util.Random; //Biblioteca Ramdom
import javax.swing.ImageIcon;
public class Loja {
    private Pecas pecLoj[] = new Pecas [4];
    private int preco;
    Random gerador = new Random();
    
    public Loja(){                        //Precisamos ver um jeito de cada personagem ter um preço quando
                                       //eles aparecem na loja
    }
    
    public Pecas[] preencheVetPecas(){
        int num;
        ImageIcon image;
        
       
        for (int i = 0; i < pecLoj.length; i++){
            num = gerador.nextInt(5);
            //pecLoj[i] = Pecas.criarPeca(num);  //Geral números de 0 a 0, ou seja, só 0, para testarmos.
            if (num == 0){
            image = new ImageIcon ("IMAGENS\\PECAS\\Cavaleiro.png");
            image.setImage(image.getImage().getScaledInstance(80, 80, 100));
            pecLoj[i]= new Cavaleiro (100, 100, 100, 100, image);
        
        }else if (num == 1){
            image = new ImageIcon ("IMAGENS\\PECAS\\Mestrelam.png");
            image.setImage(image.getImage().getScaledInstance(80, 80, 100));
            pecLoj[i] = new MestreLaminas (100, 100, 100, 100, image);
       
        }else if (num == 2){
            image = new ImageIcon ("IMAGENS\\PECAS\\Ninja.png");
            image.setImage(image.getImage().getScaledInstance(80, 80, 100));
            pecLoj[i]= new Ninja (100, 100, 100, 100, image);
            
        }else if (num == 3){
            image = new ImageIcon ("IMAGENS\\PECAS\\Glacial.png");
            image.setImage(image.getImage().getScaledInstance(80, 80, 100));
            pecLoj[i] = new Glacial (100, 100, 100, 100, image);
            
        }else if (num == 4){
            image = new ImageIcon ("IMAGENS\\PECAS\\Feiticeiro.png");
            image.setImage(image.getImage().getScaledInstance(80, 80, 100));
            pecLoj[i] = new Feiticeiro (100, 100, 100, 100, image);
            
        }
            
            
        }
        for (int i = 0; i < pecLoj.length; i++){
                System.out.println(pecLoj[i] + " \n" + pecLoj[i].getImage().toString() + " \n");
        }
        return pecLoj;
    }

    
    public void mostraVetPecas(int estet){
        char nulo = 157;
//======================Mostra as peças da loja================================
        
        System.out.println("\nLOJA: ");
        for (int i = 0; i < pecLoj.length; i++ ){   
            if (pecLoj[i] != null){
                System.out.print(pecLoj[i].getId() + " "); 
            }
            if (pecLoj[i] == null){
                System.out.print(nulo + " "); 
            }
            
            if(i == 3){
                System.out.print("  Seu ouro: " + Jogador.getOuro());
            }
        }
        
        System.out.println();
        
        for (int i = 0; i < pecLoj.length; i++){
            if (pecLoj[i] != null){
                System.out.print(pecLoj[i].getPreco() + " ");
            }
            if (pecLoj[i] == null){
                System.out.print(nulo + " "); 
            }
            if(i == 3 && estet == 1){
                System.out.println("  [5]Sair.");
                
            }
        }
    }
//=============================================================================
    
    public int escolhePec(int num){
    
//====================Manda a peça escolhida para o vetor de peças do jogador==
        if(pecLoj[num - 1] != null){  
            if(Jogador.getOuro() >= pecLoj[num - 1].getPreco()){
                Jogador.alocaPeca(pecLoj[num - 1]);
                Jogador.setOuro(pecLoj[num - 1].getPreco());
                pecLoj [num - 1] = null;
                return 1;

            }else{
                System.out.println("Você não tem ouro o suficiente.");
                return 0;
            }
        }else{
            System.out.println("Você já comprou esta peça.");
            return 0;
        }
    }
    
    public ImageIcon getImage (int num){
        return pecLoj[num].getImage();
    }
    
    public void ajuda (){
        
        for (int i = 0; i < pecLoj.length; i++){
            System.out.println("ID: " + pecLoj[i].getId());
            System.out.print(pecLoj[i].getImage().toString());
        }
    }
//=============================================================================
}