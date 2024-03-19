#include <stdio.h>
#include <stdlib.h>

#include "ivector.h"

void imprimeVector(ivector v, int tam) {
    for (int i = 0; i < tam; ++i) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

ivector ordenaElementos(ivector vA, ivector vB, int tam) {
    //printf("\nREORDENAR\n");
    ivector aux = icreavector(tam);
    for (int i = 0; i < tam; ++i) {
        int posMenor = -1;
        int menorAux = 9999;
        for (int j = 0; j < tam; ++j) {
            if(vA[i].valor <= vB[j].valor && vB[j].valor < menorAux && !vB[j].escogido) {
                vB[posMenor].escogido = false;
                posMenor = j;
                menorAux = vB[j].valor;
                vB[posMenor].escogido = true;
            }
        }
        if(posMenor != -1) {
            aux[i].valor = vB[posMenor].valor;
        }else {
            aux[i].valor = 0;
        }
    }
    for (int i = 0; i < tam; ++i) {
        int contador = 0;
        for (int j = 0; j < tam; ++j) {
            if(vB[i].valor == aux[j].valor) {
                contador++;
            }
        }
        if(contador == 0) {
            vB[i].escogido = false;
        }else {
            vB[i].escogido = true;
        }
    }
    for (int i = 0; i < tam; ++i) {
        for (int j = 0; j < tam; ++j) {
            if(aux[i].valor == 0 && !vB[j].escogido) {
                aux[i].valor = vB[j].valor;
                vB[j].escogido = true;
            }
        }
    }
    //imprimeVector(aux, tam);
    return aux;
}

int sumaMaximaVoraz(ivector vA, ivector vB, int tam) {
    ivector sol = ordenaElementos(vA, vB, tam);
    printf("Vector B reordenado\n");
    imprimeVector(sol, tam);
    int suma = 0;
    for (int i = 0; i < tam; ++i) {
        if(vA[i].valor <= sol[i].valor) {
            suma += vA[i].valor;
        }
    }
    return suma;
}

int main(void) {
    int tam = 5;
    ivector vectorA = icreavector(tam);
    ivector vectorB = icreavector(tam);

    vectorA[0].valor = 1; vectorB[0].valor = 3;
    vectorA[1].valor = 4; vectorB[1].valor = 2;
    vectorA[2].valor = 6; vectorB[2].valor = 4;
    vectorA[3].valor = 7; vectorB[3].valor = 6;
    vectorA[4].valor = 9; vectorB[4].valor = 5;

    printf("Vector A\n");
    imprimeVector(vectorA, tam);
    printf("Vector B\n");
    imprimeVector(vectorB, tam);

    printf("Suma total = %d\n", sumaMaximaVoraz(vectorA, vectorB, tam));

    // LIBERAR MEMORIAS
    ifreevector(&vectorA);
    ifreevector(&vectorB);



    return 0;
}
