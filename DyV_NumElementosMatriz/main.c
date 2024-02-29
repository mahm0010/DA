#include <stdio.h>
#include <stdlib.h>

#include "imatriz2d.h"

#define umbral 2

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

int NumElementosClasico(imatriz2d m, int cIni, int cFin, int fIni, int fFin, int a, int b) {
    int cont = 0;
    for (int i = fIni; i <= fFin; ++i) {
        for (int j = cIni; j <= cFin; ++j) {
            if(m[i][j] >= a && m[i][j] <= b) {
                ++cont;
            }
        }
    }
    return cont;
}

int NumElementosDyV(imatriz2d m, int cIni, int cFin, int fIni, int fFin, int a, int b) {
    int n = cFin - cIni + 1;

    if (n <= umbral) {
        return NumElementosClasico(m, cIni, cFin, fIni, fFin, a, b);
    } else {
        int nC = cFin - cIni + 1;
        int nF = fFin - fIni + 1;
        int medioC = nC / 2 + cIni - 1;
        int medioF = nF / 2 + fIni - 1;

        int numElementos = 0;

        numElementos += NumElementosDyV(m, cIni, medioC, fIni, medioF, a, b);
        numElementos += NumElementosDyV(m, medioC + 1, cFin, fIni, medioF, a, b);
        numElementos += NumElementosDyV(m, cIni, medioC, medioF + 1, fFin, a, b);
        numElementos += NumElementosDyV(m, medioC + 1, cFin, medioF + 1, fFin, a, b);
        return numElementos;
    }
}

int main() {
    int n = 4;
    imatriz2d m = icreamatriz2d(n, n);
    // m[0][0] = 4;
    // m[0][1] = 8;
    // m[0][2] = 5;
    // m[0][3] = 6;
    // m[1][0] = 6;
    // m[1][1] = 12;
    // m[1][2] = 4;
    // m[1][3] = 1;
    // m[2][0] = 3;
    // m[2][1] = 1;
    // m[2][2] = 3;
    // m[2][3] = 5;
    // m[3][0] = 5;
    // m[3][1] = 13;
    // m[3][2] = 6;
    // m[3][3] = 2;

    rellenarMatriz(m, n);

    ImprimeMatriz(m, n);
    int a = 5;
    int b = 8;
    printf("[NUMELEMENTOSCLASICO] La matriz anterior tiene %d elementos dentro del intervalo [%d, %d]\n",
        NumElementosClasico(m, 0, n-1, 0, n-1, a, b), a, b);
    printf("[NUMELEMENTOSDyV] La matriz anterior tiene %d elementos dentro del intervalo [%d, %d]\n",
        NumElementosDyV(m, 0, n-1, 0, n-1, a, b), a, b);


    return 0;
}
