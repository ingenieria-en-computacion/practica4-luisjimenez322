#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *arreglo=NULL, num, cont; //Se inicializan los apuntadores en NULL para evitar que apunten a direcciones basura
    printf("Ingresa el numero de elementos del conjunto:\n");
    scanf("%d", &num);
    arreglo = (int*)malloc(num *sizeof(int)); //Reserva memoria para num,*int-> convierte el puntero genérico que devuelve malloc a un puntero a int.
    if(arreglo != NULL) //Verifica si la reserva de memoria fue exitosa, de ser lo contrario regresa NULL
    {        
        for(cont =0; cont <num; cont++) //Recorre el arreglo
        {
            printf("Ingresa el elemento %d del conjunto\n", cont+1);
            scanf("%d", (arreglo+cont)); //Calcula la dirección de cada elemento
        }
        printf("Arreglo\n\t["); 
        for(cont =0; cont <num; cont++)
        {
            printf("\t%d", *(arreglo + cont)); //Accede al valor almacenado en cada posición del arreglo
        }
        printf("\t]\n");
        
        printf("Liberando el espacio reservado\n");

        free(arreglo); //Libera la memoria reservada.   
        arreglo=NULL; //Asigna NULL al apuntador 
    }
    return 0;
}
