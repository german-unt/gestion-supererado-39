#pragma once
#include "venta.h"

class ArchivoVenta{

private:
    char _nombreArchivo[30];
public:
    ArchivoVenta(const char *nombreArchivo="ArchivoVenta.dat");
    int agregarRegistro(Venta nuevoRegistro);
    bool listar();
    int modificarRegistro(Venta registro, int idVenta);
    int cantidadRegistros();
    bool eliminarLogico(int idVenta);
    Venta leer(int numero);
};




