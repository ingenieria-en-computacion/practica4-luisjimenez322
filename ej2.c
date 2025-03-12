#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m, n; // Tamaño de la matriz
    int *matriz; // Apuntador de memoria reservada

    printf("Ingrese el valor de m: \n"); // Solicitar dimensiones de la matriz
    scanf("%d", &m);
    printf("Ingrese el valor de n: \n");
    scanf("%d", &n);

    matriz = (int *)calloc(m * n, sizeof(int)); // Reservar memoria para la matriz dinámica

    if (matriz == NULL) // Verificar si la reserva de memoria fue exitosa
    {
        printf("Error al asignar memoria\n");
        return 1;
    }

    // Imprimir la matriz inicializada en ceros
    printf("Matriz inicializada en ceros:\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", *(matriz + i * n + j)); // Mostrar cada elemento de la matriz
        }
        printf("\n");
    }

    // Permitir al usuario modificar valores en la matriz
    int fila, columna, new_v; // Nuevo valor a ingresar 
    char continuar = 's'; // Inicializamos continuar con 's' para entrar al bucle

    while (continuar=='s' || continuar=='S') 
    {
        printf("\nIngrese la fila y columna a modificar (0-%d, 0-%d): ", m - 1, n - 1); // Pedir al usuario la posición a modificar
        scanf("%d %d", &fila, &columna); // Ingresar fila y columna separados por un espacio

        if (fila >= 0 && fila < m && columna >= 0 && columna < n)   // Verificar que la posición es válida
        {
            printf("Ingrese el nuevo valor:\n "); // Pedir nuevo valor
            scanf("%d", &new_v);            
            *(matriz + fila * n + columna) = new_v;   // Actualizar la matriz
            printf("Matriz actualizada:\n"); // Mostrar la matriz actualizada
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    printf("%d ", *(matriz + i * n + j)); // Mostrar cada elemento de la matriz
                }
                printf("\n");
            }
        }
        else
        {
            printf("Error, intente de nuevo.\n");
        }

        // Preguntar si desea continuar
        printf("¿Desea modificar otro valor? (s/n): \n");
        scanf(" %c", &continuar); // Espacio antes de %c para evitar errores con el buffer de entrada
    }

    free(matriz); // Liberar la memoria reservada

    return 0;
}
