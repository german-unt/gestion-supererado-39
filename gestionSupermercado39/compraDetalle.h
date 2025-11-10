#pragma once

class CompraDetalle {
private:
    int _idCompra;
    int _idProducto;
    int _cantidad;
    float _precioUnitario;
    float _subtotal;

public:
    // setters
    void setIdCompra(int idCompra);
    void setIdProducto(int idProducto);
    void setCantidad(int cantidad);
    void setPrecioUnitario(float precio);
    void setSubtotal();
    // getters
    int getIdCompra();
    int getIdProducto();
    int getCantidad();
    float getPrecioUnitario();
    float getSubtotal();

    void mostrar();
};
