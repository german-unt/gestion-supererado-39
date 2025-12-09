#include <iostream>
#include "menuCategorias.h"
#include "funcionesGlobales.h"
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

    Categoria categoriaOriginal;
    bool existe = false;

    /// Buscamos si existe la categoria
    for(int i=0; i<arch.cantidadRegistros(); i++){
        categoriaOriginal = arch.leer(i);
        if(categoriaOriginal.getIdCategoria() == id && !categoriaOriginal.getEliminado()){
            existe = true;
            break;
        }
    }

    if(!existe){
        cout << "No existe una categoria con ese ID." << endl;
        system("pause");
        break;
    }

    Categoria nueva;
    char nombre[20];

    cout << "Ingrese nuevo nombre: ";
    cargarCadena(nombre,19);
    nueva.setIdCategoria(id);
    nueva.setNombre(nombre);
    nueva.setEliminado(false);

    int ok = arch.modificarRegistro(nueva,id);

    if(ok == 1) cout << "Categoria modificada correctamente." << endl;
    else        cout << "Error al modificar." << endl;

    system("pause");
} break;

        }
        cout << endl;
    } while (opc != 0);
}
