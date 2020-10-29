#include <stdio.h>
#include <stdlib.h>
#include "no.h"

Lista* cria(){
	//Cria a lista, alocando certinho
	Lista* novaLista = (Lista*) malloc(sizeof(Lista));
	if(novaLista == NULL){
		printf("Nao consegui alocar memoria \0/");
	}
	//Inicia inicio e fim da lista com NULL
	novaLista->inicio = NULL;
	novaLista->fim = NULL;
	
	//Retorna Lista
	return novaLista;	
}

void InsereNoInicio(Lista** lista, int valor){
	//Cria lista, alocando certinho
	No* no = (No*) malloc(sizeof(No));
	if(no == NULL){
		printf("Nao consegui alocar memoria \0/");
	}
	//Coloca o valor no novo n�
	no->valor = valor;
	
	//Verifica se o incio da lista � null
	if((*lista)->inicio == NULL){
		//seta o valor do pr�ximo como null
		no->prox = NULL;
		//seta o valor do anterior como null
		no->ant = NULL;
		//pega o final e seta com o n�
		(*lista)->fim = no;
	}
	else{
		//seta o inicio da lista, como o pr�ximo do n�
		no->prox = (*lista)->inicio;
		//seta como null o anterior do n�
		no->ant = NULL;
		//pega o anterior do inicio, e seta o n�
		(*lista)->inicio->ant = no;
	}
	//o inicio vira o n�
	(*lista)->inicio = no;
}

void InsereNoFinal(Lista** lista, int valor){
	//Cria lista, alocando certinho
	No* no = (No*) malloc(sizeof(No));
	if(no == NULL){
		printf("Nao consegui alocar memoria \0/");
	}
	//Coloca o valor no novo n�
	no->valor = valor;
	
	//verifica se o sim � null
	if((*lista)->fim == NULL){
		//seta o proximo do no como null
		no->prox = NULL;
		//seta o anterior do no como null
		no->ant = NULL;
		// pega o inicio e seta nele o novo n�
		(*lista)->inicio = no;
	}
	else{
		//seta null no proximo do n�
		no->prox = NULL;
		//seta o final da lista no anterior do n�
		no->ant = (*lista)->fim;
		//seta no proximo do fim e seta o no
		(*lista)->fim->prox = no;
	}
	//pega a lista e seta o novo n� como fim
	(*lista)->fim = no;	
}

void RemoveDoInicio(Lista** lista){	
	//Verifica se o inicio da lista � diferente de null
	if((*lista)->inicio == NULL){
		printf("Nao eh possivel remover! a lista estah sem inicio!\n");
		return 0;
	}
	
	//Verifica se n�o � o �ltimo elemento da lista
	if((*lista)->inicio->prox == NULL){
		free((*lista));
		(*lista)->inicio = NULL;		
		(*lista)->fim = NULL;
		printf("Removi o primeiro elemento! agora a lista esta sem inicio/fim\n");
		return 0;
	}
	
	//o inicio da lista vira o proximo do inicio
	(*lista)->inicio = (*lista)->inicio->prox;
	
	//libera a mem�ria do anterior do inicio
	free((*lista)->inicio->ant);
	
	//pega o anterior do inicio e seta como null
	(*lista)->inicio->ant = NULL;
}

void RemoveDoFim(Lista** lista){
	//verifica se o fim da lista � diferente de null
	if((*lista)->fim == NULL){
		printf("Nao eh possivel remover! a lista estah sem final!\n");
		return 0;
	}
	
	//Verifica se n�o � o �ltimo elemento da lista
	if((*lista)->inicio->prox == NULL){
		free((*lista));
		(*lista)->inicio = NULL;		
		(*lista)->fim = NULL;
		printf("Removi o primeiro elemento! agora a lista esta sem inicio/fim\n");
		return 0;
	}
	
	//pega o final da lista e seta nele o anterior do final
	(*lista)->fim = (*lista)->fim->ant;
	
	//libera o proximo do fim
	free((*lista)->fim->prox);
	
	//pega o proximo do fim e seta como null
	(*lista)->fim->prox = NULL;	

}

void ImprimeLista(Lista* lista){
	//verifica se o inicio da lista � diferente de null
	if(lista->inicio == NULL){
		printf("Nao tem conteudo na lista!\n");
		return 1;
	}
	//seta no n� atual o inicio da lista
	No* atual =lista->inicio;	
	
	printf("Nossa lista estah assim: \n");
	
	//enquanto o atual � diferente da lista, imprime o valor do atual
	while(atual != NULL){
		printf("%d\n", atual->valor);
		//seta ao atual, o valor do proximo
		atual = atual->prox;
	}
}
