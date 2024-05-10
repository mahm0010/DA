#include <stdio.h>
#include "ivector.h"
#include "imatriz2d.h"

void InicializaMatriz(imatriz2d m, int a, int b){
    for (int i = 0; i < a; ++i) {
        for (int j = 0; j < b; ++j) {
            m[i][j] = 0;
        }
    }
}

int Maximo(int val1, int val2){
    if(val1 >= val2){
        return val1;
    }else{
        return val2;
    }
}

void ImprimeVector(ivector v, int tam){
    for (int i = 0; i < tam; ++i) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

void ImprimeMatriz(imatriz2d m, int nF, int nC){
    for (int i = 0; i < nF; ++i) {
        for (int j = 0; j < nC; ++j) {
            printf("%d\t", m[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int Funcion(int a, int b, ivector datos){
    imatriz2d sol = icreamatriz2d(a+1, b+1);
    InicializaMatriz(sol, a+1, b+1);

    for (int i = 0; i <= a; ++i) {
        for (int j = 0; j <= b; ++j) {
            if(i==0){
                sol[i][j] = 1;
            }else if(j==0){
                sol[i][j] = 0;
            }else if(i < datos[j]){
                sol[i][j] = sol[i-1][j];
            }else{
                sol[i][j] = Maximo(sol[i-1][j], sol[i-datos[j]][j-1] + 1);
            }
        }
    }
    ImprimeMatriz(sol, a+1, b+1);
    int res = sol[a][b];
    ifreematriz2d(&sol);
    return res;
}

int main() {
    // Miguel Ángel Hurtado Molina
    // DNI: 26498396G

    int a = 2;
    int b = 3;
    ivector datos = icreavector(b+1);

    for (int i = 0; i < b + 1; ++i) {
        datos[i] = i;
//        datos[i] = i % (b-1) + 1;
//        if(datos[i] == 1){
//            ++datos[i];
//        }
    }


    printf("El vector de datos es ");
    ImprimeVector(datos, b+1);

    printf("El resultado de la funcion para a=%d y b=%d es: %d", a, b, Funcion(a, b, datos));

    ifreevector(&datos);
    return 0;
}
