#include <iostream>
#include "menu.h"
#include "Reporte.h"
using namespace std;

int menu() {
    int opcion;
    do {
        cout << "==========================" << endl;
        cout << "  GESTION SUPERMERCADO    " << endl;
        cout << "==========================" << endl;
        cout << "1) Productos" << endl;
        cout << "2) Ventas" << endl;
        cout << "3) Compras" << endl;
        cout << "4) Reportes" << endl;
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
        case 4:
            system("cls");
            menuReportes();
            break;
        case 0:
            system("cls");
            cout << "Gracias por utilizar nuestro sistema!" << endl;
            system("pause");
            break;
        default: cout << "Opcion no valida" <<endl;
        system ("pause");
        }
        cout << endl;
        system("cls");
    } while (opcion != 0);
    return 0;
}


