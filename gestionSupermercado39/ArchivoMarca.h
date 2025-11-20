#ifndef ARCHIVOMARCA_H_INCLUDED
#define ARCHIVOMARCA_H_INCLUDED
#include"marca.h"

 class ArchivoMarca{
 private:
     char _nombreArchivo[30];

 public:

    ArchivoMarca(const char *nombreArchivo="ArchivoMarca.dat"); //ok
    int agregarRegistro(Marca nuevoRegistro); //ok
    int modificarRegistro(Marca nuevoRegistro, int idMarca); //ok
    int cantidadRegistros(); //ok
    bool listar(); //ok
    bool eliminarLogico(int idMarca); //ok
    Marca leer(int numero);



 };

#endif // ARCHIVOMARCA_H_INCLUDED
