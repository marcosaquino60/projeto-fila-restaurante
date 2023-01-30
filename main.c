#include <stdio.h>
#include <stdlib.h>
#include "funcao.h"
#include "funcao.c"

int main() {
    
    Fila *fi;
    fi = criaFila();

    Cardapio* cd;
    cd = criaCardapio();
    carregaCardapio(cd);

    Pilha *pi;
    pi = criaPilha();
    carregarPilha(pi);
    char* chocolate_desimpilhado[50];
    
    Comanda* cmd;
    cmd = criaComanda();

    srand(time(NULL));
    for (int i = 0; i < MAX; i++) {
        
        geradorDeComandas(cmd, cd);
        adicionaNaFila(fi, cmd);
    }
    
    
    int pay = 0;

    for(int i = 0; i < MAX; i++){
        printf("===============Comanda %d=============\n", i + 1);
        for (int j = 0; j < MAX; j++) {
            printf( "Id = %d\n", fi->comandas[i].comanda[j].id );
            printf( "Nome = %s\n", fi->comandas[i].comanda[j].nome );
            printf( "Preco = R$%.2f\n", fi->comandas[i].comanda[j].preco );
            
        }
        float total = calculaTotal(&fi->comandas[i]);
        printf("O total eh de R$%.2f\n", total);

        desempilhar(pi, chocolate_desimpilhado);
        printf("\nVoce recebeu: %s\n", chocolate_desimpilhado);
        i++;
        removeFila(fi);

        
    }

    


    liberaCardapio(cd);
    liberaFila(fi);
}