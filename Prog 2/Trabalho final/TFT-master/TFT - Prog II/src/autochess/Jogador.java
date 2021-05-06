package autochess;

public class Jogador {
    private static Pecas pecJog[] = new Pecas [10];
    private static int ouro;
    private static int exp;
    
    public Jogador (){                         //O jogador começa com 1 de ouro e as peças que aparecem na loja
                                             //na primeira vez custam todas 1 ouro. Depois, a cada rodada, vamos
        ouro = 10;                            //incrementando
        exp = 0;                                // começa com 0 e vai subindo
    }
    
    public static void alocaPeca(Pecas pec){

/*=======================Aloca a peça comprada na loja no vetor do jogador=====*/
        for (int i = 0; i < pecJog.length; i++){
            if (pecJog[i] == null){
                pecJog[i] = pec;
                break;
            }
        }
    }
/*=============================================================================*/
    
    public void mostraPecJog(){
        char nulo = 157;
        
        System.out.println("SUAS PEÇAS:");
        
        for (int i = 0; i < pecJog.length; i++){
            if (pecJog[i] != null){
                System.out.print(pecJog[i].getId() + " ");
            }else{
                System.out.print(nulo + " ");
            }
        }
        System.out.println();
    }
    
    public void pegaPec(int num, int posL, int posC){
        int i;
/*=======================Pèga a peça escolhida e manda pro tabuleiro===========*/
        
        //if (pecJog[num] == null){
            i = Tabuleiro.noTabul(pecJog[num], posL, posC);
        //}
        if (i == 0){    
            pecJog[num] = null;
        }
    }
/*=============================================================================*/
    
    public static int getOuro(){
        
        return ouro;
    }
    
    public static void setOuro(int preco){
        
       ouro -= preco; 
    }
    
    public static void setExp(int v){
        
        exp += v;
    }
}