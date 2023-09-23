#include <stdio.h>
#include <stdlib.h>
#include "lista_SE.h"


void cria_lista_se (t_lista *lista){ // crio a lista vazia, setando o primeiro a lista para apontar para zero e quantidade de elementos tambem igual a zero
	lista->cabeca = NULL;
	lista->quant_elementos = 0;
}

int lista_vazia_se (t_lista *lista){ // a lista estara vazia se a variavel quant_elementos nunca tiver sido incrementada
	if (lista->quant_elementos == 0)
		return 1;
	else 
		return 0;
}

int tamanho_lista_se (t_lista *lista){ // tamanho da lista ? a quantidade de vezes que a variavel quant_elementos foi incrementada
 	return lista->quant_elementos;
}

int insere_lista_inicio_se (t_lista *lista, int valor){ // insere no inicio da lista quando solicitado pelo usuario ou quando a lista eh vazia
	t_no *novo_no;
	
	novo_no = (t_no*)malloc(sizeof(t_no));
	
	if (novo_no == NULL){
		return 0;
	}
	
	novo_no->conteudo = valor;  
	novo_no->proximo = lista->cabeca; // se a lista for vazia ele vai apontar pra NULL que ? como inicializamos a lista
	lista->cabeca = novo_no; // a lista recebe o novo cabeca
	lista->quant_elementos++;
	
	return 1; //retorna 1 para informar que a criacao do novo no foi feita com exito
}

int insere_lista_meio_se (t_lista *lista, int pos, int valor){ // insere na posicao informada pelo usuario
	t_no *pt, *novo_no; 
	int aux = 1;
	
	novo_no = (t_no*)malloc(sizeof(t_no));
	if (novo_no == 0){
		return 0;
	}
	
	pt = lista->cabeca;
	
	while((aux < pos-1) && (pt != NULL)){
		pt = pt->proximo;
		aux++;
	} 
	
	if (pt == NULL){
		printf("ERRO: POSICAO INVALIDA\n");
		return 0;
	}
	
	novo_no->conteudo = valor;
	novo_no->proximo = pt->proximo;
	pt->proximo = novo_no;
	lista->quant_elementos += 1;
	
	return 1;
}

int insere_lista_fim_se (t_lista *lista, int valor){ // insere no final da lista, procura o final da lista e insere o novo no  
	t_no *pt, *novo_no;
	
	novo_no = (t_no*)malloc(sizeof(t_no));
	
	if (novo_no == NULL){
		return 0;	
	}
	
	novo_no->conteudo = valor;
	pt = lista->cabeca;
	
	while (pt->proximo != NULL){
		pt = pt->proximo;
	}
	
	pt->proximo = novo_no;
	novo_no->proximo = NULL;	
	lista->quant_elementos++;
	
	return 1;		
}

int insere_func (t_lista *lista, int valor, int posicao){ //verifica qual metodo usar com base nas informacoes passadas pelo usario


	t_no *p, *novoNo;
    int  aux, tamanho = lista->quant_elementos;

    if ((lista_vazia_se(lista)) || (posicao == 1)){
        aux = insere_lista_inicio_se(lista, valor);
        return aux;
    }
    
    if (posicao == tamanho+1){
        aux = insere_lista_fim_se(lista, valor);
        return aux;
   }
   
   else{
        aux = insere_lista_meio_se(lista, posicao, valor);
        return aux;
   }	
	
}

int remove_lista_se(t_lista *lista, int posicao, int *valor){
	t_no *aux, *pt; 
	int n = 1;
	
	pt=lista->cabeca;
	
	while((n<posicao) && pt->proximo != NULL){
		aux = pt;
		pt = pt->proximo;
		n++;
	}
	
	if(pt == NULL){
		return 0;
	}
	
	*valor = pt->conteudo;
	aux->proximo = pt->proximo;
	lista->quant_elementos--;
	
	free(pt);
	return 1;
}

int remove_cabeca_lista_se(t_lista *lista, int *valor){
	t_no *pt; 

	pt = lista->cabeca;
	
	*valor = pt->conteudo;
	lista->cabeca = pt->proximo;
	lista->quant_elementos--;

	free(pt);
	return 1;
}

int remove_func (t_lista *lista, int posicao, int *valor){
	int ret;
	
	if(posicao > lista->quant_elementos){
		return 0;
	}
	
	if(lista_vazia_se(lista)){
		return 0;
	}
	
	if (posicao == 1){
		ret = remove_cabeca_lista_se(lista, valor);
		return ret;
	}
	
	else {
		ret = remove_lista_se(lista, posicao, valor);
		return ret;
	}
}

int consulta_pos_se(t_lista *lista, int posicao, int *valor){
	t_no *pt;
	int n = 1;
	
	if(lista_vazia_se(lista) == 1){
		return 0;
	}
	
	if(posicao > lista->quant_elementos){
		return 0;
	}
	
	pt = lista->cabeca;
	
	while(pt != NULL && (n<posicao)){
		pt = pt->proximo;
		n++;
	}
	
	if(pt == NULL){
		return 0;
	}
	
	*valor = pt->conteudo;
	
	return *valor;
}	
	
int consulta_cont_se(t_lista *lista, int valor){
	t_no *pt;
	int n = 1;
	
	if(lista_vazia_se(lista) == 1){
		return 0;
	}
	
	pt = lista->cabeca;
	
		while(pt != NULL){
			if(pt->conteudo == valor){
				return n;
			}
		
		pt = pt->proximo;
		n++;
	}
	
}

void imprime_lista_se (t_lista* lista) { 	
	
	t_no *pt;
	char vazio = '\233'; 
	int elementos = lista->quant_elementos;
	int i;
		if(lista->quant_elementos == 0){
			printf("<< LISTA VAZIA >>");
		}
	
		pt = lista->cabeca;
		
		for(i=0; i<elementos && pt != NULL; i++){
			
			if(pt->proximo != NULL)
				printf("[\033[44m%d\033[0m|\033[0m\033[33m%#lx\033[0m]->", pt->conteudo, (unsigned long*)pt->proximo);
	
			else
				printf("[\033[44m%d\033[0m|\033[0m\033[33m%c\033[0m]\n", pt->conteudo, vazio);
			pt = pt->proximo;
		}	
}

int menu_se(void){	
	int opcao;
	
	printf("+------------------------------+ \n");
    printf("| LISTA SIMPLESMENTE ENCADEADA | \n");
    printf("|------------------------------| \n");
    printf("| 1. \033[32mInserir\033[0m elementos na lista| \n");
    printf("| 2. \033[31mRemover\033[0m elementos da lista| \n");
    printf("| 3. Consultar por valor       | \n");
    printf("| 4. Consultar por posicao     | \n");
    printf("| 5. \033[33mSair\033[0m                      |\n");
    printf("+------------------------------+ \n");
    printf("\nEscolha uma opcao: ");
	
	scanf("%d", &opcao);	
	
	system("cls");
	
	return opcao;
	
}






