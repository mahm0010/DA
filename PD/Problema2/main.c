#include <stdio.h>
#include <math.h>

#include "imatriz2d.h"

void InicializarMatriz(imatriz2d matriz, int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            matriz[i][j] = 0;
        }
    }
}

void ImprimeMatriz(imatriz2d matriz, int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int Problema2(int n, int m) {
    imatriz2d sol = icreamatriz2d(n+1, m+1);
    InicializarMatriz(sol, n+1, m+1);
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            if(j==0) {
                sol[i][j] = 0;
            }
            if(j==1) {
                sol[i][j] = i;
            }
            if(j > 1) {
                int result1 = floor((float)j/2);
                int result2 = ceil((float)j/2);
                sol[i][j] = sol[i][result1] + sol[i][result2];
            }
        }
    }
    ImprimeMatriz(sol, n+1, m+1);
    int res = sol[n][m];
    ifreematriz2d(&sol);
    return res;
}

int main(void){
    int n = 5;
    int m = 7;
    printf("El resultado de la funcion del problema 2 para n=%d y m=%d es: %d", n, m, Problema2(n, m));

    return 0;
}
