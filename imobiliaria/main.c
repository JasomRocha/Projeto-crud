#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAXIMOVEIS 100 ///definindo uma constante chamada maximoveis de tamanho 100


typedef struct imovel_info{  ///definindo o tipo estruturado imovel_info que contem informações sobre as informações que são comuns a todos os imoveis
    char rua[100];
    int numero;
    char bairro[100];
    long int cep;
    char cidade[50];
    char tipo[30];
    char disponivel[30];
    int preco;
}imovel_info;

typedef struct casa_atr{ /// tipo estruturado que vai armazenar os atributos pertecentes as casas
    int numero_pavimentos;
    int numero_quartos;
    int area_terreno;
    int area_construida;
}casa_atr;

typedef struct apart_atr{ /// tipo estruturado que vai armazenar as informações pertencentes a apartamentos
    int numero_vagas;
    int numero_quartos;
    int area;
    char posicao[100];
    int condominio;
    int andar;
}apart_atr;

typedef struct terreno_atr{ /// tipo estruturado que vai armazenar as informações de terreno
    int comprimento;
    int largura;
    int area;
}terreno_atr;

typedef struct flat_atr{ /// tipo estruturado que vai armazenar as informações pertencentes aos flats
    char ar[4];
    char recepcao[4];
    char internet[4];
    char tv[4];
    char lavanderia[4];
    char limpeza[4];
    int condominio;
    int area;
}flat_atr;

typedef struct studio_atr{ ///tipo estruturado que vai armazenar as informações pertencentes aos studios
    char ar[4];
    char recepcao[4];
    char internet[4];
    char tv[4];
    char lavanderia[4];
    char limpeza[4];
    int condominio;
    int area;
    char piscina[4];
    char sauna [4];
    char ginastica[4];
}studio_atr;

imovel_info imoveis; /// decalacrei uma varável chamada imóveis do tipo imovel_info, e assim vai...
terreno_atr terrenos;
casa_atr casas;
apart_atr apartamentos;
flat_atr flats;
studio_atr studios;

imovel_info ler[MAXIMOVEIS]; /// declarei um vetor chamado ler do tipo imovel_info de tamanho "maximoveis", ou seja, temos um vetor com 100 posições e cada posição
terreno_atr ler1[MAXIMOVEIS]; ///pode armazenar tudo que a struct imovel_info tem.
casa_atr ler2[MAXIMOVEIS];  /// mesma coisa para as demais declarações.
apart_atr ler3[MAXIMOVEIS];
flat_atr ler4[MAXIMOVEIS];
studio_atr ler5[MAXIMOVEIS];

int numero; /// algumas variaveis globais
int opcao;
int retorno;
int num, gsoma= 0;

FILE *imob; /// aqui é onde eu declaro todos os arquivos que eu vou usar ao longo do prog. onde "imob" contem todas as informações
FILE *casa; /// comuns a todos os imoveis e os demais são os atributos especificos de cada um
FILE *apartamento;
FILE *terreno;
FILE *flat;
FILE *studio;

int main(){
    int i;
     for(i=0; i<MAXIMOVEIS; i++){ /// aqui eu preencho alguns vetores com '0' pra quando, em algum ciclo, o for chegar nessa posição saber que a partir dali
        ler[i].numero=0;          /// não tem mais nada cadastrado, e que ele pare ali.
     }
      for(i=0; i<MAXIMOVEIS; i++){
        ler2[i].numero_quartos=0;
     }
     for(i=0; i<MAXIMOVEIS; i++){
        ler3[i].numero_quartos=0;
     }
     for(i=0; i<MAXIMOVEIS; i++){
        ler1[i].area = 0;
     }
     for(i=0; i<MAXIMOVEIS; i++){
        ler4[i].area = 0;
     }
      for(i=0; i<MAXIMOVEIS; i++){
        ler5[i].area = 0;
     }



void cadastra_imovel(); /// faço a declaração de todas as funções que eu usei no programa, a maioria void, pois não retornam nada a função main.
void consulta_bairro();
void consulta_numero();
void listar();
void cadastra_atr();
void cadastra_atr2();
void cadastra_atr3();
void cadastra_atr4();
void cadastra_atr5();
void consulta_bairro2();
void listar_tipo2();
void listar_tudo();
void listar_tipo();
void listar_disponiveis();
void listar_cidade();
void listar_quantidade();
void Ler();
void Ler2();
void Ler3();
int menu();
int salvar;
do{  /// aqui começamos o programa de fato, com um do while pra executar o menu enquanto o ususario não digita o 0.
    Ler(); /// aqui chamo as funções de leitura, que irão retirar as informações do arquivo.
    Ler1();
    Ler2();
    Ler3();
    Ler4();
    Ler5();
    menu();/// chamo a função menu, que vai exibir as opçoes disponiveis para o ususario

    if (opcao == 1){ /// se a funcao menu retornar 1 eu entro nesse if
	    cadastra_imovel(); /// chamo a função de cadastro geral, das informações gerais de todos os imoveis, endereço e etc
	    if(strcmp(imoveis.tipo, "CASA")==0){
            cadastra_atr();
	    }
	    if(strcmp(imoveis.tipo, "APARTAMENTO")==0){
            cadastra_atr2();
	    }
	    if( strcmp(imoveis.tipo, "TERRENO")==0){
            cadastra_atr3();
	    }
	    if(strcmp(imoveis.tipo, "STUDIO")==0){
            cadastra_atr5();
	    }
	    if(strcmp(imoveis.tipo, "FLAT")==0){
            cadastra_atr4();
	    }
	    printf("deseja salvar esse imovel ?");
        scanf("%d", &salvar);
        system("cls");
	    if(salvar == 1){
            salve();
            printf("imovel salvo com sucesso !!\n");
	    }
        else if (salvar == 0)
            printf("imovel nao salvo !!\n");
        else
          printf("opcao invalida !!!\n");
    }

    else if(opcao == 2){ ///se a função menu retornar dois chamo a função que consulta casas pra vender por bairro
    	consulta_bairro();
    }
    else if(opcao == 3){ /// se a função menu retornar 3 chamo a função que lista todos os imoveis disponiveis ou indisponiveis incluindo seus atributos
        listar_tudo();
    }
    else if(opcao == 4){
        consulta_bairro2(); /// se a função menu retornar 4 chamo a função que consulta casas pra vender por bairro
    }
    else if(opcao == 5){
        listar_disponiveis(); /// se a função menu retornar 5 chamo a função que lista todas os imoveis disponiveis
    }
    else if(opcao == 6){ /// caso retorne 6, chamo a função que lista imoveis para vender por tipo casa, apartamento, terreno, flat ou studio
        listar_tipo();
    }
    else if(opcao == 7){ /// caso seja 7, chamo a função que lista imoveis disponiveis po cidade
        listar_cidade();
    }
    else if(opcao == 8){ /// caso 8, chamo a função que contabiliza todos os imveis separadamente por tipo
        listar_quantidade();
    }
    else if(opcao == 9){
        listar_tipo2(); /// caso 9, lista todos os imoveis disponiveis para alugar por tipo casa, apartamento...
    }
    else if(opcao == 0){ /// caso 0, encerra o programa.
        return 0;
    }

    else
    printf("\nopcao invalida !!\n");
    fclose(imob); /// fecha o arquivo imob
    printf("\ndeseja retornar ao menu ? (1-sim / 0- nao): ");
    scanf("%d", &retorno); /// lê a variavel retorno
    system("cls");

}  while(retorno == 1 ); /// enquanto retorno for 1 ele vai fazer tudo de novo
    return 0;
}

int menu(void){ /// exibe as opções do usuario e retorna ao main um inteiro indicando a opção escolhida pelo usuario
    printf("********SISTEMA IMOBILIARIO*******");
    printf("\n*1->CADASTRAR");
    printf("\n*2->CONSULTAR CASAS DISPONIVEIS PARA ALUGAR POR BAIRRO");
    printf("\n*3->LISTAR TODOS OS IMOVEIS CADASTRADOS(INCLUINDO SEUS ATRIBUTOS)");
    printf("\n*4->LISTAR CASAS DISPONIVEIS PARA VENDER POR BAIRRO");
    printf("\n*5->LISTAR IMOVEIS DISPONIVEIS");
    printf("\n*6->LISTAR IMOVEIS DISPONIVEIS PARA VENDER POR TIPO(APARTAMENTO, CASA, TERRENO, FLAT OU STUDIO)");
    printf("\n*7->LISTAR IMOVEIS DISPONIVEIS POR CIDADE");
    printf("\n*8->LISTAR QUANTIDADE DE IMOVEIS CADASTRADOS");
    printf("\n*9->LISTAR IMOVEIS DISPONIVEIS PARA ALUGAR POR TIPO(APARTAMENTO, CASA, TERRENO, FLAT OU STUDIO)");
    printf("\n*0->ENCERRAR");
    printf("\ndigite a opcao desejada:");
    scanf("%d", &opcao);
    system("cls");

    return opcao;
}

void cadastra_imovel(){ /// cadastra as caracteristicas gerais de qualquer imovel cadastrado, rua, numero... e etc
    int i=0, num, retorno, salvar;

    contador();

    printf("imovel codigo %d\n", gsoma);
    getchar();
    setbuf(stdin, NULL);
    printf("que tipo de imovel voce deseja cadastrar ?(casa, apartamento, terreno, flat ou studio) ");
    gets(imoveis.tipo);
    for(i=0; i<strlen(imoveis.tipo); i++){
		imoveis.tipo[i] = toupper(imoveis.tipo[i]);
	}
    system("cls");

    /// esse if é caso algum usuario digite algo diferente das opcoes indicadas a ele pelo programa, usando a função strcmp, pertencente a biblioteca string.h
    if( !strcmp(imoveis.tipo, "studio") == 0 && !strcmp(imoveis.tipo, "terreno") == 0 && !strcmp(imoveis.tipo, "apartamento") == 0 && !strcmp(imoveis.tipo, "casa") == 0 && !strcmp(imoveis.tipo, "flat") == 0 && !strcmp(imoveis.tipo, "STUDIO") == 0 && !strcmp(imoveis.tipo, "TERRENO") == 0 && !strcmp(imoveis.tipo, "APARTAMENTO") == 0 && !strcmp(imoveis.tipo, "CASA") == 0 && !strcmp(imoveis.tipo, "FLAT") == 0){
        printf("nao cadastramos esse tipo de imovel !!\n");
        system("PAUSE");
        return 0;
    }

    printf("imovel numero %d\n", gsoma);
    printf("informe a rua do(a) %s:", imoveis.tipo);
        gets(imoveis.rua);
        for(i=0; i<strlen(imoveis.rua); i++){
		imoveis.rua[i] = toupper(imoveis.rua[i]);
	}
    printf("informe o numero:");
        scanf("%d", &imoveis.numero);
        getchar();
    printf("informe o bairro:");
        gets(imoveis.bairro);
        for(i=0; i<strlen(imoveis.bairro); i++){
		imoveis.bairro[i] = toupper(imoveis.bairro[i]);
	}
    printf("informe o cep:");
        scanf("%ld", &imoveis.cep);
        getchar();
    printf("informe a cidade:");
        gets(imoveis.cidade);
        for(i=0; i<strlen(imoveis.cidade); i++){
		imoveis.cidade[i] = toupper(imoveis.cidade[i]);
	}
    printf("esta disponivel para (venda ou aluguel):");
        gets(imoveis.disponivel);
        for(i=0; i<strlen(imoveis.disponivel); i++){
		imoveis.disponivel[i] = toupper(imoveis.disponivel[i]);
	}

    printf("qual o preco do imovel ?");
    scanf("%d", &imoveis.preco);

    printf("\n");

}

void Ler(){ /// leitura dos atributos gerais dos imoveis, mas aqui ja sabemos se é casa, se é apartamento, apenas não temos os atributos
    FILE *imob;
    int i=0;

	imob = fopen("imob.txt", "r");

    if (imob == NULL){ ///caso o arquivo não exista, ou não encontre o arquivo ele vai exibir essa msg
    	printf("Nao foi possivel abrir o arquivo !\n\n");
    }

    else{
	    for(i=0;i<MAXIMOVEIS; i++){ /// lê as informações do arquivo imob.txt

            fscanf(imob,"\n%[^\n]s\n", ler[i].rua);
	        fscanf(imob,"%d\n", &ler[i].numero);
	        fscanf(imob,"%[^\n]s\n", ler[i].bairro);
	        fscanf(imob,"%ld\n", &ler[i].cep);
	        fscanf(imob,"%[^\n]s\n", ler[i].cidade);
	        fscanf(imob,"%s", ler[i].tipo);
	        fscanf(imob,"%s", ler[i].disponivel);
	        fscanf(imob,"%d\n", &ler[i].preco);
	        if(ler[i].numero==0)
	        	break;
	    }
	}
    fclose(imob); /// fecha o arquivo
}

void Ler1(){ /// lê as informações do arquivo terreno.txt
FILE *terreno;
int i;
terreno = fopen("terreno.txt", "r"); /// abre o aquivo terreno.txt

    if (terreno == NULL){ ///caso o arquivo não exista, ou não encontre o arquivo ele vai exibir essa msg
    	printf("Nao foi possivel abrir o arquivo !\n\n");
    }

    else{
	    for(i=0;i<MAXIMOVEIS; i++){ /// aqui ele faz a leitura de fato e já joga as informções num vetor do tipo terreno_atr
            fscanf(terreno,"%d -- %d -- %d\n", &ler1[i].comprimento, &ler1[i].largura, &ler1[i].area);
	        if(ler1[i].area==0)
	        	break;
	    }
	}
    fclose(terreno); /// fecha o arquivo
}

void Ler2(){ /// função de leitura da mesma forma que as anteriores
FILE *casa;
int i;
casa = fopen("casa.txt", "r");

    if (casa == NULL){
    	printf("Nao foi possivel abrir o arquivo !\n\n");
    }

    else{
	    for(i=0;i<MAXIMOVEIS; i++){
            fscanf(casa,"%d -- %d -- %d -- %d\n", &ler2[i].numero_quartos, &ler2[i].numero_pavimentos, &ler2[i].area_terreno, &ler2[i].area_construida);
	        if(ler2[i].numero_quartos==0)
	        	break;
	    }
	}
    fclose(casa);
}

void Ler3(){ /// função de leitura da mesma forma que as anteriores
FILE *apartamento;
int i;
apartamento = fopen("apartamento.txt", "r");

    if (apartamento == NULL){
    	printf("Nao foi possivel abrir o arquivo !\n\n");
    }

    else{
	    for(i=0;i<MAXIMOVEIS; i++){
            fscanf(apartamento,"%d -- %d -- %d -- %d -- %d -- %[^\n]s\n", &ler3[i].numero_quartos, &ler3[i].numero_vagas, &ler3[i].area, &ler3[i].condominio, &ler3[i].andar, &ler3[i].posicao);
	        if(ler3[i].numero_quartos==0)
	        	break;
	    }
	}
    fclose(apartamento);
}

void Ler4(){ /// função de leitura da mesma forma que as anteriores
FILE *flat;
int i;
flat = fopen("flat.txt", "r");

    if (flat == NULL){
    	printf("Nao foi possivel abrir o arquivo !\n\n");
    }

    else{
	    for(i=0;i<MAXIMOVEIS; i++){
            fscanf(flat,"%d -- %d -- %s -- %s -- %s -- %s -- %s -- %s\n", &ler4[i].area, &ler4[i].condominio, &ler4[i].recepcao, &ler4[i].internet, &ler4[i].limpeza, &ler4[i].ar, &ler4[i].tv, &ler4[i].lavanderia);	        if(ler3[i].numero_quartos==0)
	        	break;
	    }
	}
    fclose(flat);
}

void Ler5(){ /// função de leitura da mesma forma que as anteriores
FILE *studio;
int i;
studio = fopen("studio.txt", "r");

    if (studio == NULL){
    	printf("Nao foi possivel abrir o arquivo !\n\n");
    }

    else{
	    for(i=0;i<MAXIMOVEIS; i++){ /// faz a leitura e já joga num vetor de struct
            fscanf(studio,"%d -- %d -- %s -- %s -- %s -- %s -- %s -- %s -- %s -- %s -- %s\n", &ler5[i].area, &ler5[i].condominio, &ler5[i].recepcao, &ler5[i].internet, &ler5[i].limpeza, &ler5[i].ar, &ler5[i].tv, &ler5[i].lavanderia, &ler5[i].piscina, &ler5[i].sauna, &ler5[i].ginastica);	        if(ler3[i].numero_quartos==0)
	        	break;
	    }
	}
    fclose(studio);
}

void listar_disponiveis(){ /// função que vai listar todas os imoveis disponivei OK !
    FILE *imob;
    int i=0, count=0, conta=0, conte=0, cont = 0, conti = 0; /// cada tipo de imovel coloquei um contador
    imob = fopen("imob.txt", "r"); /// abro o arquivo

    for(i=0; i<MAXIMOVEIS; i++){
        if(ler[i].numero==0){
        	break; /// quando encontrar o 0 no vetor de numeros dos imoveis ele para, pois adiante dali não possui nada cadastrado
		}

    	  if(strcmp(ler[i].tipo, "CASA")==0) {
            count++;
            printf("\n");
    		printf("%s codigo %d\n",ler[i].tipo, i+1);
	        printf("rua: %s\n", ler[i].rua);
	        printf("numero: %d\n", ler[i].numero);
	        printf("bairro: %s\n", ler[i].bairro);
	        printf("cep: %ld\n", ler[i].cep);
	        printf("cidade: %s\n", ler[i].cidade);
	        printf("disponivel para : %s\n", ler[i].disponivel);
	        printf("valor : %d\n", ler[i].preco);
	        printf("numero de quartos : %d\n", ler2[count-1].numero_quartos); /// observe o uso do contador especifico de casa
	        printf("numero de pavimentos : %d\n", ler2[count-1].numero_pavimentos); /// para podermos obter o atributo que foi cadastrado junto com aquela casa
	        printf("area de terreno : %d metros quadrados\n", ler2[count-1].area_terreno); /// da mesma forma para os outros tipos de imoveis
	        printf("area construida : %d metros quadrados\n", ler2[count-1].area_construida);
	        printf("\n");
        }

        if(strcmp(ler[i].tipo, "APARTAMENTO")==0) {
            conta++;
            printf("\n");
    		printf("%s codigo %d\n",ler[i].tipo, i+1);
	        printf("rua: %s\n", ler[i].rua);
	        printf("numero: %d\n", ler[i].numero);
	        printf("bairro: %s\n", ler[i].bairro);
	        printf("cep: %ld\n", ler[i].cep);
	        printf("cidade: %s\n", ler[i].cidade);
	        printf("disponivel para : %s\n", ler[i].disponivel);
	        printf("valor : %d R$\n", ler[i].preco);
	        printf("numero de quartos : %d\n", ler3[conta-1].numero_quartos);
	        printf("numero de vagas : %d\n", ler3[conta-1].numero_vagas);
	        printf("area: %d metros quadrados\n", ler3[conta-1].area);
	        printf("condominio : %d R$\n", ler3[conta-1].condominio);
	        printf("andar : %d°\n", ler3[conta-1].andar);
	        printf("posicao : %s", ler3[conta-1].posicao);
	        printf("\n");

        }

        else if( strcmp(ler[i].tipo, "TERRENO")==0 ){
            conte++;
            printf("\n");
    		printf("%s codigo %d\n",ler[i].tipo, i+1);
	        printf("rua: %s\n", ler[i].rua);
	        printf("numero: %d\n", ler[i].numero);
	        printf("bairro: %s\n", ler[i].bairro);
	        printf("cep: %ld\n", ler[i].cep);
	        printf("cidade: %s\n", ler[i].cidade);
	        printf("disponibilidade : %s\n", ler[i].disponivel);
	        printf("valor : %d R$\n", ler[i].preco);
	        printf("comprimento : %d metros\n", ler1[conte-1].comprimento);
            printf("largura : %d metros\n", ler1[conte-1].largura);
            printf("area : %d metros quadrados\n", ler1[conte-1].area);
            printf("\n");
		}

		if(strcmp(ler[i].tipo, "FLAT")==0) {
            cont++;
            printf("\n");
    		printf("%s codigo %d\n",ler[i].tipo, i+1);
	        printf("rua: %s\n", ler[i].rua);
	        printf("numero: %d\n", ler[i].numero);
	        printf("bairro: %s\n", ler[i].bairro);
	        printf("cep: %ld\n", ler[i].cep);
	        printf("cidade: %s\n", ler[i].cidade);
	        printf("disponivel para : %s\n", ler[i].disponivel);
	        printf("valor : %d R$\n", ler[i].preco);
	        printf("valor do condominio : %d R$\n", ler4[cont-1].condominio);
	        printf("area: %d metros quadrados\n", ler4[cont-1].area);
	        printf("internet : %s\n", ler4[cont-1].internet);
	        printf("recepcao 24 hrs : %s\n", ler4[cont-1].recepcao);
	        printf("servico de quarto : %s\n", ler4[cont-1].limpeza);
	        printf("ar condicionado : %s\n", ler4[cont-1].ar);
	        printf("TV a cabo : %s\n", ler4[cont-1].tv);
	        printf("servico de lavanderia : %s", ler4[cont-1].lavanderia);
	        printf("\n");
        }


		if(strcmp(ler[i].tipo, "STUDIO")==0 ) {
            printf("\n");
    		printf("%s codigo %d\n",ler[i].tipo, i+1);
	        printf("rua: %s\n", ler[i].rua);
	        printf("numero: %d\n", ler[i].numero);
	        printf("bairro: %s\n", ler[i].bairro);
	        printf("cep: %ld\n", ler[i].cep);
	        printf("cidade: %s\n", ler[i].cidade);
	        printf("disponivel para : %s\n", ler[i].disponivel);
	        printf("valor : %d R$\n", ler[i].preco);
            printf("area: %d metros quadrados\n", ler5[conti].area);
	        printf("condominio : %d R$\n", ler5[conti].condominio);
	        printf("internet : %s\n", ler5[conti].internet);
	        printf("recepcao 24 hrs : %s\n", ler5[conti].recepcao);
	        printf("servico de quarto : %s\n", ler5[conti].limpeza);
	        printf("ar condicionado : %s\n", ler5[conti].ar);
	        printf("TV a cabo : %s\n", ler5[conti].tv);
	        printf("servico de lavanderia : %s\n", ler5[conti].lavanderia);
            printf("sauna: %s\n", ler5[conti].sauna);
            printf("sala de ginastica : %s\n", ler5[conti].ginastica );
            printf("piscina : %s\n", ler5[conti].piscina);
	        printf("\n");
	        conti++;
        }
    }
    if (count ==0 && conte == 0 && conta == 0 && cont == 0 && conti == 0)
    printf("\anão temos este tipo de imovel a venda !"); /// caso ele não entre em nenhum if, é porque não temos nenhum imovel cadastrado...
    fclose(imob); ///...ou o usuario digitou um nome de imovel invalido
}

void listar_tudo(){ /// função que lista todos os imoveis sem restrições OK !
    int i=0, count=0, conta=0, conte=0,cont=0, conti = 0; /// dessa vez os contadores não funcionam como controle
    imob = fopen("imob.txt", "r");

    if(imob){
    for(i=0; i<MAXIMOVEIS; i++){

        if(ler[i].numero==0){
        	break; /// vetor preenchido com zeros no começo da execução do codigo, servindo como o "freio" do for
		}

        if(strcmp(ler[i].tipo, "CASA")==0 ) {
            count++;
            printf("\n");
    		printf("%s codigo %d\n",ler[i].tipo, i+1);
	        printf("rua: %s\n", ler[i].rua);
	        printf("numero: %d\n", ler[i].numero);
	        printf("bairro: %s\n", ler[i].bairro);
	        printf("cep: %ld\n", ler[i].cep);
	        printf("cidade: %s\n", ler[i].cidade);
	        printf("disponivel para : %s\n", ler[i].disponivel);
	        printf("valor : R$ %d \n", ler[i].preco);
	        printf("numero de quartos : %d\n", ler2[count-1].numero_quartos);
	        printf("numero de pavimentos : %d\n", ler2[count-1].numero_pavimentos);
	        printf("area de terreno : %d metros quadrados\n", ler2[count-1].area_terreno);
	        printf("area construida : %d metros quarados\n", ler2[count-1].area_construida);
	        printf("\n");
        }

        if(strcmp(ler[i].tipo, "APARTAMENTO")==0) {
            conta++;
            printf("\n");
    		printf("%s codigo %d\n",ler[i].tipo, i+1);
	        printf("rua: %s\n", ler[i].rua);
	        printf("numero: %d\n", ler[i].numero);
	        printf("bairro: %s\n", ler[i].bairro);
	        printf("cep: %ld\n", ler[i].cep);
	        printf("cidade: %s\n", ler[i].cidade);
	        printf("disponivel para : %s\n", ler[i].disponivel);
	        printf("valor : R$ %d\n", ler[i].preco);
	        printf("numero de quartos : %d\n", ler3[conta-1].numero_quartos);
	        printf("numero de vagas : %d\n", ler3[conta-1].numero_vagas);
	        printf("area: %d metros quadrados\n", ler3[conta-1].area);
	        printf("condominio : R$ %d \n", ler3[conta-1].condominio);
            printf("andar : %d°\n", ler3[conta-1].andar);
	        printf("posicao : %s", ler3[conta-1].posicao);
	        printf("\n");
        }

        if (strcmp(ler[i].tipo, "TERRENO")==0){
            conte++;
            printf("\n");
    		printf("%s codigo %d\n",ler[i].tipo, i+1);
	        printf("rua: %s\n", ler[i].rua);
	        printf("numero: %d\n", ler[i].numero);
	        printf("bairro: %s\n", ler[i].bairro);
	        printf("cep: %ld\n", ler[i].cep);
	        printf("cidade: %s\n", ler[i].cidade);
	        printf("disponibilidade : %s\n", ler[i].disponivel);
	        printf("valor : R$ %d \n", ler[i].preco);
	        printf("comprimento : %d metros\n", ler1[conte-1].comprimento);
            printf("largura : %d metros\n", ler1[conte-1].largura);
            printf("area : %d metros quadrados\n", ler1[conte-1].area);
            printf("\n");
		}
        if(strcmp(ler[i].tipo, "FLAT")==0){
            cont++;
            printf("\n");
    		printf("%s codigo %d\n",ler[i].tipo, i+1);
	        printf("rua: %s\n", ler[i].rua);
	        printf("numero: %d\n", ler[i].numero);
	        printf("bairro: %s\n", ler[i].bairro);
	        printf("cep: %ld\n", ler[i].cep);
	        printf("cidade: %s\n", ler[i].cidade);
	        printf("disponivel para : %s\n", ler[i].disponivel);
	        printf("valor : R$ %d\n", ler[i].preco);
	        printf("valor do condominio : R$ %d \n", ler4[cont-1].condominio);
	        printf("area: %d metros quadrados\n", ler4[cont-1].area);
	        printf("condominio : R$ %d \n", ler4[cont-1].condominio);
	        printf("internet : %s\n", ler4[cont-1].internet);
	        printf("recepcao 24 hrs : %s\n", ler4[cont-1].recepcao);
	        printf("servico de quarto : %s\n", ler4[cont-1].limpeza);
	        printf("ar condicionado : %s\n", ler4[cont-1].ar);
	        printf("TV a cabo : %s\n", ler4[cont-1].tv);
	        printf("servico de lavanderia : %s", ler4[cont-1].lavanderia);
	        printf("\n");
        }

        if(strcmp(ler[i].tipo, "STUDIO")==0) {
            printf("\n");
    		printf("%s codigo %d\n",ler[i].tipo, i+1);
	        printf("rua: %s\n", ler[i].rua);
	        printf("numero: %d\n", ler[i].numero);
	        printf("bairro: %s\n", ler[i].bairro);
	        printf("cep: %ld\n", ler[i].cep);
	        printf("cidade: %s\n", ler[i].cidade);
	        printf("disponivel para : %s\n", ler[i].disponivel);
	        printf("valor : R$ %d \n", ler[i].preco);
            printf("area: %d metros quadrados\n", ler5[conti].area);
	        printf("condominio : R$ %d \n", ler5[conti].condominio);
	        printf("internet : %s\n", ler5[conti].internet);
	        printf("recepcao 24 hrs : %s\n", ler5[conti].recepcao);
	        printf("servico de quarto : %s\n", ler5[conti].limpeza);
	        printf("ar condicionado : %s\n", ler5[conti].ar);
	        printf("TV a cabo : %s\n", ler5[conti].tv);
	        printf("servico de lavanderia : %s\n", ler5[conti].lavanderia);
            printf("sauna: %s\n", ler5[conti].sauna);
            printf("sala de ginastica : %s\n", ler5[conti].ginastica );
            printf("piscina : %s\n", ler5[conti].piscina);
	        printf("\n");
	        conti++;
        }

    }
    if (count=0 && cont ==0 && conta==0 && conte == 0 && conti == 0) /// caso não entre em nenhum if
        printf("nao existem imoveis cadastrados\n");
    fclose(imob);
 }
 }

void listar_tipo(){ /// função que lista todas os imoveis para vender e por tipo OK !
    int i=0;
    char tipo[30]; ///variavel que vai aramazenar o tipo de imovel que o usuario procura
    int count=0;
    int conta=0, conte=0, cont=0, conti =0;

    setbuf(stdin, NULL); /// limpa o buffer do teclado, pq se não buga o gets kkkk'
    printf("que tipo de imovel voce procura ?(casa, apartamento, terreno, flat ou studio): ");
    gets(tipo);
    for(i=0; i<strlen(tipo); i++){
		tipo[i] = toupper(tipo[i]);
	}
    system("cls");


    if( !strcmp(tipo, "STUDIO") == 0 && !strcmp(tipo, "TERRENO") == 0 && !strcmp(tipo, "APARTAMENTO") == 0 && !strcmp(tipo, "CASA") == 0 && !strcmp(tipo, "FLAT") == 0){
        printf("nao possuimos esse tipo de imovel !!\n");
        system("PAUSE");
        return 0;
    }

    FILE *imob;
    imob = fopen("imob.txt", "r");

    if(imob){
    for(i=0; i<MAXIMOVEIS; i++){
        if(ler[i].numero==0){
        	break;
		}

		if(strcmp(tipo, "CASA")==0 && strcmp(ler[i].tipo, tipo)==0 && strcmp(ler[i].disponivel, "VENDA")==0) {
            count++;
    		printf("%s codigo %d\n",ler[i].tipo, i+1);
	        printf("rua: %s\n", ler[i].rua);
	        printf("numero: %d\n", ler[i].numero);
	        printf("bairro: %s\n", ler[i].bairro);
	        printf("cep: %ld\n", ler[i].cep);
	        printf("cidade: %s\n", ler[i].cidade);
	        printf("disponivel para : %s\n", ler[i].disponivel);
	        printf("valor : R$ %d\n", ler[i].preco);
	        printf("numero de quartos : %d\n", ler2[count-1].numero_quartos);
	        printf("numero de pavimentos : %d\n", ler2[count-1].numero_pavimentos);
	        printf("area de terreno : %d metros quadrados\n", ler2[count-1].area_terreno);
	        printf("area construida : %d metros quadrados\n", ler2[count-1].area_construida);
	        printf("\n");
        }

        if(strcmp(tipo, "APARTAMENTO")==0 && strcmp(ler[i].tipo, tipo)==0 && strcmp(ler[i].disponivel, "VENDA")==0) {
            conta++;
            printf("\n");
    		printf("%s codigo %d\n",ler[i].tipo, i+1);
	        printf("rua: %s\n", ler[i].rua);
	        printf("numero: %d\n", ler[i].numero);
	        printf("bairro: %s\n", ler[i].bairro);
	        printf("cep: %ld\n", ler[i].cep);
	        printf("cidade: %s\n", ler[i].cidade);
	        printf("disponivel para : %s\n", ler[i].disponivel);
	        printf("valor : R$ %d\n", ler[i].preco);
	        printf("numero de quartos : %d\n", ler3[conta-1].numero_quartos);
	        printf("numero de vagas : %d\n", ler3[conta-1].numero_vagas);
	        printf("area: %d metros quadrados\n", ler3[conta-1].area);
	        printf("condominio : R$ %d \n", ler3[conta-1].condominio);
            printf("andar : %d°\n", ler3[conta-1].andar);
	        printf("posicao : %s", ler3[conta-1].posicao);
	        printf("\n");
        }

        if (strcmp(tipo, "TERRENO")==0 && strcmp(ler[i].tipo, tipo)==0 && strcmp(ler[i].disponivel, "VENDA")==0){
            conte++;
            printf("\n");
    		printf("%s codigo %d\n",ler[i].tipo, i+1);
	        printf("rua: %s\n", ler[i].rua);
	        printf("numero: %d\n", ler[i].numero);
	        printf("bairro: %s\n", ler[i].bairro);
	        printf("cep: %ld\n", ler[i].cep);
	        printf("cidade: %s\n", ler[i].cidade);
	        printf("disponibilidade : %s\n", ler[i].disponivel);
	        printf("valor : R$ %d\n", ler[i].preco);
	        printf("comprimento : %d metros\n", ler1[conte-1].comprimento);
            printf("largura : %d metros\n", ler1[conte-1].largura);
            printf("area : %d metros quadrados\n", ler1[conte-1].area);
            printf("\n");
		}

		if(strcmp(tipo, "FLAT")==0 && strcmp(ler[i].tipo, tipo)==0 && strcmp(ler[i].disponivel, "VENDA")==0) {
            cont++;
            printf("\n");
    		printf("%s codigo %d\n",ler[i].tipo, i+1);
	        printf("rua: %s\n", ler[i].rua);
	        printf("numero: %d\n", ler[i].numero);
	        printf("bairro: %s\n", ler[i].bairro);
	        printf("cep: %ld\n", ler[i].cep);
	        printf("cidade: %s\n", ler[i].cidade);
	        printf("disponivel para : %s\n", ler[i].disponivel);
	        printf("valor : R$ %d \n", ler[i].preco);
	        printf("valor do condominio : R$ %d \n", ler4[cont-1].condominio);
	        printf("area: %d metros quadrados\n", ler4[cont-1].area);
	        printf("internet : %s\n", ler4[cont-1].internet);
	        printf("recepcao 24 hrs : %s\n", ler4[cont-1].recepcao);
	        printf("servico de quarto : %s\n", ler4[cont-1].limpeza);
	        printf("ar condicionado : %s\n", ler4[cont-1].ar);
	        printf("TV a cabo : %s\n", ler4[cont-1].tv);
	        printf("servico de lavanderia : %s", ler4[cont-1].lavanderia);
	        printf("\n");
        }

        if(strcmp(tipo, "STUDIO")==0 && strcmp(ler[i].tipo, tipo)==0 && strcmp(ler[i].disponivel, "VENDA")==0) {
            printf("\n");
    		printf("%s codigo %d\n",ler[i].tipo, i+1);
	        printf("rua: %s\n", ler[i].rua);
	        printf("numero: %d\n", ler[i].numero);
	        printf("bairro: %s\n", ler[i].bairro);
	        printf("cep: %ld\n", ler[i].cep);
	        printf("cidade: %s\n", ler[i].cidade);
	        printf("disponivel para : %s\n", ler[i].disponivel);
	        printf("valor : R$ %d \n", ler[i].preco);
            printf("area: %d metros quadrados\n", ler5[conti].area);
	        printf("condominio : R$ %d \n", ler5[conti].condominio);
	        printf("internet : %s\n", ler5[conti].internet);
	        printf("recepcao 24 hrs : %s\n", ler5[conti].recepcao);
	        printf("servico de quarto : %s\n", ler5[conti].limpeza);
	        printf("ar condicionado : %s\n", ler5[conti].ar);
	        printf("TV a cabo : %s\n", ler5[conti].tv);
	        printf("servico de lavanderia : %s\n", ler5[conti].lavanderia);
            printf("sauna: %s\n", ler5[conti].sauna);
            printf("sala de ginastica : %s\n", ler5[conti].ginastica );
            printf("piscina : %s\n", ler5[conti].piscina);
	        printf("\n");
	        conti++;
        }

    }
     if(count==0 && cont == 0 && conta ==0 && conti == 0 && conte == 0)
        printf("\nnao possuimos esse tipo de imovel cadastrado !!!\n");
        getchar();
        system("cls");
    fclose(imob);
    }

 }

void listar_tipo2(){ /// função que lista todas os imoveis pra alugar e por tipo OK !
    int i=0;
    char tipo[30];
    int count=0;
    int conta=0, conte=0, cont=0, conti =0;

    setbuf(stdin, NULL);
    printf("que tipo de imovel voce procura ?(casa, apartamento, terreno, flat ou studio): ");
    gets(tipo);
    for(i=0; i<strlen(tipo); i++){
		tipo[i] = toupper(tipo[i]);
	}
    system("cls");
    if( !strcmp(tipo, "STUDIO") == 0 && !strcmp(tipo, "TERRENO") == 0 && !strcmp(tipo, "APARTAMENTO") == 0 && !strcmp(tipo, "CASA") == 0 && !strcmp(tipo, "FLAT") == 0){
        printf("nao possuimos esse tipo de imovel !!\n");
        system("PAUSE");
        return 0;
    }

    FILE *imob;
    imob = fopen("imob.txt", "r");

    if(imob){
    for(i=0; i<MAXIMOVEIS; i++){
        if(ler[i].numero==0){
        	break;
		}

		if(strcmp(tipo, "CASA")==0 && strcmp(ler[i].tipo, tipo)==0 && strcmp(ler[i].disponivel, "ALUGUEL")==0) {
            count++;
    		printf("%s codigo %d\n",ler[i].tipo, i+1);
	        printf("rua: %s\n", ler[i].rua);
	        printf("numero: %d\n", ler[i].numero);
	        printf("bairro: %s\n", ler[i].bairro);
	        printf("cep: %ld\n", ler[i].cep);
	        printf("cidade: %s\n", ler[i].cidade);
	        printf("disponivel para : %s\n", ler[i].disponivel);
	        printf("valor :R$ %d\n", ler[i].preco);
	        printf("numero de quartos : %d\n", ler2[count-1].numero_quartos);
	        printf("numero de pavimentos : %d\n", ler2[count-1].numero_pavimentos);
	        printf("area de terreno : %d metros quadrados\n", ler2[count-1].area_terreno);
	        printf("area construida : %d metros quadrados\n", ler2[count-1].area_construida);
	        printf("\n");
        }

        if(strcmp(tipo, "APARTAMENTO")==0 && strcmp(ler[i].tipo, tipo)==0 && strcmp(ler[i].disponivel, "ALUGUEL")==0) {
            conta++;
            printf("\n");
    		printf("%s codigo %d\n",ler[i].tipo, i+1);
	        printf("rua: %s\n", ler[i].rua);
	        printf("numero: %d\n", ler[i].numero);
	        printf("bairro: %s\n", ler[i].bairro);
	        printf("cep: %ld\n", ler[i].cep);
	        printf("cidade: %s\n", ler[i].cidade);
	        printf("disponivel para : %s\n", ler[i].disponivel);
	        printf("valor : R$ %d\n", ler[i].preco);
	        printf("numero de quartos : %d\n", ler3[conta-1].numero_quartos);
	        printf("numero de vagas : %d\n", ler3[conta-1].numero_vagas);
	        printf("area: %d metros quadrados\n", ler3[conta-1].area);
	        printf("condominio : R$ %d\n", ler3[conta-1].condominio);
            printf("andar : %d°\n", ler3[conta-1].andar);
	        printf("posicao : %s", ler3[conta-1].posicao);
	        printf("\n");
        }

        if (strcmp(tipo, "TERRENO")==0 && strcmp(ler[i].tipo, tipo)==0  && strcmp(ler[i].disponivel, "ALUGUEL")==0){
            conte++;
            printf("\n");
    		printf("%s codigo %d\n",ler[i].tipo, i+1);
	        printf("rua: %s\n", ler[i].rua);
	        printf("numero: %d\n", ler[i].numero);
	        printf("bairro: %s\n", ler[i].bairro);
	        printf("cep: %ld\n", ler[i].cep);
	        printf("cidade: %s\n", ler[i].cidade);
	        printf("disponibilidade : %s\n", ler[i].disponivel);
	        printf("valor : R$ %d\n", ler[i].preco);
	        printf("comprimento : %d\n", ler1[conte-1].comprimento);
            printf("largura : %d\n", ler1[conte-1].largura);
            printf("area : %d\n", ler1[conte-1].area);
            printf("\n");
		}

		if(strcmp(tipo, "FLAT")==0 && strcmp(ler[i].tipo, tipo)==0  && strcmp(ler[i].disponivel, "ALUGUEL")==0) {
            cont++;
            printf("\n");
    		printf("%s codigo %d\n",ler[i].tipo, i+1);
	        printf("rua: %s\n", ler[i].rua);
	        printf("numero: %d\n", ler[i].numero);
	        printf("bairro: %s\n", ler[i].bairro);
	        printf("cep: %ld\n", ler[i].cep);
	        printf("cidade: %s\n", ler[i].cidade);
	        printf("disponivel para : %s\n", ler[i].disponivel);
	        printf("valor : R$ %d\n", ler[i].preco);
	        printf("area: %d metros quadrados\n", ler4[cont-1].area);
	        printf("condominio : R$ %d \n", ler4[cont-1].condominio);
	        printf("internet : %s\n", ler4[cont-1].internet);
	        printf("recepcao 24 hrs : %s\n", ler4[cont-1].recepcao);
	        printf("servico de quarto : %s\n", ler4[cont-1].limpeza);
	        printf("ar condicionado : %s\n", ler4[cont-1].ar);
	        printf("TV a cabo : %s\n", ler4[cont-1].tv);
	        printf("servico de lavanderia : %s", ler4[cont-1].lavanderia);
	        printf("\n");
        }

        if(strcmp(tipo, "STUDIO")==0 && strcmp(ler[i].tipo, tipo)==0 && strcmp(ler[i].disponivel, "ALUGUEL")==0) {
            printf("\n");
    		printf("%s codigo %d\n",ler[i].tipo, i+1);
	        printf("rua: %s\n", ler[i].rua);
	        printf("numero: %d\n", ler[i].numero);
	        printf("bairro: %s\n", ler[i].bairro);
	        printf("cep: %ld\n", ler[i].cep);
	        printf("cidade: %s\n", ler[i].cidade);
	        printf("disponivel para : %s\n", ler[i].disponivel);
	        printf("valor : %d\n", ler[i].preco);
            printf("area: %d metros quadrados\n", ler5[conti].area);
	        printf("condominio : R$ %d \n", ler5[conti].condominio);
	        printf("internet : %s\n", ler5[conti].internet);
	        printf("recepcao 24 hrs : %s\n", ler5[conti].recepcao);
	        printf("servico de quarto : %s\n", ler5[conti].limpeza);
	        printf("ar condicionado : %s\n", ler5[conti].ar);
	        printf("TV a cabo : %s\n", ler5[conti].tv);
	        printf("servico de lavanderia : %s\n", ler5[conti].lavanderia);
            printf("sauna: %s\n", ler5[conti].sauna);
            printf("sala de ginastica : %s\n", ler5[conti].ginastica );
            printf("piscina : %s\n", ler5[conti].piscina);
	        printf("\n");
	        conti++;
        }

    }
     if(count==0 && cont == 0 && conta ==0 && conti == 0 && conte == 0 )
        printf("\nnao possuimos esse tipo de imovel alugar!!!\n");
        getchar();
        system("cls");
    fclose(imob);
    }

 }

void cadastra_atr(){ /// função que cadastra os atributos de casa
     printf("precisamos de mais algumas informacoes sobre sua casa :\n");
     printf("digite o numero de quartos:");
     scanf("%d", &casas.numero_quartos);
     printf("digite o numero de pavimentos:");
     scanf("%d", &casas.numero_pavimentos);
     printf("digite a area do terreno:");
     scanf("%d", &casas.area_terreno);
     printf("digite a area contruida:");
     scanf("%d", &casas.area_construida);
}

void cadastra_atr2(){ /// função que cadastra os atributos de apartamento

     printf("precisamos de mais algumas informacoes sobre seu apartamento :\n");
     printf("digite o numero de quartos:");
     scanf("%d", &apartamentos.numero_quartos);
     printf("digite o numero de vagas de garagem:");
     scanf("%d", &apartamentos.numero_vagas);
     printf("digite o valor do condominio:");
     scanf("%d", &apartamentos.condominio);
     printf("digite a area:");
     scanf("%d", &apartamentos.area);
     printf("digite o andar do apartamento:");
     scanf("%d", &apartamentos.andar);
     setbuf(stdin, NULL);
     printf("digite a posicao (nascente sul ou nascente norte): ");
     scanf("%[^\n]s", &apartamentos.posicao);

};

void cadastra_atr3(){ /// função que cadastra os atributos de terrenos

     printf("precisamos de mais algumas informações sobre seu terreno :\n");
     printf("digite o comprimento do terreno:");
     scanf("%d", &terrenos.comprimento);
     printf("digite a largura do terreno:");
     scanf("%d", &terrenos.largura);

     terrenos.area = terrenos.comprimento * terrenos.largura;
}

void cadastra_atr4(){ /// função que cadastra os atributos de flat
     setbuf(stdin, NULL);
     printf("precisamos de mais algumas informacoes sobre seu flat :\n");
     printf("possui ar condicionado ? (sim ou nao)");
     gets(flats.ar);
     printf("possui servico de limpeza ? (sim ou nao)");
     gets(flats.limpeza);
     printf("possui TV a cabo ? (sim ou nao)");
     gets(flats.tv);
     printf("possui internet ? (sim ou nao)");
     gets(flats.internet);
     printf("possui recepcao 24 hrs ? (sim ou nao)");
     gets(flats.recepcao);
     printf("possui lavanderia ? (sim ou nao)");
     gets(flats.lavanderia);
     printf("digite o valor do condominio:");
     scanf("%d", &flats.condominio);
     printf("digite a area :");
     scanf("%d", &flats.area);
     };

void cadastra_atr5(){ /// função que cadastra os atributos de studio
     setbuf(stdin, NULL);
     printf("precisamos de mais algumas informacoes sobre seu studio :\n");
     printf("possui ar condicionado ? (sim ou nao)");
     gets(studios.ar);
     printf("possui servico de limpeza ? (sim ou nao)");
     gets(studios.limpeza);
     printf("possui TV a cabo ? (sim ou nao)");
     gets(studios.tv);
     printf("possui internet ? (sim ou nao)");
     gets(studios.internet);
     printf("possui recepcao 24 hrs ? (sim ou nao)");
     gets(studios.recepcao);
     printf("possui lavanderia ? (sim ou nao)");
     gets(studios.lavanderia);
     printf("digite o valor do condominio:");
     scanf("%d", &studios.condominio);
     printf("digite a area :");
     scanf("%d", &studios.area);
     setbuf(stdin, NULL);
     printf("possui piscina ? (sim ou nao)");
     gets(studios.piscina);
     printf("possui sauna ? (sim ou nao)");
     gets(studios.sauna);
     printf("possui sala de gisnatica ? (sim ou nao)");
     gets(studios.ginastica);

     };

void consulta_bairro(){ /// OK!
    FILE *imob;
    int i=0;
    char bairro[50];
    char condicao[50];
    void imprime();
    int count = 0;

    int valor;

    setbuf(stdin, NULL);
    printf("voce esta procurando por casas disponiveis para alugar em qual bairro ?");
    gets(bairro);
     for(i=0; i<strlen(bairro); i++){
		bairro[i] = toupper(bairro[i]);
	}
    imob = fopen("imob.txt", "r");
    system("cls");
    printf("as casas diponiveis para alugar no bairro de %s sao :\n", bairro);

    for(i=0; i<MAXIMOVEIS; i++){
        if(ler[i].numero == 0)
         break;


     if(strcmp(ler[i].bairro, bairro)==0 && strcmp(ler[i].disponivel, "ALUGUEL")==0 && strcmp(ler[i].tipo, "CASA")==0){

            printf("\n");
    		printf("%s codigo %d\n",ler[i].tipo, i+1);
	        printf("rua: %s\n", ler[i].rua);
	        printf("numero: %d\n", ler[i].numero);
	        printf("bairro: %s\n", ler[i].bairro);
	        printf("cep: %ld\n", ler[i].cep);
	        printf("cidade: %s\n", ler[i].cidade);
	        printf("disponivel para : %s\n", ler[i].disponivel);
	        printf("valor : %d R$\n", ler[i].preco);
	        printf("numero de quartos : %d\n", ler2[count].numero_quartos);
	        printf("numero de pavimentos : %d\n", ler2[count].numero_pavimentos);
	        printf("area de terreno : %d metros quadrados\n", ler2[count].area_terreno);
	        printf("area construida : %d metros quadrados\n", ler2[count].area_construida);
	        printf("\n");
	        count++;

        }
    }
    if(count==0)
        printf("\nainda nao existem casas cadastradas nesse bairro !!!\n");
   getchar();
   fclose(imob);
}

void consulta_bairro2(){ /// OK !
    FILE *imob;
    int i=0;
    char bairro[50];
    char condicao[50];
    void imprime();
    int count = 0;

    int valor;

    setbuf(stdin, NULL);
    printf("voce esta procurando por casas disponiveis para venda em qual bairro ?");
    gets(bairro);
    for(i=0; i<strlen(bairro); i++){
		bairro[i] = toupper(bairro[i]);
	}
    imob = fopen("imob.txt", "r");
    system("cls");
    printf("as casas diponiveis para comprar no bairro de %s sao :\n", bairro);

     for(i=0; i<MAXIMOVEIS; i++){
        if(ler[i].numero == 0)
         break;

     if(strcmp(ler[i].bairro, bairro)==0 && strcmp(ler[i].disponivel, "VENDA")==0 && strcmp(ler[i].tipo, "CASA")==0){
            count++;
            printf("\n");
    		printf("%s codigo %d\n",ler[i].tipo, i+1);
	        printf("rua: %s\n", ler[i].rua);
	        printf("numero: %d\n", ler[i].numero);
	        printf("bairro: %s\n", ler[i].bairro);
	        printf("cep: %ld\n", ler[i].cep);
	        printf("cidade: %s\n", ler[i].cidade);
	        printf("disponivel para : %s\n", ler[i].disponivel);
	        printf("valor : R$ %d\n", ler[i].preco);
	        printf("numero de quartos : %d\n", ler2[count].numero_quartos);
	        printf("numero de pavimentos : %d\n", ler2[count].numero_pavimentos);
	        printf("area de terreno : %d metros quadrados\n", ler2[count].area_terreno);
	        printf("area construida : %d metros quadrados\n", ler2[count].area_construida);
	        printf("\n");

        }
    }
    if(count==0)
        printf("\nainda nao existem imoveis cadastrados e disponiveis nesse bairro\n");
   getchar();
   fclose(imob);
}

void listar_cidade(){ /// OK!
    int i=0;
    char cidade[30];
    int count=0;
    int conta=0, conte=0, cont=0, conti=0;

    setbuf(stdin, NULL);
    printf("qual cidade voce procura imoveis disponiveis ? ");
    gets(cidade);
    for(i=0; i<strlen(cidade); i++){
		cidade[i] = toupper(cidade[i]);
	}
    system("cls");
    FILE *imob;
    imob = fopen("imob.txt", "r");

    if(imob){
    for(i=0; i<MAXIMOVEIS; i++){
        if(ler[i].numero==0){
        	break;
		}

		if(strcmp(ler[i].tipo, "CASA")==0 && strcmp(ler[i].cidade, cidade)==0){
            count++;
            printf("\n");
    		printf("%s codigo %d\n",ler[i].tipo, i+1);
	        printf("rua: %s\n", ler[i].rua);
	        printf("numero: %d\n", ler[i].numero);
	        printf("bairro: %s\n", ler[i].bairro);
	        printf("cep: %ld\n", ler[i].cep);
	        printf("cidade: %s\n", ler[i].cidade);
	        printf("disponivel para : %s\n", ler[i].disponivel);
	        printf("valor : R$ %d\n", ler[i].preco);
	        printf("numero de quartos : %d\n", ler2[count-1].numero_quartos);
	        printf("numero de pavimentos : %d\n", ler2[count-1].numero_pavimentos);
	        printf("area de terreno : %d metros quadrados\n", ler2[count-1].area_terreno);
	        printf("area construida : %d metros quadrados\n", ler2[count-1].area_construida);
	        printf("\n");
        }

        if(strcmp(ler[i].tipo, "APARTAMENTO")==0 && strcmp(ler[i].cidade, cidade)==0) {
            conta++;
            printf("\n");
    		printf("%s codigo %d\n",ler[i].tipo, i+1);
	        printf("rua: %s\n", ler[i].rua);
	        printf("numero: %d\n", ler[i].numero);
	        printf("bairro: %s\n", ler[i].bairro);
	        printf("cep: %ld\n", ler[i].cep);
	        printf("cidade: %s\n", ler[i].cidade);
	        printf("disponivel para : %s\n", ler[i].disponivel);
	        printf("valor : R$ %d\n", ler[i].preco);
	        printf("numero de quartos : %d\n", ler3[conta-1].numero_quartos);
	        printf("numero de vagas : %d\n", ler3[conta-1].numero_vagas);
	        printf("area: %d metros quadrados\n", ler3[conta-1].area);
	        printf("condominio : R$ %d \n", ler3[conta-1].condominio);
            printf("andar : %d°\n", ler3[conta-1].andar);
	        printf("posicao : %s", ler3[conta-1].posicao);
	        printf("\n");
        }

        if (strcmp(ler[i].tipo, "TERRENO")==0 && strcmp(ler[i].cidade, cidade)==0){
            conte++;
            printf("\n");
    		printf("%s codigo %d\n",ler[i].tipo, i+1);
	        printf("rua: %s\n", ler[i].rua);
	        printf("numero: %d\n", ler[i].numero);
	        printf("bairro: %s\n", ler[i].bairro);
	        printf("cep: %ld\n", ler[i].cep);
	        printf("cidade: %s\n", ler[i].cidade);
	        printf("disponibilidade : %s\n", ler[i].disponivel);
	        printf("valor : R$ %d\n", ler[i].preco);
	        printf("comprimento : %d metros\n", ler1[conte-1].comprimento);
            printf("largura : %d metros \n", ler1[conte-1].largura);
            printf("area : %d metros quadrados\n", ler1[conte-1].area);
            printf("\n");
		}
    if (strcmp(ler[i].tipo, "FLAT")==0 && strcmp(ler[i].cidade, cidade)==0){
            cont++;
            printf("\n");
    		printf("%s codigo %d\n",ler[i].tipo, i+1);
	        printf("rua: %s\n", ler[i].rua);
	        printf("numero: %d\n", ler[i].numero);
	        printf("bairro: %s\n", ler[i].bairro);
	        printf("cep: %ld\n", ler[i].cep);
	        printf("cidade: %s\n", ler[i].cidade);
	        printf("disponivel para : %s\n", ler[i].disponivel);
	        printf("valor : R$ %d\n", ler[i].preco);
	        printf("valor do condominio : R$ %d \n", ler4[cont-1].condominio);
	        printf("area: %d metros quadrados\n", ler4[cont-1].area);
	        printf("internet : %s\n", ler4[cont-1].internet);
	        printf("recepcao 24 hrs : %s\n", ler4[cont-1].recepcao);
	        printf("servico de quarto : %s\n", ler4[cont-1].limpeza);
	        printf("ar condicionado : %s\n", ler4[cont-1].ar);
	        printf("TV a cabo : %s\n", ler4[cont-1].tv);
	        printf("servico de lavanderia : %s", ler4[cont-1].lavanderia);
	        printf("\n");
    }


        if(strcmp(ler[i].tipo, "STUDIO")==0 && strcmp(ler[i].cidade, cidade)==0) {
            printf("\n");
    		printf("%s codigo %d\n",ler[i].tipo, i+1);
	        printf("rua: %s\n", ler[i].rua);
	        printf("numero: %d\n", ler[i].numero);
	        printf("bairro: %s\n", ler[i].bairro);
	        printf("cep: %ld\n", ler[i].cep);
	        printf("cidade: %s\n", ler[i].cidade);
	        printf("disponivel para : %s\n", ler[i].disponivel);
	        printf("valor : R$ %d\n", ler[i].preco);
            printf("area: %d metros quadrados\n", ler5[conti].area);
	        printf("condominio : %d R$\n", ler5[conti].condominio);
	        printf("internet : %s\n", ler5[conti].internet);
	        printf("recepcao 24 hrs : %s\n", ler5[conti].recepcao);
	        printf("servico de quarto : %s\n", ler5[conti].limpeza);
	        printf("ar condicionado : %s\n", ler5[conti].ar);
	        printf("TV a cabo : %s\n", ler5[conti].tv);
	        printf("servico de lavanderia : %s\n", ler5[conti].lavanderia);
            printf("sauna: %s\n", ler5[conti].sauna);
            printf("sala de ginastica : %s\n", ler5[conti].ginastica );
            printf("piscina : %s\n", ler5[conti].piscina);
	        printf("\n");
	        conti++;
        }
    }

     if(count==0 && cont==0 && conta==0 && conte == 0 && cont == 0)
        printf("\nnao possuimos esse tipo de imovel cadastrado !!!\n");
        getchar();
        system("cls");
    fclose(imob);
    }

 }

void listar_quantidade(){ /// OK !

    int i, count=0, conta=0, conte=0, cont=0, conti=0, soma;
    FILE *imob;
    imob = fopen("imob.txt", "r");
     for(i=0; i<MAXIMOVEIS; i++){
        if(ler[i].numero==0){
        	break;
		}

    if(strcmp(ler[i].tipo, "CASA")==0)
            count++;

    if(strcmp(ler[i].tipo, "APARTAMENTO")==0)
            conta++;

    if(strcmp(ler[i].tipo, "TERRENO")==0)
            conte++;

    if(strcmp(ler[i].tipo, "FLAT")==0)
            cont++;

    if(strcmp(ler[i].tipo, "STUDIO")==0)
            conti++;

     }
    fclose(imob);

    printf("a quantidade de casas cadastradas : %d", count);
    printf("\na quantidade de apartamentos cadastrados : %d", conta);
    printf("\na quantidade de terrenos cadastrados  : %d", conte);
    printf("\na quantidade de flats cadastrados : %d", cont);
    printf("\na quantidade de studios cadastrados : %d", conti);
    getchar();
    getchar();
    gsoma = count + conte + conta + cont + conti;
}

void contador(){ /// OK !
int i, count=0, conta=0, conte=0, cont=0, conti=0, soma;
    FILE *imob;
    imob = fopen("imob.txt", "r");
     for(i=0; i<MAXIMOVEIS; i++){
        if(ler[i].numero==0){
        	break;
		}

    if(strcmp(ler[i].tipo, "CASA")==0)
            count++;

    if(strcmp(ler[i].tipo, "APARTAMENTO")==0)
            conta++;

    if(strcmp(ler[i].tipo, "TERRENO")==0)
            conte++;

    if(strcmp(ler[i].tipo, "FLAT")==0)
            cont++;

    if(strcmp(ler[i].tipo, "STUDIO")==0)
            conti++;
     }
    fclose(imob);

    gsoma = count + conte + conta + cont + conti;
}

void salve(){ /// OK !

    FILE *imob; /// faço a declaração do arquivo

    imob = fopen("imob.txt", "a"); /// abro o arquivo no modo de append, modo que acrescenta no final do arquivo, e caso não exista um arquivo ele cria um.
    /// escrevo no arquivo
    fprintf(imob,"\n%s\n%d\n%s\n%ld\n%s\n%s\n%s\n%d\n", imoveis.rua, imoveis.numero, imoveis.bairro, imoveis.cep, imoveis.cidade, imoveis.tipo, imoveis.disponivel, imoveis.preco);

    fclose(imob); /// fecho o arquivo


    if( strcmp(imoveis.tipo, "CASA")==0){ ///comparo o conteudo de duas strings, a que recebemos do usuario durante a execução do programa e a string casa
        FILE *casa; /// declaro meu arquivo
        casa = fopen("casa.txt", "a"); /// abro meu arquivo casa no modo append.

        fprintf(casa,"%d -- ", casas.numero_quartos); /// escrevo no arquivo
        fprintf(casa,"%d -- ", casas.numero_pavimentos);
        fprintf(casa,"%d -- ", casas.area_terreno);
        fprintf(casa,"%d\n", casas.area_construida);
        fclose(casa); ///fecho o arquivo
	    }


	    if(strcmp(imoveis.tipo, "APARTAMENTO")==0){ /// mesma coisa de cima, comparo e a partir do retorno da função strcmp vejo se entro ou não no if

         FILE *apartamento; /// declaro meu arquivo apartamento
         apartamento = fopen("apartamento.txt", "a"); /// abro meu arquivo apartamento.txt no modo append.

        fprintf(apartamento,"%d -- ", apartamentos.numero_quartos); /// escrevo no arquivo
        fprintf(apartamento,"%d -- ", apartamentos.numero_vagas);
        fprintf(apartamento,"%d -- ", apartamentos.area);
        fprintf(apartamento,"%d -- ", apartamentos.condominio);
        fprintf(apartamento,"%d -- ", apartamentos.andar);
        fprintf(apartamento,"%s\n", apartamentos.posicao);
        fclose(apartamento); /// fecho o arquivo
	    }


	    if(strcmp(imoveis.tipo, "TERRENO")==0){ /// mesma coisa de cima
            FILE *terreno; /// declaro o arquivo
            terreno = fopen("terreno.txt", "a"); /// abro o arquivo

            fprintf(terreno,"%d -- ", terrenos.comprimento); /// escrevo no arquivo
            fprintf(terreno,"%d -- ", terrenos.largura);
            fprintf(terreno,"%d\n", terrenos.area);
            fclose (terreno); /// fecho o arquivo

	    }

        if(strcmp(imoveis.tipo, "FLAT")==0){ /// comparo, chamo, declaro, abro, escrevo e fecho
            FILE *flat;
            flat = fopen("flat.txt", "a");

            fprintf(flat,"%d -- ", flats.area);
            fprintf(flat,"%d -- ", flats.condominio);
            fprintf(flat,"%s -- ", flats.recepcao);
            fprintf(flat,"%s -- ", flats.internet);
            fprintf(flat,"%s -- ", flats.limpeza);
            fprintf(flat,"%s -- ", flats.ar);
            fprintf(flat,"%s -- ", flats.tv);
            fprintf(flat,"%s\n", flats.lavanderia);
            fclose (flat);

	    }
	     if(strcmp(imoveis.tipo, "STUDIO")==0){ /// comparo, chamo, declaro, abro, escrevo e fecho
            FILE *studio;
            studio = fopen("studio.txt", "a");

            fprintf(studio,"%d -- ", studios.area);
            fprintf(studio,"%d -- ", studios.condominio);
            fprintf(studio,"%s -- ", studios.recepcao);
            fprintf(studio,"%s -- ", studios.internet);
            fprintf(studio,"%s -- ", studios.limpeza);
            fprintf(studio,"%s -- ", studios.ar);
            fprintf(studio,"%s -- ", studios.tv);
            fprintf(studio,"%s -- ", studios.lavanderia);
            fprintf(studio,"%s -- ", studios.piscina);
            fprintf(studio,"%s -- ", studios.sauna);
            fprintf(studio,"%s\n", studios.ginastica);
            fclose (studio);

	    }

    }

