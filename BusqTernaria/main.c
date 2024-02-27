#include <stdio.h>

#include "ivector.h"

void imprimeVector(ivector v, int tam) {
    for(int i = 0; i < tam; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

int busquedaClasica(ivector v, int tam, int valorBuscar) {
    for (int i = 0; i < tam; ++i) {
        if (v[i] == valorBuscar) {
            return i;
        }
    }
    return -1;
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

    return 0;
}
