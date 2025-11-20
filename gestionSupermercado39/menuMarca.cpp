#include <iostream>
#include "menuMarca.h"
using namespace std;



void menuMarca() {
    ArchivoMarca arch("ArchivoMarca.dat");
    Marca reg;
    int opc;
    do {
        system("cls");
        cout << "----- MENU MARCAS -----" << endl;
        cout << "1) Cargar Marca" << endl;
        cout << "2) Listar Marca" << endl;
        cout << "3) eliminar marca" << endl;
        cout << "4) modificar marca" << endl;
        cout << "0) Volver" << endl;
        cout << "Opcion: ";
        cin >> opc;
        switch (opc) {
        case 1: {
            system("cls");
            reg = reg.cargarMarca();
            int ok = arch.agregarRegistro(reg);
            if (ok == 1) {
                cout << "Marca guardada." << endl;
            } else {
                cout << "ERROR al guardar." << endl;
            }
            system("pause");
        } break;
        case 2: {
            system("cls");
            cout << "LISTADO DE Marca" << endl;
            reg.mostrarTodos() ;
        } break;

        }
        cout << endl;
    } while (opc != 0);
}
