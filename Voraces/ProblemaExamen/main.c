#include <stdio.h>
#include <stdlib.h>

#include "imatriz2d.h"
#include "ivector.h"

void imprimeVectorChars(ivector v, int tam) {
    for (int i = 0; i < tam; ++i) {
        printf("%c ", v[i]);
    }
    printf("\n");
}

void ImprimeMatriz(imatriz2d m, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d\t", m[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void rellenarMatriz(imatriz2d m, int n){
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            m[i][j] = rand() % 10;
        }
    }
}

int MayorCaminoEsquina (imatriz2d m, int n, ivector camino, int *contadorCamino) {
    int suma = 0;
    int contadorCaminoFilas = 0;
    int contadorCaminoColumnas = 0;
    while (contadorCaminoFilas < n-1 && contadorCaminoColumnas < n-1){
            if (m[contadorCaminoFilas+1][contadorCaminoColumnas] > m[contadorCaminoFilas][contadorCaminoColumnas+1]) {
                printf("Nos movemos hacia abajo desde m[%d][%d]\n", contadorCaminoFilas, contadorCaminoColumnas);
                camino[*contadorCamino] = 'A';
                *contadorCamino = *contadorCamino+1;
                suma += m[contadorCaminoFilas+1][contadorCaminoColumnas];
                ++contadorCaminoFilas;
            }else {
                printf("Nos movemos hacia la derecha desde m[%d][%d]\n", contadorCaminoFilas, contadorCaminoColumnas);
                camino[*contadorCamino] = 'D';
                *contadorCamino = *contadorCamino+1;
                suma += m[contadorCaminoFilas][contadorCaminoColumnas+1];
                contadorCaminoColumnas++;
            }
    }
    return suma;
}

int main(void) {
    int n = 8;
    imatriz2d m = icreamatriz2d(n, n);

    rellenarMatriz(m, n);

    ImprimeMatriz(m, n);

    ivector camino = icreavector(100);
    for (int i = 0; i < 100; ++i) {
        camino[i] = '-';
    }

    int *contadorCamino = 0;

    //imprimeVectorChars(camino, 100);

    printf("La suma del camino pasando por los mayores valores hacia una esquina es: %d, y el camino es:\n", MayorCaminoEsquina(m, n, camino, &contadorCamino));
    imprimeVectorChars(camino, 100);


    return 0;
}
