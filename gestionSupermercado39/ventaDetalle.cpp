#include <iostream>
#include "ventaDetalle.h"
#include "ArchivoProducto.h"
#include "producto.h"
using namespace std;



void VentaDetalle::setIdVenta(int idVenta){
    while(idVenta < 0){
        cout << "ID INVALIDO, POT FAVOR INGRESAR OTRO: ";
        cin >> idVenta;
    }
    _idVenta = idVenta;
}

void VentaDetalle::setIdProducto(int idProducto){
    while(idProducto < 0){
        cout << "ID INVALIDO, POT FAVOR INGRESAR OTRO: ";
        cin >> idProducto;
    }
    _idProducto = idProducto;
}
void VentaDetalle::setCantidad(int cantidad){
    while(cantidad < 0){
        cout << "CANTIDAD INVALIDA, POT FAVOR INGRESAR OTRA: ";
        cin >> cantidad;
    }
    _cantidad = cantidad;
}

void VentaDetalle::setPrecioUnitario(float precio){
    while(precio < 0){
        cout << "PRECIO INVALIDO, POT FAVOR INGRESAR OTRO: ";
        cin >> precio;
    }
    _precioUnitario = precio;
}

void VentaDetalle::setEstado(bool anulada){
    _anulada = anulada;
}

void VentaDetalle::setSubtotal(){_subtotal = _precioUnitario * _cantidad;}


int VentaDetalle::getIdVenta(){return _idVenta; }
int VentaDetalle::getIdProducto(){return _idProducto; }
int VentaDetalle::getCantidad(){return _cantidad; }
float VentaDetalle::getPrecioUnitario(){return _precioUnitario; }
float VentaDetalle::getSubtotal(){return _subtotal; }
bool  VentaDetalle::getEstado(){return _anulada; }


void VentaDetalle::mostrarVentaDetalle(){
    cout << "ID VENTA: " << getIdVenta() << endl;
    cout << "ID PRODUCTO: " << getIdProducto() << endl;
    cout << "PRECIO UNITARIO: " << getPrecioUnitario() << endl;
    cout << "CANTIDAD: " << getCantidad() << endl;
    cout << "SUBTOTAL: " <<getSubtotal() << endl;
    cout << "*******************************************" << endl;
}

VentaDetalle VentaDetalle::cargarVentaDetalle(int idVenta) {
    VentaDetalle reg;
    ArchivoProducto Archiproduc("ArchivoProducto.dat");
    Producto producto;

    int idProducto, cantidad;

    cout << "ID Producto: ";
    cin >> idProducto;

    bool existe = Archiproduc.buscarPorId(idProducto, producto);

    if(!existe){
        cout << "No se encuentra el producto en la lista, por favor agregue primero el producto." << endl;
        reg.setIdProducto(0); // invalidado
        reg.setCantidad(0);
        return reg;
    }

    cout << "Cantidad: ";
    cin >> cantidad;
    if (cantidad <= 0) {
        cout << "Cantidad inválida" << endl;
        reg.setIdProducto(0);
        reg.setCantidad(0);
        return reg;
    }
    if (cantidad > producto.getStock()) {
        cout << "Sin stock disponible" << endl;
        reg.setIdProducto(0);
        reg.setCantidad(0);
        return reg;
    }

    reg.setIdVenta(idVenta);
    reg.setIdProducto(idProducto);
    reg.setCantidad(cantidad);
    float precio = producto.getPrecioUnitario();
    reg.setPrecioUnitario(precio);
    cout << "Precio unitario: " << precio << endl;
    reg.setEstado(false);
    reg.setSubtotal();

    return reg;
}
