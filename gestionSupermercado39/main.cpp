#include <iostream>
using namespace std;

#include "producto.h"
#include "ArchivoProducto.h"
// si tenés también compra, podés agregar:
// #include "compra.h"
// #include "ArchivoCompra.h"

void menuProductos() {
    ArchivoProducto arch("ArchivoProducto.dat");
    int opc;
    do {
        cout << "----- MENU PRODUCTOS -----" << endl;
        cout << "1) Cargar producto" << endl;
        cout << "2) Listar productos" << endl;
        cout << "3) Eliminar producto" << endl;
        cout << "4) Modificar producto" << endl;
        cout << "0) Volver" << endl;
        cout << "Opcion: ";
        cin >> opc;
        switch (opc) {
        case 1: {
            Producto reg;
            reg.cargarProducto();              // usa el que vos ya tenes
            int ok = arch.agregarRegistro(reg);
            if (ok == 1) {
                cout << "Producto guardado." << endl;
            } else {
                cout << "ERROR al guardar." << endl;
            }
        } break;
        case 2: {
            system("cls");
            cout << "LISTADO DE PRODUCTOS" << endl;
            bool ok = arch.listar();           // en tu ArchivoProducto poné que esto muestre
            if (!ok) {
                cout << "No se pudo abrir el archivo o no hay datos." << endl;
            }
        } break;
        case 3: {
            system("cls");
            int id;
            cout << "Ingrese ID" << endl;
            cin >> id;
            bool ok = arch.eliminarLogico(id);           // en tu ArchivoProducto poné que esto muestre
            if (!ok) {
                cout << "No se pudo abrir el archivo o no hay datos." << endl;
            }
        } break;
                case 4: {
            system("cls");
            int id;
            cout << "Ingrese ID" << endl;
            cin >> id;
            Producto nuevoProducto;
            nuevoProducto.cargarProducto();
            bool ok = arch.modificarRegistro(nuevoProducto, id) ;         // en tu ArchivoProducto poné que esto muestre
            if (!ok) {
                cout << "No se pudo abrir el archivo o no hay datos." << endl;
            }
        } break;
        }
        cout << endl;
    } while (opc != 0);
}
int main() {
    int opcion;
    do {
        cout << "==========================" << endl;
        cout << "  GESTION SUPERMERCADO   " << endl;
        cout << "==========================" << endl;
        cout << "1) Productos" << endl;
        // cout << "2) Compras" << endl;
        // cout << "3) Ventas" << endl;
        cout << "0) Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;
        switch (opcion) {
        case 1:
            menuProductos();
            break;
        /*
        case 2:
            menuCompras();
            break;
        */
        }
        cout << endl;
    } while (opcion != 0);

    return 0;
}
