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

    int cobroTiempo_a = a->cobro/a->tiempoLimite;
    int cobroTiempo_b = b->cobro/b->tiempoLimite;

    return  (cobroTiempo_b - cobroTiempo_a);
}

void SeleccionaPedido(ivector v, int tam, ivector sol, int contadorTiempo) {
    for (int i = 0; i < tam; ++i) {
        if(contadorTiempo <= v[i].tiempoLimite && !v[i].escogido) {
            sol[contadorTiempo - 1] = v[i];
            v[i].escogido = true;
            break;
        }
    }
}

ivector planificacionVoraz (ivector v, int tam, int maxTiempo) {
    qsort(v, tam, sizeof(Pedido), &Compare);
    ivector sol = icreavector(maxTiempo);
    int contadorTiempo = 1;
    while (contadorTiempo <= maxTiempo && contadorTiempo < tam) {
        SeleccionaPedido(v, tam, sol, contadorTiempo);
        ++contadorTiempo;
    }

    return sol;
}

int main(void) {
    int tam = 9;
    ivector pedidos = icreavector(tam);

    int maxTiempo = 5;

    pedidos[0].tiempoLimite=1;  pedidos[0].cobro=60;  pedidos[0].escogido=false;
    pedidos[1].tiempoLimite=5;  pedidos[1].cobro=70;  pedidos[1].escogido=false;
    pedidos[2].tiempoLimite=5;  pedidos[2].cobro=80;  pedidos[2].escogido=false;
    pedidos[3].tiempoLimite=6;  pedidos[3].cobro=20;  pedidos[3].escogido=false;
    pedidos[4].tiempoLimite=6;  pedidos[4].cobro=20;  pedidos[4].escogido=false;
    pedidos[5].tiempoLimite=4;  pedidos[5].cobro=30;  pedidos[5].escogido=false;
    pedidos[6].tiempoLimite=4;  pedidos[6].cobro=50;  pedidos[6].escogido=false;
    pedidos[7].tiempoLimite=2;  pedidos[7].cobro=50;  pedidos[7].escogido=false;
    pedidos[8].tiempoLimite=2;  pedidos[8].cobro=90;  pedidos[8].escogido=false;

    printf("Pedidos iniciales\n");
    imprimeVectorPedidos(pedidos, tam);
    printf("Pedidos escogidos\n");
    ivector sol = planificacionVoraz(pedidos, tam, maxTiempo);
    imprimeVectorPedidos(sol, maxTiempo);

    // LIBERAR MEMORIAAAAAAS
    ifreevector(&pedidos);
    ifreevector(&sol);

    return 0;
}
