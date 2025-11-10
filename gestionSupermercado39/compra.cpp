#include <string>
#include "compra.h"
#include "fecha.h"


void Compra::setIdCompra(int idCompra){
    _idCompra = idCompra;
}
void Compra::setIdProveedor(int idProveedor){
    _idProveedor = idProveedor;
}
void Compra::setFecha(int dia, int mes, int anio){
    Fecha.setDia(dia);
    Fecha.setDia(mes);
    Fecha.setDia(anio);
}
void Compra::setImporte(float importe){
    _importe = importe;
}
void Compra::setIdProducto(int idProducto){
    _idProducto = idProducto;
}
void Compra::setCantidad(int cantidad){
    _cantidad = cantidad;
}

///getters
int Compra::getIdCompra(){
    return _idCompra;
}
int Compra::getIdProveedor(){
    return _idProveedor;
}
string Compra::getFecha(){
    return Fecha.toString();
}
float Compra::getImporte(){
    return _importe;
}
int Compra::getIdProducto(){
    return _idProducto;
}
int Compra::getCantidad(){
    return _cantidad;
}


void Compra::mostrarProducto(){
    cout << "ID COMPRA: " << getIdCompra() << endl;
    cout << "ID PROVEEDOR: " << getIdProveedor() << endl;
    cout << "ID PRODUCTO: " << getIdProducto() << endl;
    cout << "FECHA: " << getFecha() << endl;
    cout << "IMPORTE: " << getImporte() << endl;
    cout << "IMPORTE TOTAL: " << getImporte() * getCantidad() << endl;
    cout << "CANTIDAD: " << getCantidad() << endl;
    cout << "*******************************************" << endl;
    }
