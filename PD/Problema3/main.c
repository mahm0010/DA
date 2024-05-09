#include <stdio.h>
#include "ivector.h"
#include "imatriz2d.h"

void ImprimeMatriz(imatriz2d matriz, int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void ImprimeVector(ivector v, int tam) {
    for(int i = 0; i < tam; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

void InicializarMatriz(imatriz2d matriz, int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            matriz[i][j] = 0;
        }
    }
}

int Problema3(int m, int n, ivector datos) {
    imatriz2d sol = icreamatriz2d(m+1, n+1);
    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <= n; ++j) {
            if(i==0) {
                sol[i][j] = 1;
            }else if(j==0) {
                sol[i][j] = 1;
            }else if(j < datos[i]) {
                sol[i][j] = sol[i-1][j];
            } else {
                int suma = 0;
                for (int k = 1; k <= datos[i]-1; ++k) {
                    suma += sol[i][j-k];
                }
                sol[i][j] = suma;
            }
        }
    }
    ImprimeMatriz(sol, m+1, n+1);
    int res = sol[m][n];
    ifreematriz2d(&sol);
    return res;
}

int main(void){
    int m = 10;
    int n = 10;
    ivector datos = icreavector(n);

    for (int i = 0; i < (m + 1); ++i) {
        int val = (1 + i) * 3 % n;
        if (val < 2) {
            datos[i] = 2;
        }
        else {
            datos[i] = val;
        }
    }

    printf("El vector de datos es el siguiente: ");
    ImprimeVector(datos, n);

    printf("La solucion para la funcion del tercer problema para m=%d y n=%d es: %d", m, n, Problema3(m, n, datos));
    ifreevector(&datos);

    return 0;
}
