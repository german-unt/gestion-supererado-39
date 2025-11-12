#pragma once
#include "fecha.h"


class Venta{
private:
    int _idVenta;
    int _idVendedor;
    Fecha _fecha;
    float _total = 0;
    bool _eliminada = false;

public:
    void setIdVenta(int idVenta);
    void setIdVendedor(int idVendedor);
    void setFecha(Fecha fecha);
    void setTotal(float total);
    void setEstado(bool estado);

    ///getters
    int getIdVenta();
    int getIdVendedor();
    std::string getFechatoString();
    Fecha getFecha();
    float getTotal();
    bool getEstado();

    void mostrarTodos();
    void mostrarVenta(Venta venta);
    void sumarAlTotal(float subtotal);
    Venta cargarVenta();
};



