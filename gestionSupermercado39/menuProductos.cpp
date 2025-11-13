#include <iostream>
#include "menuProductos.h"





void menuProductos() {
    ArchivoProducto arch("ArchivoProducto.dat");
    Producto reg;
    int opc;
    do {
        system("cls");
        cout << "==========================" << endl;
        cout << "      MENU PRODUCTOS       " << endl;
        cout << "==========================" << endl;
        cout << "1) Cargar producto" << endl;
        cout << "2) Listar productos" << endl;
        cout << "3) Eliminar producto" << endl;
        cout << "4) Modificar producto" << endl;
        cout << "5) Listar Productos en stock" << endl;
        cout << "0) Volver" << endl;
        cout << "Opcion: ";
        cin >> opc;
        switch (opc) {
            case 1: {
                system("cls");
                reg = reg.cargarProducto();
                int ok = arch.agregarRegistro(reg);
                if (ok == 1) {
                    cout << "Producto guardado." << endl;
                } else {
                    cout << "ERROR al guardar." << endl;
                }
                system("pause");
            } break;
            case 2: {
                system("cls");
                cout << "==========================" << endl;
                cout << "   LISTADO DE PRODUCTOS" << endl;
                cout << "==========================" << endl;
                reg.mostrarTodos() ;
            } break;
            case 3: {
                system("cls");
                int id;
                cout << "Ingrese ID" << endl;
                cin >> id;
                bool ok = arch.eliminarLogico(id);
                if (ok) {
                    cout << "Producto eliminado correctamente." << endl;
                }else{
                    cout << "No se pudo abrir el archivo o no hay datos." << endl;
                    }
                system("pause");
                }
                break;
            case 4: {
                    system("cls");
                    int id;
                    cout << "Ingrese ID: ";
                    cin >> id;

                    if (!arch.existeProducto(id)) {
                        cout << "No existe un producto con ese ID." << endl;
                    } else {
                        reg = reg.cargarProductoModificado(id);

                        int ok = arch.modificarRegistro(reg, id);
                        if (ok == 1) {
                            cout << "Producto modificado correctamente." << endl;
                        } else if (ok == -1) {
                            cout << "Error al abrir el archivo." << endl;
                        } else if (ok == -2) {
                            cout << "Error al escribir en el archivo." << endl;
                        } else {
                            cout << "Error al modificar el registro." << endl;
                        }
                    }

                    system("pause");
                }
                break;
            case 5:
                    system("cls");
                    cout << "           Productos en stock: " << endl;
                    cout << "*****************************************" << endl;
                    if(!arch.listarStock()){
                        cout << "- No existen productos en stock" << endl;
                        cout << "-----------------------------------------" << endl;
                    }
                    system("pause");
                    break;
                }


    }while (opc != 0);
}
