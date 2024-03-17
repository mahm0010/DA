#include <stdio.h>

#include "ivector.h"

void ImprimeVectorCorredor(ivector v, int tam) {
    for (int i = 0; i < tam; ++i) {
        if (i == tam - 1) {
            printf("%d - %d", v[i].dorsal, v[i].liquido);
        } else {
            printf("%d - %d | ", v[i].dorsal, v[i].liquido);
        }
    }
    printf("\n");
}

struct Corredor CarreraClasico(ivector v, int inf, int sup, int posicion) {
    int tam = sup - inf + 1;
    ivector aux = icreavector(tam);
    for (int i = 0; i < tam; ++i) {
        aux[i].dorsal = -1;
        aux[i].liquido = -1;
    }
    for (int i = inf; i <= sup; ++i) {
        for (int j = inf; j <= sup; ++j) {
            if (aux[i].liquido < v[j].liquido) {
                aux[i] = v[j];
                v[j].dorsal = -1;
                v[j].liquido = -1;
            }
        }
    }
    // printf("[CARRERACLASICO] El corredor que ha llegado en la posicion %d ha sido %d - %d\n", posicion, aux[posicion].dorsal, aux[posicion].liquido);
    ImprimeVectorCorredor(aux, tam);
    return aux[posicion - 1];
}

int main() {
    int tam = 10;
    ivector v = icreavector(tam);
    v[0].dorsal = 7;
    v[0].liquido = 575;
    v[1].dorsal = 3;
    v[1].liquido = 842;
    v[2].dorsal = 10;
    v[2].liquido = 27;
    v[3].dorsal = 1;
    v[3].liquido = 135;
    v[4].dorsal = 4;
    v[4].liquido = 970;
    v[5].dorsal = 6;
    v[5].liquido = 10;
    v[6].dorsal = 8;
    v[6].liquido = 1000;
    v[7].dorsal = 2;
    v[7].liquido = 624;
    v[8].dorsal = 5;
    v[8].liquido = 468;
    v[9].dorsal = 9;
    v[9].liquido = 580;

    ImprimeVectorCorredor(v, tam);

    int posicion = 5;
    struct Corredor corredorGanador = {-1, -1};
    corredorGanador = CarreraClasico(v, 0, tam-1, posicion);
    printf("[CARRERACLASICO] El corredor que ha llegado en la posicion %d ha sido %d - %d\n",
        posicion, corredorGanador.dorsal, corredorGanador.liquido);




    return 0;
}
