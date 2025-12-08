#include <iostream>
#include "menuMarca.h"
#include "funcionesGlobales.h"
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
        case 3: { /// ELIMINAR MARCA
    system("cls");
    int id;
    cout << "Ingrese ID de la marca a eliminar: ";
    cin >> id;

    bool ok = arch.eliminarLogico(id);

    if(ok){
        cout << "Marca eliminada correctamente." << endl;
    }else{
        cout << "No se pudo eliminar (ID inexistente o ya eliminada)." << endl;
    }
    system("pause");
} break;

case 4: { /// MODIFICAR MARCA
    system("cls");
    int id;
    cout << "Ingrese ID a modificar: ";
    cin >> id;

    Marca marcaOriginal;
    bool existe = false;

    /// Buscamos si existe la marca
    for(int i=0; i<arch.cantidadRegistros(); i++){
        marcaOriginal = arch.leer(i);
        if(marcaOriginal.getIdMarca() == id && !marcaOriginal.getEliminado()){
            existe = true;
            break;
        }
    }

    if(!existe){
        cout << "No existe una marca con ese ID." << endl;
        system("pause");
        break;
    }

    Marca nueva;
    char nombre[20];

    cout << "Ingrese nuevo nombre: ";
    cargarCadena(nombre,19);
    nueva.setIdMarca(id);
    nueva.setNombre(nombre);
    nueva.setEliminado(false);

    int ok = arch.modificarRegistro(nueva,id);

    if(ok == 1) cout << "Marca modificada correctamente." << endl;
    else        cout << "Error al modificar." << endl;

    system("pause");
} break;
        }
        cout << endl;
    } while (opc != 0);
}






