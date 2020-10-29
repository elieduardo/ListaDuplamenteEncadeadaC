typedef struct no{
	int valor;
	struct no* ant;
	struct no* prox;
}No;

typedef struct lista{
	No* inicio;
	No* fim;
}Lista;

Lista* cria();

void InsereNoInicio(Lista** lista, int valor);

void InsereNoFinal(Lista** lista, int valor);

void RemoveDoInicio(Lista** lista);

void RemoveDoFim(Lista** lista);

void ImprimeLista(Lista* lista);
