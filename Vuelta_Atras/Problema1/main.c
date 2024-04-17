#include <stdio.h>
#include <stdbool.h>

#include "ivector.h"

void imprimeVector (ivector v, int tam) {
    for (int i = 0; i < tam; ++i) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

bool factible(int numDados, int puntuacion, ivector sol) {
    int suma = 0;
    for (int i = 0; i < numDados; ++i) {
        if (sol[i] > 0) {
            suma += sol[i];
        }else {
            ++suma; // Si el dado está a 0, como mínimo tomará una puntuación de 1
        }
    }
    if(suma <= puntuacion) {
        return true;
    }
    return false;
}

int CombinacionesDados(int numDados, int puntuacion, int paso, ivector sol) {
    int numCombinaciones = 0;
    int suma = 0;
    for (int i = 0; i < numDados; ++i) {
        suma += sol[i];
    }

    // Si ya hemos probado con todos los dados
    if(paso == numDados) {
        // Si la suma alcanza la puntuación deseada
        if(suma == puntuacion) {
            // Mostramos la solución y aumentamos el contador
            imprimeVector(sol, numDados);
            ++numCombinaciones;
        }
    } else { // Si no hemos probado con todos los dados
        // Probamos para ese paso las diferentes caras del dado
        for (int i = 1; i <= 6; ++i) {
            sol[paso] = i;
            // Comprobamos si es factible
            if (factible(numDados, puntuacion, sol)) {
                numCombinaciones += CombinacionesDados(numDados, puntuacion, paso + 1, sol);
            }
        }
    }
    // Deshacemos el paso
    sol[paso] = 0;
    return numCombinaciones;
}

int main(void) {
    int tam = 5;
    ivector v = icreavector(tam);

    for (int i = 0; i < tam; ++i) {
        v[i] = 0;
    }
    int puntuacion = 6;

    printf("El numero de combinaciones posibles para sacar la puntuacion %d con %d dados es %d", puntuacion, tam, CombinacionesDados(tam, puntuacion, 0, v));

    return 0;
}
