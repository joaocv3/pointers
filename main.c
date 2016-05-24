#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>

typedef struct nodoAtoresFilmes{struct nodoAtores *nome;struct nodoAtoresFilmes *prox;} AtoresFilmes; // Lista de atores de um filme
typedef struct nodoFilmesAtores{struct nodoFilmes *nome;struct nodoFilmesAtores *prox;} FilmesAtores; // Lista de filmes de um ator
typedef struct nodoFilmes{char NomeFilmes[100]; int ano; char Diretores[200]; struct nodoFilmes *prox; struct nodoFilmes *ant; struct nodoAtoresFilmes *atores;} Filmes; //Lista principal dos filmes
typedef struct nodoAtores{char NomeAtor[50];struct nodoAtores *prox; struct nodoAtores *ant; struct nodoFilmesAtores *filmes;} Atores; // Lista principal dos atores
typedef struct nodoFilmesPersonagens{struct nodoFilmes *filmes; struct nodoFilmesPersonagens *prox;} FilmesPersonagens; // lista de filmes em que determinados personagens apareceram
typedef struct nodoPersonagens{char NomePersonagem[50]; struct nodoPersonagens *prox; struct nodoAtoresFilmes *atores; struct nodoFilmesPersonagens *filmes;} Personagens; // lista de personagens interpretados

/* ---- MENU PRINCIPAL ---- */

int menu();

/* ----------------------- */

/* -------------------Funções INICIAIS------------------------- */ 


int leitura(Filmes **inicioF, Filmes **fimF, Atores **inicioA, Atores **fimA, Personagens **inicioP);

void InsercaoInicial(Filmes **inicioF, Filmes **fimF, Atores **inicioA, Atores **fimA, Personagens **inicioP, char ValorASerInserido[600]);

/* ---------------------------------------------------------- */


/* -------------------Funções PESQUISA------------------------- */

struct nodoAtores *verificaAtores(Atores **inicioA, char nome[100]);

struct nodoFilmes *verificaFilmes(Filmes **inicioF, char nome[100]);

struct nodoPersonagens *verificaPersonagens(Personagens **inicioP, char NomePersonagem[50]);

void buscaFilmeEspecifico(Filmes **inicioF);

/* ---------------------------------------------------------- */


/* -------------------Funções INSERÇÃO------------------------- */ 

struct nodoFilmes * insereOrdenadoNaListaDeFilmes(Filmes **inicioF, Filmes **fimF ,char nome[100], int ano, char Diretores[200]);

struct nodoAtores *insereOrdenadoNaListaDeAtores( Atores **inicio, Atores **fim , char nome[100]);

void InsereAtorListaAFilmes(AtoresFilmes **inicioAF, Atores **Pos );

void InsereFilmesListaFAtor(FilmesAtores **inicioFA, Filmes **Pos , Atores **Ator);

void InsereFilmesListaFPersonagens(FilmesPersonagens **inicioFP, Filmes **Pos );

struct nodoPersonagens *InserePersonagem(Personagens **inicioP, char NomePersonagem[50]);

void InsereAtorListaPersonagem(AtoresFilmes **inicioAF, Atores **ator);

void InserePersonagemListaAtor(AtoresFilmes **inicioAF, Personagens **pos);

void insercaoOrdenada(Filmes **inicioF, Filmes **fimF, Atores **inicioA, Atores **fimA, char ValorASerInserido[600]);

/* ---------------------------------------------------------- */


//int PesquisaNasStructs(Filmes **inicioF, Atores **inicioA, char ValorPesquisa[200], char FilmeAnoDiretorNome);


/* -------------------Funções LISTAR------------------------- */ 
void defineFilmesAlfabeticoOuReverso(Filmes **inicioF, Filmes **fimF); // Função que define se a lista de filmes será mostrada em ordem alfabética ou alfabética reversa

void ListaFilmesOrdemAlfabetica(Filmes **inicioF, Filmes **fimF, char NormalOuReverso); // Função que mostra a lista de filmes

void defineAtoresAlfabeticoOuReverso(Atores **inicioA, Atores **fimA); // Função que define se a lista de atores será mostrada em ordem alfabética ou alfabética reversa

void listarFilmesAtorOrdemCronologica(Atores **inicioA);

void ListaAtoresOrdemAlfabetica(Atores **inicioA, Atores **fimA, char NormalOuReverso); // Função que mostra a lista de atores

void ListaPersonagens(Personagens **inicioP); // Função teste para visualizar a lista de personagens

/* -------------------------------------------------------- */




int main()
{
	Filmes *inicioF = NULL, *fimF = NULL; // Início/fim lista Filmes.
	Atores *inicioA = NULL, *fimA = NULL; // Início/fim lista Atores.
	Personagens *inicioP = NULL;
	setlocale(LC_ALL,"Portuguese");
	if((leitura(&inicioF, &fimF, &inicioA, &fimA, &inicioP))==0) //verifica se conseguiu ler o arquivo
	{
		printf("\n Erro! Arquivo nÃ£o encontrado. \n");
		printf("Insira o arquivo no diretorio especifico e tente novamente. \n");
		return; // Encerra o programa
	}
	
	int escolha = menu(); // Verifica a primeira escolha. Se for para sair, retorna e encerra o programa;
/*	if(escolha!=0) 		 // Inicializa o início e fim das listas até então utilizadas.
	{
		
		
	}*/
	while(escolha>0) //Escolha 0 == sair do programa
	{
		switch (escolha)
		{
			case 1:
				defineAtoresAlfabeticoOuReverso(&inicioA, &fimA);
				break;
			case 2:
				listarFilmesAtorOrdemCronologica(&inicioA);
				break;
			case 3:
				defineFilmesAlfabeticoOuReverso(&inicioF, &fimF); 
				//buscaFilmeEspecifico(&inicioF); // teste
				break;
			case 4:

				break;
			case 5:
				break;
			case 6:
				break;
			case 7:
				break;
			case 8:
				break;
			case 9:
				break;
			case 10:
				ListaPersonagens(&inicioP); // teste
				break;		
		}
		escolha = menu();
	}
	
}


int menu()
{
	int opcaoMenu = 0;
	
	while(opcaoMenu!= -1 )
	{
		printf("\n 1: Listar todos os atores da lista em ordem alfabetica e alfabetica reversa ");
		printf("\n 2:Listar todos os filmes de um determinado ator em ordem cronolÃ³gica.");
		printf("\n 3:Listar todos os filmes em ordem alfabÃ©tica e alfabÃ©tica reversa.");
		printf("\n 4:Inserir novos filmes");
		printf("\n 5:Remover filmes");
		printf("\n 6:Listar todos os filmes de um determinado diretor (ordem cronologica)");
		printf("\n 7:Listar todos os atores que trabalharam diretamente com um determinado ator e o nome do filme no qual trabalharam juntos");
		printf("\n 8:Listar todos os atores que trabalharam diretamente com um diretor e o nome do filme em que trabalharam juntos");
		printf("\n 9:Listar todos os filmes que estÃ£o duplicados");
		printf("\n 10:Listar todos os atores que interpretaram um determinado personagem, bem como o filme e o ano em que o fizeram");
		printf("\n\n 0: Para sair do programa\n");
		scanf("\n%d", &opcaoMenu);
		if(opcaoMenu<-1 || opcaoMenu>10)
		{
		
			printf("Digite uma opcao valida!");
			system("pause");
			system("cls");
		}
		else
			break;
	}
	return opcaoMenu;
}

int leitura(Filmes **inicioF, Filmes **fimF, Atores **inicioA, Atores **fimA,Personagens **inicioP)
{
	
	FILE *arquivo; // especificando o arquivo...
	char linha[600]; // linha que recebera os dados lidos
	arquivo = fopen("resumo.txt", "r"); // abre o arquivo em modo leitura
	if(arquivo==NULL)
	{
		return 0; // retorna 0 para indicar falha ao abrir.
	}
	else
	{
		while((fgets(linha, sizeof(linha), arquivo))!= NULL)
		{

			
			
			InsercaoInicial(&(*inicioF), &(*fimF), &(*inicioA), &(*fimA), inicioP, linha); // Atualiza diretamente a lista de filmes e atores
			
		}
		fclose(arquivo);
		return 1; // retorna 1 para indicar que abriu com sucesso.
	}
}

void InsercaoInicial(Filmes **inicioF, Filmes **fimF, Atores **inicioA, Atores **fimA,Personagens **inicioP, char ValorASerInserido[600])
{
	Filmes *novoF = NULL;
	Atores *novoA = NULL;
	Personagens *novoP = NULL;
	
	char aux[100], nomeAtor[100], NomePersonagem[50], Diretores[200], NomeFilme[100];
	
	int i, j=0,k; //variaveis contadoras para percorrer a linha, a string atÃ© a virgula e a string auxiliar, respectivamente;
	
	int ano,l,m,n, flagSairLacoStatus2, contador; // variáveis contadoras para a verificação de outros diretores (utilizadas no status 2)
	
	int o, flagPersonagem; // Variáveis contadoras para o segmento de status >2;
	int status=0; //status para a inserÃ§Ã£o nos elementos do nodo
	
	
	for(i=0; i<strlen(ValorASerInserido); i++)//Percorre o vetor de chars
	{ 
		if(ValorASerInserido[i]==',' || ValorASerInserido[i+1]=='\0')
		{ 
			strcpy(aux,"");
			k=0;	//zera o contador da string auxiliar
			for(j; j<i ;j++){ // percorre da posicao inicial atÃ© a virgula
			
				aux[k]=ValorASerInserido[j]/*)*/; //insere char a char na string auxiliar

				k++; //proxima posicao na string auxiliar
				
			}
			
			aux[k]='\0'; // encerra a string atÃ© a virgula
			
			if(status==0)//guarda nome filme
			{
				
				strcpy(NomeFilme, aux);	

			}
			else if (status==1) //ano
			{

				ano = atoi(aux);

			}
			else if (status==2) //diretor
			{
				strcpy(Diretores, "");
				strcpy(Diretores, aux);

				/* O Próximo Laço irá verificar se existem mais diretores no mesmo filme. 
				Se ele conseguir encontrar o 'dir:' na frente, irá copiar o nome para a string que será inserida na lista com o filme */
				
				
				m = j+1;
				

				if(ValorASerInserido[m]=='d' && ValorASerInserido[m+1]=='i' && ValorASerInserido[m+2]=='r' && ValorASerInserido[m+3]==':')
				{
					m += 4;
					flagSairLacoStatus2 = 0;
					l=0;
					while(Diretores[l]!='\0')
					{
						l++;
					}
				}
				else flagSairLacoStatus2 = 1;
				while(flagSairLacoStatus2 == 0)
				{

					Diretores[l] = ',';
					l++;
					Diretores[l] = '\0'; // Finaliza a linha.

					while(ValorASerInserido[m]!=',' ) //&& ValorASerInserido[m]!='\0')  <--- Não encontrei caso que fosse necessário (programa passou a ter comportamento estranho)
					{

						Diretores[l]=ValorASerInserido[m];

						l++;
						m++;
					}

					if(ValorASerInserido[m+1]=='d' && ValorASerInserido[m+2]=='i' && ValorASerInserido[m+3]=='r' && ValorASerInserido[m+4]==':' )
					{
						m+=5;
						
					}
					else
					{ 
						flagSairLacoStatus2 = 1 ; // quebra o laço e insere o nome dos diretores na lista de filmes.
						Diretores[l+1] = '\0'; // insere indicador de fim de linha para evitar loops
						i = m; // ATENÇãO: variável i é incrementada aqui pois outro nome de diretor fora inserido
						// diretamente da string ValorASerInserido. Assim, nenhum nome é duplicado no próximo status.

					}


				}

				novoF = insereOrdenadoNaListaDeFilmes(inicioF,fimF,NomeFilme,ano,Diretores); // inserção do filme de maneira ordenada na lista de filmes
				novoF->atores = NULL; // insere NULL na struct AtoresFilme, pois o filme recém fora inserido.
			}
			else if(status>2) 
			{
				o = 0; // variável contadora utilizada nas cópias seguintes
				
				flagPersonagem = 0; //zera o indicador de personagem
				
				while(aux[o]!='=') // copia o nome do ator para a string respectiva até ou encontrar = ou o caracter de final de string.
				{
					nomeAtor[o] = aux[o];

					o++;
					if(aux[o]=='\0') 
					{
						break;
					}
					else if(aux[o]=='=')  // Se possuir um =, existe o personagem na string aux.
					{
						flagPersonagem = 1;
					}
				}
				
				nomeAtor[o]='\0'; //determina o fim da string para evitar loops.
				
				
				if(flagPersonagem==1) // Se possuir um =, existe o personagem na string aux.
				{
					n = 0; // zera n;
					o++; 
					while(aux[o]!='\0') // Enquanto não estiver no fim da string auxiliar, continua a inserção.
				 	{
						NomePersonagem[n] = aux[o]; // transfere o nome do personagem.
						n++;
						o++;
					}	
					
				NomePersonagem[n]='\0'; //determina o fim da string para evitar loops.
				
				}
				
				
				novoA = verificaAtores(inicioA,nomeAtor); // Aqui é verificada a existência do determinado ator. Se existe, retorna a posição da struct;
				

				if(novoA == NULL) // Se retornar nulo, insere o ator.
				{
					novoA = insereOrdenadoNaListaDeAtores( inicioA, fimA, nomeAtor); // insere ator novo, para facilitar nossa vida futuramente na listagem.
					novoA->filmes = NULL; // define como NULL a lista de filmes, pois o ator fora recém inserido.
						
				}
				
				InsereAtorListaAFilmes(&novoF->atores, &novoA); // Insere o ator na lista AtoresFilmes do Filme que está sendo inserido.
				InsereFilmesListaFAtor(&novoA->filmes,&novoF,&novoA); // Insere o filme na lista FilmesAtores do Ator que está sendo inserido (ou já existe).
				
				if(flagPersonagem==1) // Se existir = na variável aux, significa que possui personagem.
				{
					
					novoP  = verificaPersonagens(inicioP, NomePersonagem); // Faz a verificação se existe, da mesma maneira como é feita logo acima para atores.

					if(novoP == NULL) // Se for NULL, insere o personagem.
					{
				 		novoP = InserePersonagem(inicioP, NomePersonagem);
				 	}

				 	InsereFilmesListaFPersonagens(&novoP->filmes, &novoF); // Insere filme na lista FilmesPersonagens do Personagem
				 	InsereAtorListaPersonagem(&novoP->atores, &novoA); //Insere ator que interpretou determinado personagem na lista do personagem.
				 	

					strcpy(NomePersonagem,""); //"Zera" a variável para a próxima iteração.
				}

			}

			j=i+1; //comeca a contagem da proxima string apÃ³s a virgula 
		 status++; // incrementa o status, para continuar a leitura.

		}

	}
	
}

struct nodoFilmes * insereOrdenadoNaListaDeFilmes(Filmes **inicioF, Filmes **fimF,char nome[100], int ano, char Diretores[200])
{				// Inserção ordenada por nome

		Filmes  *ptaux = (Filmes *)malloc(sizeof(Filmes));
		strcpy(ptaux->NomeFilmes,nome);
		ptaux->ano = ano;
		strcpy(ptaux->Diretores, Diretores);
		if(*inicioF==NULL || strcmp((*inicioF)->NomeFilmes,nome)>1)
		{
			
			ptaux->ant = NULL;
			ptaux->prox = *inicioF;
			if(*inicioF!=NULL) 
			{
				(*inicioF)->ant = ptaux;
			}
			else 
			{
				*fimF = ptaux;
			}
			*inicioF = ptaux;
			
			
			return ptaux;
		}
		else 
		{
			Filmes *ptaux2 = *inicioF;
			while(ptaux2->prox!=NULL && strcmp(ptaux2->prox->NomeFilmes,nome)<1)
			{
				ptaux2 = ptaux2->prox;
			}
			ptaux->prox = ptaux2->prox;
			ptaux->ant = ptaux2;
			ptaux2->prox = ptaux;
			if(ptaux->prox==NULL)
				*fimF = ptaux;
			else
				ptaux->prox->ant=ptaux;
			return ptaux;		
		}

}

struct nodoAtores *insereOrdenadoNaListaDeAtores( Atores **inicio, Atores **fim , char nome[100]) // inserção ordenada por nome.
{
		Atores *ptaux = (Atores *)malloc(sizeof(Atores));
		strcpy(ptaux->NomeAtor,nome);
		if(*inicio==NULL || strcmp((*inicio)->NomeAtor,nome)>1)
		{
			ptaux->ant = NULL;
			ptaux->prox = *inicio;
			if(*inicio!=NULL) (*inicio)->ant = ptaux;
			else *fim = ptaux;
			*inicio = ptaux;
			return ptaux;
		}
		else 
		{
			Atores *ptaux2 = *inicio;
			while(ptaux2->prox!=NULL && strcmp(ptaux2->prox->NomeAtor,nome)<1)
			{
				ptaux2 = ptaux2->prox;
			}
			ptaux->prox = ptaux2->prox;
			ptaux->ant = ptaux2;
			ptaux2->prox = ptaux;
			if(ptaux->prox==NULL)
			{
				*fim = ptaux;
			}
			else
				ptaux->prox->ant=ptaux;	
			return ptaux;
		}
}

void InsereFilmesListaFAtor(FilmesAtores **inicioFA, Filmes **Pos , Atores **Ator) // Insere no início da lista FilmesAtores na lista Atores * favor verificar em inserçãoInicial *
{
	FilmesAtores *ptaux,*ptnovo = (FilmesAtores *)malloc(sizeof(FilmesAtores));
	ptnovo->nome = *Pos;
	ptnovo->prox = *inicioFA;
	if(*inicioFA==NULL || (ptnovo->nome->ano)<(*inicioFA)->nome->ano);
	{
		*inicioFA = ptnovo;
		return;
	}
	ptaux = *inicioFA;
	while(ptaux->prox!=NULL && (ptaux->prox->nome->ano)<(ptnovo->nome->ano))
	{
		ptaux = ptaux->prox;
	}
	ptnovo->prox=ptaux->prox;
	ptaux->prox=ptnovo;
	
}

void listarFilmesAtorOrdemCronologica(Atores **inicioA)
{
	int flag=1;
	char nomeAtor[200];
	while(flag==1)
	{
		printf("\n Digite o nome do ator/atriz que deseja pesquisar:\n");
		scanf("\n%[a-z A-Z]", nomeAtor);
		Atores *ptaux = verificaAtores(inicioA, nomeAtor);
		if(ptaux!=NULL)
		{
			printf("\n Nome: %s", ptaux->NomeAtor);
			printf("\n Filmes dos quais participou:");
			while(ptaux->filmes!=NULL)
			{
				printf("\n %s. Ano: %d",ptaux->filmes->nome->NomeFilmes, ptaux->filmes->nome->ano);
				ptaux->filmes = ptaux->filmes->prox;
			}
		}
		
		printf("\n Deseja realizar outra consulta? (1/0)\n");
		scanf("%d",&flag);
	}
	printf("\n Retornando ao menu!");
	system("pause");
}

struct nodoAtores *verificaAtores(Atores **inicioA, char nome[50]) // verificação se existe ator. Se existe, retorna o ator.
{
	Atores *ptaux = *inicioA;
	while(ptaux!=NULL)
	{
		if(strcmp(ptaux->NomeAtor,nome)==0)
		{
			return ptaux;
		}
		ptaux = ptaux->prox;
	}
	return NULL;
}


struct nodoFilmes *verificaFilmes(Filmes **inicioF, char nome[100]) // verificação se existe filme. Se existe, retorna o filme. 
{
	Filmes *ptaux = *inicioF;
	while(ptaux!=NULL)
	{
		if(strcmp(ptaux->NomeFilmes,nome)==0)
		{
			return ptaux;
		}
		ptaux = ptaux->prox;
	}
	return NULL;
}

struct nodoPersonagens *verificaPersonagens(Personagens **inicioP, char NomePersonagem[50]) // verificação se existe personagem. Se existe, retorna o personagem.
{
	Personagens *ptaux = *inicioP;
	while(ptaux!=NULL)
	{
		if(strcmp(ptaux->NomePersonagem,NomePersonagem)==0)
		{
			return ptaux;
		}
		ptaux = ptaux->prox;
	}
	return NULL;
}

void InsereAtorListaAFilmes(AtoresFilmes **inicioAF, Atores **Pos ) // Insere no início da lista AtoresFilmes na lista Filmes * favor verificar em inserçãoInicial *
{
	AtoresFilmes *ptaux = (AtoresFilmes *)malloc(sizeof(AtoresFilmes));
	ptaux->nome = *Pos;
	ptaux->prox = *inicioAF;
	*inicioAF = ptaux;

}



void defineFilmesAlfabeticoOuReverso(Filmes **inicioF, Filmes **fimF) // Sub-menu para definir qual tipo de listagem de filmes será feita, com a opção 0 para sair
{
	int flag = 1;
	while(flag>=1)
	{
		printf("\n Deseja listar os filmes em ordem alfabetica(1) ou alfabetica reversa(2)?\n(Se desejar, digite 0 para sair)");
		scanf(" %d",&flag);
		switch(flag)
		{
			case(0):
			{
				system("cls");
				return;
				break;		
			}
			case(1):
			{
				ListaFilmesOrdemAlfabetica(inicioF,fimF,'N');
				break;
			}
			case(2):
			{
				ListaFilmesOrdemAlfabetica(inicioF,fimF,'R');
				break;
			}
			default:
				printf("\nDigite uma opção válida!");
				break;
		}
	}
}

void ListaFilmesOrdemAlfabetica(Filmes **inicioF, Filmes **fimF, char NormalOuReverso) // Listagem de filmes em ordem alfabética ou alfabética reversa
{
	int flag=0,count;
	char SimNao;
	
	printf("\n Deseja definir quantos nomes aparecem na tela por vez?[S/N]");
	scanf(" %c",&SimNao);
	
	if(toupper(SimNao)=='S')
	{
		
		while(flag<1 || flag>100)
		{
			printf("\n Quantos? (entre 1 e 100)");
			scanf(" %d",&flag);
			if(flag<1 || flag > 100)
				{
					printf("\n Digite um número válido!");
				}
		}
	}
	
	if(NormalOuReverso=='N')
	{
		count = 0;
		Filmes *ptaux = *inicioF;
		if(ptaux==NULL)
		{
			printf("\n Desculpe mas esta entrada nao existe! ");
		}
		while(ptaux!=NULL)
		{
			printf("\n Filme: %s\n", ptaux->NomeFilmes);
			printf(" Diretor/Diretores: %s\n", ptaux->Diretores);
			printf(" Ano: %d \n", ptaux->ano);
			/*printf("\n Atores Que Participaram do Filme: \n");
			while(ptaux->atores!=NULL)
			{
				printf(" %s\n", ptaux->atores->nome);
				ptaux->atores = ptaux->atores->prox;
				
			}*/
			ptaux = ptaux->prox;
			count++;
			if(flag==count)
			{
				system("pause");
				count=0;
			}
		}
		
	}
	else if(NormalOuReverso=='R')
	{
		count = 0;
		Filmes *ptaux = *inicioF;
		if(ptaux==NULL)
		{
			printf("\n Desculpe mas esta entrada nao existe! ");
		}
		while(ptaux!=NULL)
		{
			printf("\n Filme: %s ", ptaux->NomeFilmes);
			printf("; Diretor/Diretores: %s ", ptaux->Diretores);
			printf("; Ano: %d ", ptaux->ano);
			/*printf("\n Atores Que Participaram do Filme: \n");
			while(ptaux->atores!=NULL)
			{
				printf(" %s\n", ptaux->atores->nome);
				ptaux->atores = ptaux->atores->prox;
				
			}*/
			ptaux = ptaux->prox;
			count++;
			if(flag==count)
			{
				system("pause");
				flag=0;
			}
		}
	}

}

void defineAtoresAlfabeticoOuReverso(Atores **inicioA, Atores **fimA) // Sub-menu para definir qual tipo de listagem de atores será feita, com a opção 0 para sair
{
	int flag = 1;
	while(flag>=1)
	{
		system("cls");
		printf("\n Deseja listar os atores em ordem alfabetica(1) ou alfabetica reversa(2)?\n(Se desejar, digite 0 para sair)\n");
		scanf("%d",&flag);
		switch(flag)
		{
			case(0):
			{
				system("cls");
				return;
				break;	
			}
			case(1):
			{
				ListaAtoresOrdemAlfabetica(inicioA,fimA,'N');
				break;
			}
			case(2):
			{
				ListaAtoresOrdemAlfabetica(inicioA,fimA,'R');
				break;
			}
			default:
				printf("\nDigite uma opção válida!");
				break;
		}
	}
}
void ListaAtoresOrdemAlfabetica(Atores **inicioA, Atores **fimA, char NormalOuReverso) // Listagem de atores em ordem alfabética ou alfabética reversa
{
	int flag=0,count;
	char SimNao;
	
	printf("\n Deseja definir quantos nomes aparecem na tela por vez?[S/N]\n");
	scanf(" %c",&SimNao);
	SimNao=toupper(SimNao);
	if( SimNao=='S' || SimNao=='s')
	{	
		while(flag<1 || flag>100)
		{
			printf("\n Quantos? (entre 1 e 100)\n");
			scanf(" %d", &flag);
			if(flag<1 || flag > 100)
				{
					printf("\n Digite um número válido!");
				}
		}
	}

	
	if(NormalOuReverso=='N')
	{
		Atores *ptaux = *inicioA;
		count = 0;
		while(ptaux!=NULL)
		{
			
			printf("\n Ator: %s  ", ptaux->NomeAtor);
		/*	printf(" Filmes que participou: ");
			while(ptaux->filmes!=NULL)
			{
				printf(" %s,", ptaux->filmes->nome);
				ptaux->filmes = ptaux->filmes->prox;
			}*/
			ptaux = ptaux->prox;
			count++;
			if(flag==count)
			{
				system("pause");
				count = 0;
			}
		}
	}
	else if(NormalOuReverso=='R')
	{
		Atores *ptaux = *fimA;

		while(ptaux!=NULL)
		{
			
			printf("\n Ator: %s  ", ptaux->NomeAtor);
		/*	printf(" Filmes que participou: ");
			while(ptaux->filmes!=NULL)
			{
				printf(" %s,", ptaux->filmes->nome);
				ptaux->filmes = ptaux->filmes->prox;
			}*/
			ptaux = ptaux->ant;
			count++;
			if(flag==count)
			{
				system("pause");
				count = 0;
			}
		}
	}
	system("pause");
}


void buscaFilmeEspecifico(Filmes **inicioF) // Pesquisa para verificações específicas. Utilizada para testes
{
	char nome[100];
	printf("\n Digite o nome do filme que deseja pesquisar:");
	scanf("\n%[a-z A-Z 1-9]", nome);
	Filmes *ptaux = verificaFilmes(inicioF, nome);
	if(ptaux!= NULL )
	{
		printf("\n Nome do Filme: %s", ptaux->NomeFilmes);
		printf("\n Diretor do Filme: %s\n", ptaux->Diretores);
		printf("\n %d", ptaux->ano);
		if(ptaux->atores!=NULL && ptaux->atores->prox!=NULL) printf("\n Atores/Atrizes que participaram do filme:");
		else if(ptaux->atores!=NULL) printf("\nAtor/Atriz que participou do filme:");
		while(ptaux->atores!=NULL)
		{
			printf("\n%s",ptaux->atores->nome);
			ptaux->atores = ptaux->atores->prox;
		}
		system("pause");
	}
	else printf("Desculpe, esse filme não existe!");
}


/* Sessão de funções relacionadas aos personagens; Mesmo padrão que os acima */



struct nodoPersonagens *InserePersonagem(Personagens **inicioP, char NomePersonagem[50])
{
	Personagens *ptaux, *ptnovo= (Personagens *)malloc(sizeof(Personagens));
	strcpy(ptnovo->NomePersonagem,NomePersonagem);
	ptnovo->prox=*inicioP;
	if(*inicioP==NULL || strcmp(NomePersonagem,(*inicioP)->NomePersonagem)>0)
	{
		*inicioP=ptnovo;
		return ptnovo;
	}
	ptaux = *inicioP;
	while ( ptaux->prox!=NULL && strcmp(ptaux->prox->NomePersonagem,NomePersonagem)<0)
	{
		ptaux=ptaux->prox;
	}
	
	ptnovo->prox=ptaux->prox;
	ptaux->prox=ptnovo;
	return ptnovo;
}


void InsereFilmesListaFPersonagens(FilmesPersonagens **inicioFP, Filmes **Pos )
{
	FilmesPersonagens *ptaux = (FilmesPersonagens *)malloc(sizeof(FilmesPersonagens));
	ptaux->filmes = *Pos;
	ptaux->prox = *inicioFP;
	*inicioFP = ptaux;
}

void InsereAtorListaPersonagem(AtoresFilmes **inicioAF, Atores **ator)
{
	AtoresFilmes *ptaux = (AtoresFilmes *)malloc(sizeof(AtoresFilmes));
	ptaux->nome = *ator;
	ptaux->prox = *inicioAF;
	*inicioAF = ptaux;
}

void ListaPersonagens(Personagens **inicioP)
{
	Personagens *ptaux = *inicioP;
	while(ptaux!=NULL)
	{
		printf("\nPersonagem:%s\n",ptaux->NomePersonagem);
		while(ptaux->atores!=NULL && ptaux->filmes!= NULL)
		{
			printf("Ator:%s Filme: %s Ano: %d\n", ptaux->atores->nome->NomeAtor, ptaux->filmes->filmes->NomeFilmes, ptaux->filmes->filmes->ano);
			ptaux->atores = ptaux->atores->prox;
			ptaux->filmes = ptaux->filmes->prox;
		}
		ptaux=ptaux->prox;
		system("pause");
	}
}


