#ifndef FUNCAO_H_INCLUDED
#define FUNCAO_H_INCLUDED
#include <stdbool.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
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

typedef struct pilhachocolate {
    int topo;
    char chocolate[MAX][50]; 
}Pilha;

typedef struct comanda {
    int qtd;
    Item comanda[MAX];
    float total;
}Comanda;

typedef struct fila {
    int inicio, final,qtd;
    Comanda comandas[MAX];

}Fila;



Pilha* criaPilha();
void liberaPilha(Pilha * pi);
int pilhaCheia(Pilha* pi);
int pilhaVazia(Pilha * pi);
int desempilhar(Pilha * pi, char* chocolate);
void carregarPilha(Pilha* pi);
Cardapio* criaCardapio() ;
void liberaCardapio(Cardapio* cd);
void liberaComanda(Comanda* cmd) ;
void carregaCardapio(Cardapio *cd) ;
Fila* criaFila() ;
void liberaFila(Fila* fi) ;
int filaCheia(Fila* fi);
int filaVazia(Fila* fi) ;
void adicionaNaFila(Fila* fi, Comanda *cmd) ;
int removeFila(Fila* fi);
int buscaID (Cardapio* cd, int search, Item** it) ;
void geradorDeComandas(Comanda *cmd, Cardapio *cd);
float calculaTotal(Comanda *cmd) ;

// criaPilha: aloca memória para uma nova pilha, inicializa o topo com -1 e retorna um ponteiro para essa pilha

// liberaPilha: libera a memória de uma pilha

// criaCardapio: aloca memória para um novo cardápio e retorna um ponteiro para este

// liberaCardapio: libera a memória de um cardápio

// criaComanda: aloca memória para uma nova comanda e retorna um ponteiro para esta

// liberaComanda: libera a memória de uma comanda

// carregaCardapio: lê os dados de um arquivo chamado "cardapio.txt" e coloca os dados de cada item no vetor cardapio

// carregarPilha: lê os dados de um arquivo chamado "chocolates.txt" e coloca os dados de cada item

// criaFila: aloca memória para uma nova fila, inicializa o início e o final com 0 e a quantidade com 0 e retorna um ponteiro para esta

// liberaFila: libera a memória da fila

// filaCheia: verifica se a fila está cheia

// filaVazia: verifica se a fila está vazia

// pilhaCheia: verifica se a pilha está cheia

// pilhaVazia: verifica se a pilha está vazia

// desempilhar: remove o elemento do topo da pilha e copia o conteúdo deste para o parâmetro chocolate

// adicionaNaFila: adiciona uma comanda na fila

// removeFila: remove uma comanda da fila

// buscaID: busca um item no vetor cardapio de acordo com o ID passado como parâmetro

// geradorDeComandas: gera comandas aleatórias para serem inseridas na fila

// calculaTotal: calcula o total da comanda

#endif