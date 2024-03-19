/*************************ivector.h***************************/
/*         Módulo de cabeceras para uso de objetos           */
/*                   VECTORES DE ENTEROS                     */
/*************************************************************/

#ifndef IVECTOR

#define IVECTOR
#include <stdbool.h>

typedef struct {
    int tiempoLimite;
    int cobro;
    bool escogido;
} Pedido;

typedef Pedido *ivector;

ivector icreavector(int tam);
void ifreevector(ivector *v);

#endif
