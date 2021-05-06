#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<time.h>
#include <locale.h>
#include<conio.h>
#include<windows.h>
#include <string.h>

typedef struct{
	int posl;
	int posc;
	char repre;
}Jogador;

typedef struct{
	int anda;
	char tiro;
}Tiro;

typedef struct{
	char pos;
	int posc;
	int posl;
	int contc;
	int contl;
	int poslcont;
	int posccont;
}Inimigo;

int main(int argc, char *argv[]) {
	Jogador tp,*tp2=&tp;
	Inimigo I1,*pI1=&I1,I2,*pI2=&I2;
	Tiro tiro,*ptiro=&tiro;
	char mat[15][15],acao,*pacao=&acao,pi=177,diretiro='w',*pdiretiro=&diretiro, diretiroI1='s', diretiroI2='s', *pdiretiroI1=&diretiroI1, *pdiretiroI2=&diretiroI2;
	int pontos=0,vidas=3,op=0,aleatorio, *ppontos=&pontos,*pvidas=&vidas,ctp,opd=0,contf=0,contmorte=0,*pcontmorte=&contmorte,pm,turno=0;
	int saida=0;
	char listaa[100000];
	
	srand(time(NULL));
	
	tp.posl = 11;
	tp.posc = 7;
	tp.repre = 202;
	I1.pos = 194;
	I1.posl = 1;
	I1.posc = 1;
	I2.pos = 'V';
	I2.posl = 1;
	I2.posc = 13;
	
	tiro.tiro='*';
	
	criandofases(mat);
	
	while(op!=4){
		printf("Escolha uma das opcoes:\n[1]:Jogar;\n[2]:Jogar no modo DEBUG;\n[3]:Lista de ganhadors;\n[4]:Sair.\n\n%c = EE-T1 Osorio;\n\n%c = M1-Abrams;\n\n%c = Jogador principal.\n\nOpcao: ", I2.pos , I1.pos, tp.repre);
		scanf("%d",&op);
		system("cls");
		acao = 'h';
		switch(op){
		case 1:
			op = 0;
			limpatabuleiro(mat);
			borda(mat);
			fase1(mat);
			base(mat,pI1,pI2);
			imprimir(mat);
			vidas =3;
			pontos = 0;
			contf = 1;
	

			
				while(acao!='o'){
					printf("Pontos:%d       Vidas :%d\n(W):Cima\n(S):Baixo\n(D):Esquerda\n(A):Direita\n(G):Girar\n(F):Tiro\n(O):Sair\n: ",pontos,vidas);
					acao = getch();
					turno = 0;
					
				if(acao == 'g'){
					girar(mat,tp2,pdiretiro,pacao,ppontos,pvidas);
					turno = 0;
				}
			
				if(acao == 'w' || acao == 'a' || acao == 's' || acao == 'd'){
					andar(mat,tp2,pacao,pdiretiro);
					turno = 1;
				}
				else if(acao == 'f'){
					pm = atirar(mat,tp2,pacao,pdiretiro,ptiro,pI1, pI2,ppontos,pcontmorte);
					turno = 1;
					if(pm == 1){
						pontos = pontos +10;
					}
				}
			
				
				aleatorio=rand()%4;
				if(aleatorio==0){
					MovInimigoInteligente(mat,tp2,pI1,pI2,ptiro, pdiretiroI1, pdiretiroI2,pvidas);
				}
				else if (aleatorio==1){
					MovInimigoAleatorio(mat,tp2,pI1,pI2,ptiro, pdiretiroI1, pdiretiroI2,pvidas);
					tirodoInimigo1 (mat,tp2,pI1,pI2,ptiro,pdiretiroI1, pdiretiroI2, pvidas);
				}else if (aleatorio==2){
					MovInimigoAleatorio(mat,tp2,pI1,pI2,ptiro, pdiretiroI1, pdiretiroI2,pvidas);
				}
				else{
					MovInimigoAleatorio(mat,tp2,pI1,pI2,ptiro, pdiretiroI1, pdiretiroI2,pvidas);
					tirodoInimigo2 (mat,tp2,pI1,pI2,ptiro,pdiretiroI1, pdiretiroI2, pvidas);
				}
				system("cls");
				imprimir(mat);
				if (contmorte>11){
					system("cls");
					vitoria(ppontos);
					system("pause");
					break;
				}
				if (contmorte > 5 && contf==1){
					pontos = pontos*vidas;
					borda(mat);
					fase2(mat);
					base(mat,pI1,pI2);
					imprimir(mat);
					tp.posl = 11;
					tp.posc = 7;
					I1.posl = 1;
					I1.posc = 1;
					I2.posl = 1;
					I2.posc = 13;
					contf = 2;
				}
				if(vidas == 0){
					system("cls");
					printf("VOCE FOI COMPLETAMENTE ESMAGADO!\n(1):Reiniciar fase\n(2):Novo jogo\n:");
					scanf("%d",&opd);
					
						switch(opd){
							case 1:
									limpatabuleiro(mat);
									borda(mat);
									fase1(mat);
									base(mat,pI1,pI2);
									imprimir(mat);
									vidas =3;
									tp.posl = 11;
									tp.posc = 7;
									I1.posl = 1;
									I1.posc = 1;
									I2.posl = 1;
									I2.posc = 13;
									mat[13][7]='W';
									
									contf = 1;
									acao = 'o';
									op = '1';
									contmorte = 0;
								break;
							case 2:
								acao = 'o';
								system("cls");
								break;
							
							default:
								printf("Opcao invalida.Digite numero 1 ou 2");
								break;
					}
			}
				else if(mat[13][7]!='W'){
					system("cls");
					while(opd=! 1 || opd!=2){
					
					printf("SUA BASE FOI ANIQUILADA!ONDE VC ESTAVA!?\n(1):Reiniciar fase\n(2):Novo jogo\n:");
					scanf("%d",&opd);
					
						switch(opd){
							case 1:
									limpatabuleiro(mat);
									borda(mat);
									fase1(mat);
									base(mat,pI1,pI2);
									imprimir(mat);
									vidas =3;
									tp.posl = 11;
									tp.posc = 7;
									tp.repre = 202;
									I1.pos = 194;
									I1.posl = 1;
									I1.posc = 1;
									I2.pos = 'V';
									I2.posl = 1;
									I2.posc = 13;
									contf = 1;
									acao = 'o';
									op = '1';
									mat[13][7]='W';
									break;
							case 2:
								acao = 'o';
								system("cls");
								break;
							
							default:
								printf("Opcao invalida.Digite numero 1 ou 2\n");
								break;
					}
					}
				}
				
				
			}
		
	case 2:
			op = 0;
			limpatabuleiro(mat);
			borda(mat);
			fase1(mat);
			base(mat,pI1,pI2);
			imprimir(mat);
			vidas =3;
			pontos = 0;
			contf = 1;
	

			
				while(acao!='o'){
					printf("Pontos:%d       Vidas :%d\n(W):Cima\n(S):Baixo\n(D):Esquerda\n(A):Direita\n(G):Girar\n(F):Tiro\n(O):Sair\n: ",pontos,vidas);
					acao = getch();
					turno = 0;
					
				if(acao == 'g'){
					girar(mat,tp2,pdiretiro,pacao,ppontos,pvidas);
					turno = 0;
				}
			
				if(acao == 'w' || acao == 'a' || acao == 's' || acao == 'd'){
					andard(mat,tp2,pacao,pdiretiro);
					turno = 1;
				}
				else if(acao == 'f'){
					pm = atirar(mat,tp2,pacao,pdiretiro,ptiro,pI1, pI2,ppontos,pcontmorte);
					turno = 1;
					if(pm == 1){
						pontos = pontos +10;
					}
				}
			
				
				aleatorio=rand()%4;
				if(aleatorio==0){
					MovInimigoInteligente(mat,tp2,pI1,pI2,ptiro, pdiretiroI1, pdiretiroI2,pvidas);
				}
				else if (aleatorio==1){
					MovInimigoAleatorio(mat,tp2,pI1,pI2,ptiro, pdiretiroI1, pdiretiroI2,pvidas);
					tirodoInimigo1 (mat,tp2,pI1,pI2,ptiro,pdiretiroI1, pdiretiroI2, pvidas);
				}else if (aleatorio==2){
					MovInimigoAleatorio(mat,tp2,pI1,pI2,ptiro, pdiretiroI1, pdiretiroI2,pvidas);
				}
				else{
					MovInimigoAleatorio(mat,tp2,pI1,pI2,ptiro, pdiretiroI1, pdiretiroI2,pvidas);
					tirodoInimigo2 (mat,tp2,pI1,pI2,ptiro,pdiretiroI1, pdiretiroI2, pvidas);
				}
				system("cls");
				imprimir(mat);
				if (contmorte>11){
					system("cls");
					vitoria(ppontos);
					system("pause");
					break;
				}
				if (contmorte > 5 && contf==1){
					pontos = pontos*vidas;
					borda(mat);
					fase2(mat);
					base(mat,pI1,pI2);
					imprimir(mat);
					tp.posl = 11;
					tp.posc = 7;
					I1.posl = 1;
					I1.posc = 1;
					I2.posl = 1;
					I2.posc = 13;
					contf = 2;
				}
				if(vidas == 0){
					system("cls");
					printf("VOCE FOI COMPLETAMENTE ESMAGADO!\n(1):Reiniciar fase\n(2):Novo jogo\n:");
					scanf("%d",&opd);
					
						switch(opd){
							case 1:
									limpatabuleiro(mat);
									borda(mat);
									fase1(mat);
									base(mat,pI1,pI2);
									imprimir(mat);
									vidas =3;
									tp.posl = 11;
									tp.posc = 7;
									I1.posl = 1;
									I1.posc = 1;
									I2.posl = 1;
									I2.posc = 13;
									mat[13][7]='W';
									
									contf = 1;
									acao = 'o';
									op = '1';
									contmorte = 0;
								break;
							case 2:
								acao = 'o';
								system("cls");
								break;
							
							default:
								printf("Opcao invalida.Digite numero 1 ou 2");
								break;
					}
			}
				else if(mat[13][7]!='W'){
					system("cls");
					while(opd=! 1 || opd!=2){
					
					printf("SUA BASE FOI ANIQUILADA!ONDE VC ESTAVA!?\n(1):Reiniciar fase\n(2):Novo jogo\n:");
					scanf("%d",&opd);
					
						switch(opd){
							case 1:
									limpatabuleiro(mat);
									borda(mat);
									fase1(mat);
									base(mat,pI1,pI2);
									imprimir(mat);
									vidas =3;
									tp.posl = 11;
									tp.posc = 7;
									tp.repre = 202;
									I1.pos = 194;
									I1.posl = 1;
									I1.posc = 1;
									I2.pos = 'V';
									I2.posl = 1;
									I2.posc = 13;
									contf = 1;
									acao = 'o';
									op = '1';
									mat[13][7]='W';
									break;
							case 2:
								acao = 'o';
								system("cls");
								break;
							
							default:
								printf("Opcao invalida.Digite numero 1 ou 2\n");
								break;
					}
					}
				}
				
				
			}
		break;
	
	case 3:
		printarjogadores(mat);
		
	
	
		
		break;
	case 4:
		break;
		
	default:
		printf("Opcao invalida.Escolha uma opcao de 1 a 3");
	}
	
}
	return 0;
}

