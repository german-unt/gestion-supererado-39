#pragma once
#include <string>
#include "fecha.h"




class Compra{

private:

 int _idCompra;
 int _idProveedor;
 Fecha _fecha;
 float _total;
 bool _anulada = false;


public:
    ///setters
    void setIdCompra(int idCompra);
    void setIdProveedor(int idProveedor);
    void setFecha(int dia, int mes, int anio);
    void setTotal(float total);
    void setEstado(bool estado);

    ///getters
    int getIdCompra();
    int getIdProveedor();
    std::string getFechatoString();
    Fecha getFecha();
    float getTotal();
    bool getEstado();

    void mostrarCompra();

};




