#include <stdio.h>
#include <string.h>

#define MAX_PERSONAS 2
#define MAX_NOMBRE 50
#define MAX_CALIFICACIONES 10

typedef struct {
    char nombre[MAX_NOMBRE];
    int calificaciones[MAX_CALIFICACIONES];
    int num_calificaciones;
} Persona;

Persona personas[MAX_PERSONAS];
int contador_personas = 0;

void crear_persona(const char nombre[]) {
    if (contador_personas < MAX_PERSONAS) {
        strncpy(personas[contador_personas].nombre, nombre, MAX_NOMBRE);
        personas[contador_personas].nombre[MAX_NOMBRE - 1] = '\0'; 
        personas[contador_personas].num_calificaciones = 0;
        contador_personas++;
        printf("Persona agregada con exito.\n");
    } else {
        printf("La lista de personas esta llena.\n");
    }
}

void agregar_calificacion(int indice, int calificacion) {
    if (indice >= 0 && indice < contador_personas) {
        if (personas[indice].num_calificaciones < MAX_CALIFICACIONES) {
            personas[indice].calificaciones[personas[indice].num_calificaciones] = calificacion;
            personas[indice].num_calificaciones++;
            printf("Calificacion agregada con exito.\n");
        } else {
            printf("No se pueden agregar mas calificaciones.\n");
        }
    } else {
        printf("indice no valido.\n");
    }
}

void listar_personas() {
    if (contador_personas == 0) {
        printf("No hay personas en la lista.\n");
    } else {
        for (int i = 0; i < contador_personas; i++) {
            printf("Persona %d: Nombre: %s, Calificaciones: ", i + 1, personas[i].nombre);
            for (int j = 0; j < personas[i].num_calificaciones; j++) {
                printf("%d ", personas[i].calificaciones[j]);
            }
            printf("\n");
        }
    }
}

void actualizar_persona(int indice, const char nombre[]) {
    if (indice >= 0 && indice < contador_personas) {
        strncpy(personas[indice].nombre, nombre, MAX_NOMBRE);
        personas[indice].nombre[MAX_NOMBRE - 1] = '\0';
        printf("Persona actualizada con exito.\n");
    } else {
        printf("indice no valido.\n");
    }
}

void borrar_persona(int indice) {
    if (indice >= 0 && indice < contador_personas) {
        for (int i = indice; i < contador_personas - 1; i++) {
            personas[i] = personas[i + 1];
        }
        contador_personas--;
        printf("Persona eliminada con exito.\n");
    } else {
        printf("indice no valido.\n");
    }
}

int main() {
    crear_persona("Lazaro");
    crear_persona("Lupita");

    printf("Agregando calificaciones...\n");
    agregar_calificacion(0, 10);
    agregar_calificacion(1, 8);

    printf("Lista de personas:\n");
    listar_personas();

    printf("\nActualizando el nombre de la primera persona a Lazaro...\n");
    actualizar_persona(0, "Lilian");

    printf("\nLista de personas despues de actualizar:\n");
    listar_personas();

    printf("\nEliminando la segunda persona...\n");
    borrar_persona(1);

    printf("\nLista de personas despues de eliminar:\n");
    listar_personas();

    return 0;
}