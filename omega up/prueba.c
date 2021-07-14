#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    Libro deque[MAX];
    int indice;
    int fin;
}Pila;
void Dividir(char *nombre,Pila *prestasmo, Pila *reserva)
{
    FILE *A;

    A=fopen("MyComputers.txt","r");

    Libros aux;
    rewind(A);
    fread(&aux,sizeof(Libro),1,A);
    while(!feof(A))
    {
         if(aux.cTipo == 'p')
            push(prestamo,aux);
        else
            push(reserva,aux);
        fread(&aux,sizeof(int),1,A);
    }
    fclose(A);
}
int main()
{
//return 0;
}/*
