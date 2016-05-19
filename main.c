
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

int menu();

int leitura(Filmes **inicioF, Filmes **fimF, Atores **inicioA, Atores **fimA, Personagens **inicioP);

void InsercaoInicial(Filmes **inicioF, Filmes **fimF, Atores **inicioA, Atores **fimA, Personagens **inicioP, char ValorASerInserido[600]);

struct nodoFilmes * insereOrdenadoNaListaDeFilmes(Filmes **inicioF, Filmes **fimF ,char nome[100], int ano, char Diretores[200]);

struct nodoAtores *insereOrdenadoNaListaDeAtores( Atores **inicio, Atores **fim , char nome[100]);

struct nodoAtores *verificaAtores(Atores **inicioA, char nome[100]);

struct nodoFilmes *verificaFilmes(Filmes **inicioF, char nome[100]);

struct nodoPersonagens *verificaPersonagens(Personagens **inicioP, char NomePersonagem[50]);

void buscaFilmeEspecifico(Filmes **inicioF);

void InsereAtorListaAFilmes(AtoresFilmes **inicioAF, Atores **Pos );

void InsereFilmesListaFAtor(FilmesAtores **inicioFA, Filmes **Pos , Atores **Ator);

void InsereFilmesListaFPersonagens(FilmesPersonagens **inicioFP, Filmes **Pos );

struct nodoPersonagens *InserePersonagem(Personagens **inicioP, char NomePersonagem[50]);

void InsereAtorListaPersonagem(AtoresFilmes **inicioAF, Atores **ator);

void InserePersonagemListaAtor(AtoresFilmes **inicioAF, Personagens **pos);

void insercaoOrdenada(Filmes **inicioF, Filmes **fimF, Atores **inicioA, Atores **fimA, char ValorASerInserido[600]);

int PesquisaNasStructs(Filmes **inicioF, Atores **inicioA, char ValorPesquisa[200], char FilmeAnoDiretorNome);

void ListaFilmesOrdemAlfabetica(Filmes **inicioF); // FunÁ„o que mostra a lista de filmes (como j· est· ordenada, est· "em ordem alfabÈtica");

void ListaAtoresOrdemAlfabetica(Atores **inicioA); // FunÁ„o que mostra a lista de atores (como j· est· ordenada, est· "em ordem alfabÈtica");

void ListaPersonagens(Personagens **inicioP); // FunÁ„o teste para visualizar a lista de personagens

int main()
{
	Filmes *inicioF = NULL, *fimF = NULL; // InÌcio/fim lista Filmes.
	Atores *inicioA = NULL, *fimA = NULL; // InÌcio/fim lista Atores.
	Personagens *inicioP = NULL;
	setlocale(LC_ALL,"Portuguese");
	if((leitura(&inicioF, &fimF, &inicioA, &fimA, &inicioP))==0) //verifica se conseguiu ler o arquivo
	{
		printf("\n Erro! Arquivo n√£o encontrado. \n");
		printf("Insira o arquivo no diretorio especifico e tente novamente. \n");
		return; // Encerra o programa
	}
	
	int escolha = menu(); // Verifica a primeira escolha. Se for para sair, retorna e encerra o programa;
/*	if(escolha!=0) 		 // Inicializa o inÌcio e fim das listas atÈ ent„o utilizadas.
	{
		
		
	}*/
	while(escolha>0) //Escolha 0 == sair do programa
	{
		switch (escolha)
		{
			case 1:
				ListaFilmesOrdemAlfabetica(&inicioF); // teste
				break;
			case 2:
				ListaAtoresOrdemAlfabetica(&inicioA); // teste
				break;
			case 3:
				buscaFilmeEspecifico(&inicioF); // teste
				break;
			case 4:
				ListaPersonagens(&inicioP); // teste
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
		printf("\n 2:Listar todos os filmes de um determinado ator em ordem cronol√≥gica.");
		printf("\n 3:Listar todos os filmes em ordem alfab√©tica e alfab√©tica reversa.");
		printf("\n 4:Inserir novos filmes");
		printf("\n 5:Remover filmes");
		printf("\n 6:Listar todos os filmes de um determinado diretor (ordem cronologica)");
		printf("\n 7:Listar todos os atores que trabalharam diretamente com um determinado ator e o nome do filme no qual trabalharam juntos");
		printf("\n 8:Listar todos os atores que trabalharam diretamente com um diretor e o nome do filme em que trabalharam juntos");
		printf("\n 9:Listar todos os filmes que est√£o duplicados");
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
	
	int i, j=0,k; //variaveis contadoras para percorrer a linha, a string at√© a virgula e a string auxiliar, respectivamente;
	
	int ano,l,m,n, flagSairLacoStatus2, contador; // vari·veis contadoras para a verificaÁ„o de outros diretores (utilizadas no status 2)
	
	int o, flagPersonagem; // Vari·veis contadoras para o segmento de status >2;
	int status=0; //status para a inser√ß√£o nos elementos do nodo
	
	
	for(i=0; i<strlen(ValorASerInserido); i++)//Percorre o vetor de chars
	{ 
		if(ValorASerInserido[i]==',' || ValorASerInserido[i+1]=='\0')
		{ 
			strcpy(aux,"");
			k=0;	//zera o contador da string auxiliar
			for(j; j<i ;j++){ // percorre da posicao inicial at√© a virgula
			
				aux[k]=ValorASerInserido[j]/*)*/; //insere char a char na string auxiliar

				k++; //proxima posicao na string auxiliar
				
			}
			
			aux[k]='\0'; // encerra a string at√© a virgula
			
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

				/* O PrÛximo LaÁo ir· verificar se existem mais diretores no mesmo filme. 
				Se ele conseguir encontrar o 'dir:' na frente, ir· copiar o nome para a string que ser· inserida na lista com o filme */
				
				
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

					while(ValorASerInserido[m]!=',' ) //&& ValorASerInserido[m]!='\0')  <--- N„o encontrei caso que fosse necess·rio (programa passou a ter comportamento estranho)
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
						flagSairLacoStatus2 = 1 ; // quebra o laÁo e insere o nome dos diretores na lista de filmes.
						Diretores[l+1] = '\0'; // insere indicador de fim de linha para evitar loops
						i = m; // ATEN«„O: vari·vel i È incrementada aqui pois outro nome de diretor fora inserido
						// diretamente da string ValorASerInserido. Assim, nenhum nome È duplicado no prÛximo status.

					}


				}

				novoF = insereOrdenadoNaListaDeFilmes(inicioF,fimF,NomeFilme,ano,Diretores); // inserÁ„o do filme de maneira ordenada na lista de filmes
				novoF->atores = NULL; // insere NULL na struct AtoresFilme, pois o filme recÈm fora inserido.
			}
			else if(status>2) 
			{
				o = 0; // vari·vel contadora utilizada nas cÛpias seguintes
				
				flagPersonagem = 0; //zera o indicador de personagem
				
				while(aux[o]!='=') // copia o nome do ator para a string respectiva atÈ ou encontrar = ou o caracter de final de string.
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
					while(aux[o]!='\0') // Enquanto n„o estiver no fim da string auxiliar, continua a inserÁ„o.
				 	{
						NomePersonagem[n] = aux[o]; // transfere o nome do personagem.
						n++;
						o++;
					}	
					
				NomePersonagem[n]='\0'; //determina o fim da string para evitar loops.
				
				}
				
				
				novoA = verificaAtores(inicioA,nomeAtor); // Aqui È verificada a existÍncia do determinado ator. Se existe, retorna a posiÁ„o da struct;
				

				if(novoA == NULL) // Se retornar nulo, insere o ator.
				{
					novoA = insereOrdenadoNaListaDeAtores( inicioA, fimA, nomeAtor); // insere ator novo, para facilitar nossa vida futuramente na listagem.
					novoA->filmes = NULL; // define como NULL a lista de filmes, pois o ator fora recÈm inserido.
						
				}
				
				InsereAtorListaAFilmes(&novoF->atores, &novoA); // Insere o ator na lista AtoresFilmes do Filme que est· sendo inserido.
				InsereFilmesListaFAtor(&novoA->filmes,&novoF,&novoA); // Insere o filme na lista FilmesAtores do Ator que est· sendo inserido (ou j· existe).
				
				if(flagPersonagem==1) // Se existir = na vari·vel aux, significa que possui personagem.
				{
					
					novoP  = verificaPersonagens(inicioP, NomePersonagem); // Faz a verificaÁ„o se existe, da mesma maneira como È feita logo acima para atores.

					if(novoP == NULL) // Se for NULL, insere o personagem.
					{
				 		novoP = InserePersonagem(inicioP, NomePersonagem);
				 	}

				 	InsereFilmesListaFPersonagens(&novoP->filmes, &novoF); // Insere filme na lista FilmesPersonagens do Personagem
				 	InsereAtorListaPersonagem(&novoP->atores, &novoA); //Insere ator que interpretou determinado personagem na lista do personagem.
				 	

					strcpy(NomePersonagem,""); //"Zera" a vari·vel para a prÛxima iteraÁ„o.
				}

			}

			j=i+1; //comeca a contagem da proxima string ap√≥s a virgula 
		 status++; // incrementa o status, para continuar a leitura.

		}

	}
	
}

struct nodoFilmes * insereOrdenadoNaListaDeFilmes(Filmes **inicioF, Filmes **fimF,char nome[100], int ano, char Diretores[200])
{				// InserÁ„o ordenada por nome

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

struct nodoAtores *insereOrdenadoNaListaDeAtores( Atores **inicio, Atores **fim , char nome[100]) // inserÁ„o ordenada por nome.
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

struct nodoAtores *verificaAtores(Atores **inicioA, char nome[50]) // verificaÁ„o se existe ator. Se existe, retorna o ator.
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


struct nodoFilmes *verificaFilmes(Filmes **inicioF, char nome[100]) // verificaÁ„o se existe filme. Se existe, retorna o filme. 
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

struct nodoPersonagens *verificaPersonagens(Personagens **inicioP, char NomePersonagem[50]) // verificaÁ„o se existe personagem. Se existe, retorna o personagem.
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

void InsereAtorListaAFilmes(AtoresFilmes **inicioAF, Atores **Pos ) // Insere no inÌcio da lista AtoresFilmes na lista Atores * favor verificar em inserÁ„oInicial *
{
	AtoresFilmes *ptaux = (AtoresFilmes *)malloc(sizeof(AtoresFilmes));
	ptaux->nome = *Pos;
	ptaux->prox = *inicioAF;
	*inicioAF = ptaux;

}

void InsereFilmesListaFAtor(FilmesAtores **inicioFA, Filmes **Pos , Atores **Ator) // Insere no inÌcio da lista FilmesAtores na lista Filmes * favor verificar em inserÁ„oInicial *
{
	FilmesAtores *ptaux = (FilmesAtores *)malloc(sizeof(FilmesAtores));
	ptaux->nome = *Pos;
	ptaux->prox = *inicioFA;
	*inicioFA = ptaux;
}

void ListaFilmesOrdemAlfabetica(Filmes **inicioF) // listagem simples
{
	Filmes *ptaux = *inicioF;
	int flag=0;
	while(ptaux!=NULL)
	{
		printf("\n Filme: %s\n", ptaux->NomeFilmes);
		printf(" Diretor: %s\n", ptaux->Diretores);
		printf(" Ano: %d \n", ptaux->ano);
		printf("\n Atores Que Participaram do Filme: \n");
		while(ptaux->atores!=NULL)
		{
			printf(" %s\n", ptaux->atores->nome);
			ptaux->atores = ptaux->atores->prox;
			
		}
		ptaux = ptaux->prox;
		flag++;
		if(flag==100)
		{
			system("cls");
			flag=0;
		}
	}
	system("pause");
}


void ListaAtoresOrdemAlfabetica(Atores **inicioA) // listagem simples
{
	Atores *ptaux = *inicioA;
	int flag=0;
	while(ptaux!=NULL)
	{
		
		printf("\n Ator: %s", ptaux->NomeAtor);
		printf(" Filmes que participou: ");
		while(ptaux->filmes!=NULL)
		{
			printf(" %s,", ptaux->filmes->nome);
			ptaux->filmes = ptaux->filmes->prox;
		}
		ptaux = ptaux->prox;
		flag++;
		if(flag==19)
		{
			system("pause");
			flag=0;
		}
	}
	system("pause");
}


void buscaFilmeEspecifico(Filmes **inicioF) // Pesquisa para verificaÁıes especÌficas. Utilizada para testes
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
	else printf("Desculpe, esse filme n„o existe!");
}


/* Sess„o de funÁıes relacionadas aos personagens; Mesmo padr„o que os acima */



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
