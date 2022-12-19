#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <locale>

struct lista
{
	int info;
	struct lista* prox;
	struct lista* ant;
};	
typedef struct lista Lista;

Lista* inicializa();
bool vazia(Lista* l);
Lista* insere_inicio(Lista* l, int v);
Lista* insere_fim(Lista* l, int v);
Lista* remove_inicio(Lista* l);
Lista* remove_fim(Lista* l);
Lista* remove_valor(Lista* l, int v);
void imprime(Lista* l);
void imprime_reverso(Lista* l);
