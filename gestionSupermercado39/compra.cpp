#include <string>
#include <iostream>
#include "compra.h"
#include "fecha.h"
#include "ArchivoCompra.h"
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


void Compra::setFecha(Fecha fecha){
    _fecha = fecha;
}


void Compra::setTotal(float total){_total = total;  }


void Compra::setEstado(bool estado){_eliminada  = estado; }

///getters
int Compra::getIdCompra(){return _idCompra; }
int Compra::getIdProveedor(){return _idProveedor;   }
string Compra::getFechatoString(){return _fecha.toString();    }
Fecha Compra::getFecha(){return _fecha;}
float Compra::getTotal(){return _total; }
bool Compra::getEstado(){return _eliminada;   }



void Compra::sumarAlTotal(float subtotal){ _total += subtotal; }

void Compra::mostrarCompra(Compra reg){
    cout << "ID COMPRA: " << reg.getIdCompra() << endl;
    cout << "ID PROVEEDOR: " << reg.getIdProveedor() << endl;
    cout << "FECHA: " << reg.getFechatoString() << endl;
    cout << "TOTAL: " << reg.getTotal() << endl;
    cout << "===========================================" << endl;
}

void Compra::mostrarTodos(){
    ArchivoCompra archi;
    Compra reg;
    int cantidadRegis = archi.cantidadRegistros();
    if(cantidadRegis < 0){
        cout << "- No existen Compras." << endl;
    }else{
        for(int i = 0; i< cantidadRegis; i++){
            reg = archi.leer(i);
            if(!reg.getEstado()){
                mostrarCompra(reg);
            }
        }
    }
    system("pause");
}



Compra Compra::cargarCompra() {
    Compra compra;
    ArchivoCompra archiC;
    int idProveedor;
    Fecha fecha;
    bool eliminada = false;

    int idCompra = compra.asignarId();
    compra.setIdCompra(idCompra);


    cout << "ID de proveedor: ";
    cin >> idProveedor;
    compra.setIdProveedor(idProveedor);

    cout << "Fecha de la compra:" << endl;
    fecha.Cargar();
    compra.setFecha(fecha);

    compra.setTotal(0);
    compra.setEstado(eliminada);

    return compra;
}


int Compra::asignarId(){
     ArchivoCompra archiC;
     int idMax = 0;
     int total = archiC.cantidadRegistros();
     for(int i=0; i<total; i++) {
        Compra c = archiC.leer(i);
        if(c.getIdCompra() > idMax){
            idMax = c.getIdCompra();
        }
    }
     return idMax+1;
}


