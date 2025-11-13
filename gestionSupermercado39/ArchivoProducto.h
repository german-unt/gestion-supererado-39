#pragma once
#include <string>
#include "Producto.h"


class ArchivoProducto{
private:
    char _nombreArchivo[30];
public:
    ArchivoProducto(const char *nombreArchivo="ArchivoProducto.dat"); //ok
    int agregarRegistro(Producto nuevoRegistro); //ok
    int modificarRegistro(Producto nuevoRegistro, int idProducto); //ok
    int cantidadRegistros(); //ok
    bool listar(); //ok
    bool eliminarLogico(int idProducto); //ok
    //bool listarXnombre();
    //bool listarXCategoria();
    bool listarStock();
    bool existeProducto(int idProducto);
    bool buscarPorId(int idProducto, Producto &productoEncontrado);
    Producto leer(int numero);


};
