#include <iostream>
#include "CompraDetalle.h"

using namespace std;

void CompraDetalle::setIdCompra(int idCompra) { _idCompra = idCompra; }
void CompraDetalle::setIdProducto(int idProducto) { _idProducto = idProducto; }
void CompraDetalle::setCantidad(int cantidad) { _cantidad = cantidad; }
void CompraDetalle::setPrecioUnitario(float precio) { _precioUnitario = precio; }
void CompraDetalle::setSubtotal() { _subtotal = _cantidad * _precioUnitario; }

int CompraDetalle::getIdCompra()  { return _idCompra; }
int CompraDetalle::getIdProducto()  { return _idProducto; }
int CompraDetalle::getCantidad()  { return _cantidad; }
float CompraDetalle::getPrecioUnitario()  { return _precioUnitario; }
float CompraDetalle::getSubtotal()  { return _subtotal; }


void CompraDetalle::mostrar(){
    cout << "ID COMPRA: " << getIdCompra() << endl;
    cout << "ID PRODUCTO: " << getIdProducto() << endl;
    cout << "PRECIO UNITARIO: " << getPrecioUnitario() << endl;
    cout << "CANTIDAD: " << getCantidad() << endl;
    cout << "SUBTOTAL: " <<getSubtotal() << endl;
    cout << "*******************************************" << endl;
}
