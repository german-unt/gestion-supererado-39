#include <iostream>
#include "menuReportes.h"
#include "Reporte.h"

using namespace std;

void menuReportes(){
    int opcion;

     do{
        system("cls");
        cout << "----- MENU REPORTES -----" << endl;
        cout << "1) Reporte de stock critico" << endl;
        cout << "2) Producto menos vendido" << endl;
        cout << "0) Volver" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        switch(opcion){
            case 1:
                reporteStock();
                break;

            case 2:
                reporteProductoMenosVendido();
                break;


            default:
                cout << "Opcion invalida" << endl;
                system("pause");
                break;
        }

    }while(opcion != 0);
}

