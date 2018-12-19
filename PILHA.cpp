/*
	* Projeto: Pilha de Inteiros
	* Autor: Joyce Claine, Marcos Monteiro e William
	* Dados: 16/12/2018
	* Versao: 1.0
	* Data da ultima modificao: 16/12/2018
	* Descricao: Exemplo de pilha inserir a cada 3segs e removendo a cada 10segs.
*/

//#include "pch.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <ctime>
#include <thread>        
#include <chrono> 

using namespace std;
using namespace chrono;
using namespace this_thread;

typedef struct Reg
{
	int info;
	Reg *prox;
} No;

typedef struct tipoPilha
{
	No * Topo;
	int tamanho;
} Pilha;

Pilha *iniciaPilha(Pilha *PL)
{
	PL->Topo = NULL;
	PL->tamanho = 0;
	return PL;
}

int pilhaVazia(Pilha *PL)
{
	return(PL->Topo == NULL);
}

Pilha *empilhar(Pilha *PL, int k)
{
	No *novo;
	novo = new No;
	novo->info = k;
	novo->prox = PL->Topo;
	PL->Topo = novo;
	PL->tamanho++;
	return PL;
}

Pilha *desempilhar(Pilha *PL)
{
	No *aux;
	int sai;
	if (pilhaVazia(PL))
		cout << "\nA PILHA ESTA VAZIA!" << endl;
	else
	{
		aux = PL->Topo;
		PL->Topo = aux->prox;
		sai = aux->info;
		cout << "\n" << sai << " Retirado da pilha! " << endl;
		PL->tamanho--;
		delete aux;
	}
	return PL;
}

void imprimirPilha(Pilha *PL)
{
	No *copia;
	copia = PL->Topo;
	int cont = 1;
	if (pilhaVazia(PL))
		cout << "PILHA VAZIA!" << endl;
	else
		while (copia != NULL)
		{
			cout << "PILHA[" << cont << "] = " << copia->info << endl;
			copia = copia->prox;
			cont++;
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
	Pilha *PL;
	PL = new Pilha;
	int v = 10;
	iniciaPilha(PL);

	while (v != 0)
	{	
		while(PL->tamanho<=19){
		for (int i = 0; i < 1; i++) 
		{   

			sleep_for(seconds(3));
			x = GeraValAleatorio(num, 1, 100);
			empilhar(PL, x);
			cout << "Inserido na Pilha" << endl;
			imprimirPilha(PL);
			cout << endl;
		}
		}
		sleep_for(seconds(2));
		desempilhar(PL);
		imprimirPilha(PL);
		cout << endl;

		v--;
	}

	return 0;
}