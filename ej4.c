#include<stdlib.h> 
#include<stdio.h>
#include<string.h> //Cadenas

#define mn 50 //Tamaño max. de nombre del alumno

typedef struct //Estructura de estudainte, con nombre y edad
{
    char name[mn]; //Arreglo para almacenar nombre
    int edad; //Almacena edad(entero)
}estudiante; 

int main()
{
    estudiante *lista; //Apuntador
    int cap=2; //Capacidad inicial del arreglo de estudiantes
    int cant=0; //Cuenta los estudiantes ingresados

    lista=(estudiante*)malloc(cap* sizeof(estudiante)); //Reserva memoria para 2 estudiantes

    if (lista==NULL) //Verifica si se asigno memoria de manera adecuada
    {
        printf("Error al asignar memoria\n");
        return 1; //1 indica que hubo un error
    }

    printf("Ingrese el nombre y edad del estudiante: (`fin` para terminar) \n");

    while (1) //Bucle para recibir "n" estudiantes hasta que el usuario ingrese "fin"
    { //Crea un bucle infinito hasta que "break;" lo detenga.
        char name[mn];  //Almacena el nombre de estudiante
        int edad;  //Almacena edad de estudiante

        printf("Nombre:\n");
        scanf("%s", &name);

        if (strcmp(name, "fin") == 0) //strcmp->comparar cadenas de caracteres "char"
        { //verifica si name es igual a "fin", si devuelve 0 significa que las cadenas son iguales y para el bucle 
            break; //Termina bucle
        } 

        printf("Edad: \n");
        scanf("%d", &edad);

        if (cant==cap)
        {
            cap*=2; // Evita hacer muchas llamadas a realloc, mejorando el rendimiento
            lista=(estudiante*)realloc(lista, cap* sizeof(estudiante)); //Aumenta el tamaño de la memoria asignada al apuntador lista
            if (lista==NULL) //Verifica si la memoria fue asignada correctamente
            {
                printf("Error al asignar memoria\n");
                return 1; //Indica que hubo error al asignar la memoria
            }
        }

        strcpy(lista[cant].name, name); //Copia el contenido de name en la posición cant dentro de lista
        lista[cant].edad=edad; //Guarda la edad ingresada en la  lista[cant]
        cant++; //Aumenta en 1 la cantidad de estudiantes registrados (cant)
    }
        printf("Lista de estudiantes:\n");
        for(int i=0;i<cant;i++)
        {
            printf("Nombre: %s, Edad: %d \n", lista[i].name, lista[i].edad);
        }
    
        free(lista); //Libera memoria asignada
    return 0;
}
