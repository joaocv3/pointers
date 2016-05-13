João Carlos
1


Pesquisar no Google Drive

Drive
.
Caminho da pasta
Meu Drive
UCS
programação II
trabalho
NOVO 
Pastas e visualizações
Meu Drive
Compartilhados comigo
Google Fotos
Recentes
Com estrela
Lixeira
86 GB de 100 GB usados
Fazer upgrade do armazenamento
.

C
filmes.c

PDF
Especificacao do Trabalho - 2016-2 (1).pdf
C
filmes.c
Detalhes
Atividade
filmes.c
Informações de compartilhamento

Informações gerais
Tipo
C
Tamanho
4 KB (4.545 bytes)
Armazenamento usado
4 KB (4.545 bytes)
Local
trabalho
Proprietário
eu
Modificado
em 12 de mai de 2016 por mim
Aberto
em 10:32 por mim
Criado em
12 de mai de 2016
Descrição
Adicionar uma descrição
Permissões de download
Os leitores podem fazer o download

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct nodoAtoresFilmes{struct nodoAtores*nome;struct nodoAtoresFilmes *prox;} AtoresFilmes; 
typedef struct nodoFilmes{char NomeFilmes[50]; int ano; char Diretores[150]; struct nodoFilmes *prox; struct nodoFilmes *ant; struct nodoAtoresFilmes *atores;} Filmes;
typedef struct nodoAtores{char NomeAtor[50];struct nodoAtores *prox; struct nodoAtores *ant; struct nodoFilmes *filmes;} Atores;

int menu();
int leitura(Filmes **inicioF, Filmes **fimF, Atores **inicioA, Atores **fimA);
void insercaoOrdenada(Filmes **inicioF, Filmes **fimF, Atores **inicioA, Atores **fimA, char ValorASerInserido[600]);
int PesquisaNasStructs(Filmes **inicioF, Atores **inicioA, char ValorPesquisa[200], char FilmeAnoDiretorNome);

int main()
{
	
	int escolha = menu(); 
	if(escolha!=0)
	{
		Filmes *inicioF = NULL, *fimF = NULL;
		Atores *inicioA = NULL, *fimA = NULL;
		if((leitura(&inicioF, &fimF, &inicioA, &fimA))==0)
		{
			printf("\n Erro! Arquivo não encontrado. \n");
			printf("Insira o arquivo no diretorio especifico e tente novamente. \n");
			return; // Encerra o programa
		}
		
	}
	while(escolha>0)
	{
		switch (escolha)
		{
			case 1:
				break;
			case 2:
				break;
			case 3:
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
		printf("\n 2:Listar todos os filmes de um determinado ator em ordem cronológica.");
		printf("\n 3:Listar todos os filmes em ordem alfabética e alfabética reversa.");
		printf("\n 4:Inserir novos filmes");
		printf("\n 5:Remover filmes");
		printf("\n 6:Listar todos os filmes de um determinado diretor (ordem cronologica)");
		printf("\n 7:Listar todos os atores que trabalharam diretamente com um determinado ator e o nome do filme no qual trabalharam juntos");
		printf("\n 8:Listar todos os atores que trabalharam diretamente com um diretor e o nome do filme em que trabalharam juntos");
		printf("\n 9:Listar todos os filmes que estão duplicados");
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

int leitura(Filmes **inicioF, Filmes **fimF, Atores **inicioA, Atores **fimA)
{
	
	FILE *arquivo;
	char linha[600];
	arquivo = fopen("resumo.txt", "r");
	if(arquivo==NULL)
	{
		return 0;
	}
	else
	{
		while((fgets(linha, sizeof(linha), arquivo))!= NULL)
		{
			insercaoOrdenada(inicioF, fimF, inicioA, fimA, linha); // mudei o esquema do 'I' pq toda hora passaria como valor inicial.
		}
		fclose(arquivo);
		return 1;
	}
}

void insercaoOrdenada(Filmes **inicioF, Filmes **fimF, Atores **inicioA, Atores **fimA, char ValorASerInserido[600])
{
	Filmes *novoF = (Filmes*)malloc(sizeof(Filmes));
	Atores *novoA = (Atores*)malloc(sizeof(Atores));
	
	char aux[100];
	int i, j=0,k;//variaveis contadoras para percorrer a linha, a string até a virgula e a string auxiliar, respectivamente;
	int status=0; //status para a inserção nos elementos do nodo
	for(i=0; i<strlen(ValorASerInserido); i++){ //Percorre o vetor de chars
		if(ValorASerInserido[i]==','){ 
			k=0;	//zera o contador da string auxiliar
			for(j; j<i ;j++){ // percorre da posicao inicial até a virgula
				aux[k]=ValorASerInserido[j]; //insere char a char na string auxiliar
				k++; //proxima posicao na string auxiliar
			}
			aux[k]='\0'; // encerra a string até a virgula
			printf("\n%s", aux);
			if(status=0)//guarda nome filme
				strcpy(novoF->NomeFilmes, aux);		
			else if (status==2) //ano
				novoF->ano=atoi(aux);
			else if (status==3) //diretor
				strcpy(novoF->Diretores, aux);
			else if (status>3){
				AtoresFilmes *novoAF = (AtoresFilmes*)malloc(sizeof(AtoresFilmes));
					
				if (novoF->atores==NULL)
					novoF->atores=novoAF;
				else{
					
				}
					
			}
			
			j=i+1; //comeca a contagem da proxima string após a virgula 
			status++; 
		}
	}


	
	if(1)
	{
	
	}
}


filmes.c
Abrir com
1 de 2 itens
filmes.cEspecificacao do Trabalho - 2016-2 (1).pdfExibindo filmes.c…
