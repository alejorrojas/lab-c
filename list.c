#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* 
-----CONSIGNAS-----------
1- Cuantos empleados de más de 5 años tiene la empresa
2- Cuantos empleados hay trabajando en Blockchain ahora mismo 
3- Proyecto con más empleados
4- Empleados con mayor antigüedad y en que proyecto trabajan
*/


const char proyects[4][11] = {"Web", "Blockchain", "IA", "Cloud"};
const char names[10][11] = {"Mark ", "Jeff ", "Elon ", "Freddy ", "Guillermo ", "George ", "Gonzalo ", "Steve ", "Tim "};
const char surnames[10][11] = {"Zuck", "Bezos", "Musk", "Mercury", "Rauch", "Lucas", "Pozzo", "Jobs", "Cook"};
struct Employee
{
    char name[50];
    int hireYear;
    char proyect[50];
};
struct Employee list[50];
struct Employee oldest;
int matriz[4][5];
int randName, randYear, randProyect, randSurname, i, amount;
char fullname[11];

//funcion para generar una lista aleatoria de empleados
void GenerateList(int amount){
    for (i = 0; i < amount; i++)
    {
        //generamos numeros aleatorios para combinaciones aleatorias de empleados
        randName = rand() % 9;
        randSurname = rand() % 9;
        randYear = rand() % 23;
        randProyect = rand() % 4;

        //creamos el nombre completo concatenando dos strings
        strcpy(fullname, names[randName]);
        strcat(fullname, surnames[randSurname]);

        //escribimos en la lista
        list[i].hireYear = 2000+randYear;
        strcpy(list[i].name, fullname);
        strcpy(list[i].proyect, proyects[randProyect]);
    }

    //Generamos manualmente un empleado muy antiguo para probar la busqueda
    list[5].hireYear = 1999;
    strcpy(list[5].name, "Larry Page");
    strcpy(list[5].proyect, "Web");


}

//funcion para imprimir la lista aleatoria de empleados
void PrintList(){
      for (i = 0; i < amount; i++)
    {
        printf("--------------------------\n");
        printf("Employee name: %s\n", list[i].name);
        printf("Proyect: %s\n", list[i].proyect);
        printf("Hire year: %i\n", list[i].hireYear);
    }
}

void InicializarMatriz(){
    for (i = 0; i < 5; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            matriz[i][j] = 0;
        }
    }
    
}

//funcion para calcular columna en base al proyecto
int CalcColum(char proyect[11]){
    if(strcmp(proyect, "Web") == 0){
        return 0;
    }
    else if(strcmp(proyect, "Blockchain") == 0){
        return 1;
    }
    else if(strcmp(proyect, "IA") == 0){
        return 2;
    }
    else if(strcmp(proyect, "Cloud") == 0){
        return 3;
    }
}

//funcion para calcular fila en base a la antiguedad
int CalcRow(int year){
    if(year > 2020){
        //de 0 a 2 años
        return 0;
    }
    else if(year > 2017){
        //de 3 a 5 años
        return 1;
    }
    else{
        //mas de 5 años
        return 2;
    }
}

//imprimir matriz
void PrintMatriz(){
    printf("Web  Bl  IA  Cl  Total \n");
     for (i = 0; i < 4; i++)
    {   
        for (int j = 0; j < 5; j++)
        {
            printf("%i    ",matriz[i][j]);
        }
        printf("\n");
    }
    
}

void BusquedaProyecto(){
    int columProyecto;
    int maxEmpleados = 0;
    char proyecto[11];

    for ( i = 0; i < 4; i++)
    {
        if(matriz[3][i] > maxEmpleados){
            columProyecto = i;
            maxEmpleados = matriz[3][i];
        }
    }
    
    //en base a la columna determino a que proyecto hace referencia
    if(columProyecto == 0){
        strcpy(proyecto,"Web");
    }
    else if(columProyecto == 1){
        strcpy(proyecto,"Blockchain");

    }
    else if(columProyecto == 2){
        strcpy(proyecto,"IA");

    }
    else if(columProyecto == 3){
        strcpy(proyecto,"Cloud");
    }
     printf("Proyecto con mas empleados trabajando: %s ",   proyecto);
     printf("con %i ", maxEmpleados);
     printf("empleados\n");
}

int main(){
    
    amount = 50;
    GenerateList(amount);
    InicializarMatriz();

    //asumimos que el empleado mas antiguo es el primero
    oldest = list[0];
    for ( i = 0; i < amount; i++)
    {
        int colum = CalcColum(list[i].proyect);
        int row = CalcRow(list[i].hireYear);

        if (oldest.hireYear > list[i].hireYear)
        {   
            //si encontramos un empleado con un año de contratacion anterior lo guardamos
            oldest = list[i];
        }
        


        //acumulo en la poscion indicada
        matriz[row][colum] =  matriz[row][colum] + 1;

        //acumulo al total por proyecto
        matriz[3][colum] = matriz[3][colum] + 1;

        //acumulo al total por antiguedad
        matriz[row][4] = matriz[row][4] + 1;

        matriz[3][4] += 1;
        
    }

    PrintMatriz();

    printf("------------------------------\n");
    printf("Cantidad de empleados con mas de 5 anios en la empresa: %i\n", matriz[2][4]);
    printf("Cantidad de empleados trabajando en la Blockchain: %i\n", matriz[3][1]);
    
    BusquedaProyecto();

    printf("Empleado con mayor antiguedad en la empresa: %s .", oldest.name);
    printf(" Actualmente trabajando en el proyecto: %s .", oldest.proyect);
    printf(" Desde: %i ", oldest.hireYear);

    return 0; 
}




