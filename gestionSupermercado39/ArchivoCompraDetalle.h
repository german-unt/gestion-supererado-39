#pragma once
#include <string>

class ArchivoCompraDetalle{

private:

std::string _nombreArchivo;

public:

ArchivoCompraDetalle(std::string nombreArchivo);
int agregarRegistro(CompraDetalle detalle);
bool listarPorCompra(int idCompra);
int cantidadRegistros();


};
