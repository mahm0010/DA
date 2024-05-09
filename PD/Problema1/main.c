#include <stdio.h>
#include "ivector.h"

void imprimeVector(ivector v, int tam) {
    for(int i = 0; i < tam; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

int Problema1(int n) {
    ivector sol = icreavector(n+1);
    for (int i = 0; i < n+1; ++i) {
        sol[i] = 0;
    }
    sol[0] = 0;
    for (int i = 1; i <= n; ++i) {
        int suma = 0;
        for (int j = 0; j <= n-1; ++j) {
            suma += sol[j];
        }
        sol[i] = i + 2/(float)i * suma;
    }
    imprimeVector(sol, n+1);
    int res = sol[n];
    ifreevector(&sol);
    return res;
}



int main(void) {
    int n = 10;
    printf("Solucion al primer problema para n=%d: %d", n, Problema1(n));


    return 0;
}
