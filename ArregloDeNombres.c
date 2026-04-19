#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 5

void MostrarPersonas(char *nombreAlumno[],int cant);
char *BuscarNombrePorPalabra(char *nombreAlumno[],int cant,char *palabra);
void  BuscarNombrePorID(char *nombreAlumno[],int cant,int ID);

int main(){

    char *nombreAlumno[N],*resultado;
    char buff[120];
    int cantcaracteres;
    int ID,opcion;
    for (int i = 0; i < N; i++)
    {
        printf("\nIngrese el nombre: ");
        gets(buff);
        cantcaracteres = strlen(buff);
        nombreAlumno[i] = (char * )malloc(sizeof(char)*cantcaracteres+1);
        strcpy(nombreAlumno[i],buff);
    }

    MostrarPersonas(nombreAlumno,N);

    do
    {
        printf("\nIngrese una opcion: \n");
        printf("1- buscar por ID\n");
        printf("2- buscar por nombre\n");
        scanf("%d",&opcion);
    } while (opcion>2 || opcion <1);
    fflush(stdin);
    switch (opcion)
    {
    case 1:
        printf("Ingrese el ID: \n");
        scanf("%d",&ID);
        BuscarNombrePorID(nombreAlumno,N,ID);
        break;
    case 2 :
        printf("\nIngrese el nombre : ");
        scanf("%s",buff);
        resultado = BuscarNombrePorPalabra(nombreAlumno,N,buff);
        puts(resultado);
        break;
    }

    for (int j = 0; j < N; j++)
    {
        free(nombreAlumno[j]);
    }

}

void MostrarPersonas(char *nombreAlumno[],int cant){
    for (int j = 0; j < N; j++)
    {
        printf("\n%s",nombreAlumno[j]);
    }
}



char *BuscarNombrePorPalabra(char *nombreAlumno[],int cant,char *palabra){
    
    int band = 0;
    char *cadenaAux;

    while (!band && cant-1>=0)
    {
        cadenaAux = strstr(nombreAlumno[cant-1],palabra);
        if (cadenaAux != NULL)
        {
            band = 1;
        }
        cant-=1;
    }
    if (band)
    {
         return nombreAlumno[cant];
    }else{
        return "-1";
    }
}

void  BuscarNombrePorID(char *nombreAlumno[],int cant,int ID){
    if (ID<=cant && ID>0)
    {
        printf("\n%s",nombreAlumno[ID-1]);
    }else{
        printf("no se encontró el valor buscado");
    }
    
}