#pragma once
#include "fecha.h"

class Venta{
private:
    int _idVenta;
    int _idVendedor;
    Fecha _fecha;
    float _total = 0;
    bool _anulada = false;

public:
    void setIdVenta(int idVenta);
    void setIdVendedor(int idVendedor);
    void setFecha(int dia, int mes, int anio);
    void setTotal(float total);
    void setEstado(bool estado);

    ///getters
    int getIdVenta();
    int getIdVendedor();
    std::string getFechatoString();
    Fecha getFecha();
    float getTotal();
    bool getEstado();

    void mostrarVenta();
    void sumarAlTotal(float subtotal);
};



