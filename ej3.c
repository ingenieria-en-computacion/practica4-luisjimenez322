#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *lst; //Apuntador para lista dinámica
    int cap=2; //Inicie en 2
    int can=0; //Núm. de elementos en la lista
    int num; //Núm. ingresado por usuario

    lst=(int*)malloc(cap* sizeof(int)); //Reserva memoria para 2 elementos

    if(lst==NULL)
    {
        printf("Error al asignar memoria\n");
        return 1; //Indica que hubo un errror return 0;->finalizo correctamente
    } //0=false - cualquier valor !=0 -> True

    printf("Ingrese numeros al azar:\n");
    printf("Para salir --> -1.\n");

    while (1)
    {
        printf("Numero: ");
        scanf("%d", &num);

        if(num==-1) //Salida
        {
            break;
        }
    
        if(can==cap)//realloc
        {
            cap*=2;//duplicar tamaño
            lst=(int*)realloc(lst, cap* sizeof(int));
                if(lst=NULL)    //Comprobar que se asigno memoria
                {
                    printf("Error al asignar memmoria.\n");
                    return 1;
                }
        }
        lst[can]=num; //Almacena el número en la lista
        can++;
    }
    printf("Lista ingresada:\n");
        for(int i=0;i<can;i++)
        {
            printf("%d", lst[i]);
        }
        printf("\n");

        free(lst); //Liberar memoria
    return 0;
}