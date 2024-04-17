#include <stdio.h>

#include "ivector.h"

void imprimeVector(ivector v, int tam) {
    for (int i = 0; i < tam; ++i) {
        printf("%c ", v[i]);
    }
    printf("\n");
}

int CombinacionesPalabras(int numSimbolos, int tamSol, int paso, ivector simbolos, ivector sol) {
    int numVocales = 0;
    int numCombinaciones = 0;

    for (int i = 0; i < tamSol; ++i) {
        if(sol[i] == 'A' || sol[i] == 'E' || sol[i] == 'I' || sol[i] == 'O' || sol[i] == 'U') {
            ++numVocales;
        }
    }
}

int main(void)
{
    int numSimbolos = 8;
    int tamSol = 5;
    ivector simbolos = icreavector(numSimbolos);
    ivector sol = icreavector(tamSol);
    simbolos[0] = '1';
    simbolos[1] = '2';
    simbolos[2] = '3';
    simbolos[3] = 'A';
    simbolos[4] = 'E';
    simbolos[5] = 'I';
    simbolos[6] = 'O';
    simbolos[7] = 'U';
    for (int i = 0; i < tamSol; ++i) {
        sol[i] = 0;
    }

    imprimeVector(simbolos, numSimbolos);

    return 0;
}
