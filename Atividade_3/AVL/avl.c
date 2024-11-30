#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* esquerda;
    struct No* direita;
    int altura;
} No;

int obter_altura(No* no) {
    return (no == NULL) ? 0 : no->altura;
}

int calcular_balanceamento(No* no) {
    if (no == NULL) return 0;
    return obter_altura(no->esquerda) - obter_altura(no->direita);
}

No* criar_no(int valor) {
    No* novo_no = (No*)malloc(sizeof(No));
    novo_no->valor = valor;
    novo_no->esquerda = NULL;
    novo_no->direita = NULL;
    novo_no->altura = 1;
    return novo_no;
}

No* rotacao_direita(No* y) {
    No* x = y->esquerda;
    No* T2 = x->direita;

    x->direita = y;
    y->esquerda = T2;

    y->altura = 1 + (obter_altura(y->esquerda) > obter_altura(y->direita) ? 
                     obter_altura(y->esquerda) : obter_altura(y->direita));
    x->altura = 1 + (obter_altura(x->esquerda) > obter_altura(x->direita) ? 
                     obter_altura(x->esquerda) : obter_altura(x->direita));

    return x;
}

No* rotacao_esquerda(No* x) {
    No* y = x->direita;
    No* T2 = y->esquerda;

    y->esquerda = x;
    x->direita = T2;

    x->altura = 1 + (obter_altura(x->esquerda) > obter_altura(x->direita) ? 
                     obter_altura(x->esquerda) : obter_altura(x->direita));
    y->altura = 1 + (obter_altura(y->esquerda) > obter_altura(y->direita) ? 
                     obter_altura(y->esquerda) : obter_altura(y->direita));

    return y;
}

No* inserir(No* raiz, int valor) {
    if (raiz == NULL) {
        return criar_no(valor);
    }
    if (valor < raiz->valor) {
        raiz->esquerda = inserir(raiz->esquerda, valor);
    } else if (valor > raiz->valor) {
        raiz->direita = inserir(raiz->direita, valor);
    } else {
        return raiz; 
    }

    raiz->altura = 1 + (obter_altura(raiz->esquerda) > obter_altura(raiz->direita) ? 
                        obter_altura(raiz->esquerda) : obter_altura(raiz->direita));

    int balanceamento = calcular_balanceamento(raiz);

    if (balanceamento > 1 && valor < raiz->esquerda->valor) {
        return rotacao_direita(raiz);
    }

    if (balanceamento < -1 && valor > raiz->direita->valor) {
        return rotacao_esquerda(raiz);
    }

    if (balanceamento > 1 && valor > raiz->esquerda->valor) {
        raiz->esquerda = rotacao_esquerda(raiz->esquerda);
        return rotacao_direita(raiz);
    }

    if (balanceamento < -1 && valor < raiz->direita->valor) {
        raiz->direita = rotacao_direita(raiz->direita);
        return rotacao_esquerda(raiz);
    }

    return raiz;
}

void exibir_em_ordem(No* raiz) {
    if (raiz != NULL) {
        exibir_em_ordem(raiz->esquerda);
        printf("%d ", raiz->valor);
        exibir_em_ordem(raiz->direita);
    }
}

void liberar_arvore(No* raiz) {
    if (raiz != NULL) {
        liberar_arvore(raiz->esquerda);
        liberar_arvore(raiz->direita);
        free(raiz);
    }
}

int main() {
    No* raiz = NULL;

    raiz = inserir(raiz, 50);
    raiz = inserir(raiz, 30);
    raiz = inserir(raiz, 70);
    raiz = inserir(raiz, 20);
    raiz = inserir(raiz, 40);
    raiz = inserir(raiz, 60);
    raiz = inserir(raiz, 80);

    printf("Elementos em ordem: ");
    exibir_em_ordem(raiz);
    printf("\n");

    liberar_arvore(raiz);

    return 0;
}
