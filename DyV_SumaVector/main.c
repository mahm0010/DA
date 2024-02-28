#include <stdio.h>

#include "ivector.h"

#define umbral 2

void imprimeVector(ivector v, int tam) {
    for(int i = 0; i < tam; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

int SumaClasica(ivector v, int inf, int sup, int *mayorElemento, int *menorElemento) {
    int suma = 0;
    for (int i = inf; i <= sup; ++i) {
        if(v[i] < *menorElemento) {
            *menorElemento = v[i];
        }
        if(v[i] > *mayorElemento) {
            *mayorElemento = v[i];
        }
        suma += v[i];
    }
    suma -= (*mayorElemento + *menorElemento);
    // printf("\n[SUMACLASICA] Suma=%d | mayorElemento=%d | menorElemento=%d\n", suma, *mayorElemento, *menorElemento);
    // imprimeVector(v, sup-inf+1);
    return suma;
}

void ComprobarMayoresMenores(int *mayorElemento, int *menorElemento, int *mayorIzq, int *menorIzq, int *mayorDer, int *menorDer, int *suma) {
    int mayorLocal = -9999999;
    int menorLocal = 9999999;
    // Mayores
    if (*mayorIzq == *mayorDer) {
        *suma += *mayorIzq;
        mayorLocal = *mayorIzq;
    }
    if (*mayorIzq > *mayorDer) {
        *suma += *mayorDer;
        mayorLocal = *mayorIzq;
    }
    if (*mayorIzq < *mayorDer) {
        *suma += *mayorIzq;
        mayorLocal = *mayorDer;
    }

    // Menores
    if (*menorIzq == *menorDer) {
        *suma += *menorIzq;
        menorLocal = *menorIzq;
    }
    if (*menorIzq < *menorDer) {
        *suma += *menorDer;
        menorLocal = *menorIzq;
    }
    if (*menorIzq > *menorDer) {
        *suma += *menorIzq;
        menorLocal = *menorDer;
    }

    if (*mayorElemento < mayorLocal) {
        *suma += *mayorElemento;
        *mayorElemento = mayorLocal;
    }
    if (*menorElemento > menorLocal) {
        *suma += *menorElemento;
        *menorElemento = menorLocal;
    }

}

int SumaDyV(ivector v, int inf, int sup, int *mayorElemento, int *menorElemento) {
    int tam = sup - inf + 1;
    if (tam <= umbral) {
        // printf("LLAMADA A CLASICO\n");
        // imprimeVector(v, tam);
        // printf("Suma devuelta por clasico = %d\n", SumaClasica(v, inf, sup, mayorElemento, menorElemento));
        return SumaClasica(v, inf, sup, mayorElemento, menorElemento);
    } else {
        int mitad = tam / 2 + inf - 1;

        int mayorIzq, menorIzq, mayorDer, menorDer;
        mayorIzq = -9999999;
        mayorDer = -9999999;
        menorIzq = 9999999;
        menorDer = 9999999;

        int sumaIzq = SumaDyV(v, inf, mitad, &mayorIzq, &menorIzq);
        int sumaDer = SumaDyV(v, mitad + 1, sup, &mayorDer, &menorDer);

        int suma = sumaIzq + sumaDer;

        ComprobarMayoresMenores(mayorElemento, menorElemento, &mayorIzq, &menorIzq, &mayorDer, &menorDer, &suma);
        //printf("[SUMADyV] mayorElemento=%d | menorElemento=%d || mayorIzq=%d | menorIzq=%d || mayorDer=%d | menorDer=%d ||| sumaIzq=%d | sumaDer=%d\n", *mayorElemento, *menorElemento, mayorIzq, menorIzq, mayorDer, menorDer, sumaIzq, sumaDer);
        return suma;
    }
}

int main() {
    int tam = 8;
    ivector v = icreavector(tam);
    v[0] = 4;
    v[1] = 1;
    v[2] = 8;
    v[3] = 7;
    v[4] = 2;
    v[5] = 6;
    v[6] = 9;
    v[7] = 3;
    imprimeVector(v, tam);
    int mayorE = -9999999;
    int menorE = 9999999;
    printf("[SUMACLASICA] Suma del vector anterior = %d\n", SumaClasica(v, 0, 7, &mayorE, &menorE));

    printf("[SUMADyV] Suma del vector anterior = %d\n", SumaDyV(v, 0, 7, &mayorE, &menorE));

    return 0;
}
