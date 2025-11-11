#include <iostream>
#include "ventaDetalle.h"
using namespace std;



void ventaDetalle::setIdVenta(int idVenta){_idVenta = idVenta;}
void ventaDetalle::setIdProducto(int idProducto){_idProducto = idProducto;}
void ventaDetalle::setCantidad(int cantidad){_cantidad = cantidad;}
void ventaDetalle::setPrecioUnitario(float precio){_precioUnitario = precio;}
void ventaDetalle::setSubtotal(){_subtotal = _precioUnitario * _cantidad;}


int ventaDetalle::getIdVenta(){return _idVenta; }
int ventaDetalle::getIdProducto(){return _idProducto; }
int ventaDetalle::getCantidad(){return _cantidad; }
float ventaDetalle::getPrecioUnitario(){return _precioUnitario; }
float ventaDetalle::getSubtotal(){return _subtotal; }


void ventaDetalle::mostrarVentaDetalle(){
    cout << "ID VENTA: " << getIdVenta() << endl;
    cout << "ID PRODUCTO: " << getIdProducto() << endl;
    cout << "PRECIO UNITARIO: " << getPrecioUnitario() << endl;
    cout << "CANTIDAD: " << getCantidad() << endl;
    cout << "SUBTOTAL: " <<getSubtotal() << endl;
    cout << "*******************************************" << endl;
}
