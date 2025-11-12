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


void Venta::setFecha(Fecha fecha){
    _fecha = fecha;
}

void Venta::setTotal(float total){
     _total = total;
}

void Venta::setEstado(bool estado){
     _eliminada = estado;
}




///getters
int Venta::getIdVenta(){return _idVenta;}
int Venta::getIdVendedor(){return _idVendedor; }
std::string Venta::getFechatoString(){ return _fecha.toString(); }
Fecha Venta::getFecha(){return _fecha;}
float Venta::getTotal(){return _total;}
bool Venta::getEstado(){ return _eliminada;}
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
        if(!reg.getEstado()){
            mostrarVenta(reg);
        }
    }
    system("pause");
}

Venta Venta::cargarVenta(){
    Venta venta;
    ArchivoVenta archiV;
    int idVenta, idVendedor;
    float total;
    Fecha fecha;
    bool eliminada = false;

    idVenta = archiV.cantidadRegistros()+1;
    venta.setIdVenta(idVenta);

    cout << "ID de vendedor: ";
    cin >> idVendedor;
    venta.setIdVendedor(idVendedor);

    cout << "Fecha: " << endl;
    fecha.Cargar();
    venta.setFecha(fecha);

    venta.setTotal(0);

    venta.setEstado(eliminada);

    return venta;

}




