#include <stdio.h>
#include <stdlib.h>

#include "ivector.h"

void imprimeVectorPedidos(ivector v, int tam) {
    for (int i = 0; i < tam; ++i) {
        printf("[%d-%d] ", v[i].tiempoLimite, v[i].cobro);
    }
    printf("\n");
}

int Compare (const void *_a, const void *_b) {
    Pedido *a; Pedido *b;
    a = (Pedido *) _a;
    b = (Pedido *) _b;

    return  (b->cobro - a->cobro);
}

ivector planificacionVoraz (ivector v, int tam, int maxTiempo) {
    qsort(v, tam, sizeof(Pedido), &Compare);
    int numPedidos = 0;
    int tiempoTotal = 0;
    while (tiempoTotal < maxTiempo && numPedidos < tam) {
        tiempoTotal += v[numPedidos++].tiempoLimite;
    }

    ivector solucion = icreavector(numPedidos);
    for (int i = 0; i < numPedidos; ++i) {
        solucion[i] = v[i];
    }
    return solucion;
}

int main(void) {
    int tam = 9;
    ivector pedidos = icreavector(tam);

    int maxTiempo = 20;

    pedidos[0].tiempoLimite=1;  pedidos[0].cobro=60;
    pedidos[1].tiempoLimite=5;  pedidos[1].cobro=70;
    pedidos[2].tiempoLimite=5;  pedidos[2].cobro=80;
    pedidos[3].tiempoLimite=6;  pedidos[3].cobro=20;
    pedidos[4].tiempoLimite=6;  pedidos[4].cobro=20;
    pedidos[5].tiempoLimite=4;  pedidos[5].cobro=30;
    pedidos[6].tiempoLimite=4;  pedidos[6].cobro=50;
    pedidos[7].tiempoLimite=2;  pedidos[7].cobro=50;
    pedidos[8].tiempoLimite=2;  pedidos[8].cobro=90;

    printf("Pedidos iniciales\n");
    imprimeVectorPedidos(pedidos, tam);
    printf("Pedidos escogidos\n");
    imprimeVectorPedidos()

    return 0;
}
