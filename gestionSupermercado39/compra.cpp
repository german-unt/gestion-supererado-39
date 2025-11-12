#include <string>
#include <iostream>
#include "compra.h"
#include "fecha.h"
using namespace std;

void Compra::setIdCompra(int idCompra){
    while (idCompra < 0){
        cout << "ID INVALIDO, POR FAVOR INGRESE OTRO: ";
        cin >> idCompra;
    }
    _idCompra = idCompra;
}


void Compra::setIdProveedor(int idProveedor){
        while (idProveedor < 0){
        cout << "ID INVALIDO, POR FAVOR INGRESE OTRO: ";
        cin >> idProveedor;
    }
    _idProveedor = idProveedor;
}


void Compra::setFecha(int dia, int mes, int anio){
    _fecha.setDia(dia);
    _fecha.setMes(mes);
    _fecha.setAnio(anio);
}


void Compra::setTotal(float total){_total = total;  }


void Compra::setEstado(bool estado){_anulada  = estado; }

///getters
int Compra::getIdCompra(){return _idCompra; }
int Compra::getIdProveedor(){return _idProveedor;   }
string Compra::getFechatoString(){return _fecha.toString();    }
Fecha Compra::getFecha(){return _fecha;}
float Compra::getTotal(){return _total; }
bool Compra::getEstado(){return _anulada;   }



void Compra::sumarAlTotal(float subtotal){ _total += subtotal; }

void Compra::mostrarCompra(){
    cout << "ID COMPRA: " << getIdCompra() << endl;
    cout << "ID PROVEEDOR: " << getIdProveedor() << endl;
    cout << "FECHA: " << getFechatoString() << endl;
    cout << "TOTAL: " << getTotal() << endl;
    cout << "*******************************************" << endl;
}




