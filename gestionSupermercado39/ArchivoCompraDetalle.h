#pragma once
#include <string>
#include "compraDetalle.h"

class ArchivoCompraDetalle{

private:

    char _nombreArchivo[30];

public:

ArchivoCompraDetalle(const char *nombreArchivo="ArchivoCompraDetalle.dat");
int agregarRegistro(CompraDetalle detalle);
bool listarPorCompra(int idCompra);
int cantidadRegistros();
bool existeRegistro(int idCompra);


};
