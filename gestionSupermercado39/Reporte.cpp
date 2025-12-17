#include <iostream>
#include "Reporte.h"
#include "ArchivoProducto.h"
#include "producto.h"
#include "ArchivoVentaDetalle.h"

using namespace std;

void reporteStock (){

ArchivoProducto archP("ArchivoProducto.dat");

Producto prod;

int total = archP.cantidadRegistros();

system ("cls");
cout << "_-_-_- REPORTES DE STOCK -_-_-_-" <<endl<< endl;

 bool hubo = false;
    for (int i = 0; i < total; i++) {
        prod = archP.leer(i);
        if (prod.getEliminado()) continue;

        int stk = prod.getStock();
        if (stk == 0) {
            hubo = true;
            cout << " SIN STOCK: " << prod.getNombreProducto() << " (ID: " << prod.getIdProducto() << ")" << endl;
            cout << "    Stock: 0" << endl;
            cout << "    Vencimiento: " << prod.getFechaDeVencimiento().toString() << endl;
            cout << "-----------------------------------------" << endl;
        } else if (stk <= 5) {
            hubo = true;
            cout << " STOCK BAJO: " << prod.getNombreProducto() << " (ID: " << prod.getIdProducto() << ")" << endl;
            cout << "    Stock: " << stk << endl;
            cout << "    Vencimiento: " << prod.getFechaDeVencimiento().toString() << endl;
            cout << "-----------------------------------------" << endl;
        }
    }

    if (!hubo) {
        cout << "No se encontraron productos con stock crítico (<=5 o 0)." << endl;
    }

    cout << endl;
    system("pause");
}


void reporteProductoMenosVendido (){

ArchivoProducto archP("ArchivoProducto.dat");
Producto prod;
int cantProductos = archP.cantidadRegistros();


ArchivoVentaDetalle archV("ArchivoVentaDetalle.dat");
VentaDetalle ven;
int cantVentas = archV.cantidadRegistros();


system ("cls");
cout << "_-_-_- PRODUCTO MENOS VENDIDO -_-_-_-" <<endl<< endl;

int *vec;
vec = new int [cantProductos];

int menorIdProducto;
int menor = vec[0];

if(vec == nullptr){
    cout << "Error al asignar memoria" << endl;
    return;
}

for(int i=0; i<cantProductos; i++){
    prod = archP.leer(i);
    int acumulador = 0;

    for (int j=0; j<cantVentas; j++){
        ven = archV.leer(j);

        if(ven.getIdProducto() == prod.getIdProducto() && !ven.getEstado() && !prod.getEliminado()){


            acumulador += ven.getCantidad();

        }

    }
    vec[i] = acumulador;


}



for (int i=0; i<cantProductos; i++){
    if(vec[i] > 0){

        if(vec[i] < menor){


        menor = vec[i];
        menorIdProducto = i+1;
        }


    }

}



    prod = archP.leer(menorIdProducto-1);
    prod.mostrarProducto(prod);


system("pause");



delete []vec;

}


