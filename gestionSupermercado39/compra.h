#pragma once
#include <string>
#include "fecha.h"




class Compra{

private:

 int _idCompra;
 int _idProveedor;
 Fecha _fecha;
 float _importe;
 int _idProducto;
 int _cantidad;

public:
    ///setters
    void setIdCompra(int idCompra);
    void setIdProveedor(int idProveedor);
    void setFecha(int dia, int mes, int anio);
    void setImporte(float importe);
    void setIdProducto(int idProducto);
    void setCantidad(int cantidad);

    ///getters
    int getIdCompra();
    int getIdProveedor();
    string getFecha();
    float getImporte();
    int getIdProducto();
    int getCantidad();

    void mostrarProducto();

};




