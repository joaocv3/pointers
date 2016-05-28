#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <time.h>


typedef struct nodoAtoresFilmes{struct nodoAtores *nome;struct nodoAtoresFilmes *prox;} AtoresFilmes; // Lista de atores de um filme
typedef struct nodoFilmesAtores{struct nodoFilmes *nome;struct nodoFilmesAtores *prox;} FilmesAtores; // Lista de filmes de um ator
typedef struct nodoFilmes{char NomeFilmes[100]; int ano; char Diretores[200]; struct nodoFilmes *prox; struct nodoFilmes *ant; struct nodoAtoresFilmes *atores;} Filmes; //Lista principal dos filmes
typedef struct nodoAtores{char NomeAtor[50];struct nodoAtores *prox; struct nodoAtores *ant; struct nodoFilmesAtores *filmes;} Atores; // Lista principal dos atores
typedef struct nodoFilmesPersonagens{struct nodoFilmes *filmes; struct nodoFilmesPersonagens *prox;} FilmesPersonagens; // lista de filmes em que determinados personagens apareceram
typedef struct nodoPersonagens{char NomePersonagem[50]; struct nodoPersonagens *prox; struct nodoAtoresFilmes *atores; struct nodoFilmesPersonagens *filmes;} Personagens; // lista de personagens interpretados



/* ---- MENUS ---- */

int menu();

void defineAtoresAlfabeticoOuReverso(Atores **inicioA, Atores **fimA); // Fun��o que define se a lista de atores ser� mostrada em ordem alfab�tica ou alfab�tica reversa

void defineFilmesAlfabeticoOuReverso(Filmes **inicioF, Filmes **fimF); // Fun��o que define se a lista de filmes ser� mostrada em ordem alfab�tica ou alfab�tica reversa

void menuInserirFilme(Filmes **inicioF, Filmes **fimF, Atores **inicioA, Atores **fimA, Personagens **inicioP);

// Complemento para o menu principal

void tituloProg();

/* ----------------------- */

/* -------------------Fun��es INICIAIS------------------------- */ 


int leitura(Filmes **inicioF, Filmes **fimF, Atores **inicioA, Atores **fimA, Personagens **inicioP);

void InsercaoInicial(Filmes **inicioF, Filmes **fimF, Atores **inicioA, Atores **fimA, Personagens **inicioP, char ValorASerInserido[2100]);

/* ---------------------------------------------------------- */


/* -------------------Fun��es PESQUISA------------------------- */

struct nodoAtores *verificaAtores(Atores **inicioA, char nome[100]);

struct nodoFilmes *verificaFilmes(Filmes **inicioF, char nome[100]);

struct nodoPersonagens *verificaPersonagens(Personagens **inicioP, char NomePersonagem[50]);

void buscaFilmeEspecifico(Filmes **inicioF);

/* ---------------------------------------------------------- */


/* -------------------Fun��es INSER��O------------------------- */ 

struct nodoFilmes * insereOrdenadoNaListaDeFilmes(Filmes **inicioF, Filmes **fimF ,char nome[100], int ano, char Diretores[200]);

struct nodoAtores *insereOrdenadoNaListaDeAtores( Atores **inicio, Atores **fim , char nome[100]);

void InsereAtorListaAFilmes(AtoresFilmes **inicioAF, Atores **Pos );

void InsereFilmesListaFAtor(FilmesAtores **inicioFA, Filmes **Pos );

void InsereFilmesListaFPersonagens(FilmesPersonagens **inicioFP, Filmes **Pos );

struct nodoPersonagens *InserePersonagem(Personagens **inicioP, char NomePersonagem[50]);

void InsereAtorListaPersonagem(AtoresFilmes **inicioAF, Atores **ator);

void InserePersonagemListaAtor(AtoresFilmes **inicioAF, Personagens **pos);

void insercaoOrdenada(Filmes **inicioF, Filmes **fimF, Atores **inicioA, Atores **fimA, char ValorASerInserido[2100]);

int tratarCharAcento(char nomeNodo[], char nome[]);

void verificaAcentos(char nome[], int aux);

/* ---------------------------------------------------------- */


//int PesquisaNasStructs(Filmes **inicioF, Atores **inicioA, char ValorPesquisa[200], char FilmeAnoDiretorNome);


/* -------------------Fun��es LISTAR------------------------- */ 

void ListaFilmesOrdemAlfabetica(Filmes **inicioF, Filmes **fimF, char NormalOuReverso); // Fun��o que mostra a lista de filmes

void listarFilmesAtorOrdemCronologica(Atores **inicioA);

void ListaAtoresOrdemAlfabetica(Atores **inicioA, Atores **fimA, char NormalOuReverso); // Fun��o que mostra a lista de atores

void ListaPersonagens(Personagens **inicioP); // Fun��o teste para visualizar a lista de personagens

/* -------------------------------------------------------- */




int main()
{
	setlocale(LC_ALL,"Portuguese");
	tituloProg();

	Filmes *inicioF = NULL, *fimF = NULL; // In�cio/fim lista Filmes.
	Atores *inicioA = NULL, *fimA = NULL; // In�cio/fim lista Atores.
	Personagens *inicioP = NULL;
	
	if((leitura(&inicioF, &fimF, &inicioA, &fimA, &inicioP))==0) //verifica se conseguiu ler o arquivo
	{
		printf("\n Erro! Arquivo não encontrado. \n");
		printf("Insira o arquivo no diretorio especifico e tente novamente. \n");
		return; // Encerra o programa
	}
	
	int escolha = menu(); // Verifica a primeira escolha. Se for para sair, retorna e encerra o programa;
/*	if(escolha!=0) 		 // Inicializa o in�cio e fim das listas at� ent�o utilizadas.
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
				menuInserirFilme(&inicioF, &fimF, &inicioA, &fimA, &inicioP);
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
		tituloProg();
	}
	printf("\n Obrigado por utilizar o programa!");
	printf("\n V.27052016");
	printf("\n Au Revoir!");
	
}

void tituloProg()
{ 
		printf("\t-------------------------------------------------------------------------------");
		printf("\n\t-------------------------------------------------------------------------------");
		printf("\n\t--------------------------- Banco de Dados de Filmes --------------------------\n");
		printf("\t---------------------------- da aula de Programa��o 2 -------------------------\n");
		printf("\t-------------------------------------------------------------------------------\n");
		printf("\t-------------------------------------------------------------------------------\n\n\n");
		
}

int menu()
{
	int opcaoMenu = 0;
	
	while(opcaoMenu!= -1 )
	{
		printf("\n\t 1:Listar todos os atores da lista em ordem alfabetica e alfabetica reversa ");
		printf("\n\t 2:Listar todos os filmes de um determinado ator em ordem cronol�gica.");
		printf("\n\t 3:Listar todos os filmes em ordem alfab�tica e alfab�tica reversa.");
		printf("\n\t 4:Inserir um novo filme");
		printf("\n\t 5:Remover um filme");
		printf("\n\t 6:Listar filmes de um determinado diretor (ordem cronol�gica)");
		printf("\n\t 7:Listar atores que trabalharam diretamente com um determinado ator e o nome\n\t\t do filme no qual trabalharam juntos");
		printf("\n\t 8:Listar atores que trabalharam diretamente com um diretor e o nome do filme\n\t\t em que trabalharam juntos");
		printf("\n\t 9:Listar filmes que est�o duplicados");
		printf("\n\t 10:Listar os atores que interpretaram um determinado personagem");
		printf("\n\n\t\t 0: Para sair do programa\n");
		scanf("%5d", &opcaoMenu);
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

void InsercaoInicial(Filmes **inicioF, Filmes **fimF, Atores **inicioA, Atores **fimA,Personagens **inicioP, char ValorASerInserido[2100])
{
	Filmes *novoF = NULL;
	Atores *novoA = NULL;
	Personagens *novoP = NULL;
	
	char aux[100], nomeAtor[100], NomePersonagem[50], Diretores[200], NomeFilme[100];
	
	int i, j=0,k; //variaveis contadoras para percorrer a linha, a string até a virgula e a string auxiliar, respectivamente;
	
	int ano,l,m,n, flagSairLacoStatus2, contador; // vari�veis contadoras para a verifica��o de outros diretores (utilizadas no status 2)
	
	int o, flagPersonagem; // Vari�veis contadoras para o segmento de status >2;
	int status=0; //status para a inserção nos elementos do nodo
	
	
	for(i=0; i<strlen(ValorASerInserido); i++)//Percorre o vetor de chars
	{ 
		if(ValorASerInserido[i]==',' || ValorASerInserido[i+1]=='\0')
		{ 
			strcpy(aux,"");
			k=0;	//zera o contador da string auxiliar
			for(j; j<i ;j++){ // percorre da posicao inicial até a virgula
			
				aux[k]=ValorASerInserido[j]; //insere char a char na string auxiliar

				k++; //proxima posicao na string auxiliar
				
			}
			
			aux[k]='\0'; // encerra a string até a virgula
			
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

				/* O Pr�ximo La�o ir� verificar se existem mais diretores no mesmo filme. 
				Se ele conseguir encontrar o 'dir:' na frente, ir� copiar o nome para a string que ser� inserida na lista com o filme */
				
				
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

					while(ValorASerInserido[m]!=',' ) //&& ValorASerInserido[m]!='\0')  <--- N�o encontrei caso que fosse necess�rio (programa passou a ter comportamento estranho)
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
						flagSairLacoStatus2 = 1 ; // quebra o la�o e insere o nome dos diretores na lista de filmes.
						Diretores[l+1] = '\0'; // insere indicador de fim de linha para evitar loops
						i = m; // ATEN��O: vari�vel i � incrementada aqui pois outro nome de diretor fora inserido
						// diretamente da string ValorASerInserido. Assim, nenhum nome � duplicado no pr�ximo status.

					}


				}

				novoF = insereOrdenadoNaListaDeFilmes(inicioF,fimF,NomeFilme,ano,Diretores); // inser��o do filme de maneira ordenada na lista de filmes
				novoF->atores = NULL; // insere NULL na struct AtoresFilme, pois o filme rec�m fora inserido.
			}
			else if(status>2) 
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
					while(aux[o]!='\0') // Enquanto n�o estiver no fim da string auxiliar, continua a inser��o.
				 	{
						NomePersonagem[n] = aux[o]; // transfere o nome do personagem.
						n++;
						o++;
					}	
					
				NomePersonagem[n]='\0'; //determina o fim da string para evitar loops.
				
				}
				
				
				novoA = verificaAtores(inicioA,nomeAtor); // Aqui � verificada a exist�ncia do determinado ator. Se existe, retorna a posi��o da struct;
				

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
				 	

					strcpy(NomePersonagem,""); //"Zera" a vari�vel para a pr�xima itera��o.
				}

			}

			j=i+1; //comeca a contagem da proxima string após a virgula 
		 status++; // incrementa o status, para continuar a leitura.

		}

	}
	
}

struct nodoFilmes * insereOrdenadoNaListaDeFilmes(Filmes **inicioF, Filmes **fimF,char nome[100], int ano, char Diretores[200])
{				// Inser��o ordenada por nome

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
			while(ptaux2->prox!=NULL && (tratarCharAcento((ptaux2->prox->NomeFilmes),nome))<1)
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

// Trata as palavras com acento, inserindo normalmente, mas verificando sem acento
int tratarCharAcento(char nomeNodo[], char nome[]){
	int aux;
	char testeNodo[100], teste[100]; //variaveis com o nome sem acento para comparacao
	strcpy (testeNodo, nomeNodo);
	strcpy (teste, nome);
	
	for (aux=0;aux<strlen(testeNodo); aux++)
		verificaAcentos(testeNodo, aux);
	
	
	for (aux=0;aux<strlen(teste); aux++)
		verificaAcentos(teste, aux);

	aux= strcmp(testeNodo, teste); 
	return aux;  //retornar diretamente da funcao retornava erro: return strcmp(testeNodo, teste); 
}


// Verifica a presenca de um dos caracteres especiais
void verificaAcentos(char nome[], int aux){
	if(nome[aux]=='�')
		nome[aux]= 'U';
	else if((nome[aux]=='�'))
		nome[aux]= 'I';	
	else if((nome[aux]=='�')||(nome[aux]=='�'))
		nome[aux]= 'O';	
	else if((nome[aux]=='�')||(nome[aux]=='�'))
		nome[aux]= 'A';
	else if((nome[aux]=='�')||(nome[aux]=='�'))
		nome[aux]= 'E';	
}

struct nodoAtores *insereOrdenadoNaListaDeAtores( Atores **inicio, Atores **fim , char nome[100]) // inser��o ordenada por nome.
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
			while(ptaux2->prox!=NULL && (tratarCharAcento((ptaux2->prox->NomeAtor),nome))<1)
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

void menuInserirFilme(Filmes **inicioF, Filmes **fimF, Atores **inicioA, Atores **fimA, Personagens **inicioP)
{
	int flag=0,i=0,existe,existeDir,ano,j=0,anoAtual,qntA;
	char compAno[4];
	char nomeFilme[100], ValorASerInserido[2100];
	char Diretores[10][100];
	char nomeAtores[10][100];
	
	// Para comparar com o ano inserido:
	
	time_t rawtime;
	struct tm *timeinfo;
	time (&rawtime);
	timeinfo = localtime(&rawtime);
	anoAtual = timeinfo->tm_year+1900; 
	
	
	system("cls");
		printf("\n Digite o nome do filme que deseja inserir:\n ");
		scanf(" %[^\n]",nomeFilme);
		if(verificaFilmes(inicioF,nomeFilme)!=NULL) // Verifica se o filme j� existe. Se sim, mostra a mensagem de erro e retorna ao menu principal...
		{
			printf("\n Erro, filme j� existe. Retornando ao menu principal!\n");
			system("pause");
			system("cls");
			return;
		}
		else //... Se n�o existe, concatena na string que ser� passada como par�metro para a fun��o de Inser��o.
		{
			strcat(ValorASerInserido,nomeFilme);
			strcat(ValorASerInserido, ",");
		}
		

		printf("\n Digite o ano em que foi lan�ado o filme:\n");
		scanf("%d",&ano);

		while(ano<1895 || ano>anoAtual+5) // Verifica se o ano inserido condiz com o ano do primeiro filme lan�ado na hist�ria do cinema ou � menor do que ano atual + 5 anos.
		{
			printf("\n A data est� fora da data de lan�amento do primeiro filme da hist�ria ou\n excede o limite de cinco anos partindo do ano atual.\n Digite outro ano!");
			scanf("%d",&ano);
		}
		
		sprintf(compAno, "%i", ano); //Converte o inteiro para char;
		
		strcat(ValorASerInserido,compAno); // Concatena o ano e uma v�rgula
		strcat(ValorASerInserido, ",");
		
		printf("\n Deseja inserir o nome de algum diretor que participou do filme?(1/0)\n");
		scanf("%d",&existeDir);
		if(existeDir==1)
		{
			printf("\n Digite o nome do diretor do filme:\n");
			scanf(" %[^\n]",Diretores[i]);
			
			printf("%s", Diretores[i]);
			
			strcat(ValorASerInserido,Diretores[i]);
			
			fflush(stdin);
			
			printf("\n Existe(m) outro(s) Diretor(es) que participou(participaram) do filme?(1/0)\n"); // Se existirem outros diretores, concatenar� uma v�rgula e ir� ler o nome dos diretores, um por um.
			scanf("%d", &existe);
			if(existe==1) strcat(ValorASerInserido,",");
			while(existe==1)
			{
				i++;
				fflush(stdin);
				printf("\n Digite o nome do proximo do diretor:\n");
				scanf(" %[^\n]",Diretores[i]);
				
				strcat(ValorASerInserido,Diretores[i]);
				strcat(ValorASerInserido,",");
				
				printf("\n Existe(m) outro(s) Diretor(es) que participaram do filme?(1/0)\n");
				scanf(" %d", &existe);
				if(existe!=0 && existe!=1) printf("\n Irei considerar isso como um sim!");
			}
		}

		printf("\n Quantos atores/atrizes que trabalharam no filme desejas inserir? (max:10)\n"); // M�ximo estabelecido de acordo com o arquivo resumo.txt
		scanf(" %d", &qntA);
		while(qntA<0 || qntA>20)
		{
			printf("\n Possivelmente esse n�o � o n�mero correto de atores/atrizes que participaram do filme.\n Deseja inserir algum ator/atriz? (1/0)");
			scanf(" %d",&qntA);
		}
		fflush(stdin);
		for(j=0;j<qntA;j++)
		{
			strcat(ValorASerInserido,","); // Concatena sempre a v�rgula antes pois o �ltimo ficar� sem a v�rgula ao final.
			printf("\n Digite um ator/atriz que trabalhou no filme \n(Se deseja incluir um personagem especifico para o ator,\n insira NomeDoAtor=NomePersonagem, substituindo NomeDoAtor pelo nome do ator e Nome Personagem pelo nome do personagem): ");
			scanf(" %[^\n]",nomeAtores[j]);
			strcat(ValorASerInserido,nomeAtores[j]);
			fflush(stdin);
		
		}
	
		
		InsercaoInicial(inicioF,fimF,inicioA,fimA,inicioP,ValorASerInserido);
		
		printf("\n Pronto! A inser��o est� feita.\n");
		
		printf("\n Nome do filme para consultar: %s", nomeFilme);
		
		printf("\n\n Retornando ao menu principal!\n");
		system("pause");
		system("cls");
		return;

}


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


void listarFilmesAtorOrdemCronologica(Atores **inicioA)
{
	int flag=1,i=0,flagAno=0,j;
	char nomeAtor[200];
	char semAnoNome[20][200];
	while(flag==1)
	{
		flag=1;
		printf("\n Digite o nome do ator/atriz que deseja pesquisar:\n");
		scanf("\n%[a-z A-Z � � � � � � � � � �]", nomeAtor);
		Atores *ptaux = verificaAtores(inicioA, nomeAtor);
		if(ptaux!=NULL)
		{
			printf("\n Nome: %s", ptaux->NomeAtor);
			printf("\n Filmes dos quais participou:");
			while(ptaux->filmes!=NULL)
			{
			/*	if(ptaux->filmes->nome->ano=='') /*        N�o encontrei filmes sem ano... */ // <----------- Isso ficar� por enquanto pois esse caso n�o foi testado. (sinta-se livre para excluir, se achar necess�rio).
			/*	{
					flagAno=1;
					strcpy(semAnoNome[i],ptaux->filmes->nome->NomeFilmes);
					i++;
				}
				else*/
			//	{
					printf("\n %s. Ano: %d",ptaux->filmes->nome->NomeFilmes, ptaux->filmes->nome->ano);
			//	}
				ptaux->filmes = ptaux->filmes->prox;
			}
		/*	if(flagAno==1)
			{
				for(j=0;j<i;j++)
				{
					printf("\n %s.", semAnoNome[j]);
				}
			}*/
		}
		
		printf("\n Deseja realizar outra consulta? (1/0)\n");
		scanf("%d",&flag);
	}
	printf("\n Retornando ao menu!");
	system("pause");
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
			return ptaux;
		}
		ptaux = ptaux->prox;
	}
	return NULL;
}


void InsereAtorListaAFilmes(AtoresFilmes **inicioAF, Atores **Pos ) // Insere no in�cio da lista AtoresFilmes na lista Filmes * favor verificar em inser��oInicial *
{
	AtoresFilmes *ptaux = (AtoresFilmes *)malloc(sizeof(AtoresFilmes));
	ptaux->nome = *Pos;
	ptaux->prox = *inicioAF;
	*inicioAF = ptaux;

}



void defineFilmesAlfabeticoOuReverso(Filmes **inicioF, Filmes **fimF) // Sub-menu para definir qual tipo de listagem de filmes ser� feita, com a op��o 0 para sair
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
				printf("\nDigite uma op��o v�lida!");
				break;
		}
	}
}

void ListaFilmesOrdemAlfabetica(Filmes **inicioF, Filmes **fimF, char NormalOuReverso) // Listagem de filmes em ordem alfab�tica ou alfab�tica reversa
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
					printf("\n Digite um n�mero v�lido!");
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

void defineAtoresAlfabeticoOuReverso(Atores **inicioA, Atores **fimA) // Sub-menu para definir qual tipo de listagem de atores ser� feita, com a op��o 0 para sair
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
				printf("\nDigite uma op��o v�lida!");
				break;
		}
	}
}

void ListaAtoresOrdemAlfabetica(Atores **inicioA, Atores **fimA, char NormalOuReverso) // Listagem de atores em ordem alfab�tica ou alfab�tica reversa
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
					printf("\n Digite um n�mero v�lido!");
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


void buscaFilmeEspecifico(Filmes **inicioF) // Pesquisa para verifica��es espec�ficas. Utilizada para testes
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
	else printf("Desculpe, esse filme n�o existe!");
}


/* Sess�o de fun��es relacionadas aos personagens; Mesmo padr�o que os acima */



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
