#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

}

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
int CalcColum(char proyect[]){
    if(strcmp(proyect, "Web") == 0){
        return 1;
    }
    else if(strcmp(proyect, "Blockchain") == 0){
        return 2;
    }
    else if(strcmp(proyect, "IA") == 0){
        return 3;
    }
    else if(strcmp(proyect, "Cloud") == 0){
        return 4;
    }
}

//funcion para calcular fila en base a la antiguedad
int CalcRow(int year){
    if(year > 2020){
        //de 0 a 2 años
        return 1;
    }
    else if(year > 2017){
        //de 3 a 5 años
        return 2;
    }
    else{
        //mas de 5 años
        return 3;
    }
}

void PrintMatriz(){
    printf("Web   Blockchain   IA   Cloud \n");
     for (i = 0; i < 5; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%i   ",matriz[i][j]);
        }
        printf("\n");
    }
    
}

int main(){
    
    amount = 50;
    GenerateList(amount);
    InicializarMatriz();

    for ( i = 0; i < amount; i++)
    {
        int colum = CalcColum(list[i].proyect);
        int row = CalcRow(list[i].hireYear);
        printf(" row: %i\n ", row);
        printf(" colum: %i\n ", colum);

        //acumulo en la poscion indicada
        matriz[row][colum] =  matriz[row][colum] + 1;
        printf("matriz: %i\n", matriz[row][colum]);

        //acumulo al total por proyecto
        matriz[4][colum] = matriz[4][colum] + 1;

        //acumulo al total por antiguedad
        matriz[row][5] = matriz[4][colum] + 1;
        
    }

    PrintMatriz();
    

    
    return 0; 
}