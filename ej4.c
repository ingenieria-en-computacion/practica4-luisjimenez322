#include <stdio.h>   // Biblioteca estándar para entrada y salida
#include <stdlib.h>  // Biblioteca para manejo de memoria dinámica
#include <string.h>  // Biblioteca para manipulación de cadenas

#define MAX_NOMBRE 50 // Tamaño máximo del nombre del estudiante

// Definimos la estructura Estudiante con dos campos: nombre y edad
typedef struct {
    char nombre[MAX_NOMBRE]; // Arreglo de caracteres para almacenar el nombre
    int edad;                // Entero para almacenar la edad
} Estudiante;

int main() {
    Estudiante *lista;  // Puntero a la lista dinámica de estudiantes
    int capacidad = 2;  // Capacidad inicial del arreglo de estudiantes
    int cantidad = 0;   // Contador de estudiantes ingresados

    // Reservamos memoria inicialmente con malloc para 2 estudiantes
    lista = (Estudiante *)malloc(capacidad * sizeof(Estudiante));

    // Verificamos si la asignación de memoria fue exitosa
    if (lista == NULL) {
        printf("Error al asignar memoria.\n");
        return 1; // Terminamos el programa con error
    }

    printf("Ingrese los datos de los estudiantes (nombre y edad). Escriba 'fin' para terminar.\n");

    while (1) { // Bucle infinito para recibir estudiantes hasta que el usuario decida parar
        char nombre[MAX_NOMBRE]; // Variable temporal para almacenar el nombre del estudiante
        int edad;                // Variable temporal para almacenar la edad

        printf("Nombre: ");
        scanf("%s", nombre); // Leer el nombre ingresado por el usuario

        // Si el usuario ingresa "fin", terminamos el ingreso de estudiantes
        if (strcmp(nombre, "fin") == 0) {
            break; // Salimos del bucle
        }

        printf("Edad: ");
        scanf("%d", &edad); // Leer la edad ingresada por el usuario

        // Si la lista está llena, duplicamos su tamaño con realloc
        if (cantidad == capacidad) {
            capacidad *= 2; // Duplicamos la capacidad del arreglo
            lista = (Estudiante *)realloc(lista, capacidad * sizeof(Estudiante));

            // Verificamos si realloc fue exitoso
            if (lista == NULL) {
                printf("Error al reasignar memoria.\n");
                return 1; // Terminamos el programa con error
            }
        }

        // Copiamos los datos ingresados en la lista de estudiantes
        strcpy(lista[cantidad].nombre, nombre); // Copiamos el nombre
        lista[cantidad].edad = edad; // Asignamos la edad
        cantidad++; // Aumentamos el contador de estudiantes
    }

    // Imprimir la lista de estudiantes ingresados
    printf("\nLista de estudiantes:\n");
    for (int i = 0; i < cantidad; i++) {
        printf("Nombre: %s, Edad: %d\n", lista[i].nombre, lista[i].edad);
    }

    // Liberamos la memoria asignada dinámicamente para evitar fugas
    free(lista);

    return 0; // Fin del programa
}
