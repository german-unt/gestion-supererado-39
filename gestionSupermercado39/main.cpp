#include <iostream>
using namespace std;
#include "menuProductos.h"
#include "menuVenta.h"
#include "menuCompras.h"


int main() {
    int opcion;
    do {
        cout << "==========================" << endl;
        cout << "  GESTION SUPERMERCADO   " << endl;
        cout << "==========================" << endl;
        cout << "1) Productos" << endl;
        cout << "2) Ventas" << endl;
        cout << "3) Compras" << endl;
        cout << "0) Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;
        switch (opcion) {
        case 1:
            system("cls");
            menuProductos();
            break;

        case 2:
            system("cls");
            menuVenta();
            break;
        case 3:
            system("cls");
            menuCompras();
            break;
        default: cout << "Opcion no valida" <<endl;
        system ("pause");
        }
        cout << endl;
        system("cls");
    } while (opcion != 0);

    return 0;
}
