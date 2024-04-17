#include <stdbool.h>
#include <stdio.h>

#include "ivector.h"

void imprimeVector(ivector v, int tam) {
    for (int i = 0; i < tam; ++i) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

void imprimeSubconjunto(ivector numeros, ivector sol, int tam) {
    printf("{");
    for (int i = 0; i < tam; ++i) {
        if(sol[i] == 1) {
            printf(" %d ", numeros[i]);
        }
    }
    printf("}\n");
}

bool factible(int tam, int puntuacion, ivector numeros, ivector sol) {
    int suma = 0;
    for (int i = 0; i < tam; ++i) {
        suma += sol[i] * numeros[i];
    }
    if(suma <= puntuacion) {
        return true;
    }
    return false;
}

int CombinacionesSuma(int tam, int puntuacion, int paso, ivector numeros, ivector sol) {
    int numCombinaciones = 0;
    int suma = 0;
    for (int i = 0; i < tam; ++i) {
        suma += sol[i] * numeros[i];
    }

    if(paso == tam) {
        if(suma == puntuacion) {
            imprimeSubconjunto(numeros, sol, tam);
            ++numCombinaciones;
        }
    } else {
        for (int i = 0; i <= 1; ++i) {
            sol[paso] = i;
            if(factible(tam, puntuacion, numeros, sol)) {
                numCombinaciones += CombinacionesSuma(tam, puntuacion, paso+1, numeros, sol);
            }
        }
    }
    sol[paso] = 0;
    return numCombinaciones;
}

int main(void) {
    int tam = 5;
    ivector numeros = icreavector(tam);
    ivector sol = icreavector(tam);
    for (int i = 0; i < tam; ++i) {
        numeros[i] = i+1;
        sol[i] = 0;
    }
    imprimeVector(numeros, tam);
    int puntuacion = 6;

    printf("\nNumero de subconjuntos posibles para sumar %d: %d\n", puntuacion, CombinacionesSuma(tam, puntuacion, 0, numeros, sol));

    return 0;
}
