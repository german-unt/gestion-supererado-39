#pragma once

class VentaDetalle{
    private: int _idVenta;
    int _idProducto;
    int _cantidad;
    float _precioUnitario;
    float _subtotal;
public:
    void setIdVenta(int idVenta);
    void setIdProducto(int idProducto);
    void setCantidad(int cantidad);
    void setPrecioUnitario(float precio);
    void setSubtotal();
    int getIdVenta();
    int getIdProducto();
    int getCantidad();
    float getPrecioUnitario();
    float getSubtotal();
    void mostrarVentaDetalle();
};
