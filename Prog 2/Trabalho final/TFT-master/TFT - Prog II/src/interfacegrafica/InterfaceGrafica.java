package interfacegrafica;
import autochess.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.logging.Level;
import java.util.logging.Logger;
import java.util.Random;
//import autochess.*;
import javax.swing.*;
    public class InterfaceGrafica extends JFrame implements ActionListener{
        JLabel fundo,rI[] = new JLabel [10];
        JButton bot1, bot2, bot3, bot4, bot[][], botPlay,botRound[] = new JButton[9];
        Random rand = new Random();
        Loja loj = new Loja();
        Pecas loja[] = new Pecas[4]; 
        Pecas jogador[] = new Pecas[7];
        Pecas jogadorm[][] = new Pecas[4][7];
        int auxi, auxj, contP = 0, limP = 3, round = 0, auxclik = 0, auxc = 0, auxf = 0, auxg = 0, auxn = 0, auxm = 0;
        Icon auxIcon,auxIconRound;
        Pecas auxPeca;
        
    public InterfaceGrafica(){
        super("Janela Sem Laytout");
        setSize(1360, 768);  //1600, 940 (Monitoria). 1360, 768 (Alef)
        setResizable(false);
        ImageIcon image = new ImageIcon("IMAGENS\\inicio.jpg");
        fundo = new JLabel(image);
        fundo.setBounds(0,0,1360,760);
        
        bot1 = new JButton ("JOGAR");
        bot2 = new JButton ("SOBRE O JOGO");
        bot3 = new JButton ("PLACAR");
        bot4 = new JButton ("SAIR");
        bot1.setBounds(600,550,250,50);
        bot2.setBounds(600,600,250,50);
        bot3.setBounds(600,650,250,50);
        bot4.setBounds(600,700,250,50);
        fundo.add(bot1);
        fundo.add(bot2);
        fundo.add(bot3);
        fundo.add(bot4);
        
        bot1.addActionListener (this);
        bot2.addActionListener (this);
        bot3.addActionListener (this);
        bot4.addActionListener (this);
        
        getContentPane().add(fundo);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setVisible(true);
       
    }   
    
    @Override
    public void actionPerformed(ActionEvent ae) {
        Object o = ae.getSource();
        
        if (o == bot1){
            Jogar();
        }
        
        if(o == bot2){
            try {
                leitor("JogPont/SOBRE.txt");
            } catch (IOException ex) {
                Logger.getLogger(InterfaceGrafica.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
        
        if (o == bot3){
            try {
                leitor("JogPont/PLACAR.txt");
            } catch (IOException ex) {
                Logger.getLogger(InterfaceGrafica.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
        
        if (o == bot4){
            System.exit(0);
        }
        
//==========================ATUALIZA LOJA===========================================================        
        if (o == bot[8][7]){
            loja = loj.preencheVetPecas();
            atualBut();
        }
//==================================================================================================
        

//==========================COMPRA DA LOJA E PREENCHE O INVENTÁRIO==================================
        for(int j = 0; j < 7; j++){
            if (o == bot[4][7] && jogador[j] == null){
                if(bot[8][j].getIcon() == null){
                    bot[8][j].setIcon (bot[4][7].getIcon());
                    bot[8][j].setBackground(new Color(255, 255, 255));
                    bot[4][7].setIcon (null);
                    bot[4][7].setBackground(new Color(255, 255, 0));
                    bot[4][7].removeActionListener(this);
                    
                    jogador[j] = loja[0];
                    break;
                }    
            }
            if (o == bot[5][7]){
                if(bot[8][j].getIcon() == null && jogador[j] == null){
                    bot[8][j].setIcon (bot[5][7].getIcon());
                    bot[8][j].setBackground(new Color(255, 255, 255));
                    bot[5][7].setIcon(null);
                    bot[5][7].setBackground(new Color(255, 255, 0));
                    bot[5][7].removeActionListener(this);
                    
                    jogador[j] = loja[1];
                    break;
                }    
            }
            if (o == bot[6][7]){
                if(bot[8][j].getIcon() == null && jogador[j] == null){
                    bot[8][j].setIcon (bot[6][7].getIcon());
                    bot[8][j].setBackground(new Color(255, 255, 255));
                    bot[6][7].setIcon (null);
                    bot[6][7].setBackground(new Color(255, 255, 0));
                    bot[6][7].removeActionListener(this);
                    
                    jogador[j] = loja[2];
                    break;
                }    
            }
            if (o == bot[7][7]){
                if(bot[8][j].getIcon() == null && jogador[j] == null){
                    bot[8][j].setIcon (bot[7][7].getIcon());
                    bot[8][j].setBackground(new Color(255, 255, 255));
                    bot[7][7].setIcon (null);
                    bot[7][7].setBackground(new Color(255, 255, 0));
                    bot[7][7].removeActionListener(this);
                    
                    jogador[j] = loja[3];
                    break;
                }    
            }
        }
//==============================================================================================
        
//=========================PEGAR DO INVENTÁRIO E MANDAR PRO CAMPO===============================
        for(int h = 4; h < 8; h++){
            for(int g = 0; g < 7; g++){
                if(bot[h][g].getIcon() != null){
                    contP++;
                }
            }
        }
        
        for(int j = 0; j < 7; j++){
            if(o == bot[8][j]){
                if(bot[8][j].getIcon() != null){
                    auxIcon = bot[8][j].getIcon();
                    auxj = j;
                    auxclik = 1;
                }
            }
        }

        for(int i = 7; i>3; i--){
            for(int j = 0; j < 7; j++){
                if(o == bot[i][j] && contP < limP){
                    if(bot[i][j].getIcon() == null && auxclik == 1){
                        bot[i][j].setIcon(auxIcon);
                        bot[8][auxj].setIcon(null);
                        bot[8][auxj].setBackground(new Color (255, 255, 255));
                        auxIcon = null;
                        
                        jogadorm[i-4][j] = jogador[j];
                        System.out.println("OLA" + jogador[j].getID());

                        jogador[j] = null;
                        auxclik = 0;
                        break;
                    }
                }
            }
        }
//============================================================================           

    //-------------------------EXEMPLO 1----------------------------------
//        if(o == bot[8][0]){
//            if(bot[8][0].getIcon() != null){
//                bot[7][0].setIcon(bot[8][0].getIcon());
//                bot[8][0].setIcon(null);
//                bot[8][0].setBackground(new Color (255, 255, 255));
//            }
//        }
    //------------------------------------------------------------------
    
    //-------------------------EXEMPLO 2--------------------------------
//            if(o == bot[8][0]){
//                if(bot[8][0].getIcon() != null){
//                    auxIcon = bot[8][0].getIcon();
//                }
//            }
//            if(o == bot[7][0]){
//                bot[7][0].setIcon(auxIcon);
//                bot[8][0].setIcon(null);
//                bot[8][0].setBackground(new Color (255, 255, 255));
//            }
    //--------------------------------------------------------------------
    
        if(o == botPlay){
            System.out.println(round);
               /* 
                rI[0] = new JLabel(new ImageIcon("IMAGENS\\ROUNDS\\1.jpg"));
                rI[0].setIcon(new ImageIcon("IMAGENS\\ROUNDS\\1.jpg"));
                rI[0].setBounds(150, 300, 300, 70);
                fundo.add(rI[0]);
                getContentPane().add(rI[0]);
                rI[0].setVisible(true);
            */

                //botRound[round].setVisible(true);
                if(round == 0){
                   rI[round].setVisible(true); 
                }else if(round > 0 && round < 9){
                rI[round].setVisible(true);
                rI[round-1].setVisible(false);
                }else{
                    rI[9].setVisible(true);
                    rI[8].setVisible(false);
                }
                
            Jogador.setExp(1);
            round++;
        }
        contP = 0;
    }
    
    public static void leitor(String path) throws IOException {
        /* Ler o arquivo cujo nome é recebido pelo argumento 'path' linha por linha*/
        BufferedReader buffRead = new BufferedReader(new FileReader(path));
        String linha = "";
        String texto = "";
        while (linha != null) {
            linha = buffRead.readLine();
            if(linha != null){
                texto += linha + "\n";
            }
        }
        buffRead.close();
        JOptionPane.showMessageDialog(null, texto);
    }
    
    public void Jogar(){
                
        loja = loj.preencheVetPecas();
        int esc = 0;
        
        getContentPane().removeAll();
        int a = 450, b = 50;                                                     //Monitoria: a = 450, b = 100. Alef: 450, 50
        //
        ImageIcon image1 = new ImageIcon("IMAGENS\\jogar.jpg");
        setSize(1360, 768);                                                     //Monitoria: 1600, 940 . Alef: 1360, 768 
        fundo = new JLabel(image1);
        fundo.setBounds(0, 0, 1360, 760);
        add(fundo);
        bot = new JButton[9][8];
        
        ImageIcon aux0 = new ImageIcon("IMAGENS\\Comecar.png");
        aux0.setImage(aux0.getImage().getScaledInstance(65, 65, 100));
        botPlay = new JButton(aux0);
        botPlay.setBounds(380, 610, 70, 70);
        fundo.add(botPlay);
        botPlay.addActionListener(this);
        //========================Botões =======================================
        /*
        for(int i = 0; i<9;i++){
                botRound[i] = new JButton("IMAGENS\\ROUNDS\\1.jpg");
                botRound[i].setIcon(new ImageIcon("IMAGENS\\ROUNDS\\1.jpg"));
                botRound[i].setBounds(150, 300, 250, 70);
                fundo.add(botRound[i]);
                botRound[i].setVisible(false);
        }
*/
                rI[0] = new JLabel(new ImageIcon("IMAGENS\\ROUNDS\\1.png"));
                rI[0].setBounds(100, 300, 340, 120);
                fundo.add(rI[0]);
                rI[0].setVisible(false);
                
                rI[1] = new JLabel(new ImageIcon("IMAGENS\\ROUNDS\\2.png"));
                rI[1].setBounds(100, 300, 340, 120);
                fundo.add(rI[1]);
                rI[1].setVisible(false);
                
                rI[2] = new JLabel(new ImageIcon("IMAGENS\\ROUNDS\\3.png"));
                rI[2].setBounds(100, 300, 340, 120);
                fundo.add(rI[2]);
                rI[2].setVisible(false);
                
                rI[3] = new JLabel(new ImageIcon("IMAGENS\\ROUNDS\\4.png"));
                rI[3].setIcon(new ImageIcon("IMAGENS\\ROUNDS\\4.png"));
                rI[3].setBounds(100, 300, 340, 120);
                fundo.add(rI[3]);
                rI[3].setVisible(false);
                
                rI[4] = new JLabel(new ImageIcon("IMAGENS\\ROUNDS\\5.png"));
                rI[4].setIcon(new ImageIcon("IMAGENS\\ROUNDS\\5.png"));
                rI[4].setBounds(100, 300, 340, 120);
                fundo.add(rI[4]);
                rI[4].setVisible(false);
                
                rI[5] = new JLabel(new ImageIcon("IMAGENS\\ROUNDS\\6.png"));
                rI[5].setIcon(new ImageIcon("IMAGENS\\ROUNDS\\6.png"));
                rI[5].setBounds(100, 300, 340, 120);
                fundo.add(rI[5]);
                rI[5].setVisible(false);
                
                rI[6] = new JLabel(new ImageIcon("IMAGENS\\ROUNDS\\7.png"));
                rI[6].setIcon(new ImageIcon("IMAGENS\\ROUNDS\\7.png"));
                rI[6].setBounds(100, 300, 340, 120);
                fundo.add(rI[6]);
                rI[6].setVisible(false);
                
                rI[7] = new JLabel(new ImageIcon("IMAGENS\\ROUNDS\\8.png"));
                rI[7].setIcon(new ImageIcon("IMAGENS\\ROUNDS\\8.png"));
                rI[7].setBounds(100, 300, 340, 120);
                fundo.add(rI[7]);
                rI[7].setVisible(false);
                
                rI[8] = new JLabel(new ImageIcon("IMAGENS\\ROUNDS\\9.png"));
                rI[8].setIcon(new ImageIcon("IMAGENS\\ROUNDS\\9.png"));
                rI[8].setBounds(100, 300, 340, 120);
                fundo.add(rI[8]);
                rI[8].setVisible(false);
                
                rI[9] = new JLabel(new ImageIcon("IMAGENS\\ROUNDS\\f.png"));
                rI[9].setIcon(new ImageIcon("IMAGENS\\ROUNDS\\f.png"));
                rI[9].setBounds(100, 300, 340, 120);
                fundo.add(rI[9]);
                rI[9].setVisible(false);
            
        
        
        for (int i = 0; i < 9; i++){
            for (int j = 0; j < 8; j++){
                bot[i][j] = new JButton ("");
                if (j != 7){
                    bot[i][j].setBounds(a, b, 70, 70);      //Monitoria: 80, 80. Alef: 70, 70
                    a += 70;                                //Monitoria: 80. Alef: 70
                    
                    if (i < 4){
                        bot[i][j].setBackground(new Color(255, 0, 0));
                    }else{
                        bot[i][j].setBackground(new Color(0, 0, 255));
                    }
                    
                    if (i == 8){
                        bot[i][j].setBackground(new Color (255, 255, 255));
                    }
                }else{
//==================================L O J A==============================================        

                    if (i > 3 && i < 8){
                        switch (i) {
                            case 4:
                                bot[i][7] = new JButton(loj.getImage(0));
                                bot[i][7].setBackground(new Color(255, 255, 0));
                                break;
                            case 5:
                                bot[i][7] = new JButton(loj.getImage(1));
                                bot[i][7].setBackground(new Color(255, 255, 0));
                                break;
                            case 6:
                                bot[i][7] = new JButton(loj.getImage(2));
                                bot[i][7].setBackground(new Color(255, 255, 0));
                                break;
                            case 7:
                                bot[i][7] = new JButton(loj.getImage(3));
                                bot[i][7].setBackground(new Color(255, 255, 0));
                                break;
                            default:
                                break;
                        }
                        bot[i][j].setBounds(a, b, 70, 70);      //Monitoria: 80, 80. Alef: 70, 70
                        a += 70;                                //Monitoria: 80. Alef: 70
                    }
                    
                        if (i == 8){
                        bot[i][j].setBackground (new Color (255, 255, 255));
                    }
                        if(i==8 && j == 7){
                            ImageIcon aux = new ImageIcon ("IMAGENS//Refresh.png");
                            aux.setImage(aux.getImage().getScaledInstance(65, 65, 100));
                            bot[i][j] = new JButton(aux);
                            bot[i][j].setBounds(a, b, 70, 70);
                        }
//=================================================================================================                        
                }
                
                fundo.add(bot[i][j]);
            }
            b += 70;   //Monitoria: 80, 450. Alef
            a = 450;
        }
        for (int i = 0; i < 9; i ++){
            for (int j = 0; j < 8; j++){
                bot[i][j].addActionListener(this);
            }
        }
        getContentPane().add(fundo);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setVisible(true);
        a = 450;
        b = 50;
    }
    
    public void atualBut(){
        int a = 940, b = 330;
        
        for (int i = 4; i < 8; i++){
                        switch (i) {
                            case 4:
                                bot[i][7].setIcon(loj.getImage(0));
                                break;
                            case 5:
                                bot[i][7].setIcon(loj.getImage(1));
                                break;
                            case 6:
                                bot[i][7].setIcon(loj.getImage(2));
                                break;
                            case 7:
                                bot[i][7].setIcon(loj.getImage(3));
                                break;
                            default:
                                break;
                        }
                        bot[i][7].addActionListener(this);
                        bot[i][7].setBounds(a, b, 70, 70); 
                        b += 70;
        }
    }

    public static void main(String[] args) {
        InterfaceGrafica j = new InterfaceGrafica();
    }
}