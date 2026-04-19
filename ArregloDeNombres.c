#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 5

void MostrarPersonas(char *nombreAlumno[],int cant);
char *BuscarNombrePorPalabra(char *nombreAlumno[],int cant,char *palabra);
void  BuscarNombrePorID(char *nombreAlumno[],int cant,int ID);

int main(){

    char *nombreAlumno[N],*clave,*resultado;
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
    printf("\nIngrese el nombre a buscar: ");
    scanf("%s",buff);
    resultado = BuscarNombrePorPalabra(nombreAlumno,N,buff);
    printf("%s",resultado);
    printf("\nIngrese el ID: ");
    scanf("%d",&ID);
    BuscarNombrePorID(nombreAlumno,N,ID);
    

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
         return cadenaAux;
    }else{
        return "-1";
    }
void  BuscarNombrePorID(char *nombreAlumno[],int cant,int ID){
    if (ID<=cant && ID>0)
    {
        printf("\n%s",nombreAlumno[ID-1]);
    }else{
        printf("no se encontró el valor buscado");
    }
    
}