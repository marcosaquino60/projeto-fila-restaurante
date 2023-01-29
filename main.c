#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define MAX 10

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
    float total;
}Comanda;

typedef struct fila {
    int inicio, final,qtd;
    Comanda comandas[MAX];

}Fila;


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

    for(int i = 0; i < MAX; i++) {
        fscanf( f, "Id = %d\n", &cd->cardapio[i].id );
        fscanf( f, "Nome = %[^\n]\n", cd->cardapio[i].nome );
        fscanf( f, "Preco = %f\n", &cd->cardapio[i].preco );
        cd->qtd++;
        total += cd->cardapio[i].preco;

    }
    fclose(f);
}

Fila* criaFila() {
    Fila* fi = (Fila*) malloc (sizeof(Fila));
    if(fi != NULL) {
        fi->inicio = 0;
        fi->final = 0;
        fi->qtd = 0;
    }
    return fi;
}

void liberaFila(Fila* fi) {
    free(fi);
}


int filaCheia(Fila* fi) {
    if(fi == NULL) return 1;
    if(fi->qtd == MAX)
        return 1;
    else
        return 0;
}

int filaVazia(Fila* fi) {
    if(fi == NULL) return 1;
    if(fi->qtd == 0)
        return 0;
    else 
        return 0;
}

void adicionaNaFila(Fila* fi, Comanda *cmd) {
    if(fi == NULL || cmd == NULL) return;
    if(filaCheia(fi)) {
        printf("Fila cheia nao foi possivel adicionar a comanda\n");
        return;
    }
    fi->comandas[fi->final] = *cmd;
    fi->final++;
    fi->qtd++;
    if(fi->final == MAX) {
        fi->final = 0;
    }
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
    for(int i = 0; i < MAX; i++) {
        for(int j = 0 ; j < MAX; j++) {

            int id = rand() % 10 + 1;
            Item* it;
            buscaID(cd, id, &it);
            cmd->comanda[i] = *it;
        }
    }
    
}



float calculaTotal(Comanda *cmd) {
	float total = 0;
	for (int i = 0; i < MAX; i++) {
		total += cmd->comanda[i].preco;
	}
	return total;
}

int main() {
    
    Fila *fi;
    fi = criaFila();

    Cardapio* cd;
    cd = criaCardapio();
    carregaCardapio(cd);

    

    
    
    Comanda* cmd;
    cmd = criaComanda();

    srand(time(NULL));
    for (int i = 0; i < MAX; i++) {
        
        geradorDeComandas(cmd, cd);
        adicionaNaFila(fi, cmd);
    }

    
    for (int i = 0; i < fi->qtd; i++) {
        printf("===============Comanda %d=============\n", i + 1);
        for (int j = 0; j < MAX; j++) {
            printf( "Id = %d\n", fi->comandas[i].comanda[j].id );
            printf( "Nome = %s\n", fi->comandas[i].comanda[j].nome );
            printf( "Preco = R$%.2f\n", fi->comandas[i].comanda[j].preco );
        }
        float total = calculaTotal(&fi->comandas[i]);
        printf("total = %.2f\n", total);
    }
    

    liberaCardapio(cd);
    liberaFila(fi);
}