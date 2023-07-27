#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Estudiante {
    int codigo;
    char nombre[50];
    char carrera[50];
    float calificaciones[3];
    float promedio;
};

int comparar_estudiantes(const void *a, const void *b) {
    const struct Estudiante *est1 = (struct Estudiante *)a;
    const struct Estudiante *est2 = (struct Estudiante *)b;
    return (est1->promedio > est2->promedio) - (est1->promedio < est2->promedio);
}

int main() {
    FILE *archivo_entrada, *archivo_salida;
    char linea[100];
    struct Estudiante estudiantes[5];
    int i = 0;

    archivo_entrada = fopen("datos_estudiantes.txt", "r");
    if (archivo_entrada == NULL) {
        perror("Error al abrir el archivo de entrada");
        return 1;
    }

    while (fgets(linea, sizeof(linea), archivo_entrada) != NULL) {
        sscanf(linea, "%d;%[^;];%[^;];%f;%f;%f", &estudiantes[i].codigo, estudiantes[i].nombre, estudiantes[i].carrera,
            &estudiantes[i].calificaciones[0], &estudiantes[i].calificaciones[1], &estudiantes[i].calificaciones[2]);

        estudiantes[i].promedio = (estudiantes[i].calificaciones[0] + estudiantes[i].calificaciones[1] + estudiantes[i].calificaciones[2]) / 3.0;
        i++;
    }

    fclose(archivo_entrada);

    qsort(estudiantes, 5, sizeof(struct Estudiante), comparar_estudiantes);

    archivo_salida = fopen("resultados.txt", "w");
    if (archivo_salida == NULL) {
        perror("Error al abrir el archivo de salida");
        return 1;
    }

    for (i = 0; i < 5; i++) {
        fprintf(archivo_salida, "Código: %d\n", estudiantes[i].codigo);
        fprintf(archivo_salida, "Nombre: %s\n", estudiantes[i].nombre);
        fprintf(archivo_salida, "Carrera: %s\n", estudiantes[i].carrera);
        fprintf(archivo_salida, "Calificaciones: %.2f, %.2f, %.2f\n", estudiantes[i].calificaciones[0], estudiantes[i].calificaciones[1], estudiantes[i].calificaciones[2]);
        fprintf(archivo_salida, "Promedio: %.2f\n\n", estudiantes[i].promedio);
    }

    fclose(archivo_salida);

    printf("Datos ordenados y promedios generados. Se han guardado en el archivo resultados.txt\n");

    return 0;
}