#include <stdio.h>

#include "ivector.h"

#define umbral 2

void imprimeVector(ivector v, int tam) {
    for(int i = 0; i < tam; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

void insercion(ivector lista, int TAM) {
    int temp;
    for (int i = 1; i < TAM; i++)
        for (int j = 0; j < TAM - 1; j++)
            if (lista[j] > lista[j + 1]) {
                temp = lista[j];
                lista[j] = lista[j + 1];
                lista[j + 1] = temp;
            }
}

void Merge(ivector v, ivector vizq, int tamizq, ivector vder, int tamder) {
    int i, j, k = 0;
    while (i < tamizq && j < tamder) {
        if (vizq[i] < vder[j]) {
            v[k++] = vizq[i++];
        } else {
            v[k++] = vder[j++];
        }
    }
    while (i < tamizq) {
        v[k++] = vizq[i++];
    }
    while (j < tamder) {
        v[k++] = vder[j++];
    }
}

void Mergesort(ivector v, int tam) {
    imprimeVector(v, tam);

    if (tam <= umbral) {
        insercion(v, tam);
    } else {
        int tamizq = tam / 2;
        int tamder = tam - (tam / 2);
        ivector vizq;
        ivector vder;
        vizq = icreavector(tamizq);
        vder = icreavector(tamder);

        for (int i = 0; i < tamizq; i++) {
            vizq[i] = v[i];
        }

        for (int i = 0; i < tamder; i++) {
            vder[i] = v[i + tamizq];
        }

        Mergesort(vizq, tamizq);
        Mergesort(vder, tamder);
        Merge(v, vizq, tamizq, vder, tamder);
    }
}

int main() {
    int tam = 7;
    ivector v = icreavector(tam);
    v[0] = 31;
    v[1] = 3;
    v[2] = 88;
    v[3] = 1;
    v[4] = 4;
    v[5] = 2;
    v[6] = 42;
    imprimeVector(v, tam);
    Mergesort(v, tam);
    imprimeVector(v, tam);

    return 0;
}
