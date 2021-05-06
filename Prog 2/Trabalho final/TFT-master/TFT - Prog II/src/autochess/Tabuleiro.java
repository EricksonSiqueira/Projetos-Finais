package autochess;
public class Tabuleiro {
    private static Pecas tab[][] = new Pecas [8][7];
    
    public Tabuleiro(){
        
    }
    
    
    public static void exibeTab(){
        
/*================================LÓGICA DO TABULEIRO==========================*/
        System.out.println("   A B C D E F G");
        System.out.println(" # # # # # # # # #");
        for (int i = 0; i < 8; i++){                 
            for (int j = 0; j < 7; j++){
                
                    if (j == 0){
                        System.out.print((i+1) + "# ");
                    }
                    if (tab[i][j] != null){
                        System.out.print(tab[i][j].getId() + " ");
                    }else{
                        System.out.print("  ");
                    }
                    if (j == 6){
                        System.out.println("# ");
                        if (i == 3){
                            System.out.print("------------------");
                        }
                    }
            }
            System.out.println();
        }
        
        
        
        
        System.out.println(" # # # # # # # # #");
    }
/*=============================================================================*/
    
    public static int noTabul(Pecas pec, int num1, int num2){
        
                                             //Verifica se o espaço no tabuleiro está vazio. Se não estiver, o jogador não perde a peça.
        if (tab[num1][num2] == null){                    
            tab[num1][num2] = pec;
            return 0;
        }else{
            return 1;
        }
        
    }
}