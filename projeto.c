//Marcelo Jânio & Vitor Ribeiro
#include <string.h>
#include <stdio.h>
#define MAX_A 200
#define MAX_C 200
#define MIN_N 6
#define MAX_N 15

typedef struct{
	int dia;
	int mes;
	int ano;
}tdata;

typedef struct{
	int quant;
	int apostador[MAX_A];
	int quantCart;
	int num[MAX_C][MIN_N];
	int finalizado;
	
}tBolaoVarios;

typedef struct{
	int quant;
	int quantNum;
	int num[MAX_N];
	int apostador[MAX_A];
	int finalizado;
	
}tBolaoUm;

typedef struct{
	tdata data;
	tBolaoUm bolaoU;
	tBolaoVarios bolaoV;
	
}tbolao;

typedef struct{ 

	char nome[51];
	char cpf[12];
	char telfoneP[12];
	char telefoneS[12];
}tApostador;

tApostador apost(tApostador aposta[],int *cont){
	tApostador d;
	tApostador c;
	int i;
	int a;
	printf("Digite o seu nome:\n");
	scanf("%s",d.nome);
	if(strlen(d.nome)==0){
		return c;
	}
	printf("Digite o seu cpf sem os pontos:\n");
	scanf("%s",d.cpf);
	do{a = 0;
	
	for(i=0;i<(*cont);i++){
	   if(strcmp(d.cpf,aposta[i].cpf)==0){
		   printf("Digite o cpf novamente:");
		   scanf("%s",d.cpf);
		   a = 1;
	   }
	}
	}while(a==1);

	printf("Digite o seu telefone principal:\n");
	scanf("%s",d.telfoneP);
	if(strlen(d.telfoneP)==0){
		return c;
	}
	printf("Digite um numero de celular secundario:\n");
	scanf("%s",d.telefoneS);
	if(strlen(d.telefoneS)==0){
			return c;
	}
	
	if(strlen(d.nome)==0||strlen(d.cpf)==0||strlen(d.telfoneP)==0||strlen(d.telefoneS)==0){
		*cont = *cont;
	}
	else
	{
		(*cont)++;
	}
	
	return d;

}

int menu(){
	int t;
	printf("-------MENU-------\n1.Apostadores\n2.Bolao\n0.Sair\n");
	printf("Escolha uma opcao: ");
	scanf("%d",&t);
	
	return t;
}

int menuapos(){
	int b;
	printf("-----APOSTADORES-----\n1.Cadastrar\n2.Alterar\n3.Excluir\n4.Exibir apostadores\n0.Sair\n");
	printf("Escolha uma opcao: ");
	scanf("%d",&b);
	
	return b;
}

int menubolao(q	){
	int k;
	printf("-----BOLAO-----\n1.Novo\n2.Alterar\n3.Finalizar\n4.Imprimir\n5.Verificar Ganhador\n0.Sair\n");
	scanf("%d",&k);
	
	return k;
}

void imprime(tApostador d) {
	printf("Nome: %s\n", d.nome);
	printf("Cpf: %s\n", d.cpf);
	printf("Telfone: %s\n", d.telfoneP);
	printf("Celular: %s\n", d.telefoneS);
}

	int novoBolao(){
		// falta inserir a data atual
		tbolao g;
		//g.bolaoU.quant = 1; //- SO PRA TESTAR A FUNÇÃO
		//g.bolaoV.quant = 1;
		printf("Digite a data do sorteio:\n");
		scanf("%d%d%d",&g.data.dia,&g.data.mes,&g.data.ano);
		printf("Data = %d/%d/%d\n",g.data.dia,g.data.mes,g.data.ano);
		
		if(g.bolaoU.quant == 0 && g.bolaoV.quant == 0){
			int resp1;
			do{
			printf("Qual bolao voce deseja criar?\n");
			printf("1.BOLAOUM\n2.BOLAOV\n0.SAIR\n");
			scanf("%d",&resp1);
			switch(resp1)
			{
			case 1:
				//cadastraBolaoUM();
				g.bolaoU.finalizado = 0;
				break;
			case 2:
				//cadastraBolaoV();
				g.bolaoV.finalizado = 0;
				break;
			
			case 0:
				//Volta pro menu
				break;
			
			}
		}while(resp1!=0);
		}

		
		if(g.bolaoU.quant == 0 && g.bolaoV.quant != 0){
			int resp2;
			do{
			printf("1.BOLAOUM\n");
			printf("Deseja criar um bolao do tipo BolaoUM?\n1.SIM\n2.NAO\n");
			scanf("%d",&resp2);
			
			if(resp2 == 1){
				//cadastraBolaoum();
				g.bolaoU.finalizado = 0;
			}
			if(resp2 == 2){
			
				//RETORNA PRO MENU BOLAO;
			}
			}while(resp2!=2);
			
			
			
		}
		
		if(g.bolaoV.quant == 0 && g.bolaoU.quant !=0){
			int resp3;
			do{
			printf("2.BOLAOV\n");
			printf("Deseja criar um bolao do tipo BOLAOV?\n1.SIM\n2.NAO\n");
			scanf("%d",&resp3);
			
			if(resp3 == 1){
				//cadastraBolaoum();
				g.bolaoV.finalizado = 0;
			}
			if(resp3 == 2){
			
				//RETORNA PRO MENU BOLAO;
			}
			}while(resp3!=2);
			
			
		}
		if(g.bolaoU.quant !=0 && g.bolaoV.quant !=0){
			int resp4 = 0;
			do{
			printf("Boloes ja cadastrados para esta data do sorteio.\n");
			}while(resp4!=0);
		}
	}

int main(){
	tApostador aposta[MAX_A];
	int t, b, k, c, a;
	int i,j;
	char comp[12];
	char tes[12];
	int x = 0;
	int *cont;
	cont = &x;
	
	
	do{
		t = menu();
		switch(t)
		{
			case 1: 
				do{
					b = menuapos();
					switch(b)
					{
					case 1:  aposta[*cont] = apost(aposta,cont);
					
						break;
					
					case 2: printf("Qual usuario voce deseja alterar os dados(CPF): ");
						scanf("%s", comp);
						if(strcmp(comp,aposta[j].cpf)==1){
							printf("O usuario nao existe!\n");
							break;
						}
						printf("1.Nome\n2.CPF\n3.Telefone 1\n4.Telefone 2\n5.Cancelar\nO que deseja alterar: ");
						scanf("%d", &c);
						for (j = 0; j < MAX_A; j++){
							if (strcmp(comp,aposta[j].cpf)==0){
								switch(c)
								{
								case 1:
									printf("Nome atual: %s\n", aposta[j].nome);
									printf("Novo nome: ");
									scanf("%s", aposta[j].nome);
									break;
								case 2:
									strcpy(tes, aposta[j].cpf);
									printf("CPF atual: %s\n", aposta[j].cpf);
									printf("Novo CPF: ");
									scanf("%s", tes);
									do{a = 0;
									for(i=0;i<(*cont);i++){
									   if(strcmp(tes,aposta[i].cpf)==0){
										   printf("Digite o cpf novamente:");
										   scanf("%s",tes);
										   a = 1;
									   }
									}
									}while(a==1);
									strcpy(aposta[j].cpf, tes);
									break;
								case 3:
									printf("Telefone 1 atual: %s\n", aposta[j].telfoneP);
									printf("Novo telefone: ");
									scanf("%s", aposta[j].telfoneP);
									break;
								case 4:
									printf("Telefone 2 atual: %s\n", aposta[j].telefoneS);
									printf("Novo telefone: ");
									scanf("%s", aposta[j].telefoneS);
									break;
								}
							}
						}
			
						break;
					
					case 3:
						break;
					
					case 4:
						for(i = 0; i < *cont; i++) {
						printf("----Apostador %d----\n", i + 1);
						imprime(aposta[i]);
						printf("\n");
						} 
     
						break;
					
					case 0:
						
						break;
					}
				}while(b!=0);
				
				break;
		    case 2: do{
		    	k = menubolao();
		    	switch(k)
		    	{
		    		case 1: novoBolao();
		    			break;
		    		case 2:
		    			break;
		    		case 3:
		    			break;
		    		case 4:
		    			break;
		    		case 5:
		    			break;
		    		case 0:
		    			break;
				}
			}while(k!=0);
		    	
				break;
			
			case 0:
				printf("Programa encerrado!\n");
				break;
		}
	}while(t!=0);
		
return 0;
	
}
