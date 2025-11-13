#pragma once
#include "ventaDetalle.h"



class ArchivoVentaDetalle{

private:
    char _nombreArchivo[30];
public:
    ArchivoVentaDetalle(const char *nombreArchivo="ArchivoVentaDetalle.dat");
    int agregarRegistro(VentaDetalle registro);
    bool listarPorVenta(int idVenta);
    int cantidadRegistros();
    bool existeRegistro(int idVenta);

};






