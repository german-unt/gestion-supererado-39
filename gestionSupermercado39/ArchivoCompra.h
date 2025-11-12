#pragma once
#include <string>
#include "Compra.h"

class ArchivoCompra{

private:
    char _nombreArchivo[30];
public:
    ArchivoCompra(const char *nombreArchivo="ArchivoCompra.dat"); //ok
    int agregarRegistro(Compra nuevoRegistro); //ok
    bool listar(); //ok
    int modificarRegistro(Compra registro, int idCompra); //ok
    int cantidadRegistros(); //ok
    bool eliminarLogico(int idCompra); //ok
    bool listarComprasXProveedor(int CodigoProveedor); //ok
    bool listarComprasXMes(int mes); //ok
    bool listarComprasXAnio(int anio); //ok
    bool estado(int id);
    Compra leer(int numero);

};

