#include <iostream>
#include "ventaDetalle.h"
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

void VentaDetalle::setSubtotal(){_subtotal = _precioUnitario * _cantidad;}


int VentaDetalle::getIdVenta(){return _idVenta; }
int VentaDetalle::getIdProducto(){return _idProducto; }
int VentaDetalle::getCantidad(){return _cantidad; }
float VentaDetalle::getPrecioUnitario(){return _precioUnitario; }
float VentaDetalle::getSubtotal(){return _subtotal; }


void VentaDetalle::mostrarVentaDetalle(){
    cout << "ID VENTA: " << getIdVenta() << endl;
    cout << "ID PRODUCTO: " << getIdProducto() << endl;
    cout << "PRECIO UNITARIO: " << getPrecioUnitario() << endl;
    cout << "CANTIDAD: " << getCantidad() << endl;
    cout << "SUBTOTAL: " <<getSubtotal() << endl;
    cout << "*******************************************" << endl;
}

VentaDetalle VentaDetalle::cargarVentaDetalle(int idVenta){
    VentaDetalle reg;
    int idProducto, cantidad;
    float precio;

    reg.setIdVenta(idVenta);

    cout << "ID Producto: ";
    cin >> idProducto;
    reg.setIdProducto(idProducto);

    cout << "Cantidad: ";
    cin >> cantidad;
    reg.setCantidad(cantidad);

    cout << "Precio unitario: ";
    cin >> precio;
    reg.setPrecioUnitario(precio);

    reg.setSubtotal();

    return reg;

}
