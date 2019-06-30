#ifndef ESTRUCTURADOS_H_INCLUDED
#define ESTRUCTURADOS_H_INCLUDED


typedef struct
{
    int id;
    char nombre[51];
    char nacionalidad[21];
    int datoOcupado;
} sActores;


int inicializarEstadoActores(sActores* arrayActores, int capacidad);
int buscarLibreActores(sActores* arrayActores, int capacidad);
int datoCargadoActores(sActores* arrayActores, int capacidad);
int encontrarActorPorID(sActores* arrayActores, int capacidad, int id);
int agregarActor(sActores* arrayActores, int capacidad);
void ordenarActoresPorNacionalidad(sActores* listaActores, int cantidad);
void mostrarListaActores(sActores* arrayActores, int cantidad);
int eliminarActor(sActores* arrayActores, int capacidad);
void modificarActores(sActores* arrayActores, int capacidad);

#endif // ESTRUCTURADOS_H_INCLUDED
