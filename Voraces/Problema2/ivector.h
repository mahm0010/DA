/*************************ivector.h***************************/
/*         Módulo de cabeceras para uso de objetos           */
/*                   VECTORES DE ENTEROS                     */
/*************************************************************/

#ifndef IVECTOR

#define IVECTOR
#include <stdbool.h>

typedef struct {
    int valor;
    bool escogido;
} numero;

typedef numero *ivector;

ivector icreavector(int tam);
void ifreevector(ivector *v);

#endif
