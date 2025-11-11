#include <iostream>
#include <cstring>
#include "venta.h"
using namespace std;


void Venta::setIdVenta(int idVenta){ _idVenta = idVenta; }
void Venta::setIdVendedor(int idVendedor){ _idVendedor = idVendedor; }
void Venta::setFecha(int dia, int mes, int anio){
    _fecha.setDia(dia);
    _fecha.setMes(mes);
    _fecha.setAnio(anio);
}
void Venta::setTotal(float total){ _total = total;}
void Venta::setEstado(bool estado){ _anulada = estado;}

///getters
int Venta::getIdVenta(){return _idVenta;}
int Venta::getIdVendedor(){return _idVendedor; }
std::string Venta::getFechatoString(){ return _fecha.toString(); }
Fecha Venta::getFecha(){return _fecha;}
float Venta::getTotal(){return _total;}
bool Venta::getEstado(){ return _anulada;}
void Venta::sumarAlTotal(float subtotal){_total+= subtotal; }

void Venta::mostrarVenta(){
    cout << "ID VENTA: " << getIdVenta() << endl;
    cout << "ID VENDEDOR: " << getIdVendedor() << endl;
    cout << "FECHA: " << getFechatoString() << endl;
    cout << "TOTAL: " << getTotal() << endl;
    cout << "*******************************************" << endl;
}
