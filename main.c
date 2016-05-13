#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct nodoAtoresFilmes{struct nodoAtores*nome;struct nodoAtoresFilmes *prox;} AtoresFilmes; 
typedef struct nodoFilmes{char NomeFilmes[50]; int ano; char Diretores[150]; struct nodoFilmes *prox; struct nodoFilmes *ant;; struct nodoAtoresFilmes *atores;} Filmes;
typedef struct nodoAtores{char NomeAtor[50];struct nodoAtores *prox; struct nodoAtores *ant; struct nodoFilmes *filmes;} Atores;

int menu();
int leitura(Filmes **inicio, Filmes **fim, Atores **inicio, Atores **fim);
void insercaoOrdenada(Filmes **inicio, Filmes **fim, Atores **inicio, Atores **fim, char FilmesOuAtores?, char ValorASerInserido[600]);
int PesquisaNasStructs(Filmes **inicio, Atores **inicio, char ValorPesquisa[200], char FilmeAnoDiretorNome?);

int main()
{
	
	int escolha = menu();
	if(escolha!=0)
	{
		Filmes *inicioF = NULL, *fimF = NULL;
		Atores *inicioA = NULL, *fimA = NULL;
		while(leitura(&inicioF, &FimF, &inicioA, &inicioF)==0)
		{
			printf("\n Erro! Arquivo não encontrado. \n");
			printf("Insira o arquivo no diretorio especifico e tente novamente. \n");
			system("pause");
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

int leitura(Filmes **inicio, Filmes **fim, Atores **inicio, Atores **fim)
{
	
	FILE *arquivo;
	char linha[600];
	if((arquivo = fopen("c:\\resumo.txt", "r"))==NULL)
	{
		return 0
	}
	else
	{
		while((fgets(linha, sizeof(linha), arquivo))!= NULL)
		{
			insercaoOrdenada(&inicioF, &fimF, &inicioA, &fimA, 'I', linha);
		}
		fclose(arquivo);
		return 1;
	}
}

void insercaoOrdenada(Filmes **inicio, Filmes **fim, Atores **inicio, Atores **fim, char FilmesOuAtores?, char ValorASerInserido[600])
{
	if(strcmp(FilmesOuAtores,’I’)==1)
{
	
	}
}


