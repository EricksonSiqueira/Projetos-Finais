package testautochess;
import autochess.*;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;
import java.util.Random;
public class TestAutoChess {
    
    public static void leitor(String path) throws IOException {
        /* Ler o arquivo cujo nome é recebido pelo argumento 'path' linha por linha*/
        BufferedReader buffRead = new BufferedReader(new FileReader(path));
        String linha = "";
        while (linha != null) {
            System.out.println(linha);
            linha = buffRead.readLine();
        }
        buffRead.close();
    }
    
    public static void escritor(String path) throws IOException {
        /* Escreve a string digitada pelo usuário no arquivo cujo nome é recebido pelo argumento 'path' */
        BufferedWriter buffWrite = new BufferedWriter(new FileWriter(path));
        String linha = "";
        Scanner in = new Scanner(System.in);
        System.out.println("Escreva algo: ");
        linha = in.nextLine();
        buffWrite.append(linha + "\n");
        buffWrite.close();
    }
    
    public static void main(String[] args) throws IOException {
        Scanner ent = new Scanner (System.in);
        Loja loja = new Loja();
        Jogador jogador = new Jogador();
        Random chance = new Random();
        //char vet[];
        int opc = 1;
        
        
        do{
            System.out.print("Escolha uma opção:\n1)JOGAR;\n2)SOBRE O JOGO;\n3)PLACAR;\n4)SAIR.\n\nOPÇÃO: ");
            opc = ent.nextInt();
            ent.nextLine();
            switch (opc){
                case 1:
//                    Tabuleiro.exibeTab();
//                    loja.preencheVetPecas();
//                    loja.mostraVetPecas();;
                    loja.preencheVetPecas();
                    
                    int opc2=0;
                    while(opc2 !=4){  
                        Tabuleiro.exibeTab();
                        System.out.println();
                        loja.mostraVetPecas(0);
                        System.out.println();
                        jogador.mostraPecJog();
                        System.out.println();
                        System.out.println("[1]Comprar peça;\n[2]Posicionar;\n[3]Começar combate;\n[4]Sair.\n");
                        opc2 = ent.nextInt();
                        ent.nextLine();
                        switch (opc2){
                 
                            case 1:
                                loja.mostraVetPecas(1);
                                int esc = 6; while(esc > 5 || esc < 0){
                                    System.out.print("\n\nEscolha o personagem: ");
                                    esc = ent.nextInt();
                                    ent.nextLine();
                                    if(esc < 6 && esc > 0){
                                        if(esc == 5){
                                            
                                            break;
                                        }
                                        int a = loja.escolhePec(esc);
                                        if(a  == 0){
                                            esc = 6;
                                        }
                                    }
                                    else{
                                        System.out.println("\n\nOPÇÃO INVÁLIDA\n");
                                    }
                                }
                                break;
                                
                            case 2:
                                
                                int qualPec = 1;
                                do{
                                    jogador.mostraPecJog();
                                    System.out.println("\n\nEscolha o personagem ou saia digitando 0: ");
                                    qualPec = ent.nextInt();
                                    ent.nextLine();
                                    if (qualPec == 0){
                                        break;
                                    }
                                    char vet[];// = new char[2];
                                    do{
                                        int chanc = chance.nextInt(3);
                                        Tabuleiro.exibeTab();
                                        
                                        do{
//                                            vet[0] = 'Z';
//                                            vet[1] = 'Z';
                                            
                                            System.out.println("\n\nPosicione o seu personagem: (Ex: A1)");
                                            String alocar = ent.nextLine();
                                            vet = alocar.toCharArray();
                                            if (vet[0] > 95){                                   //Tabela ASCII
                                                vet[0] -= 32;                                  //Lógica para, se o jogador digitar letra minúscula, transformar em maiúscula.
                                            }
                                            
                                        }while (vet[0]<65 && vet[0]>71 || vet[1]<49 && vet[1]>56 || 
                                                vet[0]<97 && vet[0]>103 || vet[0] == 'Z' || vet[1] == 'Z');
                                        
//                                      if (vet[0] > 95){                                   //Tabela ASCII
//                                          vet[0] -= 32;                                  //Lógica para, se o jogador digitar letra minúscula, transformar em maiúscula.
//                                      }
                                        
                                        if (((vet[1]-49) < 4 || vet[1] - 49 > 7) || (vet[0] - 65 < 0 || vet[0] - 65 > 6)){
                                            if (chanc == 0){
                                                System.out.println("\nQUER JOGAR NO CAMPO DO INIMIGO?!");
                                            }else if (chanc == 1){
                                                System.out.println("\nVOCÊ É O CAVALEIRO OU O CAVALO?");
                                            }else{
                                                System.out.println("\nVOCÊ NÃO LEU O MANUAL?! COMASSIM!???");
                                            }
                                        }
                                    }while (((vet[1]-49) < 4 || vet[1] - 49 > 7) || (vet[0] - 65 < 0 || vet[0] - 65 > 6));
                                    
                                    jogador.pegaPec(qualPec - 1, vet[1]-49, vet[0] - 65);

                                    Tabuleiro.exibeTab();
                                    jogador.mostraPecJog();
                                }while (qualPec != 0);
                                
                    
                
            
                                break;
                            case 3:
                                System.out.println("\n\nOoooooops, por enquanto você é um pacifista.SEM GUERRAS!");
                                loja.preencheVetPecas();
                                        
                                break;
                                
                            case 4:
                                break;
                                
                            default :
                                System.out.println("\n\nOPÇÃO INVÁLIDA.\n");
                        }
                    }
                case 2:
                    leitor("JogPont/SOBRE.txt");
                    System.out.println("\n");
                    break;
                    
                case 3:
                    leitor("JogPont/PLACAR.txt");
                    System.out.println("\n");
                    break;
                    
                default:
                    System.out.println("OPÇÃO INVÁLIDA...\n");
            }
        }while (opc != 4);
    }
}