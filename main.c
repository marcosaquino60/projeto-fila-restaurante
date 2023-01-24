#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
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

typedef struct comanda {
    int qtd;
    Item comanda[MAX];
}Comanda;


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
Comanda* criaComanda() {
    Comanda* cmd;
    cmd = (Comanda*) malloc (sizeof(Comanda));
    if(cmd !=NULL) {
        cmd->qtd = 0;
    }
    return cmd;
}

void liberaComanda(Comanda* cmd) {
    free(cmd);
}

void carregaCardapio(Cardapio *cd) {
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
    fclose(f);
}
int buscaID (Cardapio* cd, int search, Item** it) {
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
    
    *it = &cd->cardapio[i];
    
    return 1;
}
void geradorDeComandas(Comanda *cmd, Cardapio *cd) {
    srand(time(NULL));
    for(int i = 0; i < MAX; i++) {
        for(int j = 0 ; j < MAX; j++) {

            int id = rand() % 5 + 1;
            Item* it;
            buscaID(cd, id, &it);
            cmd->comanda[i] = *it;
        }
    }
    
}



int main() {
    
    Cardapio* cd;
    cd = criaCardapio();

    carregaCardapio(cd);

    printf("Valores copiados para a struct cardapio:\n");
    for(int i = 0; i < 5; i++) {
        printf( "Id = %d\n", cd->cardapio[i].id );
        printf( "Nome = %s\n", cd->cardapio[i].nome );
        printf( "Preco = R$%.2f\n", cd->cardapio[i].preco );
        
    }
    
    

    liberaCardapio(cd);
}