#include <stdio.h>
#include <stdlib.h>
#include "no.h"

int main() {
	Lista* lista = cria();
	
	InsereNoFinal(&lista, 112);
	InsereNoInicio(&lista, 5);
	InsereNoInicio(&lista, 4);
	InsereNoInicio(&lista, 1);
	
		
	ImprimeLista(lista);
	
	RemoveDoInicio(&lista);
	ImprimeLista(lista);
	
	RemoveDoInicio(&lista);
	ImprimeLista(lista);
	
	RemoveDoInicio(&lista);
	ImprimeLista(lista);
	RemoveDoInicio(&lista);
	ImprimeLista(lista);
	RemoveDoInicio(&lista);
	ImprimeLista(lista);
	RemoveDoInicio(&lista);
	ImprimeLista(lista);
	RemoveDoInicio(&lista);
	ImprimeLista(lista);
	RemoveDoInicio(&lista);
	ImprimeLista(lista);
	
	InsereNoInicio(&lista, 4);
	InsereNoInicio(&lista, 1);
	
		
	ImprimeLista(lista);
	
	return 0;
}
