#ifndef ARCHIVOCATEGORIA_H_INCLUDED
#define ARCHIVOCATEGORIA_H_INCLUDED
#include "categoria.h"
class ArchivoCategoria{

    private:
        char _nombreArchivo[30];

    public:
    ArchivoCategoria(const char *nombreArchivo="ArchivoCategoria.dat"); //ok
    int agregarRegistro(Categoria nuevoRegistro); //ok
    int modificarRegistro(Categoria nuevoRegistro, int idCategoria); //ok
    int cantidadRegistros(); //ok
    bool listar(); //ok
    bool eliminarLogico(int idCategoria); //ok
    Categoria leer(int numero);

    };


#endif // ARCHIVOCATEGORIA_H_INCLUDED
