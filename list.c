#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* 
-----CONSIGNAS-----------
1- Que tipo de material se recicla mas
2- Empresa que mas recicla 
3- Kilos reciclados en total por las empresas
4- Empresa que no desecho residuos generales -> 100% reciclaje
*/




const char clasificacion[5][11] = {"generales", "inorganico", "organicos"};
const char names[10][25] = {"MERCADO LIBRE", "ARCOR", "TOYOTA", "GOOGLE", "QUILMES", "NATURA", "UNILEVER", "SANTANDER", "BBVA", "FORD"};
struct Company
{
    char name[50];
    int generales;
    int inorganico;
    int organicos;
};
struct Company lista[50];
int matriz[4][11];
int i;


//funcion para generar una lista de empresas con kilos reciclados aleatorios
void Generarlista(){
    for (i = 0; i < 10; i++)
    {
        //generamos numeros aleatorios para cantidades aleatorias de reciclaje
        int randGenerales = rand() % 10;
        int randInorganicos = rand() % 10;
        int randOrganicos = rand() % 10;

      
     

        strcpy(lista[i].name, names[i]);
        lista[i].generales = randGenerales;
        lista[i].inorganico = randInorganicos;
        lista[i].organicos = randOrganicos;
    }

}

//funcion para imprimir la lista de empresas
void Printlista(){
      for ( i = 0; i < 10; i++)
    {
        printf("--------------------------\n");
        printf("Empresa: %s\n", lista[i].name);
        printf("Cantidad de desehcos generales: %i\n", lista[i].generales);
        printf("Cantidad de desehcos inorganicos: %i\n", lista[i].inorganico);
        printf("Cantidad de desehcos organicos: %i\n", lista[i].organicos);
    }
}

void InicializarMatriz(){
    for (i = 0; i < 4; i++)
    {
        for (int j = 0; j < 11; j++)
        {
            matriz[i][j] = 0;
        }
    }
    
}

//funcion para calcular columna en base a la empresa
int CalcColum(char empresa[11]){
    if(strcmp(empresa, "MERCADO LIBRE") == 0){
        return 0;
    }
    else if(strcmp(empresa, "ARCOR") == 0){
        return 1;
    }
    else if(strcmp(empresa, "TOYOTA") == 0){
        return 2;
    }
    else if(strcmp(empresa, "GOOGLE") == 0){
        return 3;
    }
    else if(strcmp(empresa, "QUILMES") == 0){
        return 4;
    }
    else if(strcmp(empresa, "NATURA") == 0){
        return 5;
    }
    else if(strcmp(empresa, "UNILEVER") == 0){
        return 6;
    }
    else if(strcmp(empresa, "SANTANDER") == 0){
        return 7;
    }
    else if(strcmp(empresa, "BBVA") == 0){
        return 8;
    }
    else if(strcmp(empresa, "FORD") == 0){
        return 9;
    }
}


void BusquedaMaterial(){
    int filaMaterial;
    int maxCantidad = 0;
    char material[15];

    for ( i = 0; i < 3; i++)
    {   
        if(matriz[i][10] > maxCantidad){
            filaMaterial = i;
            maxCantidad = matriz[i][10];
        }
    }
    
    //en base a la fila determino a que tipo hace referencia
    if(filaMaterial == 0){
         strcpy(material,"general");
    }
    else if(filaMaterial == 1){
        strcpy(material,"inorganico");

    }
    else if(filaMaterial == 2){
        strcpy(material,"organico");
    }
    printf("El tipo de material que mas se reciclo es: %s", material);
    printf(" con: %i", maxCantidad);
    printf(" de miles kilos\n");
}

void BusquedaEmpresa(){
    int colEmpresa;
    int maxCantidad = 0;
    char empresa[15];

    for ( int j = 0; j < 10; j++)
    {   
        if(matriz[3][j] > maxCantidad){
            colEmpresa = j;
            maxCantidad = matriz[3][j];
        }
    }
    
    //en base a la columna determino a que empresa hace referencia
    if(colEmpresa == 0){
         strcpy(empresa,"MERCADO LIBRE");
    }
    else if(colEmpresa == 1){
        strcpy(empresa,"ARCOR");
    }
    else if(colEmpresa == 2){
        strcpy(empresa,"TOYOTA");
    }
    else if(colEmpresa == 3){
        strcpy(empresa,"GOOGLE");
    }
    else if(colEmpresa == 4){
        strcpy(empresa,"QUILMES");
    }
    else if(colEmpresa == 5){
        strcpy(empresa,"NATURA");
    }
    else if(colEmpresa == 6){
        strcpy(empresa,"UNILEVER");
    }
    else if(colEmpresa == 7){
        strcpy(empresa,"SANTANDER");
    }
    else if(colEmpresa == 8){
        strcpy(empresa,"BBVA");
    }
    else if(colEmpresa == 9){
        strcpy(empresa,"FORD");
    }
    printf("La empresa que mas reciclo es: %s", empresa);
    printf(" con: %i", maxCantidad);
    printf(" mil kilos\n");
}

void BusquedaGenerales(){
    int colEmpresa;
    int maxCantidad = 0;
    char empresa[15];

    for( int j = 0; j < 10; j++)
    {   
        if(matriz[0][j] == 0){
            colEmpresa = j;
        }
    }
    
    //en base a la columna determino a que empresa hace referencia
    if(colEmpresa == 0){
         strcpy(empresa,"MERCADO LIBRE");
    }
    else if(colEmpresa == 1){
        strcpy(empresa,"ARCOR");
    }
    else if(colEmpresa == 2){
        strcpy(empresa,"TOYOTA");
    }
    else if(colEmpresa == 3){
        strcpy(empresa,"GOOGLE");
    }
    else if(colEmpresa == 4){
        strcpy(empresa,"QUILMES");
    }
    else if(colEmpresa == 5){
        strcpy(empresa,"NATURA");
    }
    else if(colEmpresa == 6){
        strcpy(empresa,"UNILEVER");
    }
    else if(colEmpresa == 7){
        strcpy(empresa,"SANTANDER");
    }
    else if(colEmpresa == 8){
        strcpy(empresa,"BBVA");
    }
    else if(colEmpresa == 9){
        strcpy(empresa,"FORD");
    }
    printf("La empresa que no desecho residuos generales es: %s", empresa);
}


//imprimir matriz
void PrintMatriz(){
    printf("ML AR TY GG QL NT UN ST BB FR TOTAL\n");
     for (i = 0; i < 4; i++)
    {   
        for (int j = 0; j < 11; j++)
        {
            printf("%i| ",matriz[i][j]);
        }
        printf("\n");
    }
    
}


int main(){
    
    Generarlista();
    InicializarMatriz();
    

    //asumimos que el empleado mas antiguo es el primero
    for (int i = 0; i < 10; i++)
    {
        int colum = CalcColum(lista[i].name);
        int total = lista[i].generales + lista[i].inorganico + lista[i].organicos;


        //acumulo en la poscion indicada
        matriz[0][colum] =  matriz[0][colum] + lista[i].generales;
        matriz[1][colum] =  matriz[1][colum] + lista[i].inorganico;
        matriz[2][colum] =  matriz[2][colum] + lista[i].organicos;

        //acumulo al total por proyecto
        matriz[3][colum] = total;

        //acumulo al total por antiguedad
        matriz[0][10] = matriz[0][10] + lista[i].generales;
        matriz[1][10] = matriz[1][10] + lista[i].inorganico;
        matriz[2][10] = matriz[2][10] + lista[i].organicos;

        
        matriz[3][10] = matriz[3][10] + total;
        
    }




    PrintMatriz();
    BusquedaMaterial();
    BusquedaEmpresa();
    printf("Cantidad de kilos reciclados por las empresas: %i\n", matriz[3][10]);
    BusquedaGenerales();

 

    return 0; 
}




