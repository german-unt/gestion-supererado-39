#include <iostream>
#include "Reporte.h"
#include "ArchivoProducto.h"
#include "producto.h"

using namespace std;

void menuReportes (){

ArchivoProducto arch("ArchivoProducto.dat");

Producto prod;

int total = arch.cantidadRegistros();

system ("cls");
cout << "_-_-_- REPORTES DE STOCK -_-_-_-" <<endl<< endl;

 bool hubo = false;
    for (int i = 0; i < total; i++) {
        prod = arch.leer(i);
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





