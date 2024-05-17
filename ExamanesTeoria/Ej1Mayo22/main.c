#include <stdbool.h>
#include <stdio.h>
#include "ivector.h"

void ImprimeVector(ivector v, int tam){
    for (int i = 0; i < tam; ++i) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

bool Factible(ivector cartas, int numCartas, int puntuacion, ivector solCartas, ivector solPalos, int numPalos) {
    int suma = 0;
    int contPalos = 0;
    int contPalosDiferentes = 0;
    int contCartas = 0;
    for (int i = 0; i < numCartas; ++i) {
        if(solCartas[i] == 1) {
            ++contCartas;
        }
    }
    for (int i = 0; i < numPalos; ++i) {
        if(solPalos[i] != 0) {
            contPalos += solPalos[i];
            ++contPalosDiferentes;
        }
    }
    if(contCartas <= 4 && contPalos <= 4 && contPalosDiferentes <= 2) {
        for (int i = 0; i < numCartas; ++i) {
            suma += cartas[i] * solCartas[i];
        }
        if(suma <= puntuacion) {
            return true;
        }
    }
    return false;
}

void CombinacionesCartas(ivector cartas, int numCartas, int puntuacion, int pasoCartas, ivector solCartas, ivector solPalos, int pasoPalos, int numPalos) {
    int suma = 0;
    for (int i = 0; i < numCartas; ++i) {
        suma += cartas[i] * solCartas[i];
    }
    printf("%d\n", suma);
    if(pasoCartas == numCartas) {
        if(suma == puntuacion) {
            ImprimeVector(solCartas, numCartas);
            ImprimeVector(solPalos, numPalos);
        }
    }else {
        for (int i = 0; i <= 1; ++i) {
            solCartas[pasoCartas] = i;
        }
        for (int i = 0; i <= 2; ++i) {
            solPalos[pasoPalos] = i;
        }
        if(Factible(cartas, numCartas, puntuacion, solCartas, solPalos, numPalos)) {
            CombinacionesCartas(cartas, numCartas, puntuacion, pasoCartas+1, solCartas, solPalos, pasoPalos+1 % 4, numPalos);
        }
    }
    solCartas[pasoCartas] = 0;
    solPalos[pasoPalos] = 0;
}

int main(void){
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

    int numPalos = 4;
    ivector solPalos = icreavector(numPalos);
    for (int i = 0; i < numPalos; ++i) {
        solPalos[i] = 0;
    }

    ivector solCartas = icreavector(numCartas);
    for (int i = 0; i < numCartas; ++i) {
        solCartas[i] = 0;
    }

    CombinacionesCartas(cartas, numCartas, 31, 0, solCartas, solPalos, 0, 4);

    ifreevector(&cartas);
    ifreevector(&solCartas);
    ifreevector(&solPalos);

    return 0;
}
