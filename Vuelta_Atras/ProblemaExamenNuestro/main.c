#include <stdio.h>
#include <stdlib.h>

#define MAX_ASIGNATURAS 20

typedef struct {
    int id;
    int curso;
    int horaInicio;
    int horaFin;
} Asignatura;

// Función para verificar si dos asignaturas son compatibles
int sonCompatibles(Asignatura a, Asignatura b) {
    return a.horaFin <= b.horaInicio || b.horaFin <= a.horaInicio;
}

// Función para imprimir una combinación de asignaturas
void imprimirCombinacion(Asignatura asignaturas[], int indices[], int n) {
    printf("Combinación válida: ");
    for (int i = 0; i < n; i++) {
        printf("(%d, %d, %d, %d) ", asignaturas[indices[i]].id, asignaturas[indices[i]].curso,
               asignaturas[indices[i]].horaInicio, asignaturas[indices[i]].horaFin);
    }
    printf("\n");
}

// Función de backtracking para encontrar todas las combinaciones posibles
void buscarCombinaciones(Asignatura asignaturas[], int n, int nivel, int solucion[], int ultimaAsignatura, int *maxNivel) {
    if (nivel > *maxNivel) {
        imprimirCombinacion(asignaturas, solucion, nivel);
        *maxNivel = nivel;
    }

    for (int i = ultimaAsignatura + 1; i < n; i++) {
        int compatible = 1;
        for (int j = 0; j < nivel; j++) {
            if (!sonCompatibles(asignaturas[solucion[j]], asignaturas[i])) {
                compatible = 0;
                break;
            }
        }

        if (compatible) {
            solucion[nivel] = i;
            buscarCombinaciones(asignaturas, n, nivel + 1, solucion, i, maxNivel);
        }
    }
}

int main() {
    Asignatura asignaturas[] = {
        {105, 1, 11, 12},
        {207, 2, 9, 11},
        {134, 1, 10, 12},
        {333, 3, 10, 11},
        {228, 2, 9, 10}
    };
    int n = sizeof(asignaturas) / sizeof(asignaturas[0]);
    int solucion[MAX_ASIGNATURAS];
    int maxNivel = 0;

    buscarCombinaciones(asignaturas, n, 0, solucion, -1, &maxNivel);

    return 0;
}