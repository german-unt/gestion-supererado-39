#pragma once
#include <string>
#include "Producto.h"


class ArchivoProducto{
private:
    std::string _nombreArchivo;
public:
    ArchivoProducto(std::string nombreArchivo); //ok
    int agregarRegistro(Producto nuevoRegistro); //ok
    int modificarRegistro(Producto nuevoRegistro, int idProducto); //ok
    int cantidadRegistros(); //ok
    bool listar(); //ok
    bool eliminarLogico(int idProducto); //ok
    bool listarXnombre();
    bool listarXCategoria();
    bool listarStock();


};
