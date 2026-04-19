#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 5

void MostrarPersonas(char *nombreAlumno[],int cant);
void  BuscarNombre(char *nombreAlumno[],int cant,int ID);

int main(){

    char *nombreAlumno[N];
    char buff[120];
    int cantcaracteres;
    int ID;
    for (int i = 0; i < N; i++)
    {
        printf("\nIngrese el nombre: ");
        scanf("%s",buff);
        cantcaracteres = strlen(buff);
        nombreAlumno[i] = (char * )malloc(sizeof(char)*cantcaracteres+1);
        strcpy(nombreAlumno[i],buff);
    }

    MostrarPersonas(nombreAlumno,N);
    printf("\nIngrese el ID: ");
    scanf("%d",&ID);
    BuscarNombre(nombreAlumno,N,ID);
    

}

void MostrarPersonas(char *nombreAlumno[],int cant){
    for (int j = 0; j < N; j++)
    {
        printf("\n%s",nombreAlumno[j]);
    }
}



void  BuscarNombre(char *nombreAlumno[],int cant,int ID){
    if (ID<=cant && ID>0)
    {
        printf("\n%s",nombreAlumno[ID-1]);
    }else{
        printf("no se encontró el valor buscado");
    }
    
}