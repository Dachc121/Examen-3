#include <stdio.h>
#include <stdlib.h>

#define max_estudiantes 10

// se define los estudiantes //

typedef struct {
    int codigo;
    char nombre[50];
    float calificaciones[5];
    float carrera;
    float promedio;
} Estudiante;

void ordenarEstudiantes(Estudiante estudiantes[], int numEstudiantes);
 int i, j;
    Estudiante temp;

    for (i = 0; i < numEstudiantes - 1; i++) {
        for (j = 0; j < numEstudiantes - i - 1; j++) {
            if (estudiantes[j].codigo < estudiantes[j + 1].codigo) {
                temp = estudiantes[j];
                estudiantes[j] = estudiantes[j + 1];
                estudiantes[j + 1] = temp;
            }
        }
    }

void calcularPromedio(Estudiante *estudiante);
    int i;
    float suma = 0;

    for (i = 0; i < 5; i++) {
        suma += estudiante->calificaciones[i];
    }

    estudiante->promedio = suma / 5.0;

void escribirArchivo(Estudiante estudiantes[], int numEstudiantes);
    FILE *archivo;
    int i;

    archivo = fopen("datos_estudiantes_ordenados.txt", "w");
    if (archivo == NULL) {
        printf("Error al abrir el archivo.");
        exit(1);
    }

    fprintf(archivo, "Código\tNombre\tCarrera\tPromedio\n");
    for (i = 0; i < numEstudiantes; i++) {
        fprintf(archivo, "%d\t%s\t%s\t%.2f\n", estudiantes[i].codigo, estudiantes[i].nombre, estudiantes[i].carrera), estudiantes[i].promedio);
    }

    fclose(archivo);


int main() {

    FILE *archivo;
    Estudiante estudiantes[max_estudiantes];
    int numEstudiantes = 0;
    archivo = fopen("datos_estudiantes.txt", "r");
    if (archivo == NULL) {
        printf("Error al abrir el archivo.");
        return 1;
    }
    while (fscanf(archivo, "%d %s %f %f %f %f %f", &estudiantes[numEstudiantes].codigo,
            estudiantes[numEstudiantes].nombre,
            &estudiantes[numEstudiantes].calificaciones[0],
            &estudiantes[numEstudiantes].calificaciones[1],
            &estudiantes[numEstudiantes].calificaciones[2],
            &estudiantes[numEstudiantes].calificaciones[3],
            &estudiantes[numEstudiantes].calificaciones[4]) != EOF) {
        calcularPromedio(&estudiantes[numEstudiantes]);
                }    numEstudiantes++;

                fclose(archivo);

       ordenarEstudiantes(estudiantes, numEstudiantes);   
           escribirArchivo(estudiantes, numEstudiantes);

    printf("Archivo generado con éxito.\n");

    return 0;            
}    