/*
	* Projeto: Fila de Inteiros
	* Autor: Joyce Claine, Marcos Monteiro e William 
	* Dados: 25/11/2018
	* Versao: 2.0
	* Data da ultima modificao: 15/12/2018
	* Descricao: Exemplo de fila inserir a cada 3segs e removendo a cada 10segs.
*/
#include "pch.h"
#include <iostream>
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds

using namespace std;
using namespace chrono;
using namespace this_thread;

typedef struct Reg
{
	int info;
	Reg *prox;
} No;

typedef struct fila
{
	No *primeiro;
	No *ultimo;
	int tam;
} Fila;


void inicializaFila(Fila *f)
{
	f->primeiro = NULL;
	f->ultimo = NULL;
}

Fila *inserirFila(Fila *f, int k)
{
	No *novo;
	novo = new No;
	novo->info = k;

	if (f->primeiro == NULL) {
		f->primeiro = novo;
		f->ultimo = novo;
		novo->prox = NULL;
		f->tam++;
	}
	else
	{
		novo->prox = f->ultimo->prox;
		f->ultimo->prox = novo;
		f->ultimo = novo;
	}
	return f;
}

int FilaVazia(Fila *f)
{
	return f->primeiro == NULL; // Se o inicio apontar para NULL, entao Fila est� vazia
}

Fila *removerFila(Fila *f)
{
	No *aux;
	aux = f->primeiro;

	if (aux == NULL)
		cout << "\nFila vazia!" << endl;
	else
	{
		f->primeiro = aux->prox;
		free(aux);
		f->tam--;
	}
	return f;
}

void mostrarFila(Fila *f)
{
	No *copia;
	copia = f->primeiro;
	int cont = 1;
	if (copia == NULL)
	{
		cout << "\nFila vazia!" << endl;
	}
	else
	{
		while (copia != NULL)
		{
			cout << "Fila[" << cont << "]= " << copia->info << endl;
			copia = copia->prox;
			cont++;
		}
	}

}

int GeraValAleatorio(int val[], int QuantNum, int lim)
{
	int N;
	srand(time(NULL));
	for (int i = 0; i < QuantNum; i++)
	{
		val[i] = rand() % lim;
		N = val[i];
	}
	return N;
}

int main()
{
	int x;
	int num[100];
	Fila *F1;
	F1 = new Fila;
	int v = 3;
	inicializaFila(F1);

	while (v != 0) {
		for (int i = 0; i < 3; i++) {
			sleep_for(seconds(3));
			x = GeraValAleatorio(num, 1, 100);
			inserirFila(F1, x);
			cout << "Inserido na Fila" << endl;
			mostrarFila(F1);
			cout << endl;
		}
		sleep_for(seconds(2));
		removerFila(F1);
		cout << "Removido da Fila" << endl;
		mostrarFila(F1);
		cout << endl;

		v--;
	}
	return 0;
}