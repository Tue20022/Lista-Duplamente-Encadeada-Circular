#include "Proj_dc.h"
using namespace std;

Lista* inicializa()
{
	return NULL;	
}

bool vazia(Lista* l)
{
	return l== NULL;
}

Lista* insere_inicio(Lista* l, int v)
{
	Lista* novo = (Lista*) malloc(sizeof(Lista));
	novo->info = v;
	
	if(vazia(l))
	{
		novo->prox = novo->ant = novo;	
	}else
	{
		novo->prox = l;
		novo->ant = l->ant;
		novo->ant->prox = novo;
		l->ant = novo;
	}
	return novo;
}

Lista* insere_fim(Lista* l, int v)
{
	Lista* novo = (Lista*) malloc(sizeof(Lista));
	novo->info = v;
	
	if(vazia(l)){
		insere_inicio(l, v);
	}else
	{
		novo->ant = l->ant;
		novo->prox = l;
		l->ant->prox = novo;
		l->ant = novo;
		return l;
	}
}

Lista* remove_inicio(Lista* l)
{
	Lista* aux = (Lista*)malloc(sizeof(Lista));
	
	if(vazia(l))
	{
		cout<<"Lista vazia"<<endl;
		cout<<endl;
		return l;
	}
	
	if (l->prox==l)
	{
		free(l);
		return NULL;
	}else
	{
		l->ant->prox = l->prox;
		l->prox->ant = l->ant;
		aux = l->prox;
		free(l);
		return aux;
	}
}

Lista* remove_fim(Lista* l)
{
	Lista* aux = (Lista*)malloc(sizeof(Lista));
	
	if(vazia(l))
	{
		cout<<"Lista vazia"<<endl;
		cout<<endl;
		return l;
	}
	
	if(l->prox==l)
	{
		free(l);
		return NULL;
	}else
	{
		aux = l->ant;
		aux->ant->prox = l;
		l->ant = aux->ant;
		free(aux);
		return l;
	}
}
	
Lista* remove_valor(Lista* l, int v)
{
	Lista* p = l;
	
	if(vazia(l))
	{
		cout<<"Lista vazia" <<endl;
		return l;
	}
	
	do
	{
		if(p->info==v)
			break;	
		p = p->prox;
	}while(p!=l);
	
	if(p==l && p->info!=v)//ñ achou 
	{
		cout<<"Não achou o elemento"<< endl;
		return l;
	}
	
	if(p==l & p==p->prox)
	{
		return NULL;
	}
	
	if(p==l && p->info==v) //1° elemento
	{
		p->prox->ant = l->ant;
		p->ant->prox = l->prox;
		p = p->prox;
		free(l);
		return p;
	}
	
	if(p==l->ant && p->info==v)//ultimo elemento
	{
		p->ant->prox = l;
		l->ant = p->ant;
		free(p);
		return l;
	}
	
	//no meio
	p->ant->prox = p->prox;
	p->prox->ant = p->ant;
	free(p);
	return l;	
}

void imprime(Lista* l)
{
	if(vazia(l))
	{
		cout<< "Lista Vazia"<<endl;
		return;
	}
	Lista* p = l;
	cout<< "Info: ";
	do
	{
		cout<< p->info <<" - ";
		p = p->prox;
	}while(p!=l);
	cout <<endl;
	
}

void imprime_reverso(Lista* l)
{
	if(vazia(l))
	{
		cout<<"Lista vazia"<<endl;
		return;
	}
	Lista* p = l->ant;
	cout<<"Info: ";
	do
	{
		cout<<p->info<<" - ";
		p = p->ant;
	}while(p!=l->ant);
	cout<<endl;
}
