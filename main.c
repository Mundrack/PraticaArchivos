#include <stdio.h>
#include <string.h>

void IngresarApodoM(char apodo[50]);
void Cedula(int *cedula);
void IngresarEdad(int *edad);
void NombreDueño(char nombred[50]);
void TipoAnimal(char tipo[50]);
void IngresarServicio(float *precio, char s[50]);
void generarFactura(int cedula, char tipo[50], float precio, char s[50], char apodo[50], int edad, char nombred[50]);
int menu(char apodo[50], float *precio, char s[50], int *cedula, char tipo[50], int *edad, char nombred[50]);

int main() {
    char apodo[50], tipo[50], nombred[50], s[200];
    int cedula, edad;
    float precio = 0.0;
    int n;

    printf("Bienvenido a la Veterinaria Alvatros.\n");
    printf("¿Qué desea hacer?\n");
    do {
        printf("\n 1.Ingresar mascota\n 2.Ingresar servicio\n 3.Generar factura\n 4.Salir\n");
        n = menu(apodo, &precio, s, &cedula, tipo, &edad, nombred);
    } while (n != 4);
    
    return 0;
}

int menu(char apodo[50], float *precio, char s[200], int *cedula, char tipo[50], int *edad, char nombred[50]) {
    int op;
    scanf("%d", &op);

    switch (op) {
        case 1:
            IngresarApodoM(apodo);
            Cedula(cedula);
            TipoAnimal(tipo);
            IngresarEdad(edad);
            NombreDueño(nombred);
            break;
        case 2:
            IngresarServicio(precio, s);
            break;
        case 3:
            generarFactura(*cedula, tipo, *precio, s, apodo, *edad, nombred);
            break;
        default:
            return op;
    }

    return op;
}

void IngresarApodoM(char apodo[50]) {
    printf("Ingrese el apodo de la mascota:\n");
    scanf("%s", apodo);
}

void Cedula(int *cedula) {
    printf("Ingrese la cédula del dueño de la mascota:\n");
    scanf("%d", cedula);
}

void TipoAnimal(char tipo[50]) {
    int opcion2;
    printf("Ingrese qué animal es la mascota:\n 1.-Perro\n 2.-Gato\n");
    scanf("%d", &opcion2);
    switch (opcion2) {
        case 1:
            strcpy(tipo, "Perro");
            break;
        case 2:
            strcpy(tipo, "Gato");
            break;
    }
}

void IngresarEdad(int *edad) {
    printf("Ingrese la edad de la mascota:\n");
    scanf("%d", edad);
}

void NombreDueño(char nombred[50]) {
    printf("Ingrese el nombre del dueño de la mascota:\n");
    scanf("%s", nombred);
}

void IngresarServicio(float *precio, char s[200]) {
    printf("Ingrese el servicio deseado:\n 1.-Consulta\n 2.-Peluquería\n 3.-Vacunación\n");
    int opcion3;
    scanf("%d", &opcion3);
    switch (opcion3) {
        case 1:
            strcat(s, "Consulta ($15), ");
            *precio += 15;
            break;
        case 2:
            strcat(s, "Peluquería ($10), ");
            *precio += 10;
            break;
        case 3:
            strcat(s, "Vacunación ($5), ");
            *precio += 5;
            break;
    }
}

void generarFactura(int cedula, char tipo[50], float precio, char s[200], char apodo[50], int edad, char nombred[50]) {
    printf("Factura generada:\n");
    printf("Cédula del dueño: %d\n", cedula);
    printf("Tipo de animal: %s\n", tipo);
    printf("Precio: $%.2f\n", precio);
    printf("Servicios solicitados:\n");
    printf("%s\n", s);
    printf("Apodo de la mascota: %s\n", apodo);
    printf("Edad de la mascota: %d\n", edad);
    printf("Nombre del dueño: %s\n", nombred);
}
