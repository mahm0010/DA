#include <stdio.h>

#include "ivector.h"

#define umbral 3

void imprimeVector(ivector v, int tam) {
    for(int i = 0; i < tam; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

int busquedaClasica(ivector v, int inf, int sup, int valorBuscado) {
    for (int i = inf; i <= sup; ++i) {
        if (v[i] == valorBuscado) {
            return i;
        }
    }
    return -1;
}

int busqTernaria(ivector v, int inf, int sup, int valorBuscado) {
    int tam = sup - inf;
    //imprimeVector(v, tam+1);
    int posicion = -1;

    if (tam <= umbral) {
        posicion = busquedaClasica(v, inf, sup, valorBuscado);
    }else {
        int tercio = (inf + tam) / 3;
        int tercio2 = inf + (2*tam / 3);

        if (v[inf] >= valorBuscado) {
            printf("[BUSQUEDATERNARIA] Buscando en inf=%d | sup=%d\n", inf, tercio-1);
            posicion = busqTernaria(v, inf, tercio-1, valorBuscado);
        }else if (v[tercio] >= valorBuscado) {
            printf("[BUSQUEDATERNARIA] Buscando en inf=%d | sup=%d\n", tercio, tercio2-1);
            posicion = busqTernaria(v, tercio, tercio2-1, valorBuscado);
        }else{
            printf("[BUSQUEDATERNARIA] Buscando en inf=%d | sup=%d\n", tercio2, sup);
            posicion = busqTernaria(v, tercio2, sup, valorBuscado);
        }
    }
    return posicion;
}



int main() {
    int tam = 6;
    ivector v = icreavector(tam);
    v[0] = 1;
    v[1] = 2;
    v[2] = 3;
    v[3] = 4;
    v[4] = 5;
    v[5] = 6;
    imprimeVector(v, tam);
    int valorBuscado = 4;
    printf("El valor buscado (%d) esta en la posicion %d\n", valorBuscado, busqTernaria(v, 0, tam-1, valorBuscado));

    return 0;
}
