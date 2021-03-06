#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <time.h>

typedef struct nodoAtoresFilmes{struct nodoAtores *nome;struct nodoAtoresFilmes *prox;} AtoresFilmes; // Lista de atores de um filme
typedef struct nodoFilmesAtores{struct nodoFilmes *nome;struct nodoFilmesAtores *prox;} FilmesAtores; // Lista de filmes de um ator
typedef struct nodoDiretoresFilmes{struct nodoDiretores *nome;struct nodoDiretoresFilmes *prox;} DiretoresFilmes; // Lista de diretores que participaram de determinado filme
typedef struct nodoDiretores{char NomeDiretor[50];struct nodoFilmesAtores *filmes; struct nodoDiretores*prox; } Diretores; // Lista de diretores com os filmes que o diretor participou 
typedef struct nodoFilmes{char NomeFilmes[100]; int ano; struct nodoDiretoresFilmes *diretores; struct nodoFilmes *prox; struct nodoFilmes *ant; struct nodoAtoresFilmes *atores;} Filmes; //Lista principal dos filmes
typedef struct nodoAtores{char NomeAtor[50];struct nodoAtores *prox; struct nodoAtores *ant; struct nodoFilmesAtores *filmes;} Atores; // Lista principal dos atores
typedef struct nodoFilmesPersonagens{struct nodoFilmes *filmes; struct nodoFilmesPersonagens *prox;} FilmesPersonagens; // lista de filmes em que determinados personagens apareceram
typedef struct nodoPersonagens{char NomePersonagem[50]; struct nodoPersonagens *prox; struct nodoAtoresFilmes *atores; struct nodoFilmesPersonagens *filmes;} Personagens; // lista de personagens interpretados
typedef struct nodoAtoresRelacionados{char Nome[50]; struct nodoAtoresRelacionados *proxA; struct nodoAtoresRelacionados *proxF;} AtoresRelacionados; // lista de atores que atuaram diretamente com determinado ator
typedef struct nodoAtoresDiretor{char Nome[100]; struct nodoAtoresDiretor *proxA; struct nodoAtoresDiretor *proxF;} AtoresDiretor; // lista de atores que atuaram diretamente com determinado diretor



/* ---- MENUS ---- */

int menu();

void defineAtoresAlfabeticoOuReverso(Atores **inicioA, Atores **fimA); // Fun��o que define se a lista de atores ser� mostrada em ordem alfab�tica ou alfab�tica reversa

void defineFilmesAlfabeticoOuReverso(Filmes **inicioF, Filmes **fimF); // Fun��o que define se a lista de filmes ser� mostrada em ordem alfab�tica ou alfab�tica reversa

void menuInserirFilme(Filmes **inicioF, Filmes **fimF, Atores **inicioA, Atores **fimA, Diretores **inicioD, Personagens **inicioP);

// Complemento para o menu principal

void tituloProg();


/* ----------------------- */


/* -------------------Fun�ões INICIAIS------------------------- */


int leitura(Filmes **inicioF, Filmes **fimF, Atores **inicioA, Atores **fimA, Personagens **inicioP, Diretores **inicioD);

void InsercaoInicial(Filmes **inicioF, Filmes **fimF, Atores **inicioA, Atores **fimA, Diretores **inicioD, Personagens **inicioP, char ValorASerInserido[2100]); // Fun��o que define quais outras fun�ões s�oo chamadas, partindo do valor concatenado que recebe.

/* ---------------------------------------------------------- */


/* -------------------Fun�ões PESQUISA------------------------- */

struct nodoAtores *verificaAtores(Atores **inicioA, char nome[100]);

struct nodoFilmes *verificaFilmes(Filmes **inicioF, char nome[100]);

struct nodoPersonagens *verificaPersonagens(Personagens **inicioP, char NomePersonagem[50]);

struct nodoDiretores *verificaDiretores(Diretores **inicioD, char NomeDir[50]);

void buscaFilmeEspecifico(Filmes **inicioF); // Fun��o para teste

/* ---------------------------------------------------------- */



/* -------------------Fun�ões INSERÇÃO------------------------- */

struct nodoFilmes * insereOrdenadoNaListaDeFilmes(Filmes **inicioF, Filmes **fimF ,char nome[100], int ano); // Insere o filme ordenado na lista de filmes

struct nodoAtores *insereOrdenadoNaListaDeAtores( Atores **inicio, Atores **fim , char nome[100]); // Insere o ator ordenado na lista Atores

void InsereAtorListaAFilmes(AtoresFilmes **inicioAF, Atores **Pos ); // insere ator na lista AtoresFilmes do Filme

void InsereFilmesListaFAtor(FilmesAtores **inicioFA, Filmes **Pos ); // insere filme na lista de filmes atores (em ordem cronol�gica)

struct nodoDiretores * InsereDiretor(Diretores **inicioD, char NomeDir[50]);

void InsereFilmeListaDiretor(FilmesAtores **FilmesDiretor, Filmes **Pos);

void InsereDiretorListaFilme(DiretoresFilmes **Diretor, Diretores **Pos);

void InsereFilmesListaFPersonagens(FilmesPersonagens **inicioFP, Filmes **Pos ); // insere filmes na lista de filmes personagens

struct nodoPersonagens *InserePersonagem(Personagens **inicioP, char NomePersonagem[50]); // Inser��o do personagem

void InsereAtorListaPersonagem(AtoresFilmes **inicioAF, Atores **ator); // ...

void InserePersonagemListaAtor(AtoresFilmes **inicioAF, Personagens **pos); // ...

void InsereAtoresRelacionados( AtoresRelacionados **inicioAR, AtoresRelacionados **headAR, char filme[50], char ator[50]);

void InsereAtoresRelacionadosDiretores( AtoresDiretor **inicioAD, AtoresDiretor **headAD, char filme[100], char ator[100]);
					

/* ---------------------------------------------------------- */



/* -------------------Fun�ões STRINGS------------------------ */


void substituiString(char aux, char nova[], int i); // Substitui os valores de letras acentuadas por letras acentuadas.

void tratarAcento(char nomeNodo[], char nome[]); // Troca letras acentuadas por letras normais, em UPPERCASE, para ordena��o.

int compararStringAcento(char nomeNodo[],char nome[]); //  Chama a fun��o tratar acento e compara as duas strings.

/* ---------------------------------------------------------- */





/* -------------------Fun�ões LISTAR------------------------- */

void ListaFilmesOrdemAlfabetica(Filmes **inicioF, Filmes **fimF, char NormalOuReverso); // Fun��o que mostra a lista de filmes

void listarFilmesAtorOrdemCronologica(Atores **inicioA, Filmes **inicioF); // Fun��o que lista os filmes do ator em ordem cronol�gica

void listarFilmesDiretorOrdemCronologica(Diretores **inicioD,Filmes **inicioF); //

void ListaAtoresOrdemAlfabetica(Atores **inicioA, Atores **fimA, char NormalOuReverso); // Fun��o que mostra a lista de atores

void ListaAtoresPersonagens(Atores **inicioA, Personagens **inicioP, Filmes **inicioF); // Fun��o teste para visualizar a lista de personagens

void ListarAtoresRelacionadosAtores(Atores **inicioA); // Funcao que lista atores e atores relacionados 

void ListarDuplicados(Filmes **inicioF);

void ListarAtoresDiretor(Diretores **inicioD, Filmes **inicioF);
/* -------------------------------------------------------- */



/* -------------------Fun�ões REMOVER------------------------- */

int deletaFilmes(Filmes **inicioF, char nomeFilme[]);

void menuDeletaFilmes(Filmes **inicioF, Filmes **fimF, Atores **inicioA, Atores **fimA, Personagens **inicioP);

void remover(Filmes **inicioF, char nome[100]);

/* ----------------------------------------------------------- */

int main()
{
	system("mode con:cols=100 lines=30");
	system("cls");
	system("title Banco de Filmes e Atores");
	setlocale(LC_ALL,"");
	tituloProg();
	printf("\n");

	Filmes *inicioF = NULL, *fimF = NULL; // In�cio/fim lista Filmes.
	Atores *inicioA = NULL, *fimA = NULL; // In�cio/fim lista Atores.
	Diretores *inicioD = NULL;
	Personagens *inicioP = NULL;

	if((leitura(&inicioF, &fimF, &inicioA, &fimA, &inicioP, &inicioD))==0) //verifica se conseguiu ler o arquivo
	{
		printf("\n Erro! Arquivo n�o encontrado. \n");
		printf("Insira o arquivo no diretorio especifico e tente novamente. \n");
		system("pause");
		return; // Encerra o programa
	}

	int escolha = menu(); // Verifica a primeira escolha. Se for para sair, retorna e encerra o programa;
	while(escolha>0) //Escolha 0 == sair do programa
	{

		switch (escolha)
		{
			case 1:
				defineAtoresAlfabeticoOuReverso(&inicioA, &fimA);
				break;
			case 2:
				listarFilmesAtorOrdemCronologica(&inicioA, &inicioF);
				break;
			case 3:
				defineFilmesAlfabeticoOuReverso(&inicioF, &fimF);

				break;
			case 4:
				menuInserirFilme(&inicioF, &fimF, &inicioA, &fimA,&inicioD, &inicioP);
				break;
			case 5:
				menuDeletaFilmes(&inicioF, &fimF, &inicioA, &fimA, &inicioP);
				break;
			case 6:
				listarFilmesDiretorOrdemCronologica(&inicioD, &inicioF);
				break;
			case 7:
				ListarAtoresRelacionadosAtores(&inicioA);
				break;
			case 8:
				ListarAtoresDiretor(&inicioD, &inicioF);
				break;
			case 9:
				ListarDuplicados(&inicioF);
				break;
			case 10:
				ListaAtoresPersonagens(&inicioA, &inicioP, &inicioF);
				break;
			case 11:
				buscaFilmeEspecifico(&inicioF);
				break;
		}
		system("cls");
		tituloProg();
		escolha = menu();

	}
	printf("\n Obrigado por utilizar o programa!");
	printf("\n Vers�o 1.0.0");
	printf("\n Au Revoir!");

}

void tituloProg()
{
		printf("\t+-----------------------------------------------------------------------------+\n");
		printf("\t|-------------------------+---------------------------+-----------------------|\n");
		printf("\t|-------------------------| Banco de Dados de Filmes  |-----------------------|\n");
		printf("\t|-------------------------|  da aula de Programa��o 2 |-----------------------|\n");
		printf("\t|-------------------------+---------------------------+-----------------------|\n");
		printf("\t+-----------------------------------------------------------------------------+\n\n\n");

}

int menu()
{
	int opcaoMenu = 0;

	while(opcaoMenu!= -1 )
	{
		printf("\n\t  +-------------------------------------------------------------------------+");
		printf("\n\t | 1:Listar todos os atores da lista em ordem alfab�tica e alfab�tica reversa ");
		printf("\n\t | 2:Listar todos os filmes de um determinado ator em ordem cronol�gica.");
		printf("\n\t | 3:Listar todos os filmes em ordem alfab�tica e alfab�tica reversa.");
		printf("\n\t | 4:Inserir um novo filme");
		printf("\n\t | 5:Remover um filme");
		printf("\n\t | 6:Listar filmes de um determinado diretor (ordem cronol�gica)");
		printf("\n\t | 7:Listar atores que trabalharam  com um determinado ator");
		printf("\n\t | 8:Listar atores que trabalharam  com um determinado diretor");
		printf("\n\t | 9:Listar filmes que est�o duplicados");
		printf("\n\t | 10:Listar os atores que interpretaram um determinado personagem");
		printf("\n\t | 11:Buscar filme espec�fico");
		printf("\n\t |\t 0: Para sair do programa");
		printf("\n\t  +------------------------------+\n");

		scanf("%d", &opcaoMenu);
		if(opcaoMenu<-1 || opcaoMenu>11)
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

int leitura(Filmes **inicioF, Filmes **fimF, Atores **inicioA, Atores **fimA,Personagens **inicioP ,Diretores **inicioD)
{

	FILE *arquivo; // especificando o arquivo...
	char linha[600]; // linha que recebera os dados lidos
	arquivo = fopen("resumo.txt", "r"); // abre o arquivo em modo leitura
	int count=0;
	if(arquivo==NULL)
	{
		return 0; // retorna 0 para indicar falha ao abrir.
	}
	else
	{
		printf("\n\t\t Este programa � inteiramente Case Sensitive. Seja preciso em suas buscas!\n");
		printf("\n\t\t\t\t\t+----------------+");
		printf("\n\t\t\t\t\t| Inicializando  |");
		printf("\n\t\t\t\t\t+----------------+");
		printf("\n");
		
		while((fgets(linha, sizeof(linha), arquivo))!= NULL)
		{

			InsercaoInicial(&(*inicioF), &(*fimF), &(*inicioA), &(*fimA), &(*inicioD), inicioP, linha); // Atualiza diretamente a lista de filmes e atores

		}
		system("cls");
		tituloProg();

		fclose(arquivo);
		return 1; // retorna 1 para indicar que abriu com sucesso.
	}
}


void InsercaoInicial(Filmes **inicioF, Filmes **fimF, Atores **inicioA, Atores **fimA, Diretores **inicioD,Personagens **inicioP, char ValorASerInserido[2100])
{
	Filmes *novoF = NULL;
	Atores *novoA = NULL;
	Diretores *novoD = NULL;
	Personagens *novoP = NULL;

	char aux[100], nomeAtor[100], NomePersonagem[50], Diretor[50], NomeFilme[100];

	int i, j=0,k; //variaveis contadoras para percorrer a linha, a string at� a virgula e a string auxiliar, respectivamente;

	int ano,l,m,n, flagSairLacoStatus2, contador; // vari�veis contadoras para a verifica��o de outros diretores (utilizadas no status 2)

	int o, flagPersonagem; // Vari�veis contadoras para o segmento de status >2;
	int status=0; //status para a inser��o nos elementos do nodo


	for(i=0; i<strlen(ValorASerInserido); i++)//Percorre o vetor de chars
	{
		if(ValorASerInserido[i]==',' || ValorASerInserido[i+1]=='\0')
		{
			strcpy(aux,"");
			k=0;	//zera o contador da string auxiliar
			for(j; j<i ;j++){ // percorre da posicao inicial at� a virgula

				aux[k]=ValorASerInserido[j]; //insere char a char na string auxiliar

				k++; //proxima posicao na string auxiliar

			}

			aux[k]='\0'; // encerra a string at� a virgula

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
				novoF = insereOrdenadoNaListaDeFilmes(inicioF,fimF,NomeFilme,ano); // inser��o do filme de maneira ordenada na lista de filmes
				novoF->diretores = NULL;
				strcpy(Diretor, "");
				strcpy(Diretor, aux);
				novoD = verificaDiretores(&(*inicioD),Diretor);
				if(novoD==NULL)
				{
					novoD = InsereDiretor(&(*inicioD),Diretor);
					novoD->filmes = NULL;
				}
				InsereDiretorListaFilme(&novoF->diretores,&novoD);
				InsereFilmeListaDiretor(&novoD->filmes,&novoF);
				/* O Pr�ximo La�o ir� verificar se existem mais diretores no mesmo filme.
				Se ele conseguir encontrar o 'dir:' na frente, ir� copiar o nome para a string que ser� inserida na lista com o filme */


				m = j+1;


				if(ValorASerInserido[m]=='d' && ValorASerInserido[m+1]=='i' && ValorASerInserido[m+2]=='r' && ValorASerInserido[m+3]==':')
				{
					m += 4;
					flagSairLacoStatus2 = 0;
					strcpy(Diretor, "");
					while(flagSairLacoStatus2 == 0)
					{
						l=0;
						while(ValorASerInserido[m]!=',' && ValorASerInserido[m]!='\0') // <--- N�oo encontrei caso que fosse necess�rio (programa passou a ter comportamento estranho)
						{
	
							Diretor[l]=ValorASerInserido[m];
	
							l++;
							m++;
						}
							Diretor[l] = '\0';
						if(ValorASerInserido[m+1]=='d' && ValorASerInserido[m+2]=='i' && ValorASerInserido[m+3]=='r' && ValorASerInserido[m+4]==':' )
						{
							m+=5;
						}
						else
						{
							flagSairLacoStatus2 = 1 ; // quebra o la�o e insere o nome dos diretores na lista de filmes.
							i = m; // ATENÇ�oO: vari�vel i � incrementada aqui pois outro nome de diretor fora inserido
							// diretamente da string ValorASerInserido. Assim, nenhum nome � duplicado no pr�ximo status.
						}
						novoD = verificaDiretores(&(*inicioD),Diretor);
						if(novoD==NULL)
						{
							novoD = InsereDiretor(&(*inicioD),Diretor);
							novoD->filmes = NULL;
						}
						InsereDiretorListaFilme(&novoF->diretores,&novoD);
						InsereFilmeListaDiretor(&novoD->filmes,&novoF);
						strcpy(Diretor, "");
					}
				}

				
				novoF->atores = NULL; // insere NULL na struct AtoresFilme, pois o filme rec�m fora inserido.
				
			}
			else if(status>2 && aux[0]!='\0')
			{
				o = 0; // vari�vel contadora utilizada nas c�pias seguintes

				flagPersonagem = 0; //zera o indicador de personagem

				while(aux[o]!='=') // copia o nome do ator para a string respectiva at� ou encontrar = ou o caracter de final de string.
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
					while(aux[o]!='\0') // Enquanto n�oo estiver no fim da string auxiliar, continua a inser��o.
				 	{
						NomePersonagem[n] = aux[o]; // transfere o nome do personagem.
						n++;
						o++;
					}

				NomePersonagem[n]='\0'; //determina o fim da string para evitar loops.

				}


				novoA = verificaAtores(inicioA,nomeAtor); // Aqui � verificada a existência do determinado ator. Se existe, retorna a posi��o da struct;


				if(novoA == NULL) // Se retornar nulo, insere o ator.
				{
					novoA = insereOrdenadoNaListaDeAtores( inicioA, fimA, nomeAtor); // insere ator novo, para facilitar nossa vida futuramente na listagem.
					novoA->filmes = NULL; // define como NULL a lista de filmes, pois o ator fora rec�m inserido.

				}

				InsereAtorListaAFilmes(&novoF->atores, &novoA); // Insere o ator na lista AtoresFilmes do Filme que est� sendo inserido.
				InsereFilmesListaFAtor(&novoA->filmes,&novoF); // Insere o filme na lista FilmesAtores do Ator que est� sendo inserido (ou j� existe).

				if(flagPersonagem==1) // Se existir = na vari�vel aux, significa que possui personagem.
				{

					novoP  = verificaPersonagens(inicioP, NomePersonagem); // Faz a verifica��o se existe, da mesma maneira como � feita logo acima para atores.

					if(novoP == NULL) // Se for NULL, insere o personagem.
					{
				 		novoP = InserePersonagem(inicioP, NomePersonagem);
				 	}

				 	InsereFilmesListaFPersonagens(&novoP->filmes, &novoF); // Insere filme na lista FilmesPersonagens do Personagem
				 	InsereAtorListaPersonagem(&novoP->atores, &novoA); //Insere ator que interpretou determinado personagem na lista do personagem.


					strcpy(NomePersonagem,""); //"Zera" a vari�vel para a pr�xima itera��o
				}

			}

			j=i+1; //comeca a contagem da proxima string ap�s a virgula
		 status++; // incrementa o status, para continuar a leitura.

		}

	}

}

struct nodoFilmes * insereOrdenadoNaListaDeFilmes(Filmes **inicioF, Filmes **fimF,char nome[100], int ano)
{				// Inser��o ordenada por nome

		Filmes  *ptaux = (Filmes *)malloc(sizeof(Filmes));
		strcpy(ptaux->NomeFilmes,nome);
		ptaux->ano = ano;
		char nomeNovo[100];
		
		if(*inicioF==NULL || strcmp((*inicioF)->NomeFilmes,nome)>0)
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
			tratarAcento(nome, nomeNovo ); //Transforma letras min�sculas/acentuadas em mai�sculas sem acento, para compara��o.
			while(ptaux2->prox!=NULL && (compararStringAcento((ptaux2->prox->NomeFilmes),nomeNovo))<0)
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


struct nodoAtores *insereOrdenadoNaListaDeAtores( Atores **inicio, Atores **fim , char nome[100]) // inser��o ordenada por nome.
{
		Atores *ptaux = (Atores *)malloc(sizeof(Atores));
		strcpy(ptaux->NomeAtor,nome);
		if(*inicio==NULL || strcmp((*inicio)->NomeAtor,nome)>0)
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
			char nomeNovo[100];
			tratarAcento(nome, nomeNovo ); // Mesmo da fun��o acima.
			Atores *ptaux2 = *inicio;
			while(ptaux2->prox!=NULL && (compararStringAcento((ptaux2->prox->NomeAtor),nomeNovo))<0)
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


int deletaFilmes(Filmes **inicioF, char nomeFilme[]){ //retorna -1 se filme n�oo existe
	Filmes *ptauxF = *inicioF, *rF;
	AtoresFilmes *ptauxAF;
	Atores *ptauxA;
	FilmesAtores *ptauxFA;
	char aa[100];

	while(ptauxF!=NULL)
	{
		if(strcmp(ptauxF->NomeFilmes,nomeFilme)==0)
		{
			rF =ptauxF;
			if(ptauxF->prox !=NULL){//caso nao seja o ultimo da lista
				ptauxF->ant->prox = ptauxF->prox; //desvincula o nodo a lista de filmes
				ptauxF->prox->ant = ptauxF->ant;

			}else{ //caso seja o ultimo
				ptauxF->ant->prox =NULL;	
			}
			remover(inicioF, nomeFilme);

			ptauxAF = ptauxF->atores; // recebe o primeiro ator do filme
			while(ptauxAF!=NULL)
			{
				ptauxA =ptauxAF->nome; // Ator do filme, na lista de atores
				if (ptauxA->filmes->prox!=NULL){ // se o ator so tiver um filme, ignorar a exclusao, pois nao ha mais vinculo
					if(strcmp(ptauxA->filmes->nome->NomeFilmes, nomeFilme)==0){// se o primeiro filme do ator eho removido
						ptauxA->filmes= ptauxA->filmes->prox;// desvincula Filme do Ator
					}else{
						ptauxFA = ptauxA->filmes;
						while(ptauxFA->prox!=NULL){
						 	if(ptauxFA->prox->prox==NULL)//caso em que o ultimo filme eh o removido
						 		ptauxFA->prox=NULL; //desvincula o ultimo
							else if(strcmp(nomeFilme, ptauxFA->prox->nome->NomeFilmes)==0 ){// encontrado FA
								ptauxFA->prox= ptauxFA->prox->prox;//desvincula
                                			}
							else
							ptauxFA = ptauxFA->prox; //ainda nao encontrou o filme
						}
					}
				}else{// caso o  ator soh tehna um filme
					ptauxA->ant->prox = ptauxA->prox; //desvincula o nodo a lista de atores
					ptauxA->prox->ant = ptauxA->ant;
				}
				ptauxAF = ptauxAF->prox;
			}
			return;
		}
		ptauxF = ptauxF->prox;
	}
	return -1;
}


void remover(Filmes **inicioF, char nome[100])
{
	Filmes *ptaux;
	if(*inicioF==NULL)return;
	if(strcmp((*inicioF)->NomeFilmes,nome)!=0)
	{
		remover(&(*inicioF)->prox,nome);
		return;
	}
	ptaux=*inicioF;
	(*inicioF)=(*inicioF)->prox;
	free(ptaux);
}


void menuDeletaFilmes(Filmes **inicioF, Filmes **fimF, Atores **inicioA, Atores **fimA, Personagens **inicioP)
{
	char nomeFilme[100],aux;
	int i;



	system("cls");
		printf("\n Digite o nome do filme que deseja remover:\n ");
		i=0;
		while(i<100)
			{
				fflush(stdin);
				aux = getch();

				if(aux == 8 || aux==127)
				{
					if(i>0)
					{
						i--;
						printf("\b %c",aux);
					}
				}
				else if(aux == 13)
				{
					break;
				}
				else
				{
					substituiString(aux,nomeFilme,i);
					printf("%c",nomeFilme[i]);
					i++;
				}


			}
			nomeFilme[i] = '\0';
	
		if(deletaFilmes(inicioF, nomeFilme)== -1) // Verifica se o filme existe. Se n�oo, mostra a mensagem de erro e retorna ao menu principal...
		{
			printf("\n Erro, filme n�oo existe. Retornando ao menu principal!\n");
			system("pause");
			system("cls");
			return;
		}

		printf("\n Pronto! A remo��o est� feita.\n");

		printf("\n\n Retornando ao menu principal!\n");
		system("pause");
		system("cls");
		return;

}


void menuInserirFilme(Filmes **inicioF, Filmes **fimF, Atores **inicioA, Atores **fimA, Diretores **inicioD, Personagens **inicioP)
{
	int flag=0,i=0,ano,j=0,anoAtual;
	char aux;
	char simNao;
	char compAno[4];	// Para comparar com o ano inserido:
	char nomeFilme[100];
	char ValorASerInserido[2100];
	char Diretores[100];
	char nomeAtores[100];
	


	strcpy(nomeFilme,"");
	strcpy(ValorASerInserido,"");
	strcpy(compAno,"");


	time_t rawtime;
	struct tm *timeinfo;
	time (&rawtime);
	timeinfo = localtime(&rawtime);
	anoAtual = timeinfo->tm_year+1900;


	system("cls");
		printf("\n Digite o nome do filme que deseja inserir:\n ");
		while(i<100 )
			{
				fflush(stdin);
				aux = getch();

				if(aux == 8 || aux==127)
				{
					if(i>0)
					{
						i--;
						printf("\b %c",aux);
					}
				}
				else if(aux == 13)
				{
					break;
				}
				else
				{
					substituiString(aux,nomeFilme,i);
					printf("%c",nomeFilme[i]);
					i++;
				}


			}
			nomeFilme[i] = '\0';

		if(verificaFilmes(inicioF,nomeFilme)!=NULL) // Verifica se o filme j� existe. Se sim, mostra a mensagem de erro e retorna ao menu principal...
		{
			printf("\n Erro, filme j� existe. Retornando ao menu principal!\n");
			system("pause");
			system("cls");
			return;
		}
		else //... Se n�oo existe, concatena na string que ser� passada como parâmetro para a fun��o de Inser��o.
		{
			strcat(ValorASerInserido,nomeFilme);
			strcat(ValorASerInserido, ",");
		}

		printf("\n Deseja inserir o ano do filme?(S/N)\n");
		simNao = getch();
		if(toupper(simNao)=='S')
		{
			printf("\n Digite o ano em que foi lan�ado o filme:\n");
			scanf("%d",&ano);

			while(ano<1895 || ano>anoAtual+5) // Verifica se o ano inserido condiz com o ano do primeiro filme lan�ado na hist�ria do cinema ou � menor do que ano atual + 5 anos.
			{
				printf("\n A data est� fora da data de lan�amento do primeiro filme da hist�ria ou\n excede o limite de cinco anos partindo do ano atual.\n Digite outro ano!");
				scanf("%d",&ano);
			}

			sprintf(compAno, "%i", ano); //Converte o inteiro para char;

			strcat(ValorASerInserido,compAno); // Concatena o ano e uma vírgula
		}
		strcat(ValorASerInserido, ",");
		fflush(stdin);
		printf("\n Deseja inserir o nome de algum diretor que participou do filme?(S/N)\n");
		simNao = getch();
		if(toupper(simNao)=='S')
		{
			printf("\n Digite o nome do diretor do filme:\n");
			scanf(" %[^\n]",Diretores);
			

			strcat(ValorASerInserido,Diretores);

			fflush(stdin);

			printf("\n Existe(m) outro(s) Diretor(es) que participou(participaram) do filme?(S/N)\n"); // Se existirem outros diretores, concatenar� uma vírgula e ir� ler o nome dos diretores, um por um.
			simNao = getch();
			
			while(toupper(simNao)=='S')
			{
				fflush(stdin);
				strcat(ValorASerInserido,",dir:");
				printf("\n Digite o nome do proximo do diretor:\n");
				scanf(" %[^\n]",Diretores);

				strcat(ValorASerInserido,Diretores);

				printf("\n Existe(m) outro(s) Diretor(es) que participaram do filme?(S/N)\n");
				simNao = getch();
				if(toupper(simNao)!='N' && toupper(simNao)!='S') printf("\n Irei considerar isso como um sim!");
			}
		}

		fflush(stdin);
		printf("\n Deseja inserir algum ator/atriz que trabalhou no filme?(S/N)"); // M�ximo estabelecido de acordo com o arquivo resumo.txt
		printf("\n Dica: Se deseja incluir um personagem especifico para o ator,\n insira NomeDoAtor=NomePersonagem (substituindo com o que desejas). ");
		simNao = getch();
		while(toupper(simNao)=='S')
		{
			fflush(stdin);
			strcat(ValorASerInserido,","); // Concatena sempre a vírgula antes pois o �ltimo ficar� sem a vírgula ao final.
			printf("\n Digite um ator/atriz que trabalhou no filme \n"); 
			i=0;
			while(i<100 )
			{
				fflush(stdin);
				aux = getch();

				if(aux == 8 || aux==127)
				{
					if(i>0)
					{
						i--;
						printf("\b %c",aux);
					}
				}
				else if(aux == 13)
				{
					break;
				}
				else
				{
					substituiString(aux,nomeAtores,i);
					printf("%c",nomeAtores[i]);
					i++;
				}
			}
			nomeAtores[i] = '\0';

			strcat(ValorASerInserido,nomeAtores);
			strcpy(nomeAtores,"");

			fflush(stdin);
			printf("\n Deseja inserir mais algum ator/atriz que trabalhou no filme?(S/N)"); // M�ximo estabelecido de acordo com o arquivo resumo.txt
			simNao = getch();
		}
		if(toupper(simNao)=='N') strcat(ValorASerInserido,"i");

		InsercaoInicial(&(*inicioF),&(*fimF),&(*inicioA),&(*fimA),&(*inicioD),&(*inicioP),ValorASerInserido);

		printf("\n Pronto! A inser��o est� feita.\n");

		printf("\n Nome do filme para consultas: %s ", nomeFilme);

		printf("\n\n Retornando ao menu principal!\n");
		system("pause");
		system("cls");
		return;

}

void ListarDuplicados(Filmes **inicioF)
{
    Filmes *ptauxA = *inicioF;
   	system("cls");
    if (ptauxA == NULL) //caso a lista esteja vazia
	{
		printf("\n Nenhum filme duplicado fora encontrado! Retornando ao menu.");
		system("pause");
		return; 
	}
       
 	printf ("Lista de filmes duplicados: \n");
    while (ptauxA->prox != NULL) 	// A lista segue em sequ�ncia, pois j� estar� ordenada, da inser��o, o que facilita o trabalho.
    {
       if ((strcmp(ptauxA->NomeFilmes, ptauxA->prox->NomeFilmes)==0)&&(ptauxA->ano==ptauxA->prox->ano) && verificaFilmes(inicioF,ptauxA->NomeFilmes)!=NULL) //compara ano e nome do filme
       {
     	    printf("%s \n", ptauxA->NomeFilmes);
         
  	 	}
        ptauxA = ptauxA->prox; 
       
    }
    printf("\n");
    system("pause");
}


void substituiString(char aux, char nova[], int i)// Fun��o que substitui o valor de entrada do usu�rio pela letra digitada. Feito assim pois se o usu�rio digita uma palavra acentuada
{												// Com scanf ou gets n�oo reconheceria, em virtude da tabela ASCII.
	
	if(aux==-96)
	{
		nova[i] = '�';
	}
	else if(aux==-75)
	{
		nova[i]='�';
	}
	else if(aux==-126)
	{
		nova[i] = '�';
	}
	else if(aux==-95)
	{
		nova[i] = '�';
	}
	else if(aux==-94)
	{
		nova[i] = '�';
	}
	else if(aux==-93)
	{
		nova[i] = '�';
	}
	else if(aux==-127)
	{
		nova[i] = '�';
	}
	else if(aux==-124)
	{
		nova[i] = '�';
	}
	else if(aux==-119)
	{
		nova[i] = '�';
	}
	else if(aux==-117)
	{
		nova[i] = '�';
	}
	else if(aux==-125)
	{
		nova[i] = '�';
	}
	else if(aux==-108)
	{
		nova[i] = '�';
	}
	else if(aux==-109)
	{
		nova[i] = '�';
	}
	else if(aux==-112)
	{
		nova[i] = '�';
	}
	else
	{
		nova[i] = aux;
	}

}

 /* ------------------- Fun��es de inser��o ordenada recursiva em listas encadeadas --------------------------------------*/

void InsereFilmesListaFAtor(FilmesAtores **inicioFA, Filmes **Pos ) // Insere Filme na lista FilmesAtores do Ator
{
	if(*inicioFA==NULL || (*Pos)->ano<(*inicioFA)->nome->ano)
	{
		FilmesAtores *ptaux= (FilmesAtores *)malloc(sizeof(FilmesAtores));
		ptaux->nome = *Pos;
		ptaux->prox=*inicioFA;
		*inicioFA=ptaux;
		return;
	}
	InsereFilmesListaFAtor( &(*inicioFA)->prox, &(*Pos));
}

void InsereDiretorListaFilme(DiretoresFilmes **Diretor, Diretores **Pos)
{
	DiretoresFilmes *ptaux = (DiretoresFilmes *)malloc(sizeof(DiretoresFilmes));
	ptaux->nome = *Pos;
	ptaux->prox = *Diretor;
	*Diretor = ptaux;
	return;
	
}

void InsereFilmeListaDiretor(FilmesAtores **FilmesDiretor, Filmes **Pos)
{
	if(*FilmesDiretor==NULL || (*FilmesDiretor)->nome->ano > (*Pos)->ano )
	{
		FilmesAtores *ptaux = (FilmesAtores *)malloc(sizeof(FilmesAtores));
		ptaux->nome = *Pos;
		ptaux->prox = *FilmesDiretor;
		*FilmesDiretor = ptaux;
		return;
	}
	InsereFilmeListaDiretor(&(*FilmesDiretor)->prox,&(*Pos));
}

struct nodoDiretores *InsereDiretor(Diretores **inicioD, char NomeDir[50])
{
	if(*inicioD==NULL || strcmp((*inicioD)->NomeDiretor,NomeDir)<0 )
	{
		Diretores *ptaux = (Diretores *)malloc(sizeof(Diretores));
		strcpy(ptaux->NomeDiretor,NomeDir);
		ptaux->prox = *inicioD;
		*inicioD = ptaux;
		return ptaux;
	}
	InsereDiretor(&(*inicioD)->prox,NomeDir);
}

 /* --------------------------------------------------------------------------------------------------------------*/


struct nodoDiretores *verificaDiretores(Diretores **inicioD, char NomeDir[50])
{
	Diretores *ptaux = *inicioD;
	while(ptaux!=NULL)
	{
		if(strcmp(ptaux->NomeDiretor,NomeDir)==0)
		{
			return ptaux;
		}
		ptaux = ptaux->prox;
	}
	return NULL;
	
}

void listarFilmesDiretorOrdemCronologica(Diretores **inicioD, Filmes **inicioF)
{
	int i=0,flagAno=0,j;
	char flag='S',aux;
	char Diretor[200];
	char semAnoNome[40][200];
	while(toupper(flag)=='S')
	{
		fflush(stdin);
		system("cls");
		printf("\n Digite o nome do diretor que deseja pesquisar:\n");
		i=0;
			while(i<100 && aux!='\n')
			{
				fflush(stdin);
				aux = getch();

				if(aux == 8 || aux==127)
				{
					if(i>0)
					{
						i--;
						printf("\b %c",aux);
					}
				}
				else if(aux == 13)
				{
					break;
				}
				else
				{
					substituiString(aux,Diretor,i);
					printf("%c",Diretor[i]);
					i++;
				}

			}
			Diretor[i] = '\0';
			
		Diretores *ptaux = verificaDiretores(&(*inicioD), Diretor);
		if(ptaux!=NULL)
		{
			if(strcmp(Diretor,"")==0)
			{
				printf("\n Filmes sem diretor informado: ");
			}
			else
			{
				printf("\n Nome: %s", ptaux->NomeDiretor);
				printf("\n Filmes que dirigiu:");
			}
			FilmesAtores *ptfilmes = ptaux->filmes;
			i=0;
			while(ptfilmes!=NULL)
			{
				if(verificaFilmes(inicioF, ptfilmes->nome->NomeFilmes)!=NULL)
				{
					if(ptfilmes->nome->ano==0) // Filmes sem ano...
					{
						flagAno=1;
						strcpy(semAnoNome[i],ptfilmes->nome->NomeFilmes);
						i++;
					}
					else
					{
						printf("\n %s. Ano: %d",ptfilmes->nome->NomeFilmes, ptfilmes->nome->ano); // FIlmes com ano...
					}
				}
				ptfilmes = ptfilmes->prox;
			}
				if(flagAno==1)
			{
				printf("\n Filmes sem ano:");
				
				for(j=0;j<i;j++)
						printf("\n %s.", semAnoNome[j]);

			}
		}
		else
		{
			printf("\n Diretor n�oo encontrado!");
		}
		fflush(stdin);
		printf("\n Deseja realizar outra consulta? (S/N)\n");
		flag = getch();
	}
}


void InsereAtoresRelacionados( AtoresRelacionados **inicioAR, AtoresRelacionados **headAR, char filme[50], char ator[50])
{
	AtoresRelacionados *ptauxAR= NULL;
	AtoresRelacionados *novoFilme = (AtoresRelacionados *)malloc(sizeof(AtoresRelacionados));
	novoFilme->proxA = novoFilme->proxF = NULL; 
	strcpy(novoFilme->Nome, filme);	//Cria o nodo filme e salva a string com o nome
	
	if(*inicioAR==NULL){//em caso de nao ter nenhum ator relacionado cadastrado
		AtoresRelacionados *novoA = (AtoresRelacionados *)malloc(sizeof(AtoresRelacionados));
		strcpy(novoA->Nome, ator);
		novoA->proxF = novoFilme;
		novoA->proxA =NULL;			
		(*headAR)= (*inicioAR) = novoA; //inicializa a lista	
	}else{
		ptauxAR= (*inicioAR);
		while(ptauxAR!=NULL){
			if(strcmp((ptauxAR)->Nome, ator)==0)
			{								//o ator ja existe
			
				while(ptauxAR->proxF!=NULL){ //percorre at� o ultimo filme do ator
					ptauxAR = ptauxAR->proxF;
				}			
				ptauxAR->proxF= novoFilme;// adiciona o filme
				//return ;
			}
			*headAR=ptauxAR;//salva estado anterior
			ptauxAR= (ptauxAR)->proxA;
		}
		ptauxAR= *headAR;//restaura estado
		
		//o ator ainda nao foi adicionado
		AtoresRelacionados *novoA = (AtoresRelacionados *)malloc(sizeof(AtoresRelacionados));
		strcpy(novoA->Nome, ator);
		novoA->proxF = novoFilme;
		novoA->proxA =NULL;	

		ptauxAR->proxA = novoA;
			
	}
	return;
}

void InsereAtoresRelacionadosDiretores( AtoresDiretor **inicioAD, AtoresDiretor **headAD, char filme[100], char ator[100])
{
	AtoresDiretor *ptauxAD= NULL;
	AtoresDiretor *novoFilme = (AtoresDiretor *)malloc(sizeof(AtoresDiretor));
	novoFilme->proxA = novoFilme->proxF = NULL; 
	strcpy(novoFilme->Nome, filme);	//Cria o nodo filme e salva a string com o nome
	
	if(*inicioAD==NULL){//em caso de nao ter nenhum ator relacionado cadastrado
		AtoresDiretor *novoA = (AtoresDiretor *)malloc(sizeof(AtoresDiretor));
		strcpy(novoA->Nome, ator);
		novoA->proxF = novoFilme;
		novoA->proxA =NULL;			
		(*headAD)= (*inicioAD) = novoA; //inicializa a lista	
	}else{
		ptauxAD= (*inicioAD);
		while(ptauxAD!=NULL){
			if(strcmp((ptauxAD)->Nome, ator)==0){//o ator ja existe
				while(ptauxAD->proxF!=NULL){ //percorre at� o ultimo filme do ator
					ptauxAD = ptauxAD->proxF;
				}			
				ptauxAD->proxF= novoFilme;// adiciona o filme
				//return ;
			}
			*headAD=ptauxAD;//salva estado anterior
			ptauxAD= (ptauxAD)->proxA;
		}
		ptauxAD= *headAD;//restaura estado
		
		//o ator ainda nao foi adicionado
		AtoresDiretor *novoA = (AtoresDiretor *)malloc(sizeof(AtoresDiretor));
		strcpy(novoA->Nome, ator);
		novoA->proxF = novoFilme;
		novoA->proxA =NULL;	

		ptauxAD->proxA = novoA;
	}
	return;
}


void ListarAtoresDiretor(Diretores **inicioD, Filmes **inicioF){
	int i=0,j;
	char flag='S',aux,flag1=0;
	char nomeDiretor[200];
	Diretores *ptauxD;
	FilmesAtores *ptauxFA;
	AtoresFilmes *ptauxAF;
	AtoresDiretor *inicioAD, *headAD;//head � o cabecalho	

	while(toupper(flag)=='S')
	{
		ptauxD = *inicioD;
		ptauxFA = ptauxD->filmes;
		ptauxAF;
		inicioAD=NULL, headAD=NULL;//head � o cabecalho	
	
		fflush(stdin);
		system("cls");
		flag1=0;
		printf("\n Digite o nome do diretor que deseja pesquisar:\n");
		i=0;
			while(i<100 && aux!='\n')
			{
				fflush(stdin);
				aux = getch();

				if(aux == 8 || aux==127)
				{
					if(i>0)
					{
						i--;
						printf("\b %c",aux);
					}
				}
				else if(aux == 13)
				{
					break;
				}
				else
				{
					substituiString(aux,nomeDiretor,i);
					printf("%c",nomeDiretor[i]);
					i++;
				}

			}
			nomeDiretor[i] = '\0';
			ptauxD = verificaDiretores(inicioD, nomeDiretor);
		if(ptauxD!=NULL)// verifica se diretor existe
		{
			
			ptauxFA = ptauxD->filmes; //Primeiro filme do ator escolhido
			
			i=0;
			while(ptauxFA!=NULL)
			{
				if(verificaFilmes(inicioF,ptauxFA->nome->NomeFilmes)!=NULL)
				{
					ptauxAF=ptauxFA->nome->atores; //recebe o ator a ser verificado
			
					while(ptauxAF!= NULL){
					 
						InsereAtoresRelacionadosDiretores(&inicioAD, &headAD, ptauxFA->nome->NomeFilmes, ptauxAF->nome->NomeAtor);		
						ptauxAF= ptauxAF->prox;
					}
					flag1++;
				}
				ptauxFA = ptauxFA->prox;
			}
		
			//Imprime a lista
			if(flag1>0)
			{
				printf("\n Diretor: %s\n", ptauxD->NomeDiretor);
				AtoresDiretor *ptauxAD;
				ptauxAD = headAD = inicioAD;// Recebe a primeira posi��o
				while(ptauxAD!=NULL)
				{
					printf("\nAtor: %s: ", ptauxAD->Nome);
					ptauxAD=ptauxAD->proxF; //recebe o primeiro filme
			
			        printf("\nFilmes: ");
					while(ptauxAD->proxF!= NULL){ 
					
						printf(" %s,", ptauxAD->Nome);
						ptauxAD= ptauxAD->proxF;
					}
					
					printf(" %s.\n",ptauxAD->Nome);
						
					headAD= headAD->proxA; //
					ptauxAD = headAD;
				}	
			}
		}
		else if(flag1==0)
		{
			printf("\n Diretor n�o encontrado!");
		}
		fflush(stdin);
		printf("\n Deseja realizar outra consulta? (S/N)\n");
		flag = getch();
	}

}

void ListarAtoresRelacionadosAtores(Atores **inicioA){
	int i=0,j;
	char flag='S',aux;
	char nomeAtor[200];
	Atores *ptauxA;
	FilmesAtores *ptauxFA;
	AtoresFilmes *ptauxAF;
	AtoresRelacionados *inicioAR, *headAR;//head � o cabecalho	

	while(toupper(flag)=='S')
	{
		ptauxA = *inicioA;
		ptauxFA = ptauxA->filmes;
		ptauxAF;
		inicioAR=NULL, headAR=NULL;//head � o cabecalho	
	
		fflush(stdin);
		system("cls");
		printf("\n Digite o nome do ator/atriz que deseja pesquisar:\n");
		i=0;
			while(i<100 && aux!='\n')
			{
				fflush(stdin);
				aux = getch();

				if(aux == 8 || aux==127)
				{
					if(i>0)
					{
						i--;
						printf("\b %c", aux);
					}
				}
				else if(aux == 13)
				{
					break;
				}
				else
				{
					substituiString(aux,nomeAtor,i);
					printf("%c",nomeAtor[i]);
					i++;
				}

			}
			nomeAtor[i] = '\0';
		Atores *ptauxA = verificaAtores(inicioA, nomeAtor);
		if(ptauxA!=NULL)// verifica se ator existe
		{
			
			printf("\n Ator: %s\n", ptauxA->NomeAtor);
			ptauxFA = ptauxA->filmes; //Primeiro filme do ator escolhido
			
			i=0;
			while(ptauxFA!=NULL)
			{
				ptauxAF=ptauxFA->nome->atores; //recebe o ator a ser verificado
		
				while(ptauxAF->prox!= NULL){  //verifica se o ator � o unico listado no filme
					if(strcmp(ptauxAF->nome->NomeAtor,ptauxA->NomeAtor)!=0){//verifica se o ator nao � o selecionado
						InsereAtoresRelacionados(&inicioAR, &headAR, ptauxFA->nome->NomeFilmes, ptauxAF->nome->NomeAtor);		
					}
					ptauxAF= ptauxAF->prox;
				}
				ptauxFA = ptauxFA->prox;
			}
		
			//Imprime a lista
			AtoresRelacionados *ptauxAR;
			ptauxAR = headAR = inicioAR;// Recebe a primeira posi��o
			int flag;
			while(ptauxAR!=NULL)
			{
				printf("\nAtor: %s: ", ptauxAR->Nome);
				ptauxAR=ptauxAR->proxF; //recebe o primeiro filme
		        
		        printf("\nFilmes:");
		        
				while(ptauxAR->proxF!= NULL){ 
						printf("%s, ", ptauxAR->Nome);
						ptauxAR= ptauxAR->proxF;
				}
				
				printf("%s. \n", ptauxAR->Nome);
				ptauxAR= ptauxAR->proxF;
				
				flag=0;
				
				headAR= headAR->proxA;
				ptauxAR = headAR;
			
			}	
			system("pause");
		}
		else
		{
			printf("\n Ator/atriz n�o encontrado!");
		}
		fflush(stdin);
		printf("\n Deseja realizar outra consulta? (S/N)\n");
		flag = getch();
	}

}


void listarFilmesAtorOrdemCronologica(Atores **inicioA, Filmes **inicioF)
{
	int i=0,flagAno=0,j;
	char flag='S',aux;
	char nomeAtor[200];
	char semAnoNome[40][200];
	while(toupper(flag)=='S')
	{
		fflush(stdin);
		system("cls");
		printf("\n Digite o nome do ator/atriz que deseja pesquisar:\n");
		i=0;
			while(i<100 && aux!='\n')
			{
				fflush(stdin);
				aux = getch();

				if(aux == 8 || aux==127)
				{
					if(i>0)
					{
						i--;
						printf("\b %c",aux);
					}
				}
				else if(aux == 13)
				{
					break;
				}
				else
				{
					substituiString(aux,nomeAtor,i);
					printf("%c",nomeAtor[i]);
					i++;
				}

			}
			nomeAtor[i] = '\0';
		Atores *ptaux = verificaAtores(inicioA, nomeAtor);
		if(ptaux!=NULL)
		{
			printf("\n Nome: %s", ptaux->NomeAtor);
			FilmesAtores *ptfilmes = ptaux->filmes;
			printf("\n Filmes dos quais participou:");
			i=0;
			while(ptfilmes!=NULL)
			{
				if(verificaFilmes(inicioF, ptfilmes->nome->NomeFilmes)!=NULL)
				{
					if(ptfilmes->nome->ano==0) // Filmes sem ano...
					{
						flagAno=1;
						strcpy(semAnoNome[i],ptfilmes->nome->NomeFilmes);
						i++;
					}
					else
					{
						printf("\n %s. Ano: %d",ptfilmes->nome->NomeFilmes, ptfilmes->nome->ano); // FIlmes com ano...
					}
				}
				ptfilmes = ptfilmes->prox;
			}
				if(flagAno==1)
			{
				printf("\n Filmes sem ano:");
				
				for(j=0;j<i;j++)
						printf("\n %s.", semAnoNome[j]);

			}
		}
		else
		{
			printf("\n Ator/atriz n�oo encontrado!");
		}
		fflush(stdin);
		printf("\n Deseja realizar outra consulta? (S/N)\n");
		flag = getch();
	}
}

struct nodoAtores *verificaAtores(Atores **inicioA, char nome[50]) // verifica��o se existe ator. Se existe, retorna o ator.
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


struct nodoFilmes *verificaFilmes(Filmes **inicioF, char nome[100]) // verifica��o se existe filme. Se existe, retorna o filme.
{
	Filmes *ptaux = *inicioF;
	while(ptaux!=NULL)
	{
		if(strcmp(ptaux->NomeFilmes,nome)==0)
		{
			return ptaux;			// Se encontra o filme, retorna ele, sen�oo...
		}
		ptaux = ptaux->prox;
	}
	return NULL;					// Retorna Null
}


void InsereAtorListaAFilmes(AtoresFilmes **inicioAF, Atores **Pos ) // Insere no início da lista AtoresFilmes na lista Filmes * favor verificar em inser��oInicial *
{
	AtoresFilmes *ptaux = (AtoresFilmes *)malloc(sizeof(AtoresFilmes));
	ptaux->nome = *Pos;
	ptaux->prox = *inicioAF;
	*inicioAF = ptaux;

}



void defineFilmesAlfabeticoOuReverso(Filmes **inicioF, Filmes **fimF) // Sub-menu para definir qual tipo de listagem de filmes ser� feita, com a op��o 0 para sair
{
	char flag = 1;
	while(flag!='0')
	{
		system("cls");
		printf("\n Deseja listar os filmes em ordem alfabetica(N) ou alfabetica reversa(R)?\n(Se desejar, digite 0 para sair)");
		flag = getch();
		switch(toupper(flag))
		{
			case('0'):
			{
				system("cls");
				fflush(stdin);
				return;
				break;
			}
			case('N'):
			{
				ListaFilmesOrdemAlfabetica(inicioF,fimF,'N'); // Chama a listagem como alfab�tico 'N'ormal
				fflush(stdin);
				break;
			}
			case('R'):
			{
				ListaFilmesOrdemAlfabetica(inicioF,fimF,'R'); // Chama a listagem como alfab�tico 'R'ormal
				fflush(stdin);
				break;
			}
			default:
				printf("\nDigite uma op��o v�lida!");
				system("pause");
				system("cls");
				fflush(stdin);
				break;
		}
	}
}

void ListaFilmesOrdemAlfabetica(Filmes **inicioF, Filmes **fimF, char NormalOuReverso) // Listagem de filmes em ordem alfab�tica ou alfab�tica reversa
{
	int flag=0,count;
	char SimNao;

	printf("\n Deseja definir quantos nomes aparecem na tela por vez?[S/N]");
	SimNao = getch();

	if(toupper(SimNao)=='S')
	{

		while(flag<1 || flag>100)
		{
			fflush(stdin);
			printf("\n Quantos? (entre 1 e 100)");
			scanf(" %d",&flag);
			if(flag<1 || flag > 100)
				{
					printf("\n Digite um n�mero v�lido!");
				}
		}
	}
	if(NormalOuReverso=='N')
	{
		count = 0;
		Filmes *ptaux = *inicioF;

		while(ptaux!=NULL)
		{
			printf("\n Filme: %s\n", ptaux->NomeFilmes);
			if(ptaux->diretores!=NULL)
			{
				DiretoresFilmes *aux = ptaux->diretores;
				if(aux->prox==NULL)
				{
					printf("Diretor: ");
				}
				else
				{
					printf("Diretores: ");
				}
				while(aux!=NULL)
				{
					printf("%s",aux->nome->NomeDiretor);
					aux = aux->prox;
					if(aux==NULL)
					{
						printf("\n");
					}
					else printf(", ");
				}
				
			}
			
			printf(" Ano: %d \n", ptaux->ano);
			ptaux = ptaux->prox;
			count++;
			if(flag==count)
			{
				system("pause"); // Pause mantido pois ele ir� pausar assim que o contador estiver com o mesmo n�mero de nomes que o usu�rio colocou no input anteriormente
				count=0;
			}
		}
	}
	else if(NormalOuReverso=='R')
	{
		count = 0;
		Filmes *ptaux = *fimF;
		while(ptaux!=NULL)
		{
			printf("\n Filme: %s ", ptaux->NomeFilmes);
			if(ptaux->diretores!=NULL)
			{
				DiretoresFilmes *aux = ptaux->diretores;
				if(aux->prox==NULL)
				{
					printf("Diretor: ");
				}
				else
				{
					printf("Diretores: ");
				}
				while(aux!=NULL)
				{
					printf("%s",aux->nome->NomeDiretor);
					aux = aux->prox;
					if(aux==NULL)
					{
						printf("\n");
					}
					else printf(", ");
				}
				
			}
			printf("; Ano: %d ", ptaux->ano);
			ptaux = ptaux->ant;
			count++;
			if(flag==count)
			{
				system("pause"); // Pause mantido pois ele ir� pausar assim que o contador estiver com o mesmo n�mero de nomes que o usu�rio colocou no input anteriormente
				flag=0;
			}
		}
	}
	
	system("pause");

}

void defineAtoresAlfabeticoOuReverso(Atores **inicioA, Atores **fimA) // Sub-menu para definir qual tipo de listagem de atores ser� feita, com a op��o 0 para sair
{
	char flag = '1';
	while(flag!='0')
	{
		system("cls");
		printf("\n Deseja listar os atores em ordem alfabetica(N) ou alfabetica reversa(R)?\n(Se desejar, digite 0 para sair)\n");
		flag =  getch();
		switch(toupper(flag))
		{
			case('0'):
			{
				system("cls");
				fflush(stdin);
				return;
				break;
			}
			case('N'):
			{
				ListaAtoresOrdemAlfabetica(inicioA,fimA,'N'); // Chama a listagem como alfab�tico 'N'ormal
				fflush(stdin);
				break;
			}
			case('R'):
			{
				ListaAtoresOrdemAlfabetica(inicioA,fimA,'R'); // Chama a listagem como alfab�tico 'R'ormal
				fflush(stdin);
				break;
			}
			default:
				printf("\nDigite uma op��o v�lida!");
				system("pause");
				fflush(stdin);
				break;
		}
	}
}

void ListaAtoresOrdemAlfabetica(Atores **inicioA, Atores **fimA, char NormalOuReverso) // Listagem de atores em ordem alfab�tica ou alfab�tica reversa
{
	int flag=0,count;
	char SimNao;

	printf("\n Deseja definir quantos nomes aparecem na tela por vez?[S/N]\n");
	SimNao = getch();
	SimNao=toupper(SimNao);
	if( SimNao=='S' || SimNao=='s')
	{
		while(flag<1 || flag>100)
		{
			fflush(stdin);
			printf("\n Quantos? (entre 1 e 100)\n");
			scanf(" %d", &flag);
			if(flag<1 || flag > 100)
				{
					printf("\n Digite um n�mero v�lido!");
					fflush(stdin);
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
			count++;
			ptaux = ptaux->prox;

			if(flag==count)
			{
				system("pause");  // Pause mantido pois ele ir� pausar assim que o contador estiver com o mesmo n�mero de nomes que o usu�rio colocou no input anteriormente
				count = 0;
			}
		}
	}
	else if(NormalOuReverso=='R')
	{
		Atores *ptaux = *fimA;

		while(ptaux!=NULL)
		{
			if(ptaux->NomeAtor!="")
			{
			printf("\n Ator: %s  ", ptaux->NomeAtor);
			count++;
			}
			ptaux = ptaux->ant;

			if(flag==count)
			{
				system("pause"); // Pause mantido pois ele ir� pausar assim que o contador estiver com o mesmo n�mero de nomes que o usu�rio colocou no input anteriormente
				count = 0;
			}
		}
	}
	fflush(stdin);
	system("pause");
}


void buscaFilmeEspecifico(Filmes **inicioF) // Pesquisa para verificar filmes espec�fcos.
{
	system("cls");
	char nome[100], aux;
	char escolha;
	do
	{
		printf("\n Digite o nome do filme que deseja pesquisar:");
		int i=0;
		while(i<100 )
		{
			fflush(stdin);
			aux = getch();
			if(aux == 8 || aux==127)
			{
				if(i>0)
				{
					i--;
					printf("\b %c",aux);
				}
			}
			else if(aux == 13)
			{
				break;
			}
			else
			{
				substituiString(aux,nome,i);
				printf("%c",nome[i]);
				i++;
			}
		}
		nome[i]='\0';
		Filmes *ptaux = verificaFilmes(inicioF, nome);
		
		if(ptaux!= NULL )
		{
			DiretoresFilmes *ptdir = ptaux->diretores;
			printf("\n Nome do Filme: %s", ptaux->NomeFilmes);
			printf("\n Diretor");
			if(ptdir->prox!= NULL)
				printf("es");
			printf(" do Filme:");			
			while(ptdir!= NULL)
			{
				printf(" %s\n", ptdir->nome->NomeDiretor);
				ptdir = ptdir->prox;
			}
			
			printf("\n %d", ptaux->ano);
			if(ptaux->atores!=NULL && ptaux->atores->prox!=NULL) printf("\n Atores/Atrizes que participaram do filme:");
			else if(ptaux->atores!=NULL) 
			{
				printf("\nAtor/Atriz que participou do filme:");
			}
			AtoresFilmes *ptaux1 = ptaux->atores;
			
			while(ptaux1!=NULL)
			{
				printf("\n%s",ptaux1->nome);
				ptaux1 = ptaux1->prox;
			}
			printf("\n");
			system("pause");
		}
		else printf("\nDesculpe, esse filme n�o existe!\n");
		
		printf("Deseja buscar outro filme?(s/n)");
		escolha = getch();
		
	}	while (toupper(escolha) != 'N');
}


void tratarAcento(char original[], char tratada[]) // Fun��o que troca letras acentuadas por mai�sculas, para a compara��o.
{
	
	int i=0;
	int tamanhoString = strlen(original);
	while(i<tamanhoString)
	{
		if(original[i]=='�'||(original[i]=='�')||(original[i]=='�'))
			tratada[i]= 'U';
		else if((original[i]=='�')||(original[i]=='�')||(original[i]=='�'))
			tratada[i]= 'I';
		else if((original[i]=='�')||(original[i]=='�')||(original[i]=='�')||(original[i]=='�')||(original[i]=='�'))
			tratada[i]= 'O';
		else if((original[i]=='�')||(original[i]=='�')||(original[i]=='�')||(original[i]=='�')||(original[i]=='�')||(original[i]=='�')||(original[i]=='�'))
			tratada[i]= 'A';
		else if((original[i]=='�')||(original[i]=='�')||(original[i]=='�')||(original[i]=='�')||(original[i]=='�') )
			tratada[i]= 'E';
		else
			tratada[i] = toupper(original[i]);
		i++;
	}

}


// Trata as palavras com acento, inserindo normalmente, mas verificando sem acento
int compararStringAcento(char nomeNodo[], char nome[]){
	int aux;
	char testeNodo[100]; //variavel que receber� a nova nomeNodo, j� tratada
	tratarAcento(nomeNodo,testeNodo);


	aux= strcmp(testeNodo, nome);
	return aux;  //retornar diretamente da funcao retornava erro: return strcmp(testeNodo, teste);
}



/* Sess�oo de fun��es relacionadas aos personagens; Mesmo padr�o que os acima */




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

void ListaAtoresPersonagens(Atores **inicioA, Personagens **inicioP, Filmes **inicioF)
{
	Personagens *ptaux = *inicioP;
	int flag=0;
	char nome[50], escolha;
	do
	{
		system("cls");
		
		printf("\n Qual o nome do Personagem que desejas pesquisar?\n");
		scanf(" %[^\n]", nome);
		flag=0;
		
		if((ptaux = verificaPersonagens(&(*inicioP),nome)) != NULL)
		{
			FilmesPersonagens *filmes1 = ptaux->filmes;
			while(filmes1!=NULL)
			{
				if(verificaFilmes(inicioF,filmes1->filmes->NomeFilmes)!=NULL)
					flag++;
				filmes1 = filmes1->prox;
			}
			if(flag>0)
			{
				printf("\nPersonagem:%s\n",ptaux->NomePersonagem);
				AtoresFilmes *atores = ptaux->atores; 
				FilmesPersonagens *filmes = ptaux->filmes;
				
				while(atores!=NULL && verificaFilmes(inicioF,filmes->filmes->NomeFilmes)!=NULL)
				{
					printf("Ator:%s Filme: %s Ano: %d\n", atores->nome->NomeAtor, filmes->filmes->NomeFilmes, filmes->filmes->ano);
					atores = atores->prox;
					filmes = filmes->prox;
				}
			}
			else printf("\nO personagem n�o possui filmes em sua lista.\n");
		}
		else
		{
			printf("\nO personagem n�o existe.\n");
		}
		printf("Deseja buscar outro personagem?(s/n)");
		escolha = getch();
		
	}	while (toupper(escolha) != 'N');
}

struct nodoPersonagens *verificaPersonagens(Personagens **inicioP, char NomePersonagem[50]) // verifica��o se existe personagem. Se existe, retorna o personagem.
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
