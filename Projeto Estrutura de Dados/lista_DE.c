#include <stdio.h>
#include <stdlib.h>
#include "lista_DE.h"


void cria_lista_de(t_Lista *lista){ // crio a lista vazia, setando o primeiro a lista para apontar para zero e quantidade de elementos tambem igual a zero
	lista->cabeca = NULL;
	lista->cauda = NULL;
	lista->quant_elementos = 0;
}

int lista_vazia_de(t_Lista *lista){ // a lista estara vazia se a variavel quant_elementos nunca tiver sido incrementada
	if (lista->quant_elementos == 0)
		return 1;
	else 
		return 0;
}

int tamanho_lista_de (t_Lista *lista){ // tamanho da lista ? a quantidade de vezes que a variavel quant_elementos foi incrementada
 	return lista->quant_elementos;
}

int insere_lista_inicio_de (t_Lista *lista, int valor){ // insere no inicio da lista quando solicitado pelo usuario ou quando a lista eh vazia

	t_No *novo_no;
	
	novo_no = (t_No*)malloc(sizeof(t_No));
	
	if (novo_no == NULL){
		return 0;
	}
	

	novo_no->conteudo = valor;  
	novo_no->proximo = lista->cabeca; // se a lista for vazia ele vai apontar pra NULL que ? como inicializamos a lista
	novo_no->anterior = NULL;
	
	if(lista->cabeca != NULL){
		lista->cabeca->anterior = novo_no;
	}
	
	lista->cabeca = novo_no; // a lista recebe o novo cabeca
	lista->quant_elementos++;
	
	return 1; //retorna 1 para informar que a criacao do novo no foi feita com exito
}

int insere_lista_meio_de (t_Lista *lista, int pos, int valor){ // insere na posicao informada pelo usuario
	
	t_No *pt, *ct, *novo_no; 
	int aux = 1;
	
	novo_no = (t_No*)malloc(sizeof(t_No));
	if (novo_no == 0){
		return 0;
	}
	
	pt = lista->cabeca;
	ct = NULL;
	
	while((aux < pos) && (pt != NULL)){
		ct = pt;
		pt = pt->proximo;
		aux++;
	} 
	
	 if ((pos > 1) && (pt == NULL)) { // Verifique se a posição é válida
        printf("ERRO: POSICAO INVALIDA\n");
        free(novo_no); // Libere a memória alocada para o novo nó
        return 0;
    }

    novo_no->conteudo = valor;
    novo_no->proximo = pt;
    novo_no->anterior = ct;

    if (ct != NULL) {
        ct->proximo = novo_no;
    } else {
        lista->cabeca = novo_no; // Se ct for NULL, o novo nó será a nova cabeça da lista
    }

    if (pt != NULL) {
        pt->anterior = novo_no; // Atualize o ponteiro anterior do nó seguinte
    }

    lista->quant_elementos += 1;

    return 1;
}

int insere_lista_fim_de (t_Lista *lista, int valor){ // insere no final da lista, procura o final da lista e insere o novo no  
	
	t_No *pt, *novo_no;
	
	novo_no = (t_No*)malloc(sizeof(t_No));
	
	if (novo_no == NULL){
		return 0;	
	}
	
		novo_no->conteudo = valor;
		pt = lista->cabeca;
	
	while (pt->proximo != NULL){
		pt = pt->proximo;	
	}
	
	novo_no->proximo = NULL;
	novo_no->anterior = pt;
	pt->proximo = novo_no;

	lista->cauda = novo_no;	
	lista->quant_elementos++;
	
	return 1;		
}

int insere_func_de (t_Lista *lista, int valor, int posicao){ //verifica qual metodo usar com base nas informacoes passadas pelo usario
	
	t_No *p, *novoNo;
    int  aux, tamanho = lista->quant_elementos;

	if(posicao <= 0 ){
		return 0;
	}

    if ((lista_vazia_de(lista)) || (posicao == 1)){
        aux = insere_lista_inicio_de(lista, valor);
        return aux;
    }
    
    if (posicao == tamanho+1){
        aux = insere_lista_fim_de(lista, valor);
        return aux;
   }
   
   else{
        aux = insere_lista_meio_de(lista, posicao, valor);
        return aux;
   }	
	
}

int remove_lista_de(t_Lista *lista, int posicao, int *valor){
	
	t_No *aux, *pt; 
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
    
	if (pt->proximo != NULL) {
        pt->proximo->anterior = aux;
    }
    
    if(pt->proximo == NULL){
    	lista->cauda = aux;
	}
	free(pt);
    
    lista->quant_elementos--;
	return 1;
}

int remove_cabeca_lista_de(t_Lista *lista, int *valor){
 t_No *pt;

    pt = lista->cabeca;

    if (pt->proximo == NULL && pt->anterior == NULL) {
        // A lista contém apenas um elemento, mas não queremos zerá-la
        *valor = pt->conteudo;
        lista->cabeca = NULL;
        lista->cauda = NULL;
    } else {
        *valor = pt->conteudo;
        lista->cabeca = pt->proximo;
        lista->cabeca->anterior = NULL;
    }

    lista->quant_elementos--;
    free(pt);

    return 1;
}


int remove_func_de (t_Lista *lista, int posicao, int *valor){
	int ret;
	
	if(posicao > lista->quant_elementos){
		return 0;
	}
	
	if(lista_vazia_de(lista)){
		return 0;
	}
	
	if (posicao == 1){
		ret = remove_cabeca_lista_de(lista, valor);
		return ret;
	}
	
	else {
		ret = remove_lista_de(lista, posicao, valor);
		return ret;
	}
}

int consulta_pos_de(t_Lista *lista, int posicao, int *valor){
	t_No *pt;
	int n = 1;
	
	if(lista_vazia_de(lista) == 1){
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
	
int consulta_cont_de(t_Lista *lista, int valor){

	t_No *pt;
	int n = 1;
	
	if(lista_vazia_de(lista) == 1){
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

void imprime_lista_de (t_Lista* lista) { 	
	
	t_No *pt, *nt;
	char vazio = '\233'; 
	int elementos = lista->quant_elementos;
	int i;
		if(lista->quant_elementos == 0){
			printf("<< LISTA VAZIA >>");
		}
	
			
		pt = lista->cabeca;
		nt = lista->cauda;
		
		for(i=0; i<elementos && pt != NULL; i++){
			
			if(pt->proximo != NULL && pt->anterior != NULL)
				printf("[\033[0m\033[33m%#lx\033[0m|\033[44m%d\033[0m|\033[33m%#lx\033[0m]<->", (unsigned long*)pt->anterior, pt->conteudo, (unsigned long*)pt->proximo);
	
			if(pt->proximo != NULL && pt->anterior == NULL)
				printf("[%c|\033[44m%d\033[0m|\033[0m\033[33m%#lx\033[0m]<->", vazio, pt->conteudo, (unsigned long*)pt->proximo);
			
			if(pt->proximo == NULL && pt->anterior != NULL)
				printf("[\033[0m\033[33m%#lx\033[0m|\033[44m%d\033[0m|%c]\n", (unsigned long*)pt->anterior, pt->conteudo, vazio);
			
			if(pt->proximo == NULL && pt->anterior == NULL)
				printf("[%c|\033[44m%d\033[0m|%c]\n", vazio, pt->conteudo, vazio);
			
			pt = pt->proximo;
		}
			if (nt != NULL) 			
        		printf("\nCABECA:[\033[31m%d\033[0m] \nCAUDA:[%\033[31m%d\033[0m]\n", lista->cabeca->conteudo, lista->cauda->conteudo);
    
}

int menu_de(void){	
	int opcao;
	
	printf("+------------------------------+ \n");
    printf("¦  LISTA DUPLAMENTE ENCADEADA  ¦ \n");
    printf("¦------------------------------¦ \n");
    printf("¦ 1. \033[32mInserir\033[0m elementos na lista¦ \n");
    printf("¦ 2. \033[31mRemover\033[0m elementos da lista¦ \n");
    printf("¦ 3. Consultar por valor       ¦ \n");
    printf("¦ 4. Consultar por posicao     ¦ \n");
    printf("¦ 5. \033[33mSair\033[0m                      ¦ \n");
    printf("+------------------------------+ \n");
    printf("\nEscolha uma opcao: ");
	
	scanf("%d", &opcao);	
	
	system("cls");
	
	return opcao;
	
}

