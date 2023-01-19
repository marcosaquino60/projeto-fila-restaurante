#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 5

typedef struct item {
    int id;
    char nome[50];
    float preco;
}Item;

typedef struct cardapio {
    int qtd;
    Item cardapio[MAX]; 

}Cardapio;
Cardapio* criaCardapio() {
    Cardapio* cd;
    cd = (Cardapio*) malloc (sizeof(Cardapio));
    if(cd !=NULL) {
        cd->qtd = 0;
    }
    return cd;
}

void liberaCardapio(Cardapio* cd) {
    free(cd);
}

int tamanhoCardapio(Cardapio* cd) {
    if(cd == NULL) {
        return -1;
    }
    return cd->qtd;
}

bool cardapioCheio(Cardapio* cd) {
    if(cd == NULL) {
        return false;
    }
    return (cd->qtd == MAX);
}

bool cardapioVazio(Cardapio* cd) {
    if(cd == NULL) {
      return -1;
    }
    return (cd->qtd == 0);
}

bool inserirCardapio(Cardapio* cd, Item it) {
    if(cd == NULL) {
        return false;
    }
    if(cardapioCheio(cd)) {
      return false;
    }

    cd->cardapio[cd->qtd] = it;
    cd->qtd++;
    return true;
}

int buscaID (Cardapio* cd, int search, Item* it) {
    if(cd == NULL) {
        printf("nulo\n");
        return 0;
        
    }
    int i = 0;
    
    while(i < cd->qtd && cd->cardapio[i].id != search) 
        i++;
    if(i == cd->qtd){ // id não foi encontrado
        printf("Nao encontrado\n");
        return 0;
        
    }
    printf( "Id = %d\n", cd->cardapio[i].id );
    printf( "Nome = %s\n", cd->cardapio[i].nome );
    printf( "Preco = R$%.2f\n", cd->cardapio[i].preco );
    *it = cd->cardapio[i];
    printf("Id = %d\n", it->id);
    printf("Nome = %s\n", it->nome);
    printf("Preco = R$%.2f\n", it->preco);
    return 1;
}

int main() {
    
    Cardapio* cd;
    cd = criaCardapio();

    FILE *f = NULL;
    float total = 0;
    f = fopen("cardapio.txt", "r");
    if(!f) {
        printf("Erro na abertura");
    }

    for(int i = 0; i < 5; i++) {
        fscanf( f, "Id = %d\n", &cd->cardapio[i].id );
        fscanf( f, "Nome = %[^\n]\n", cd->cardapio[i].nome );
        fscanf( f, "Preco = %f\n", &cd->cardapio[i].preco );
        cd->qtd++;
        total += cd->cardapio[i].preco;

    }

     for(int i = 0; i < 5; i++) {
        printf( "Id = %d\n", cd->cardapio[i].id );
        printf( "Nome = %s\n", cd->cardapio[i].nome );
        printf( "Preco = R$%.2f\n", cd->cardapio[i].preco );
        
    }
    printf("O total eh R$%.2f reais e a qtd = %d\n", total, cd->qtd);

    Item* it;
    int idsearch = 5;
    
    int x = buscaID(cd, idsearch, &it);
    printf("%d\n", x);
    printf("Voce buscou pelo item de id %d,  e achou:\n", idsearch);
    
    printf("Id = %d\n", it->id);
    printf("Nome = %s\n", it->nome);
    printf("Preco = R$%.2f\n", it->preco);

    liberaCardapio(cd);
}