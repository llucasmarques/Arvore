#include <stdio.h>
#include <stdlib.h>

#ifndef ARVORE_C
#define ARVORE_C

//Definição de tipo
struct estruturaArvore{
    int dado;
    struct estruturaArvore *esq;
    struct estruturaArvore *dir;

};
typedef struct estruturaArvore tipoArvore;

//prototipos das funções
insereArvore(tipoArvore **arv,int valor);
tipoArvore* alocaNo(int valor);
void imprimePreOrdem(tipoArvore *arv);
void imprimeOrdem(tipoArvore *arv);
void imprimePosOrdem(tipoArvore *arv);
tipoArvore **buscaMaior(tipoArvore **arv);
int removeArv(tipoArvore **arv, int valor);
int buscaArv(tipoArvore *arv, int valor);



//Função que realiza a alocacao
tipoArvore* alocaNo(int valor){
    tipoArvore *novoNo;

    novoNo = novoNo = (tipoArvore*) malloc(sizeof(tipoArvore));
    if(novoNo){
        novoNo->dado = valor;
        novoNo->dir = NULL;
        novoNo->esq = NULL;
    }
    return novoNo;

}

insereArvore(tipoArvore **arv,int valor){
    if(*arv == NULL){
        *arv = alocaNo(valor);
    }else{
        if( valor < ((*arv)->dado)  ){
            insereArvore((&(*arv)->esq),valor);

        }else if(valor > (*arv)->dado){
            insereArvore(&(*arv)->dir,valor);
        }

    }
}

//Função qeu implenta a impressão da arvore com base em um percursso pre-ordem
void imprimePreOrdem(tipoArvore *arv){
    if(arv != NULL){
        printf("[%d]",arv->dado);
        imprimePreOrdem(arv->esq);
        imprimePreOrdem(arv->dir);
    }


}


//
void imprimeOrdem(tipoArvore *arv){
    if(arv != NULL){
        imprimeOrdem(arv->esq);
        printf("[%d]",arv->dado);
        imprimeOrdem(arv->dir);

    }
}


void imprimePosOrdem(tipoArvore *arv){
    if(arv != NULL){
        imprimeOrdem(arv->esq);
        imprimeOrdem(arv->dir);
        printf("[%d]",arv->dado);

    }
}

int buscaArv(tipoArvore *arv, int valor){
    if(arv != NULL){
        if(valor == arv->dado)
            return 1;
        else if(valor < arv->dado)
            return buscaArv(arv->esq,valor);
        else
            return buscaArv(arv->dir,valor);
    }
    return 0;

}


//Função que remove um nó da arvore
int removeArv(tipoArvore **arv, int valor){
    //Verifica se o valor se o nó acessado é valido
    if(*arv == NULL){
        return 0;//se nulo, entao ele nao existe, retorna falso(zero)
    }else{
        //Verifica se o nó é o valor a ser removido
        if((*arv)->dado != valor){
            if(valor < (*arv)->dado)
                return removeArv(&(*arv)->esq,valor);
            else
                return removeArv(&(*arv)->dir,valor);

        }else{//se é o nó, executa a remoção
            /*Com arv apontando para o nó que deve ser removido, deve se encontrar o maior nó no ramo esquerdo da arvore(ou
            o menor ramo direito, se preferir) para tomar o seu lugar.*/
            if( ((*arv)->esq == NULL) && ((*arv)->dir == NULL) ){
                free(*arv);
                *arv = NULL;
            }else
                // Se ele tem apenas o filho direito
                if( ( (*arv)->esq == NULL ) &&  ((*arv)->dir != NULL) ){
                    tipoArvore *aux;
                    aux = *arv;
                    *arv = (*arv)->dir;//faz o nó ocupar o lugar do pai dele
                    free(aux);
            }else
                //se ele apenas o filho esquerdo
                if( ( (*arv)->esq != NULL ) &&  ((*arv)->dir == NULL) ){
                    tipoArvore *aux;
                    aux = *arv;
                    *arv = (*arv)->esq;//faz o nó ocupar o lugar do pai dele
                    free(aux);
            }else{//se tem os dois filhos
                tipoArvore **maiorNo, *aux;
                maiorNo = buscaMaior(&(*arv)->esq);
                aux = *maiorNo;

                (*arv)->dado = (*maiorNo)->dado;
                *maiorNo = (*maiorNo)->esq;

                free(aux);
            }

                return 1;
        }

    }
}


//Função que encontra o maior nó(valor) em um ramo
tipoArvore **buscaMaior(tipoArvore **arv){
    if(&(*arv)->dir == NULL){
        return arv;

    }else{
        return buscaMaior(&(*arv)->dir);
    }



}


#endif
