#include <iostream>
#include "menuCategorias.h"
using namespace std;





void menuCategoria() {
    ArchivoCategoria arch("ArchivoCategoria.dat");
    Categoria reg;
    int opc;
    do {
        system("cls");
        cout << "----- MENU CATEGORIAS -----" << endl;
        cout << "1) Cargar Categoria" << endl;
        cout << "2) Listar Categoria" << endl;
        cout << "3) Eliminar Categoria" << endl;
        cout << "4) Modificar Categoria" << endl;
        cout << "0) Volver" << endl;
        cout << "Opcion: ";
        cin >> opc;
        switch (opc) {
        case 1: {
            system("cls");
            reg = reg.cargarCategoria();
            int ok = arch.agregarRegistro(reg);
            if (ok == 1) {
                cout << "Categoria guardada." << endl;
            } else {
                cout << "ERROR al guardar." << endl;
            }
            system("pause");
        } break;
        case 2: {
            system("cls");
            cout << "LISTADO DE CATEGORIA" << endl;
            reg.mostrarTodos() ;
        } break;

        }
        cout << endl;
    } while (opc != 0);
}
