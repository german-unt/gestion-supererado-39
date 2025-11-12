#include <iostream>
#include <cstring>
#include "venta.h"
#include "ArchivoVenta.h"
using namespace std;


void Venta::setIdVenta(int idVenta){
    while (idVenta < 0 ){
        cout << "ID INVALIDO, INGRESE OTRO ID: ";
        cin >> idVenta;
    }
     _idVenta = idVenta;
}

void Venta::setIdVendedor(int idVendedor){
    while (idVendedor < 0 ){
        cout << "ID INVALIDO, INGRESE OTRO ID: ";
        cin >> idVendedor;
    }
     _idVendedor = idVendedor;
}


void Venta::setFecha(int dia, int mes, int anio){
    _fecha.setDia(dia);
    _fecha.setMes(mes);
    _fecha.setAnio(anio);
}

void Venta::setTotal(float total){
     _total = total;}
void Venta::setEstado(bool estado){
     _anulada = estado;}




///getters
int Venta::getIdVenta(){return _idVenta;}
int Venta::getIdVendedor(){return _idVendedor; }
std::string Venta::getFechatoString(){ return _fecha.toString(); }
Fecha Venta::getFecha(){return _fecha;}
float Venta::getTotal(){return _total;}
bool Venta::getEstado(){ return _anulada;}
void Venta::sumarAlTotal(float subtotal){_total+= subtotal; }



void Venta::mostrarVenta(Venta reg){
    cout << endl;
    cout << "ID VENTA: " << reg.getIdVenta() << endl;
    cout << "ID VENDEDOR: " << reg.getIdVendedor() << endl;
    cout << "FECHA: " << reg.getFechatoString() << endl;
    cout << "TOTAL: " << reg.getTotal() << endl;
    cout << "*******************************************" << endl;
}




void Venta::mostrarTodos(){
    ArchivoVenta archi;
    Venta reg;
    for(int i = 0; i< archi.cantidadRegistros(); i++){
        reg = archi.leer(i);
        mostrarVenta(reg);
    }
    system("pause");
}

Venta Venta::cargarVenta(){
    Venta venta;

    int idVenta, idVendedor;
    float total;
    Fecha fecha;
    bool anulada = false;

    cout << "ID de venta: ";
    cin >> idVenta;
    venta.setIdVenta(idVenta);

    cout << "ID de vendedor: ";
    cin >> idVendedor;
    venta.setIdVendedor(idVendedor);

    cout << "Fecha: " << endl;
    fecha.Cargar();

    venta.setTotal(0);

    venta.setEstado(anulada);

    return venta;

}



