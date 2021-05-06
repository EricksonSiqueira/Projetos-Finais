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

void tirodoInimigo1 (char m[][15], Jogador *tap, Inimigo *I1, Inimigo *I2,Tiro *tiro, char *diretiroI1, char *diretiroI2,int *vidas){
	int k1;
	char pi, p, pb;
	pi = 219;
	p = 177;
	pb=178;
	

	
//======================================INIMIGO 1=============================================================	
	
	if (*diretiroI1=='d'){					//=======DIREITA====/
		for (k1=I1->posc; k1<14 ;k1++){
		   	if (m[I1->posl][k1+1]==p){ 
				m[I1->posl][k1+1]=' ';
				m[I1->posl][k1]=' ';
				tiro->tiro=' ';
				m[I1->posl][I1->posc]=I1->pos;
				if (tiro->tiro==' '){
    	  	    	k1=14;
				}
		   	}
		   	if(m[I1->posl][k1+1]==pi){
		   	  	m[I1->posl][k1+1]=pi;
				m[I1->posl][k1]=' ';
				tiro->tiro=' ';
				m[I1->posl][I1->posc]=I1->pos;
				if (tiro->tiro==' '){
    	        	k1=14;
				}
			}
		   	if (m[I1->posl][k1+1]==I2->pos || m[I1->posl][k1+1]==tap->repre){
				if (m[I1->posl][k1+1]==I2->pos){
				 	m[I1->posl][I1->posc]=' ';
				 	I1->posl = 1;
				 	I1->posc = 1;
				}else if (m[I1->posl][k1+1]==tap->repre){
				 	m[I1->posl][I1->posc]=' ';
				 	tap->posl = 11;
				 	tap->posc = 7;
				 	*vidas = *vidas -1;
				} 
				m[I1->posl][k1+1]=' ';
				m[I1->posl][k1]=' ';
				tiro->tiro=' ';
				m[I1->posl][I1->posc]=I1->pos;
				if (tiro->tiro==' '){
    		 		k1=14;
				}
				   
		   	}
			if(m[I1->posl][k1]!=I1->pos){
				m[I1->posl][k1]=' ';		
			}
			m[I1->posl][k1+1]='*'; //O tiro anda :o
			system("cls");		
			imprimir(m);
			printf ("\n");
			m[I1->posl][I1->posc]=I1->pos;
		}
		renovBordas(m);
	}
	
	if (*diretiroI1=='a'){					//=======ESQUERDA===/
		for (k1=I1->posc; k1>0; k1--){
			if (m[I1->posl][k1-1]==p){ 
				m[I1->posl][k1-1]=' ';
				m[I1->posl][k1]=' ';
				tiro->tiro=' ';
				m[I1->posl][I1->posc]=I1->pos;
				if (tiro->tiro==' '){
    		    	k1=0;
				}
			}
			if(m[I1->posl][k1-1]==pi){
		   	  	m[I1->posl][k1-1]=pi;
				m[I1->posl][k1]=' ';
				tiro->tiro=' ';
				m[I1->posl][I1->posc]=I1->pos;
				if (tiro->tiro==' '){
    	        	k1=0;
				}
			}   	
		  	if (m[I1->posl][k1-1]==I2->pos || m[I1->posl][k1-1]==tap->repre){ 
		  		if (m[I1->posl][k1-1]==I2->pos){
				 	m[I1->posl][I1->posc]=' ';
				 	I1->posl = 1;
				 	I1->posc = 1;
				}else if (m[I1->posl][k1-1]==tap->repre){
				 	m[I1->posl][I1->posc]=' ';
				 	tap->posl = 11;
				 	tap->posc = 7;
				 	*vidas = *vidas -1;
				}
				m[I1->posl][k1-1]=' ';
				m[I1->posl][k1]=' ';
				tiro->tiro=' ';	
				m[I1->posl][I1->posc]=I1->pos;
					if (tiro->tiro==' '){
    		    		k1=0;
					}
		   	}		
			m[I1->posl][k1-1]='*';
			if (m[I1->posl][k1]!=I1->pos){
				m[I1->posl][k1]=' ';
			}
			m[I1->posl-1][12]=' ';
			system("cls");		
			imprimir(m);
			printf ("\n");
		}
		renovBordas(m);
	}
	
	if (*diretiroI1=='w'){					//=======CIMA=======/
		for (k1=I1->posl; k1>0; k1--){
			if (m[k1-1][I1->posc]==p){ 
				m[k1-1][I1->posc]=' ';
				m[k1][I1->posc]=' ';
				tiro->tiro=' ';
				m[I1->posl][I1->posc]=I1->pos;
				if (tiro->tiro==' '){
    		    	k1=0;
				}
		   	}
			if(m[k1-1][I1->posc]==pi){
		   	  	m[k1-1][I1->posc]=pi;
				m[k1][I1->posc]=' ';
				tiro->tiro=' ';
				m[I1->posl][I1->posc]=I1->pos;
				if (tiro->tiro==' '){
    	       		k1=-1;
				}
			}    	
		   	if (m[k1-1][I1->posc]==I2->pos || m[k1-1][I1->posc]==tap->repre){
		   	  	if (m[k1-1][I1->posc]==I2->pos){
				 	m[I1->posl][I1->posc]=' ';
				 	I1->posl = 1;
				 	I1->posc = 1;
				}else if (m[k1-1][I1->posc]==tap->repre){
				 	m[I1->posl][I1->posc]=' ';
				 	tap->posl = 11;
				 	tap->posc = 7;
				 	*vidas = *vidas -1;
				}
				m[k1-1][I1->posc]=' ';
				m[k1][I1->posc]=' ';
				tiro->tiro=' ';
				m[I1->posl][I1->posc]=I1->pos;
				if (tiro->tiro==' '){
    		   		k1=-1;
				}
		   	}		
			m[k1-1][I1->posc]='*';
			if (m[k1][I1->posc]!=I1->pos){
				m[k1][I1->posc]=' ';
			}
			m[1][4]=' ';
			system("cls");	
			imprimir(m);
			printf ("\n");	
		}
		renovBordas(m);
	}
	
	if (*diretiroI1=='s'){					//=======BAIXO======/				
		for (k1=I1->posl; k1<14; k1++){	
			if (m[k1+1][I1->posc]==p){ 
				m[k1+1][I1->posc]=' ';
				m[k1][I1->posc]=' ';
				tiro->tiro=' ';
				m[I1->posl][I1->posc]=I1->pos;
				if (tiro->tiro==' '){
    			    k1=14;
				}
		   	}	
		   	if(m[k1+1][I1->posc]==pi){
		   	  	m[k1+1][I1->posc]=pi;
				m[k1][I1->posc]=' ';
				tiro->tiro=' ';
				m[I1->posl][I1->posc]=I1->pos;
				if (tiro->tiro==' '){
    	        	k1=14;
				}
			}   
		   	if (m[k1+1][I1->posc]==I2->pos || m[k1+1][I1->posc]==tap->repre){ 	
		   		if (m[k1+1][I1->posc]==I2->pos){
				 	m[I1->posl][I1->posc]=' ';
				 	I1->posl = 1;
				 	I1->posc = 1;
				}else if (m[k1+1][I1->posc]==tap->repre){
				 	m[I1->posl][I1->posc]=' ';
				 	tap->posl = 11;
				 	tap->posc = 7;
				 	*vidas = *vidas -1;
				}
				m[k1+1][I1->posc]=' ';
				m[k1][I1->posc]=' ';
				tiro->tiro=' ';
				m[I1->posl][I1->posc]=I1->pos;
				if (tiro->tiro==' '){
    			  	k1=14;
				}
		   	}	
			m[k1+1][I1->posc]='*';
			if (m[k1][I1->posc]!=I1->pos){
				m[k1][I1->posc]=' ';
			}
			m[1][4]=' ';
			system("cls");		
			imprimir(m);
			printf ("\n");
		}
		renovBordas(m);
	}
	
}
void tirodoInimigo2 (char m[][15], Jogador *tap, Inimigo *I1, Inimigo *I2,Tiro *tiro, char *diretiroI1, char *diretiroI2,int *vidas){
	int  k2;
	char pi, p, pb;
	pi = 219;
	p = 177;
	pb=178;
	
	
	//====================================INIMIGO 2=======================================================	
	
	if (*diretiroI2=='d'){					//=======DIREITA====/
		for (k2=I2->posc; k2<14 ;k2++){
		   	if (m[I2->posl][k2+1]==p){ 
				m[I2->posl][k2+1]=' ';
				m[I2->posl][k2]=' ';
				tiro->tiro=' ';
				m[I2->posl][I2->posc]=I2->pos;
				if (tiro->tiro==' '){
    	  	    	k2=14;
				}
		   	}
		   	if(m[I2->posl][k2+1]==pi){
		   	  	m[I2->posl][k2+1]=pi;
				m[I2->posl][k2]=' ';
				tiro->tiro=' ';
				m[I2->posl][I2->posc]=I2->pos;
				if (tiro->tiro==' '){
    	        	k2=14;
				}
			}
		   	if (m[I2->posl][k2+1]==I1->pos || m[I2->posl][k2+1]==tap->repre){
				if (m[I2->posl][k2+1]==I1->pos){
				 	m[I1->posl][I1->posc]=' ';
				 	I1->posl = 1;
				 	I1->posc = 1;
				}else if (m[I2->posl][k2+1]==tap->repre){
				 	m[I2->posl][I2->posc]=' ';
				 	tap->posl = 11;
				 	tap->posc = 7;
				 	*vidas = *vidas -1;
				} 
				m[I2->posl][k2+1]=' ';
				m[I2->posl][k2]=' ';
				tiro->tiro=' ';
				m[I2->posl][I2->posc]=I2->pos;
				if (tiro->tiro==' '){
    		 		k2=14;
				}
				   
		   	}
			if(m[I2->posl][k2]!=I2->pos){
				m[I2->posl][k2]=' ';		
			}
			m[I2->posl][k2+1]='*'; //O tiro anda :o
			system("cls");		
			imprimir(m);
			printf ("\n");
			m[I2->posl][I2->posc]=I2->pos;
		}
		renovBordas(m);
	}
	
	if (*diretiroI2=='a'){					//=======ESQUERDA===/
		for (k2=I2->posc; k2>0; k2--){
			if (m[I2->posl][k2-1]==p){ 
				m[I2->posl][k2-1]=' ';
				m[I2->posl][k2]=' ';
				tiro->tiro=' ';
				m[I2->posl][I2->posc]=I2->pos;
				if (tiro->tiro==' '){
    		    	k2=0;
				}
			}
			if(m[I2->posl][k2-1]==pi){
		   	  	m[I2->posl][k2-1]=pi;
				m[I2->posl][k2]=' ';
				tiro->tiro=' ';
				m[I2->posl][I2->posc]=I2->pos;
				if (tiro->tiro==' '){
    	        	k2=0;
				}
			}   	
		  	if (m[I2->posl][k2-1]==I1->pos || m[I2->posl][k2-1]==tap->repre){ 
		  		if (m[I2->posl][k2-1]==I1->pos){
				 	m[I1->posl][I1->posc]=' ';
				 	I1->posl = 1;
				 	I1->posc = 1;
				}else if (m[I2->posl][k2-1]==tap->repre){
				 	m[I2->posl][I2->posc]=' ';
				 	tap->posl = 11;
				 	tap->posc = 7;
				 	*vidas = *vidas -1;
				}
				m[I2->posl][k2-1]=' ';
				m[I2->posl][k2]=' ';
				tiro->tiro=' ';	
				m[I2->posl][I2->posc]=I2->pos;
					if (tiro->tiro==' '){
    		    		k2=0;
					}
		   	}		
			m[I2->posl][k2-1]='*';
			if (m[I2->posl][k2]!=I2->pos){
				m[I2->posl][k2]=' ';
			}
			m[I2->posl-1][12]=' ';
			system("cls");		
			imprimir(m);
			printf ("\n");
		}
		renovBordas(m);
	}
	
	if (*diretiroI2=='w'){					//=======CIMA=======/
		for (k2=I2->posl; k2>0; k2--){
			if (m[k2-1][I2->posc]==p){ 
				m[k2-1][I2->posc]=' ';
				m[k2][I2->posc]=' ';
				tiro->tiro=' ';
				m[I2->posl][I2->posc]=I2->pos;
				if (tiro->tiro==' '){
    		    	k2=0;
				}
		   	}
			if(m[k2-1][I2->posc]==pi){
		   	  	m[k2-1][I2->posc]=pi;
				m[k2][I2->posc]=' ';
				tiro->tiro=' ';
				m[I2->posl][I2->posc]=I2->pos;
				if (tiro->tiro==' '){
    	       		k2=-1;
				}
			}    	
		   	if (m[k2-1][I2->posc]==I1->pos || m[k2-1][I2->posc]==tap->repre){
		   	  	if (m[k2-1][I2->posc]==I1->pos){
				 	m[I1->posl][I1->posc]=' ';
				 	I1->posl = 1;
				 	I1->posc = 1;
				}else if (m[k2-1][I2->posc]==tap->repre){
				 	m[I2->posl][I2->posc]=' ';
				 	tap->posl = 11;
				 	tap->posc = 7;
				 	*vidas = *vidas -1;
				}
				m[k2-1][I2->posc]=' ';
				m[k2][I2->posc]=' ';
				tiro->tiro=' ';
				m[I2->posl][I2->posc]=I2->pos;
				if (tiro->tiro==' '){
    		   		k2=-1;
				}
		   	}		
			m[k2-1][I2->posc]='*';
			if (m[k2][I2->posc]!=I2->pos){
				m[k2][I2->posc]=' ';
			}
			m[1][4]=' ';
			system("cls");	
			imprimir(m);
			printf ("\n");	
		}
		renovBordas(m);
	}
	
	if (*diretiroI2=='s'){					//=======BAIXO======/				
		for (k2=I2->posl; k2<14; k2++){	
			if (m[k2+1][I2->posc]==p){ 
				m[k2+1][I2->posc]=' ';
				m[k2][I2->posc]=' ';
				tiro->tiro=' ';
				m[I2->posl][I2->posc]=I2->pos;
				if (tiro->tiro==' '){
    			    k2=14;
				}
		   	}	
		   	if(m[k2+1][I2->posc]==pi){
		   	  	m[k2+1][I2->posc]=pi;
				m[k2][I2->posc]=' ';
				tiro->tiro=' ';
				m[I2->posl][I2->posc]=I2->pos;
				if (tiro->tiro==' '){
    	        	k2=14;
				}
			}   
		   	if (m[k2+1][I2->posc]==I1->pos || m[k2+1][I2->posc]==tap->repre){ 	
		   		if (m[k2+1][I2->posc]==I1->pos){
				 	m[I1->posl][I1->posc]=' ';
				 	I1->posl = 1;
				 	I1->posc = 1;
				}else if (m[k2+1][I2->posc]==tap->repre){
				 	m[I2->posl][I2->posc]=' ';
				 	tap->posl = 11;
				 	tap->posc = 7;
				 	*vidas = *vidas -1;
				}
				m[k2+1][I2->posc]=' ';
				m[k2][I2->posc]=' ';
				tiro->tiro=' ';
				m[I2->posl][I2->posc]=I2->pos;
				if (tiro->tiro==' '){
    			  	k2=14;
				}
		   	}	
			m[k2+1][I2->posc]='*';
			if (m[k2][I2->posc]!=I2->pos){
				m[k2][I2->posc]=' ';
			}
			m[1][4]=' ';
			system("cls");		
			imprimir(m);
			printf ("\n");
		}
		renovBordas(m);
	}
	
}
void MovInimigoAleatorio(char m[][15], Jogador *tap, Inimigo *I1, Inimigo *I2, Tiro *tiro, char *diretiroI1, char *diretiroI2,int *vidas){
	char pi,p,pb;
	int aleatorio1,aleatorio2;
	
	pi = 219;
	p = 177;
	pb=178;

	srand(time(NULL));
	aleatorio1=rand()%4;
	aleatorio2=rand()%4;
	
	
//============================ INIMIGO 2 =======================================/
	/*			*diretiro = 'd';
				tap->repre= 204;
				m[tap->posl][tap->posc]=tap->repre;
				*/
		
			
		if(aleatorio2==0){
				if (m[I2->posl][I2->posc-1]!=pi && m[I2->posl][I2->posc-1]!=tap->repre && m[I2->posl][I2->posc-1]!=I1->pos && m[I2->posl][I2->posc-1]!=pb){
				I2->pos = '<';
				m[I2->posl][I2->posc]=' ';
				m[I2->posl][I2->posc-1]=I2->pos;
				I2->posc = I2->posc-1;
				*diretiroI2 = 'a';
		}
				else if (m[I2->posl][I2->posc-1] == p){
					I2->pos = '<';
					tirodoInimigo2 (m,tap,I1,I2,tiro,diretiroI1, diretiroI2, vidas);
					m[I2->posl][I2->posc]=I2->pos;
					*diretiroI2 = 'a';
				}
				else if(m[I2->posl][I2->posc-1] == pi && m[I2->posl][I2->posc-1] != pb){
					I2->pos = 'V';
					m[I2->posl][I2->posc]=' ';
					m[I2->posl+1][I2->posc]=I2->pos;
					*diretiroI2 = 's';
					
					
				}
				else {
					m[I2->posl][I2->posc]=I2->pos;
				}
		}
	
		
		if(aleatorio2==1){
				if (m[I2->posl][I2->posc+1]!=pi && m[I2->posl][I2->posc+1]!=tap->repre && m[I2->posl][I2->posc+1]!=I2->pos && m[I2->posl][I2->posc+1]!=pb){
				I2->pos = '>';
				m[I2->posl][I2->posc]=' ';
				m[I2->posl][I2->posc+1]=I2->pos;
					I2->posc = I2->posc+1;
					*diretiroI2 = 'd';
				}
				
				else if (m[I2->posl][I2->posc+1] == p){
					I2->pos = '>';
					tirodoInimigo2 (m,tap,I1,I2,tiro,diretiroI1, diretiroI2, vidas);
					m[I2->posl][I2->posc]=I2->pos;
					*diretiroI2 = 'd';

				}
				else if(m[I2->posl][I2->posc+1] == pi && m[I2->posl][I2->posc+1] != pb){
					I2->pos = '^';
					m[I2->posl][I2->posc]=' ';
					m[I2->posl-1][I2->posc]=I2->pos;
					I2->pos = I2->posc;
					*diretiroI2 = 'w';
				}
				else{
					m[I2->posl][I2->posc]=I2->pos;	
				}
			}
			
		
		
	
		
		if(aleatorio2==2){
			
			
				if(m[I2->posl-1][I2->posc]!=pi && m[I2->posl-1][I2->posc]!=tap->repre && m[I2->posl-1][I2->posc]!=I2->pos && m[I2->posl-1][I2->posc]!=pb){
				I2->pos = '<';
				m[I2->posl][I2->posc]=' ';
				m[I2->posl-1][I2->posc]=I2->pos;
					I2->posl = I2->posl-1;
					*diretiroI2 = 'a';
				}
				//tiro de novo
				else if (m[I2->posl-1][I2->posc] == p){
					I2->pos = '<';
					tirodoInimigo2 (m,tap,I1,I2,tiro,diretiroI1, diretiroI2, vidas);
					m[I2->posl][I2->posc]=I2->pos;
					*diretiroI2 = 'a';

				}
				else if(m[I2->posl][I2->posc-1] == pi && m[I2->posl][I2->posc-1] != pi){
					I2->pos = '>';
					m[I2->posl][I2->posc]=' ';
					m[I2->posl][I2->posc+1]=I2->pos;
					I2->pos = I2->posc;
					*diretiroI2 = 'd';
				}
				else{
					m[I2->posl][I2->posc]=I2->pos;
				}
			}
			
		if(aleatorio2==3){
			
			
			   if(m[I2->posl+1][I2->posc]!=pi && m[I2->posl+1][I2->posc]!=tap->repre && m[I2->posl+1][I2->posc]!=I2->pos && m[I2->posl+1][I2->posc]!=pb){
			   		I2->pos = 'V';
					m[I2->posl][I2->posc]=' ';
					m[I2->posl+1][I2->posc]=I2->pos;
						I2->posl = I2->posl+1;
						*diretiroI2 = 's';
				}
				//tiro de novo
				else if (m[I2->posl-1][I2->posc] == p){
					I2->pos = '^';
					tirodoInimigo2 (m,tap,I1,I2,tiro,diretiroI1, diretiroI2, vidas);
					m[I2->posl][I2->posc]=I2->pos;
					*diretiroI2 = 'w';
					
				}
				else if(m[I2->posl][I2->posc-1] == pi && m[I2->posl][I2->posc-1] == pb){
					I2->pos = '<';
					m[I2->posl][I2->posc]=' ';
					m[I2->posl][I2->posc-1]=I2->pos;
						I2->pos = I2->posc;
						*diretiroI2 = 'a';
				}
				else{
					m[I2->posl][I2->posc]=I2->pos;
				}
			}
			
			//=======================Inimigo 1=======================/
			if(aleatorio2==0){
				if (m[I1->posl][I1->posc-1]!=pi && m[I1->posl][I1->posc-1]!=tap->repre && m[I1->posl][I1->posc-1]!=I1->pos && m[I1->posl][I1->posc-1]!=pb){
				I1->pos = 180;
				m[I1->posl][I1->posc]=' ';
				m[I1->posl][I1->posc-1]=I1->pos;
				I1->posc = I1->posc-1;
				*diretiroI1 = 'a';	
		}
				else if (m[I1->posl][I1->posc-1] == p){
					I1->pos = 180;
					tirodoInimigo1 (m,tap,I1,I2,tiro,diretiroI1, diretiroI2, vidas);
					m[I1->posl][I1->posc]=I1->pos;
					*diretiroI1 = 'a';
				}
				else if(m[I1->posl][I1->posc-1] == pi && m[I1->posl][I1->posc-1] != pb){
					I1->pos = 194;
					m[I1->posl][I1->posc]=' ';
					m[I1->posl+1][I1->posc]=I1->pos;
					*diretiroI1 = 's';
					
				}
				else {
					m[I1->posl][I1->posc]=I1->pos;
				}
		}
	
		
		if(aleatorio2==1){
			if (m[I1->posl][I1->posc+1]!=pi && m[I1->posl][I1->posc+1]!=tap->repre && m[I1->posl][I1->posc+1]!=I1->pos && m[I1->posl][I1->posc+1]!=pb){
				I1->pos = 195;
				m[I1->posl][I1->posc]=' ';
				m[I1->posl][I1->posc+1]=I1->pos;
					I1->posc = I1->posc+1;
					*diretiroI1 = 'd';
				}
				
				else if (m[I1->posl][I1->posc+1] == p){
					I1->pos = 195;
					tirodoInimigo1 (m,tap,I1,I2,tiro,diretiroI1, diretiroI2, vidas);
					m[I1->posl][I1->posc]=I1->pos;
					*diretiroI1 = 'd';
				}
				else if(m[I1->posl][I1->posc+1] == pi && m[I1->posl][I1->posc+1] != pb){
					I1->pos = 193;
					m[I1->posl][I1->posc]=' ';
					m[I1->posl-1][I1->posc]=I1->pos;
					I1->pos = I1->posc;
					*diretiroI1 = 'w';
				}
				else{
					m[I1->posl][I1->posc]=I1->pos;	
				}
			}
			
		
		
	
		
		if(aleatorio2==2){
			if(m[I1->posl-1][I1->posc]!=pi && m[I1->posl-1][I1->posc]!=tap->repre && m[I1->posl-1][I1->posc]!=I1->pos && m[I1->posl-1][I1->posc]!=pb){
				I1->pos = 193;
				m[I1->posl][I1->posc]=' ';
				m[I1->posl-1][I1->posc]=I1->pos;
					I1->posl = I1->posl-1;
					*diretiroI1 = 'w';
				}
				//tiro de novo
				else if (m[I1->posl-1][I1->posc] == p){
					I1->pos = 193;
					tirodoInimigo1 (m,tap,I1,I2,tiro,diretiroI1, diretiroI2, vidas);
					m[I1->posl][I1->posc]=I1->pos;
					*diretiroI1 = 'w';
				}
				else if(m[I1->posl][I1->posc-1] == pi && m[I1->posl][I1->posc-1] != pi){
					I1->pos = 195;
					m[I1->posl][I1->posc]=' ';
					m[I1->posl][I1->posc+1]=I1->pos;
					I1->pos = I1->posc;
					*diretiroI1 = 'd';
				}
				else{
					m[I1->posl][I1->posc]=I1->pos;
				}
			}
			
		if(aleatorio2==3){
			
			
			   if(m[I1->posl+1][I1->posc]!=pi && m[I1->posl+1][I1->posc]!=tap->repre && m[I1->posl+1][I1->posc]!=I1->pos && m[I1->posl+1][I1->posc]!=pb){
			   		I1->pos = 194;
					m[I1->posl][I1->posc]=' ';
					m[I1->posl+1][I1->posc]=I1->pos;
						I1->posl = I1->posl+1;
						*diretiroI1 = 's';
				}
				//tiro de novo
				else if (m[I1->posl-1][I1->posc] == p){
					I1->pos = 194;
					tirodoInimigo1 (m,tap,I1,I2,tiro,diretiroI1, diretiroI2, vidas);
					m[I1->posl][I1->posc]=I1->pos;
					*diretiroI1 = 's';	
				}
				else if(m[I1->posl][I1->posc-1] == pi && m[I1->posl][I1->posc-1] == pb){
					I1->pos = 180;
					m[I1->posl][I1->posc]=' ';
					m[I1->posl][I1->posc-1]=I1->pos;
					I1->pos = I1->posc;
					*diretiroI1 = 'a';	
				}
				else{
					m[I1->posl][I1->posc]=I1->pos;
				}
			}
		}				
void MovInimigoInteligente(char m[][15], Jogador *tap, Inimigo *I1, Inimigo *I2, Tiro *tiro, char *diretiroI1, char *diretiroI2,int *vidas){
	char pi,p,pb;
	
	pi = 219;
	p = 177;
	pb=178;

//============================ INIMIGO 1 =======================================/
	I2->contl=0;
	I2->contc=0;
	I2->poslcont= I2->posl;
	I2->posccont=I2->posc;
	
	//contador para jogada inteligente.
		if(tap->posl>I2->poslcont){
			while(I2->poslcont!=tap->posl){
				I2->poslcont = I2->poslcont +1;
				I2->contl = I2->contl +1;
			}
		}
		else{
			while(I2->poslcont!=tap->posl){
				I2->poslcont = I2->poslcont-1;
				I2->contl = I2->contl+1;
			}
		}
		if(tap->posc>I2->posccont){
			while(I2->posccont!=tap->posc){
				I2->posccont = I2->posccont +1;
				I2->contc = I2->contc +1;
			}
		}
		else{
			while(I2->posccont!=tap->posc){
				I2->posccont = I2->posccont-1;
				I2->contc = I2->contc+1;
			}
		}
	//Movimentação utilizando o contador inteligente
	
	
	//Caso o distancia de linhas seja maior do que a de colunas, ele vai fazer o movimento pela coluna
		if(I2->contl>I2->contc){
			//Caso a posição da coluna do inimigo seja maior do que a do tanque principal, ele vai "voltar" uma coluna
			if(I2->posc>tap->posc){
				if (m[I2->posl][I2->posc-1]!=pi && m[I2->posl][I2->posc-1]!=tap->repre && m[I2->posl][I2->posc-1]!=I2->pos && m[I2->posl][I2->posc-1]!=pb){
				I2->pos = '<';
				m[I2->posl][I2->posc]=' ';
				m[I2->posl][I2->posc-1]=I2->pos;
				I2->posc = I2->posc-1;	
				*diretiroI2 = 'a';
			}
			// nessa parte entraria o tiro, ao invez desse movimento aleatório, ele ia quebrar a parede
				else if (m[I2->posl][I2->posc-1] == p){
					I2->pos = '<';
					tirodoInimigo2 (m,tap,I1,I2,tiro,diretiroI1, diretiroI2, vidas);
					m[I2->posl][I2->posc]=I2->pos;
					*diretiroI2 = 'a';
				}
				else if(m[I2->posl][I2->posc-1] == pi && m[I2->posl][I2->posc-1] != pb){
					I2->pos = 'V';
					m[I2->posl][I2->posc]=' ';
					m[I2->posl+1][I2->posc]=I2->pos;
					*diretiroI2 = 's';
					
				}
				else {
					m[I2->posl][I2->posc]=I2->pos;
				}
		}
		//Aqui já é caso a coluna do inimigo seja menor, então ele vai andar uma coluna pra se aproximar do inimigo
			else{
				if (m[I2->posl][I2->posc+1]!=pi && m[I2->posl][I2->posc+1]!=tap->repre && m[I2->posl][I2->posc+1]!=I2->pos && m[I2->posl][I2->posc+1]!=pb){
				I2->pos = '>';
				m[I2->posl][I2->posc]=' ';
				m[I2->posl][I2->posc+1]=I2->pos;
					I2->posc = I2->posc+1;
					*diretiroI2 = 'd';
				}
				// parte do tiro de novo
				else if (m[I2->posl][I2->posc+1] == p){
					I2->pos = '>';
					tirodoInimigo2 (m,tap,I1,I2,tiro,diretiroI1, diretiroI2, vidas);
					m[I2->posl][I2->posc]=I2->pos;
					*diretiroI2 = 'd';
				}
				else if(m[I2->posl][I2->posc+1] == pi && m[I2->posl][I2->posc+1] != pb){
					I2->pos = '^';
					m[I2->posl][I2->posc]=' ';
					m[I2->posl-1][I2->posc]=I2->pos;
					I2->pos = I2->posc;
					*diretiroI2 = 'w';
				}
				else{
					m[I2->posl][I2->posc]=I2->pos;	
				}
			}
			
		
		}
	//Caso andar pelas linhas seja a opção mais curta
		else{
			//Caso o inimigo esteja numa posição de linha maior que a do tanque principal, ele vai voltar a linha
			if(I2->posl>tap->posl){
				if(m[I2->posl-1][I2->posc]!=pi && m[I2->posl-1][I2->posc]!=tap->repre && m[I2->posl-1][I2->posc]!=I2->pos && m[I2->posl-1][I2->posc]!=pb){
				I2->pos = '^';
				m[I2->posl][I2->posc]=' ';
				m[I2->posl-1][I2->posc]=I2->pos;
					I2->posl = I2->posl-1;
					*diretiroI2 = 'w';
				}
				//tiro de novo
				else if (m[I2->posl-1][I2->posc] == p){
					I2->pos = '^';
					tirodoInimigo2 (m,tap,I1,I2,tiro,diretiroI1, diretiroI2, vidas);
					m[I2->posl][I2->posc]=I2->pos;
					*diretiroI2 = 'w';

				}
				else if(m[I2->posl][I2->posc-1] == pi && m[I2->posl][I2->posc-1] != pi){
					I2->pos = '>';
					m[I2->posl][I2->posc]=' ';
					m[I2->posl][I2->posc+1]=I2->pos;
					I2->pos = I2->posc;
					*diretiroI2 = 'd';
				}
				else{
					m[I2->posl][I2->posc]=I2->pos;
				}
			}
			//Aqui é caso o inimigo esteja numa linha menor do que a do tanque principal, ele vai avançar uma linha
			else{
			   if(m[I2->posl+1][I2->posc]!=pi && m[I2->posl+1][I2->posc]!=tap->repre && m[I2->posl+1][I2->posc]!=I2->pos && m[I2->posl+1][I2->posc]!=pb){
			   		I2->pos = 'V';
					m[I2->posl][I2->posc]=' ';
					m[I2->posl+1][I2->posc]=I2->pos;
						I2->posl = I2->posl+1;
						*diretiroI2 = 's';
				}
				//tiro de novo
				else if (m[I2->posl-1][I2->posc] == p){
					I2->pos = '^';
					tirodoInimigo2 (m,tap,I1,I2,tiro,diretiroI1, diretiroI2, vidas);
					m[I2->posl][I2->posc]=I2->pos;
					*diretiroI2 = 'w';
				}
				else if(m[I2->posl][I2->posc-1] == pi && m[I2->posl][I2->posc-1] == pb){
					I2->pos = '<';
					m[I2->posl][I2->posc]=' ';
					m[I2->posl][I2->posc-1]=I2->pos;
						I2->pos = I2->posc;
						*diretiroI2 = 'a';
				}
				else{
					m[I2->posl][I2->posc]=I2->pos;
				}
			}
		}
	
	
		//zerando os contares inteligentes para poder reutiliza-los->
		I2->contl=0;
		I2->contc=0;
		
//====================================INIMIGO 2==================================\		
	I1->contl=0;
	I1->contc=0;
	I1->poslcont= I1->posl;
	I1->posccont=I1->posc;
	
	//contador para jogada inteligente.
		if(tap->posl>I1->poslcont){
			while(I1->poslcont!=tap->posl){
				I1->poslcont = I1->poslcont +1;
				I1->contl = I1->contl +1;
			}
		}
		else{
			while(I1->poslcont!=tap->posl){
				I1->poslcont = I1->poslcont-1;
				I1->contl = I1->contl+1;
			}
		}
		if(tap->posc>I1->posccont){
			while(I1->posccont!=tap->posc){
				I1->posccont = I1->posccont +1;
				I1->contc = I1->contc +1;
			}
		}
		else{
			while(I1->posccont!=tap->posc){
				I1->posccont = I1->posccont-1;
				I1->contc = I1->contc+1;
			}
		}
	//Movimentação utilizando o contador inteligente
	
	
	//Caso o distancia de linhas seja maior do que a de colunas, ele vai fazer o movimento pela coluna
		if(I1->contl>I1->contc){
			//Caso a posição da coluna do inimigo seja maior do que a do tanque principal, ele vai "voltar" uma coluna
			if(I1->posc>tap->posc){
				if (m[I1->posl][I1->posc-1]!=pi && m[I1->posl][I1->posc-1]!=tap->repre && m[I1->posl][I1->posc-1]!=I1->pos && m[I1->posl][I1->posc-1]!=pb){
				I1->pos = 180;
				m[I1->posl][I1->posc]=' ';
				m[I1->posl][I1->posc-1]=I1->pos;
				I1->posc = I1->posc-1;	
				*diretiroI1 = 'a';
			}
			// nessa parte entraria o tiro, ao invez desse movimento aleatório, ele ia quebrar a parede
				else if (m[I1->posl][I1->posc-1] == p){
					I1->pos = 180;
					tirodoInimigo1 (m,tap,I1,I2,tiro,diretiroI1, diretiroI2, vidas);
					m[I1->posl][I1->posc]=I1->pos;
					*diretiroI1 = 'a';
				}
				else if(m[I1->posl][I1->posc-1] == pi && m[I1->posl][I1->posc-1] != pb){
					I1->pos = 194;
					m[I1->posl][I1->posc]=' ';
					m[I1->posl+1][I1->posc]=I1->pos;
					*diretiroI1 = 's';
				}
				else {
					m[I1->posl][I1->posc]=I1->pos;
				}
		}
		//Aqui já é caso a coluna do inimigo seja menor, então ele vai andar uma coluna pra se aproximar do inimigo
			else{
				if (m[I1->posl][I1->posc+1]!=pi && m[I1->posl][I1->posc+1]!=tap->repre && m[I1->posl][I1->posc+1]!=I1->pos && m[I1->posl][I1->posc+1]!=pb){
				I1->pos = 195;
				m[I1->posl][I1->posc]=' ';
				m[I1->posl][I1->posc+1]=I1->pos;
					I1->posc = I1->posc+1;
					*diretiroI1 = 'd';
				}
				// parte do tiro de novo
				else if (m[I1->posl][I1->posc+1] == p){
					I1->pos = 195;
					tirodoInimigo1 (m,tap,I1,I2,tiro,diretiroI1, diretiroI2, vidas);
					m[I1->posl][I1->posc]=I1->pos;
					*diretiroI1 = 'd';
				}
				else if(m[I1->posl][I1->posc+1] == pi && m[I1->posl][I1->posc+1] != pb){
					I1->pos = 193;
					m[I1->posl][I1->posc]=' ';
					m[I1->posl-1][I1->posc]=I1->pos;
					I1->pos = I1->posc;
					*diretiroI1 = 'w';
				}
				else{
					m[I1->posl][I1->posc]=I1->pos;	
				}
			}
			
		
		}
	//Caso andar pelas linhas seja a opção mais curta
		else{
			//Caso o inimigo esteja numa posição de linha maior que a do tanque principal, ele vai voltar a linha
			if(I1->posl>tap->posl){
				if(m[I1->posl-1][I1->posc]!=pi && m[I1->posl-1][I1->posc]!=tap->repre && m[I1->posl-1][I1->posc]!=I1->pos && m[I1->posl-1][I1->posc]!=pb){
					I1->pos = 193;
					m[I1->posl][I1->posc]=' ';
					m[I1->posl-1][I1->posc]=I1->pos;
					I1->posl = I1->posl-1;
					*diretiroI1 = 'w';
				}
				//tiro de novo
				else if (m[I1->posl-1][I1->posc] == p){
					I1->pos = 193;
					tirodoInimigo1 (m,tap,I1,I2,tiro,diretiroI1, diretiroI2, vidas);
					m[I1->posl][I1->posc]=I1->pos;
					*diretiroI1 = 'w';
				}
				else if(m[I1->posl][I1->posc-1] == pi && m[I1->posl][I1->posc-1] != pi){
					I1->pos = 195;
					m[I1->posl][I1->posc]=' ';
					m[I1->posl][I1->posc+1]=I1->pos;
					I1->pos = I1->posc;
					*diretiroI1 = 'd';
				}
				else{
					m[I1->posl][I1->posc]=I1->pos;
				}
			}
			//Aqui é caso o inimigo esteja numa linha menor do que a do tanque principal, ele vai avançar uma linha
			else{
			   if(m[I1->posl+1][I1->posc]!=pi && m[I1->posl+1][I1->posc]!=tap->repre && m[I1->posl+1][I1->posc]!=I1->pos && m[I1->posl+1][I1->posc]!=pb){
			   		I1->pos = 194;
					m[I1->posl][I1->posc]=' ';
					m[I1->posl+1][I1->posc]=I1->pos;
					I1->posl = I1->posl+1;
					*diretiroI1 = 's';
				}
				//tiro de novo
				else if (m[I1->posl-1][I1->posc] == p){
					I1->pos = 193;
					tirodoInimigo1 (m,tap,I1,I2,tiro,diretiroI1, diretiroI2, vidas);
					m[I1->posl][I1->posc]=I1->pos;
					*diretiroI1 = 'w';
				}
				else if(m[I1->posl][I1->posc-1] == pi && m[I1->posl][I1->posc-1] == pb){
					I1->pos = 180;
					m[I1->posl][I1->posc]=' ';
					m[I1->posl][I1->posc-1]=I1->pos;
					I1->pos = I1->posc;
					*diretiroI1 = 'a';
				}
				else{
					m[I1->posl][I1->posc]=I1->pos;
				}
			}
		}
	
	
		//zerando os contares inteligentes para poder reutiliza-los->
		I1->contl=0;
		I1->contc=0;
}
int atirar(char m[][15],Jogador *tap,char *pa,char *diretiro,Tiro *tiro,Inimigo *I1, Inimigo *I2, int *pontos,int *contmorte){
	int k;
	char pi,p,t=2;
	pi = 219;
	p = 177;
	int morte = 0;
	
			if (*diretiro=='d'){					//=======DIREITA====/
				for (k=tap->posc; k<14 ;k++){
		   		if (m[tap->posl][k+1]==p){ 
					  m[tap->posl][k+1]=' ';
					  m[tap->posl][k]=' ';
				    tiro->tiro=' ';
				    m[tap->posl][tap->posc]=tap->repre;
					  if (tiro->tiro==' '){
    	  	    k=14;
					  }
		   	  }
		   	  if(m[tap->posl][k+1]==pi){
		   	  	m[tap->posl][k+1]=pi;
					  m[tap->posl][k]=' ';
				    tiro->tiro=' ';
				    m[tap->posl][tap->posc]=tap->repre;
				    if (tiro->tiro==' '){
    	        k=14;
					  }
					}
		   	  	if (m[tap->posl][k+1]==I1->pos || m[tap->posl][k+1]==I2->pos){
				 	if (m[tap->posl][k+1]==I1->pos){
				 		m[I1->posl][I1->posc]=' ';
				 		I1->posl = 1;
				 		I1->posc = 1;
				 		*contmorte = *contmorte+1;
				 		morte = 1;
					 }else if (m[tap->posl][k+1]==I2->pos){
				 		m[I2->posl][I2->posc]=' ';
				 		I2->posl = 1;
				 		I2->posc = 13;
				 		*contmorte = *contmorte+1;
				 		morte = 1;
					 } 
					  m[tap->posl][k+1]=' ';
					  m[tap->posl][k]=' ';
				    tiro->tiro=' ';
				    m[tap->posl][tap->posc]=tap->repre;
					  if (tiro->tiro==' '){
    		 	    k=14;
					  }
					  
					   
		   	 	 }
					if(m[tap->posl][k]!=tap->repre){
						m[tap->posl][k]=' ';		
					}
					m[tap->posl][k+1]='*'; //O tiro anda :o
					system("cls");		
					imprimir(m);
					printf ("\n");
					m[tap->posl][tap->posc]=tap->repre;
				}
			
				renovBordas(m);
			}
			if (*diretiro=='a'){					//=======ESQUERDA===/
				for (k=tap->posc; k>0; k--){
					if (m[tap->posl][k-1]==p){ 
						m[tap->posl][k-1]=' ';
						m[tap->posl][k]=' ';
					  tiro->tiro=' ';
					  m[tap->posl][tap->posc]=tap->repre;
						if (tiro->tiro==' '){
    		    	k=0;
						}
					}
					if(m[tap->posl][k-1]==pi){
		   	  	m[tap->posl][k-1]=pi;
					  m[tap->posl][k]=' ';
				    tiro->tiro=' ';
				    m[tap->posl][tap->posc]=tap->repre;
				    if (tiro->tiro==' '){
    	        k=0;
					  }
					}   	
		  		if (m[tap->posl][k-1]==I1->pos || m[tap->posl][k-1]==I2->pos){ 
		  			if (m[tap->posl][k-1]==I1->pos){
				 		m[I1->posl][I1->posc]=' ';
				 		I1->posl = 1;
				 		I1->posc = 1;
				 		*contmorte = *contmorte+1;
				 		morte = 1;
					 }else if (m[tap->posl][k-1]==I2->pos){
				 		m[I2->posl][I2->posc]=' ';
				 		I2->posl = 1;
				 		I2->posc = 13;
				 		*contmorte = *contmorte+1;
					 }
						m[tap->posl][k-1]=' ';
						m[tap->posl][k]=' ';
				    tiro->tiro=' ';	
				    m[tap->posl][tap->posc]=tap->repre;
						if (tiro->tiro==' '){
    		    		k=0;
						}
						

		   	  }		
					m[tap->posl][k-1]='*';
					if (m[tap->posl][k]!=tap->repre){
						m[tap->posl][k]=' ';
					}
			    m[tap->posl-1][12]=' ';
					system("cls");		
					imprimir(m);
					printf ("\n");
				}
				renovBordas(m);
			}
			if (*diretiro=='w'){					//=======CIMA=======/
				for (k=tap->posl; k>0; k--){
					if (m[k-1][tap->posc]==p){ 
						m[k-1][tap->posc]=' ';
						m[k][tap->posc]=' ';
				    tiro->tiro=' ';
				    m[tap->posl][tap->posc]=tap->repre;
						if (tiro->tiro==' '){
    		    	k=0;
						}
		   		}
					if(m[k-1][tap->posc]==pi){
		   	  	m[k-1][tap->posc]=pi;
					  m[k][tap->posc]=' ';
				    tiro->tiro=' ';
				    m[tap->posl][tap->posc]=tap->repre;
				    if (tiro->tiro==' '){
    	        k=-1;
					  }
					}    	
		   	  if (m[k-1][tap->posc]==I1->pos || m[k-1][tap->posc]==I2->pos){
		   	  		if (m[k-1][tap->posc]==I1->pos){
				 		m[I1->posl][I1->posc]=' ';
				 		I1->posl = 1;
				 		I1->posc = 1;
				 		*contmorte = *contmorte+1;
				 		morte = 1;
					 }else if (m[k-1][tap->posc]==I2->pos){
				 		m[I2->posl][I2->posc]=' ';
				 		I2->posl = 1;
				 		I2->posc = 13;
				 		*contmorte = *contmorte+1;
				 		morte = 1;
					 }
						m[k-1][tap->posc]=' ';
						m[k][tap->posc]=' ';
					  tiro->tiro=' ';
					  m[tap->posl][tap->posc]=tap->repre;
						if (tiro->tiro==' '){
    		   		k=-1;
						}
						
		   	  }		
					m[k-1][tap->posc]='*';
					if (m[k][tap->posc]!=tap->repre){
						m[k][tap->posc]=' ';
					}
					m[1][4]=' ';
					system("cls");	
					imprimir(m);
					printf ("\n");	
				}
				renovBordas(m);
			}
			if (*diretiro=='s'){					//=======BAIXO======/				
				for (k=tap->posl; k<14; k++){	
					if (m[k+1][tap->posc]==p){ 
						m[k+1][tap->posc]=' ';
						 m[k][tap->posc]=' ';
					  tiro->tiro=' ';
					  m[tap->posl][tap->posc]=tap->repre;
						if (tiro->tiro==' '){
    			    k=14;
						}
		   		}	
		   		if(m[k+1][tap->posc]==pi){
		   	  	m[k+1][tap->posc]=pi;
					  m[k][tap->posc]=' ';
				    tiro->tiro=' ';
				    m[tap->posl][tap->posc]=tap->repre;
				    if (tiro->tiro==' '){
    	        k=14;
					  }
					}   
		   		if (m[k+1][tap->posc]==I1->pos || m[k+1][tap->posc]==I2->pos){ 	
		   			if (m[k+1][tap->posc]==I1->pos){
				 		m[I1->posl][I1->posc]=' ';
				 		I1->posl = 1;
				 		I1->posc = 1;
				 		morte = 1;
				 		*contmorte = *contmorte+1;
					 }else if (m[k+1][tap->posc]==I2->pos){
				 		m[I2->posl][I2->posc]=' ';
				 		I2->posl = 1;
				 		I2->posc = 13;
				 		*contmorte = *contmorte+1;
				 		morte = 1;
					 }
						m[k+1][tap->posc]=' ';
						m[k][tap->posc]=' ';
					  tiro->tiro=' ';
					  m[tap->posl][tap->posc]=tap->repre;
						if (tiro->tiro==' '){
    			  	k=14;
						}
						*pontos=*pontos+10;
		   		}	
					m[k+1][tap->posc]='*';
					if (m[k][tap->posc]!=tap->repre){
						m[k][tap->posc]=' ';
					}
					m[1][4]=' ';
					system("cls");		
					imprimir(m);
					printf ("\n");
				}
				renovBordas(m);
			}
			return morte;
	  } 	
void andar(char m[][15],Jogador *tap,char *pa,char *diretiro){
	char pi,p,t=2;
	pi = 219;
	p = 177;

	if(*pa == 'd'){	
					//=======DIREITA====/
				*diretiro = 'd';
				tap->repre= 204;
				m[tap->posl][tap->posc]=tap->repre;
			if (m[tap->posl][tap->posc+1]!=pi && m[tap->posl][tap->posc+1]!=p){
				if(tap->posc<13){//>>>>>>>>>>>>>>>>>>>>>>>>>>>Não deixa o tanque sair da tela/
					m[tap->posl][tap->posc] = ' ';//>>>>>>>>>>>>>A posição anterior do tanque continuar com ponto/
					m[tap->posl][tap->posc+1] = tap->repre;
					tap->posc = tap->posc+1;		
				}
			}
		}
		if(*pa == 'a'){
		tap->repre= 185;
		*diretiro = 'a';
		m[tap->posl][tap->posc]=tap->repre;				//=======ESQUERDA===/
			if (m[tap->posl][tap->posc-1]!=pi && m[tap->posl][tap->posc-1]!=p){	
				if(tap->posc>1){   
					m[tap->posl][tap->posc] = ' ';  
					m[tap->posl][tap->posc-1] = tap->repre;
					tap->posc = tap->posc-1;
						
				}
			}
		}
		if(*pa == 'w'){
		tap->repre= 202;
		*diretiro = 'w';
		m[tap->posl][tap->posc]=tap->repre;			
		                             	//=======CIMA=======/
			if (m[tap->posl-1][tap->posc]!=pi && m[tap->posl-1][tap->posc]!=p){		
				if(tap->posl>1){  
					m[tap->posl][tap->posc] = ' ';  
					m[tap->posl-1][tap->posc] = tap->repre;
					tap->posl = tap->posl-1;	
					
				}
			}
		}
		if(*pa == 's'){
		tap->repre= 203;
		*diretiro = 's';
		m[tap->posl][tap->posc]=tap->repre;			//=======BAIXO======/
			if (m[tap->posl+1][tap->posc]!=pi && m[tap->posl+1][tap->posc]!=p){	
				if(tap->posl<13){  
					m[tap->posl][tap->posc] = ' ';  
					m[tap->posl+1][tap->posc] = tap->repre;
					tap->posl = tap->posl+1;
							
				}
			}
		}
	
  	system("cls");//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>Limpa>>>/
}
void imprimir(char m[][15]){
	int i,j;
	
	for(i=0;15>i;i++){
		for (j=0;15>j;j++){
			printf("%c", m[i][j]);    
		}
		printf("\n");
        }
	
}
void borda(char m[][15]){
	int i,j;
	
	for (i=0;15>i;i++){
		for (j=0;15>j;j++){
			m[i][j]=' ';
		}
	}
	
	for(i=0;i<15;i++){
		j = 0;
		m[i][j]=178;
	}
	for(i=0;i<15;i++){
		j = 14;
		m[i][j]=178;
	}
	for(j=0;j<15;j++){
		i=0;
		m[i][j]=178;
	}
	for(j=0;j<15;j++){
		i=14;
		m[i][j]=178;
	}
	
}
void base(char m[][15],Inimigo *I1,Inimigo *I2){
	int i,j,a;
	char b,p;
	p = 177;
	b = 'W';
		
		
		m[13][7]=b;
	   	m[13][8]=p;
	    m[13][6]=p;
	    m[12][7]=p;
	    m[12][8]=p;
	    m[12][6]=p;
	    
	m[11][7]= 202;
	m[1][1]= I1->pos;
	m[1][13]=I2->pos;
	
}
void fase1(char m[][15]){
	int matx[15][15];
	int i,j;
	FILE *fase1;
	
	// pi = 177 p = 219 borda = 178
	
	fase1=fopen("fase1.txt","r");
			if(fase1 == NULL){
				printf("Impossivel abrir o arquivo.Algo esta errado.");
			}
			else{
				for(i=0;i<15;i++){
					for(j=0;j<15;j++){
						fscanf(fase1,"%d",&matx[i][j]);
					}
				}
				
			}
		
		fclose(fase1);
		
		for(i=0;i<15;i++){
					for(j=0;j<15;j++){
						if(matx[i][j] == 1){
							m[i][j] = 178;
						}else if(matx[i][j] == 2){
							m[i][j] =' ';
						}
						else if(matx[i][j] == 3){
							m[i][j] =177;
						}
						else if(matx[i][j] == 4){
							m[i][j] =219;
						}
					}
					printf("\n");
				}
}
void fase2(char m[][15]){
	int matx[15][15];
	int i,j;
	FILE *fase2;
	
	// pi = 177 p = 219 borda = 178
	
	fase2=fopen("fase2.txt","r");
			if(fase2 == NULL){
				printf("Impossivel abrir o arquivo.Algo esta errado.");
			}
			else{
				for(i=0;i<15;i++){
					for(j=0;j<15;j++){
						fscanf(fase2,"%d",&matx[i][j]);
					}
				}
				
			}
		
		fclose(fase2);
		
		for(i=0;i<15;i++){
					for(j=0;j<15;j++){
						if(matx[i][j] == 1){
							m[i][j] = 178;
						}else if(matx[i][j] == 2){
							m[i][j] =' ';
						}
						else if(matx[i][j] == 3){
							m[i][j] =177;
						}
						else if(matx[i][j] == 4){
							m[i][j] =219;
						}
					}
					printf("\n");
				}
}
void fase3(char m[][15]){
	int matx[15][15];
	int i,j;
	FILE *fase3;
	
	// pi = 177 p = 219 borda = 178
	
	fase3=fopen("fase3.txt","r");
			if(fase3 == NULL){
				printf("Impossivel abrir o arquivo.Algo esta errado.");
			}
			else{
				for(i=0;i<15;i++){
					for(j=0;j<15;j++){
						fscanf(fase3,"%d",&matx[i][j]);
					}
				}
				
			}
		
		fclose(fase3);
		
		for(i=0;i<15;i++){
					for(j=0;j<15;j++){
						if(matx[i][j] == 1){
							m[i][j] = 178;
						}else if(matx[i][j] == 2){
							m[i][j] =' ';
						}
						else if(matx[i][j] == 3){
							m[i][j] =177;
						}
						else if(matx[i][j] == 4){
							m[i][j] =219;
						}
					}
					printf("\n");
				}
}
void renovBordas(char m[][15]){
	int i, j;
	for(i=0;i<15;i++){
		j = 0;
		m[i][j]=178;
	}
	for(i=0;i<15;i++){
		j = 14;
		m[i][j]=178;
	}
	for(j=0;j<15;j++){
		i=0;
		m[i][j]=178;
	}
	for(j=0;j<15;j++){
		i=14;
		m[i][j]=178;
	}
}
int RadarBase(char m[][15],Jogador *tap,Inimigo *I1,Inimigo *I2){
	int i,j,contp=1,contb=1;
	
		for(i=0;i<15;i++){
			for(j=0;j<15;j++){
				
				if(m[i][j]=='W'){
					contp=0;
				}
				
			}
		}
		
	return contp;
}
void limpatabuleiro(char m[][15]){
	int i,j;
	
		for(i=0;i<15;i++){
			for(j=0;j<15;j++){
				m[i][j] =' ';
			}
		}
}
void criandofases(char m[][15]){
	FILE *fase1,*fase2,*fase3;
	
	fase1 = fopen("fase1.txt","w");
	
		fprintf(fase1,"1 1 1 1 1 1 1 1 1 1 1 1 1 1 1\n");
		fprintf(fase1,"1 2 2 2 2 2 2 2 2 2 2 2 2 2 1\n"); 
		fprintf(fase1,"1 2 3 2 3 2 3 2 3 2 3 2 3 2 1\n");
		fprintf(fase1,"1 2 3 2 3 2 3 2 3 2 3 2 3 2 1\n");
		fprintf(fase1,"1 2 3 2 3 2 3 4 3 2 3 2 3 2 1\n");
		fprintf(fase1,"1 2 3 2 3 2 3 2 3 2 3 2 3 2 1\n");
		fprintf(fase1,"1 2 2 2 2 2 2 2 2 2 2 2 2 2 1\n");
		fprintf(fase1,"1 4 2 3 3 2 3 2 3 2 3 3 2 4 1\n");
		fprintf(fase1,"1 2 2 2 2 2 2 2 2 2 2 2 2 2 1\n"); 
		fprintf(fase1,"1 2 3 2 3 2 3 2 3 2 3 2 3 2 1\n");
		fprintf(fase1,"1 2 3 2 3 2 3 2 3 2 3 2 3 2 1\n");
		fprintf(fase1,"1 2 3 2 3 2 3 2 3 2 3 2 3 2 1\n");
		fprintf(fase1,"1 2 3 2 3 2 3 2 3 2 3 2 3 2 1\n");
		fprintf(fase1,"1 2 2 2 3 2 3 2 3 2 3 2 2 2 1\n");
		fprintf(fase1,"1 1 1 1 1 1 1 1 1 1 1 1 1 1 1");
		
	fclose(fase1);
	
		fase2 = fopen("fase2.txt","w");
	
		fprintf(fase2,"1 1 1 1 1 1 1 1 1 1 1 1 1 1 1\n");
		fprintf(fase2,"1 2 2 2 2 2 2 2 2 2 2 2 2 2 1\n");
		fprintf(fase2,"1 2 2 2 2 2 2 3 2 2 2 2 2 2 1\n");
		fprintf(fase2,"1 2 2 2 2 2 3 3 3 2 2 2 2 2 1\n");
		fprintf(fase2,"1 2 2 2 2 3 3 3 3 3 2 2 2 2 1\n");
		fprintf(fase2,"1 2 2 2 3 3 4 4 4 3 3 2 2 2 1\n");
		fprintf(fase2,"1 2 2 3 3 3 4 4 4 3 3 3 2 2 1\n");
		fprintf(fase2,"1 2 2 2 3 3 4 4 4 3 3 2 2 2 1\n");
		fprintf(fase2,"1 2 2 2 2 3 3 3 3 3 2 2 2 2 1\n");
		fprintf(fase2,"1 2 2 2 2 2 3 3 3 2 2 2 2 2 1\n");
		fprintf(fase2,"1 2 2 2 2 2 2 3 2 2 2 2 2 2 1\n");
		fprintf(fase2,"1 2 4 2 2 2 2 2 2 2 2 2 4 2 1\n");
		fprintf(fase2,"1 2 2 2 2 2 2 2 2 2 2 2 2 2 1\n");
		fprintf(fase2,"1 2 4 2 2 2 2 2 2 2 2 2 4 2 1\n");
		fprintf(fase2,"1 1 1 1 1 1 1 1 1 1 1 1 1 1 1");
		
	fclose(fase2);
	
		fase3 = fopen("fase3.txt","w");
	
		fprintf(fase3,"1 1 1 1 1 1 1 1 1 1 1 1 1 1 1\n");
		fprintf(fase3,"1 2 2 2 2 2 2 2 2 2 2 2 2 2 1\n");
		fprintf(fase3,"1 2 2 2 2 2 2 2 2 2 2 2 2 2 1\n");
		fprintf(fase3,"1 2 3 3 3 3 3 3 3 3 3 3 2 2 1\n");
		fprintf(fase3,"1 2 3 3 2 2 2 2 2 2 2 3 3 2 1\n");
		fprintf(fase3,"1 2 3 3 2 2 2 2 2 2 2 3 3 2 1\n");
		fprintf(fase3,"1 2 3 3 2 2 2 2 2 2 2 3 3 2 1\n");
		fprintf(fase3,"1 2 3 3 3 3 3 3 3 3 3 3 2 2 1\n");
		fprintf(fase3,"1 2 3 3 2 2 2 2 2 3 3 2 2 2 1\n");
		fprintf(fase3,"1 2 3 3 2 2 2 2 2 2 3 3 2 2 1\n");
		fprintf(fase3,"1 2 3 3 2 2 2 2 2 2 2 3 2 2 1\n");
		fprintf(fase3,"1 2 3 3 2 2 2 2 2 2 2 2 3 2 1\n");
		fprintf(fase3,"1 2 2 2 2 2 2 2 2 2 2 2 2 2 1\n");
		fprintf(fase3,"1 2 2 2 2 2 2 2 2 2 2 2 2 2 1\n");
		fprintf(fase3,"1 1 1 1 1 1 1 1 1 1 1 1 1 1 1");
		
		fclose(fase3);
		
}
void vitoria(int *pontos){
	FILE *lista;
	char nome[1000];
	
	printf("PARABENS COMBATENTE! VOCE DERROTOU TODOS OS INIMIGOS!\nDigite o seu nome para que todos se lembrem da sua grande conquista no campo de batalha: ");
	scanf("%s",nome);
	
	
	lista = fopen("Lista de jogadores.txt","a");
	
		fprintf(lista,"Nome: %s ----- Pontos:%d\n",nome,*pontos);
		
	fclose(lista);
	
	printf("\nMuito obrigado por jogar nosso jogo.Foi uma grande honra te-lo em nosso exercito.\n");
}
void girar(char m[][15],Jogador *tap,char *diretiro,char *pa,int *pontos,int *vidas){
	char acaog;
	
	system("cls");
	imprimir(m);
	
	printf("Escolha pra onde deseja girar:\n(W):Cima\n(S):Baixo\n(D):Direita\n(S):Esquerda\n(O):Sair ");
	scanf(" %c",&acaog);
	
		if(acaog == 'd'){	
		tap->repre= 204;
		*diretiro = 'd';
		m[tap->posl][tap->posc]=tap->repre;	
		}
		if(acaog == 'a'){
		tap->repre= 185;
		*diretiro = 's';
		m[tap->posl][tap->posc]=tap->repre;	
		}
		if(acaog == 'w'){
		tap->repre= 202;
		*diretiro = 'w';
		m[tap->posl][tap->posc]=tap->repre;	
		}
		if(acaog == 's'){
		tap->repre= 203;
		*diretiro = 's';
		m[tap->posl][tap->posc]=tap->repre;
		}
		if(acaog == 'o'){
			system("cls");
			imprimir(m);
			printf("Pontos:%d       Vidas :%d\n(W):Cima\n(S):Baixo\n(D):Esquerda\n(A):Direita\n(G):Girar\n(F):Tiro\n(O):Sair\n: ",*pontos,*vidas);
			*pa = getch();
		}
	
}
void printarjogadores(char m[][15]){
	FILE *lista;
	char listaa[1000];
	int saida=0;
	
		system("cls");
		lista = fopen("Lista de jogadores.txt","r");
		
		while(fgets(listaa,100000,lista) !=NULL){
			printf("%s",listaa);
		}
		while(saida != 1){
		
		printf("\n\n\n(1):Sair\n:");
		scanf("%d",&saida);
		system("cls");
		fclose(listaa);
	}
	
}
void andard(char m[][15],Jogador *tap,char *pa,char *diretiro){
	char pi,p,t=2;
	pi = 219;
	p = 177;

	if(*pa == 'd'){	
			printf("Tanque principal andou da liha %d coluna %d para liha %d coluna %d",tap->posl,tap->posc,tap->posl,tap->posc+1);
			sleep(3);
				*diretiro = 'd';
				tap->repre= 204;
				m[tap->posl][tap->posc]=tap->repre;
			if (m[tap->posl][tap->posc+1]!=pi && m[tap->posl][tap->posc+1]!=p){
				if(tap->posc<13){//>>>>>>>>>>>>>>>>>>>>>>>>>>>Não deixa o tanque sair da tela/
					m[tap->posl][tap->posc] = ' ';//>>>>>>>>>>>>>A posição anterior do tanque continuar com ponto/
					m[tap->posl][tap->posc+1] = tap->repre;
					tap->posc = tap->posc+1;		
				}
			}
		}
		if(*pa == 'a'){
		tap->repre= 185;
		*diretiro = 'a';
		printf("Tanque principal andou da liha %d coluna %d para liha %d coluna %d",tap->posl,tap->posc,tap->posl,tap->posc-1);
			sleep(3);
		m[tap->posl][tap->posc]=tap->repre;				//=======ESQUERDA===/
			if (m[tap->posl][tap->posc-1]!=pi && m[tap->posl][tap->posc-1]!=p){	
				if(tap->posc>1){   
					m[tap->posl][tap->posc] = ' ';  
					m[tap->posl][tap->posc-1] = tap->repre;
					tap->posc = tap->posc-1;
						
				}
			}
		}
		if(*pa == 'w'){
		tap->repre= 202;
		*diretiro = 'w';
		printf("Tanque principal andou da liha %d coluna %d para liha %d coluna %d",tap->posl,tap->posc,tap->posl-1,tap->posc);
			sleep(3);
		m[tap->posl][tap->posc]=tap->repre;			
		                             	//=======CIMA=======/
			if (m[tap->posl-1][tap->posc]!=pi && m[tap->posl-1][tap->posc]!=p){		
				if(tap->posl>1){  
					m[tap->posl][tap->posc] = ' ';  
					m[tap->posl-1][tap->posc] = tap->repre;
					tap->posl = tap->posl-1;	
					
				}
			}
		}
		if(*pa == 's'){
		tap->repre= 203;
		*diretiro = 's';
		printf("Tanque principal andou da liha %d coluna %d para liha %d coluna %d",tap->posl,tap->posc,tap->posl+1,tap->posc);
		sleep(3);
		m[tap->posl][tap->posc]=tap->repre;			//=======BAIXO======/
			if (m[tap->posl+1][tap->posc]!=pi && m[tap->posl+1][tap->posc]!=p){	
				if(tap->posl<13){  
					m[tap->posl][tap->posc] = ' ';  
					m[tap->posl+1][tap->posc] = tap->repre;
					tap->posl = tap->posl+1;
							
				}
			}
		}
	
  	system("cls");//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>Limpa>>>/
}
