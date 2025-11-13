#pragma once

class VentaDetalle{
    private:
    int _idVenta;
    int _idProducto = 0;
    int _cantidad;
    float _precioUnitario = 0;
    float _subtotal;
    bool _anulada = false ;
public:
    void setIdVenta(int idVenta);
    void setIdProducto(int idProducto);
    void setCantidad(int cantidad);
    void setPrecioUnitario(float precio);
    void setSubtotal();
    void setEstado(bool anulada);
    int getIdVenta();
    int getIdProducto();
    int getCantidad();
    float getPrecioUnitario();
    float getSubtotal();
    bool getEstado();
    void mostrarVentaDetalle();
    VentaDetalle cargarVentaDetalle(int idVenta);
};
