#include <stdio.h>

#include "ivector.h"

#define umbral 2

void imprimeVector(ivector v, int tam) {
    for(int i = 0; i < tam; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

void MayoritarioClasico(ivector v, int inf, int sup, int *mayoritarioGlobal) {
    int tam = sup - inf + 1;
    int mayoritario = -1;
    //printf("[MAYORITARIOCLASICO] inf=%d | sup=%d, | n/2=%d\n", inf, sup, tam/2);
    for (int i = inf; i <= sup; ++i) {
        if(mayoritario != v[i] && *mayoritarioGlobal != v[i]) {
            int contadorLocal = 0;
            for (int j = inf; j <= sup; ++j) {
                if(v[i] == v[j]) {
                    ++contadorLocal;
                }
            }
            //printf("[MAYORITARIOCLASICO] valor revisado=%d | contador=%d, | n/2=%d\n", v[i], contadorLocal, tam/2);
            if(contadorLocal > tam/2)
                mayoritario = v[i]; *mayoritarioGlobal = mayoritario;
        }
    }
}

void ComprobarMayoritario(ivector v, int inf, int sup, int mayoritarioizq, int mayoritarioder, int *mayoritarioGlobal) {
    if (mayoritarioizq == mayoritarioder) {
        *mayoritarioGlobal = mayoritarioizq;
        return;
    }

    if (mayoritarioizq == -1 || mayoritarioder == -1) {
        MayoritarioClasico(v, inf, sup, mayoritarioGlobal);
        return;
    }
    *mayoritarioGlobal = -1;
}

int Mayoritario(ivector v, int inf, int sup, int *mayoritarioGlobal) {
    int tam = sup - inf + 1;

    //printf("[MAYORITARIO] inf=%d | sup=%d\n", inf, sup);
    //imprimeVector(v, tam);

    if(tam <= umbral) {
        MayoritarioClasico(v, inf, sup, mayoritarioGlobal);
    }else {
        int medio = tam / 2 + inf - 1;
        int mayoritarioizq = -1;
        int mayoritarioder = -1;

        mayoritarioizq = Mayoritario(v, inf, medio, mayoritarioGlobal);
        mayoritarioder = Mayoritario(v, medio + 1, sup, mayoritarioGlobal);

        ComprobarMayoritario(v, inf, sup, mayoritarioizq, mayoritarioder, mayoritarioGlobal);
    }
    return  *mayoritarioGlobal;
}

int main() {
    int tam = 8;
    ivector v = icreavector(tam);
    for (int i = 0; i < tam; ++i) {
        if (i % 2 == 0 || i % 3 == 0) {
            v[i] = 2;
        } else {
            v[i] = i;
        }
    }
    int mayoritarioInicial = -1;
    imprimeVector(v, tam);
    printf("Mayoritario del vector anterior: %d", Mayoritario(v, 0, tam-1, &mayoritarioInicial));

    return 0;
}
