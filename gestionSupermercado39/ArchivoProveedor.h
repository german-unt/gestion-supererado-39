#pragma once
#include "proveedor.h"
#include <string>



class ArchivoProveedor{
private:
    char _nombreArchivo[30];

public:
    ArchivoProveedor(const char *nombreArchivo="ArchivoProveedor.dat"); //ok
    int agregarRegistro(Proveedor registroNuevo); //ok
    bool listar(); //ok
    int modificarRegistro(Proveedor registro, int id); //ok
    int cantidadRegistros(); //ok
    bool eliminar(int id); // ok
    bool listarXnombre(); //ok

};

