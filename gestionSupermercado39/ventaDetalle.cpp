#include <iostream>
#include "ventaDetalle.h"
using namespace std;



void VentaDetalle::setIdVenta(int idVenta){_idVenta = idVenta;}
void VentaDetalle::setIdProducto(int idProducto){_idProducto = idProducto;}
void VentaDetalle::setCantidad(int cantidad){_cantidad = cantidad;}
void VentaDetalle::setPrecioUnitario(float precio){_precioUnitario = precio;}
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
