#include <stdbool.h>
#include <stdio.h>

#include "ivector.h"

void imprimeVector(ivector v, int tam) {
    for (int i = 0; i < tam; ++i) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

bool Factible(ivector precioProductos, int numProductos, int dinero, ivector sol) {
    int suma = 0;
    for (int i = 0; i < numProductos; ++i) {
        suma += sol[i] * precioProductos[i];
    }
    if(suma <= dinero) {
        return true;
    }
    return false;
}

void MaximizarProductos(ivector precioProductos, int numProductos, int dinero, int paso, ivector sol, int *maxNumProductos, ivector solFinal) {
    int suma = 0;
    int numProductosEscogidos = 0;

    for (int i = 0; i < numProductos; ++i) {
        suma += sol[i] * precioProductos[i];
        if(sol[i] == 1) {
            ++numProductosEscogidos;
        }
    }

    if(paso == numProductos) {
        if(numProductosEscogidos > *maxNumProductos) {
            *maxNumProductos = numProductosEscogidos;

            for (int i = 0; i < numProductos; ++i) {
                solFinal[i] = sol[i];
            }

            imprimeVector(solFinal, numProductos);
        }
    } else {
        for (int i = 0; i <= 1; ++i) {
            sol[paso] = i;
            if (Factible(precioProductos, numProductos, dinero, sol)) {
                MaximizarProductos(precioProductos, numProductos, dinero, paso+1, sol, maxNumProductos, solFinal);
            }
        }
    }
    sol[paso] = 0;
}

int main(void)
{
    // Maximizar el número de  productos teniendo en cuenta que tienes n euros
    int numProductos = 7;
    ivector precioproductos = icreavector(numProductos);

    precioproductos[0] = 5;
    precioproductos[1] = 10;
    precioproductos[2] = 15;
    precioproductos[3] = 20;
    precioproductos[4] = 3;
    precioproductos[5] = 11;
    precioproductos[6] = 1;

    printf("Precio productos: ");
    imprimeVector(precioproductos, numProductos);

    int dinero = 19;

    ivector sol = icreavector(numProductos);
    for (int i = 0; i < numProductos; ++i) {
        sol[i] = 0;
    }

    ivector solFinal = icreavector(numProductos);
    for (int i = 0; i < numProductos; ++i) {
        solFinal[i] = 0;
    }

    int maxNumProductos = -9999;

    MaximizarProductos(precioproductos, numProductos, dinero, 0, sol, &maxNumProductos, solFinal);

    printf("Max num productos con %d euros: %d\n", dinero, maxNumProductos);
    //imprimeVector(solFinal, numProductos);
    printf("Los productos escogidos son: ");
    for (int i = 0; i < numProductos; ++i) {
        if(solFinal[i] == 1) {
            printf("%d ", precioproductos[i]);
        }
    }
    int sumaFinal = 0;
    for (int i = 0; i < numProductos; ++i) {
        sumaFinal += solFinal[i] * precioproductos[i];
    }
    printf("\nLa suma final es: %d euros", sumaFinal);

    ifreevector(&precioproductos);
    ifreevector(&sol);
    ifreevector(&solFinal);

    return 0;
}
