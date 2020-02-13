#include <stdio.h>
#include <stdlib.h>

#include "arvore.c"

int main(){

    tipoArvore *arv;
    arv = NULL;

    insereArvore(&arv,50);
    insereArvore(&arv,20);
    insereArvore(&arv,70);

    imprimePreOrdem(arv);printf("\n");
    imprimeOrdem(arv);printf("\n");
    imprimePosOrdem(arv); printf("\n");

    int valor;
    valor = 70;
    if(buscaArv(arv, valor))
        printf("Valor %d encontrado!\n",arv->dado);
    else
        printf("Valor %d NÃO encontrado!\n",valor);


    return 1;
}



