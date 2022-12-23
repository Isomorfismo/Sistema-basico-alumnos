#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50

typedef struct materia{
    char nombre[20];
    char horario[20];
    float calificaciones[3];
    float promedio;
}materia;

typedef struct estudiante{
    char nombre[20];
    int matricula;
    char grupo[20];
    int cantidad;
    materia materias[3];
}estudiante;

estudiante estudiantes[MAX];
int n=0;

void ingresarEstudiante(){
    int i,j;
    printf("Ingrese el nombre del estudiante: \n");
    scanf("%s",estudiantes[n].nombre);
    printf("Ingrese la matricula del estudiante: \n");
    scanf("%d",&estudiantes[n].matricula);
    printf("Ingrese el grupo del estudiante: \n");
    scanf("%s",estudiantes[n].grupo);
    printf("Ingrese el numero de materias: \n");
    scanf("%d",&estudiantes[n].cantidad);
    for(i=0;i<estudiantes[n].cantidad;i++){
        printf("Ingrese el nombre de la materia %d: \n",i+1);
        scanf("%s",estudiantes[n].materias[i].nombre);
        printf("Ingrese el horario de la materia %d: \n",i+1);
        scanf("%s",estudiantes[n].materias[i].horario);
        for(j=0;j<3;j++){
            printf("Ingrese la calificacion %d de la materia %d: \n",j+1,i+1);
            scanf("%f",&estudiantes[n].materias[i].calificaciones[j]);
            estudiantes[n].materias[i].promedio+=estudiantes[n].materias[i].calificaciones[j];
        }
        estudiantes[n].materias[i].promedio/=3;
    }
    n++;
}

void mostrarEstudiantes(){
    int i,j;
    for(i=0;i<n;i++){
        printf("Nombre del estudiante: %s\n",estudiantes[i].nombre);
        printf("Matricula del estudiante: %d\n",estudiantes[i].matricula);
        printf("Grupo del estudiante: %s\n",estudiantes[i].grupo);
        for(j=0;j<estudiantes[i].cantidad;j++){
            printf("Nombre de la materia %d: %s\n",j+1,estudiantes[i].materias[j].nombre);
            printf("Horario de la materia %d: %s\n",j+1,estudiantes[i].materias[j].horario);
            printf("Calificaciones de la materia %d: %.2f, %.2f, %.2f\n",j+1,estudiantes[i].materias[j].calificaciones[0],estudiantes[i].materias[j].calificaciones[1],estudiantes[i].materias[j].calificaciones[2]);
            printf("Promedio de la materia %d: %.2f\n",j+1,estudiantes[i].materias[j].promedio);
        }
        printf("");
    }
}

void modificarEstudiante(){
    int i,j,matricula;
    printf("Ingrese la matricula del estudiante a modificar: \n");
    scanf("%d",&matricula);
    for(i=0;i<n;i++){
        if(estudiantes[i].matricula==matricula){
            printf("Ingrese el nombre del estudiante: \n");
            scanf("%s",estudiantes[i].nombre);
            printf("Ingrese el grupo del estudiante: \n");
            scanf("%s",estudiantes[i].grupo);
            printf("Ingrese el numero de materias: \n");
            scanf("%d",&estudiantes[i].cantidad);
            for(j=0;j<estudiantes[i].cantidad;j++){
                printf("Ingrese el nombre de la materia %d: \n",j+1);
                scanf("%s",estudiantes[i].materias[j].nombre);
                printf("Ingrese el horario de la materia %d: \n",j+1);
                scanf("%s",estudiantes[i].materias[j].horario);
                printf("Ingrese la calificacion 1 de la materia %d: \n",j+1);
                scanf("%f",&estudiantes[i].materias[j].calificaciones[0]);
                printf("Ingrese la calificacion 2 de la materia %d: \n",j+1);
                scanf("%f",&estudiantes[i].materias[j].calificaciones[1]);
                printf("Ingrese la calificacion 3 de la materia %d: \n",j+1);
                scanf("%f",&estudiantes[i].materias[j].calificaciones[2]);
                estudiantes[i].materias[j].promedio=(estudiantes[i].materias[j].calificaciones[0]+estudiantes[i].materias[j].calificaciones[1]+estudiantes[i].materias[j].calificaciones[2])/3;
            }
            break;
        }
    }
}

int main(){
    int opcion;
    do{
        printf("1 Ingresar un estudiante\n");
        printf("2 Mostrar todos los estudiantes\n");
        printf("3 Modificar un estudiante\n");
        printf("4 Salir\n");
        printf("Ingrese una opcion: \n");
        scanf("%d",&opcion);
        switch(opcion){
            case 1:
                ingresarEstudiante();
                break;
            case 2:
                mostrarEstudiantes();
                break;
            case 3:
                modificarEstudiante();
                break;
            case 4:
                printf("Adios");
                break;
            default:
                printf("Opcion invalida");
                break;
        }
    }while(opcion!=4);
    return 0;
}