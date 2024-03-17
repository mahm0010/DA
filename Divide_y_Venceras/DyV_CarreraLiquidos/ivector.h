/*************************ivector.h***************************/
/*         Módulo de cabeceras para uso de objetos           */
/*                   VECTORES DE ENTEROS                     */
/*************************************************************/

#ifndef IVECTOR

#define IVECTOR

#include "Corredor.h"

typedef struct Corredor *ivector;

ivector icreavector(int tam);
void ifreevector(ivector *v);

#endif
