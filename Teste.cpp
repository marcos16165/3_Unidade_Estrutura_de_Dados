#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

typedef struct Reg
{
	int info;
	Reg *prox;
} Celula;

//função de inicialização: retorna uma lista vazia


Celula* inicializa(void)
{
	return NULL;
}

//vazia: retorna 1 se L vazia ou 0 caso contrário
int vazia(Celula* L)
{
	if (L == NULL)
		return 1;
	else
		return 0;
}


/*
void addinicio(struct no *head, int valor)//inserir um elemento no inicio
{
	struct no *p;
	printf("\nValor do Elemento: ");
	scanf("%d",&valor);
	if((p = malloc(sizeof(struct no))) == NULL)//erro
	{
		printf("\nMemory Failure\n");
	}
	else
	{
		p->info = valor; //recebendo valor
		p->prox = head->prox; //pprox recebe cabeçaprox
		head->prox = p; //cabeça prox recebe p;
	}
}
*/

//inserção no início: retorna a lista atualizada
Celula *insereInicio (Celula* L, int dado)
{
	Celula * novo;
	novo= new Celula;
	novo->info = dado;
	novo->prox = L->prox;
	L->prox = novo;
	return novo;
}
/*
void imprimir(struct no *head) //imrpimir elementos
{
	struct no *p;
	int okay = 0;
	p = head->prox;//começa no primeiro elemento, para nao cair na cabeça
	while(p!=head)//ensuqnaod p for diferente de cabeça, para achar o fim
	{
		printf("\n%d",p->info);//imprime registro
		p = p->prox;//proximo registro
		okay = 1; //validação para lista não ser vazia
	}
	if(okay == 0)//lista vazia
	{
		printf("\nLista Vazia\n");
	}
}
*/

//função imprime: imprime valores dos elementos
void imprime(Celula* L){ 
	Celula* p;//variável auxiliar para percorrer a lista 
	for (p = L->prox; p != NULL; p = p->prox) 
	cout<<"info = "<<p->info<<endl; 
}

//Retorna o tamanho da lista
int TamanhoLista(Celula * L)
{
	int tam = 0;
	Celula *p;
	p = L;
	while(p != NULL)
	{
		tam++;
		p = p->prox;
	}
	return tam - 1;
}

//função que busca um elemento na lista
Celula* busca(Celula* L, int v)
{
	Celula* p;
	for (p = L->prox; p != NULL; p = p->prox)
		if (p->info == v){ 
		cout<<"Nunmero encontrado"<<endl;
		return p;
		}
		else
		{
			cout<<"Numero nao encontrado";
			return NULL;
		}
}
/*
void remover(struct no *head, int valor)//remover determinado elemento
{
	struct no *p, *aux;
	printf("\nValor a Remover: ");
	scanf("%d",&valor);
	
	p = head->prox; //p recebe o primeiro elemento
	aux = head; 
	head->info = valor; //concatyena valor  na cabeça
	while(p->info != valor) //enquanto o valor digitado for diferente da lista, vai percorrendo
	{
		aux = p; //guarda o elemento e pula para o proximo
		p = p->prox;
	}	
	if(p == head) //não encontrou
	{
		printf("\nElemento nao encontrado\n");
	}
	else
	{
		aux->prox = p->prox; //aux prox recebe o p prox que aponta pra acabeça e elimina a conexao com o p
		free(p);//elimiona o valor
		printf("\nElemento removido com Sucesso!\n");
	}
}*/

void excluir(int dado, Celula *L)
{
	Celula *guarda, *lixo;
	guarda = L;
	lixo = L->prox;
	while (lixo != NULL && (lixo->info != dado))
	{
		guarda = lixo;
		lixo = lixo->prox;
	}
	if (lixo != NULL)
	{
		guarda->prox = lixo->prox;
		free (lixo);
	}
}

void menu()
{
	cout << "\n****** MENU LISTA ENCADEADA ******\n";
	cout << "1 - Inserir\n";
	cout << "2 - Remover\n";
	cout << "3 - Mostrar\n";
	cout << "4 - Buscar\n";
	cout << "0 - Sair\n";
	cout << "******************\n";
}

int main()
{
	char N;//Variável para voltar para o menu inicial
	Celula *L;
	L = new Celula;
	int op, v;
	inicializa();

	do
	{
		menu();
		cout << "\nDigite a opcao desejada: ";
		cin >> op;

		switch(op)
		{

		case 1:
			// insere();
			system("cls || clear");
			cout << "\nValor que deseja inserir: ";
			cin >> v;
			insereInicio(L, v);
			system("cls || clear");
			break;

		case 2:
			//Remover();
			system("cls || clear");
			cout << "\nValor que deseja buscar: ";
			cin >> v;
			excluir(v,L);
			cout << endl;
			cout << "\nPressione qualquer tecla para limpar e retornar para o menu: ";
			cin >> N;
			system("cls || clear");
			break;

		case 3:
			//Mostrar();
			system("cls || clear");
			imprime(L);
			cout << "\nPressione qualquer tecla para limpar e retornar para o menu: ";
			cin >> N;
			system("cls || clear");
			break;

		case 4:
			//buscar();
			system("cls || clear");
			cout << "\n----- BUSCAR DADOS DA AGENDA ----- " << endl;
			cout << "\nValor que deseja buscar: ";
			cin >> v;
		   	L= busca(L, v);

			cout << "\nPressione qualquer tecla para limpar e retornar para o menu: ";
			cin >> N;
			system("cls || clear");
			break;
		}
	}
	while(op != 0);

	return 0;
}
