#pragma once
#include "proveedor.h"
#include <string>



class ArchivoProveedor{
private:
    std::string _nombreArchivo;

public:
    ArchivoProveedor(std::string nombreArchivo); //ok
    int agregarRegistro(Proveedor registroNuevo); //ok
    bool listar(); //ok
    int modificarRegistro(Proveedor registro, int id); //ok
    int cantidadRegistros(); //ok
    bool eliminar(int id); // ok
    bool listarXnombre(); //ok

};

