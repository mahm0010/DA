#include <stdbool.h>
#include <stdio.h>
#include "ivector.h"

void ImprimeSolucion(ivector cartas, ivector solCartas, ivector solPalos, int numCartas) {
    for (int i = 0; i < numCartas; ++i) {
        if (solCartas[i]) {
            printf("%d_%c ", cartas[i], "OCEB"[solPalos[i]]);
        }
    }
    printf("\n");
}

bool Factible(ivector cartas, ivector solCartas, ivector solPalos, int numCartas) {
    int suma = 0, contPalos[4] = {0}, cartasSeleccionadas = 0;

    for (int i = 0; i < numCartas; ++i) {
        if (solCartas[i]) {
            suma += cartas[i];
            cartasSeleccionadas++;
            contPalos[solPalos[i]]++;
        }
    }

    int palosDiferentes = 0;
    for (int i = 0; i < 4; ++i) {
        if (contPalos[i] > 0) {
            palosDiferentes++;
        }
    }

    return (cartasSeleccionadas <= 4 && palosDiferentes <= 2 && suma <= 31);
}

void Backtrack(ivector cartas, int numCartas, int puntuacion, int paso, ivector solCartas, ivector solPalos) {
    if (paso == numCartas) {
        int suma = 0;
        for (int i = 0; i < numCartas; ++i) {
            if (solCartas[i]) {
                suma += cartas[i];
            }
        }
        if (suma == puntuacion) {
            ImprimeSolucion(cartas, solCartas, solPalos, numCartas);
        }
        return;
    }

    for (int i = 0; i <= 1; ++i) {
        solCartas[paso] = i;
        if (i == 1) {
            for (int j = 0; j < 4; ++j) {
                solPalos[paso] = j;
                if (Factible(cartas, solCartas, solPalos, numCartas)) {
                    Backtrack(cartas, numCartas, puntuacion, paso + 1, solCartas, solPalos);
                }
                solPalos[paso] = 0;
            }
        } else {
            if (Factible(cartas, solCartas, solPalos, numCartas)) {
                Backtrack(cartas, numCartas, puntuacion, paso + 1, solCartas, solPalos);
            }
        }
        solCartas[paso] = 0;
    }
}

int main(void) {
    int numCartas = 10;
    ivector cartas = icreavector(numCartas);
    cartas[0] = 1;
    cartas[1] = 2;
    cartas[2] = 3;
    cartas[3] = 4;
    cartas[4] = 5;
    cartas[5] = 6;
    cartas[6] = 7;
    cartas[7] = 10;
    cartas[8] = 11;
    cartas[9] = 12;

    ivector solCartas = icreavector(numCartas);
    ivector solPalos = icreavector(numCartas);
    for (int i = 0; i < numCartas; ++i) {
        solCartas[i] = 0;
        solPalos[i] = 0;
    }

    Backtrack(cartas, numCartas, 31, 0, solCartas, solPalos);

    ifreevector(&cartas);
    ifreevector(&solCartas);
    ifreevector(&solPalos);

    return 0;
}
