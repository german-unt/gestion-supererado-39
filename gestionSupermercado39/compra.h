#pragma once
#include <string>
#include "fecha.h"
#include "compra.h"




class Compra{

private:

 int _idCompra;
 int _idProveedor;
 Fecha _fecha;
 float _total = 0;
 bool _eliminada = false;


public:
    ///setters
    void setIdCompra(int idCompra);
    void setIdProveedor(int idProveedor);
    void setFecha(Fecha fecha);
    void setTotal(float total);
    void setEstado(bool estado);

    ///getters
    int getIdCompra();
    int getIdProveedor();
    std::string getFechatoString();
    Fecha getFecha();
    float getTotal();
    bool getEstado();

    void mostrarCompra(Compra compra);
    void mostrarTodos();
    void sumarAlTotal(float subtotal);
    Compra cargarCompra();
};




