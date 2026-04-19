#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<math.h>

char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};

struct Producto {
 int ProductoID; //Numerado en ciclo iterativo
 int Cantidad; // entre 1 y 10
 char *TipoProducto; // Algún valor del arreglo TiposProductos
 float PrecioUnitario; // entre 10 - 100
};

struct Cliente {
int ClienteID; // Numerado en el ciclo iterativo
char *NombreCliente; // Ingresado por usuario
int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
struct Producto *Productos //El tamaño de este arreglo depende de la variable
// “CantidadProductosAPedir”
};

float totalProducto(struct Producto producto);

int main(){
    srand(time(NULL));
    int nClientes,cantcaracteres,precioMin = 10,precioMax = 99;
    char buff[120];
    struct Cliente *Clientes;
    float total;

    
    do
    {
        puts("Ingrese la cantidad de clientes < 5");
        scanf("%d",&nClientes);
    } while (nClientes>5 || nClientes <0);
    
    Clientes = (struct Cliente * )malloc(sizeof(struct Cliente)*nClientes);
    fflush(stdin);
    puts("Ingrese los datos de los clientes");
    for (int i = 0; i < nClientes; i++)
    {
        Clientes[i].ClienteID = i;
        printf("\n -- cliente %d--  ",i+1);
        printf("\nNombre: ");
        gets(buff);
        cantcaracteres = strlen(buff);
        Clientes[i].NombreCliente = (char * )malloc(sizeof(char)*cantcaracteres+1);
        strcpy(Clientes[i].NombreCliente,buff);
        Clientes[i].CantidadProductosAPedir = 1 + rand() % (5 - 1 + 1);
        Clientes[i].Productos = (struct Producto * )malloc(sizeof(struct Producto)*Clientes[i].CantidadProductosAPedir);
        for (int j = 0; j < Clientes[i].CantidadProductosAPedir; j++)
        {
            Clientes[i].Productos[j].ProductoID = j;
            Clientes[i].Productos[j].Cantidad = 1 + rand() % (10 - 1 + 1);
            Clientes[i].Productos[j].TipoProducto = TiposProductos[0 + rand() % (4 - 0 + 1)];
            //precio unitario se calcula con parte real y parte decimal de forma aleatoria
            Clientes[i].Productos[j].PrecioUnitario = (0 + rand() % (99 - 0 + 1))/100.0+precioMin + rand() % (precioMax - precioMin + 1); //precio con 2 decimales
        }
    }

    for (int j = 0; j < nClientes; j++)
    {
        printf("\n -- cliente con ID %d--  ",Clientes[j].ClienteID);
        printf("\nNombre: %s",Clientes[j].NombreCliente);
        printf("\nCantidad de pedidos : %d\n",Clientes[j].CantidadProductosAPedir);
        total = 0.0;
        for (int k = 0; k < Clientes[j].CantidadProductosAPedir; k++)
        {
            printf("\n -- Pedido con ID %d--  ",Clientes[j].Productos[k].ProductoID);
            printf("\n Cantidad: %d",Clientes[j].Productos[k].Cantidad);
            printf("\n Tipo de producto : %s",Clientes[j].Productos[k].TipoProducto);
            printf("\n Precio unitario : %.2f\n",Clientes[j].Productos[k].PrecioUnitario);
            total +=  totalProducto(Clientes[j].Productos[k]);
        }
        printf("\n Total a pagar  : %.2f\n",total);
    }
    
    //Libera memoria
    for (int f = 0; f < nClientes; f++)
    {
        free(Clientes[f].NombreCliente);
        free(Clientes[f].Productos);
    }
}

float totalProducto(struct Producto producto){
    return producto.PrecioUnitario*producto.Cantidad;
}