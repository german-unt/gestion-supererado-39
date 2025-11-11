#include <iostream>
#include <cstdlib>  // Para system()
using namespace std;

int main() {
    int opcionPrincipal, opcionSubmenu;

    do {
        system("cls"); // Limpia la pantalla
        cout << "===== SISTEMA DE GESTION DE SUPERMERCADO =====" << endl;
        cout << "1. Compras" << endl;
        cout << "2. Ventas" << endl;
        cout << "3. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcionPrincipal;

        switch (opcionPrincipal) {
            case 1: // Submenú de Compras
                do {
                    system("cls");
                    cout << "--- MENU DE COMPRAS ---" << endl;
                    cout << "1. Agregar compra" << endl;
                    cout << "2. Modificar compra" << endl;
                    cout << "3. Eliminar compra" << endl;
                    cout << "4. Listar compras" << endl;
                    cout << "5. Volver al menu principal" << endl;
                    cout << "Opcion: ";
                    cin >> opcionSubmenu;

                    system("cls"); // Limpia antes de ejecutar la acción

                    switch (opcionSubmenu) {
                        case 1: cout << "Agregando compra..." << endl; break;
                        case 2: cout << "Modificando compra..." << endl; break;
                        case 3: cout << "Eliminando compra..." << endl; break;
                        case 4: cout << "Listado de compras..." << endl; break;
                        case 5: cout << "Volviendo al menu principal..." << endl; break;
                        default: cout << "Opcion no valida." << endl; break;
                    }

                    if (opcionSubmenu != 5) {
                        cout << "\nPresione ENTER para continuar...";
                        cin.ignore();
                        cin.get();
                    }

                } while (opcionSubmenu != 5);
                break;

            case 2: // Submenú de Ventas
                do {
                    system("cls");
                    cout << "--- MENU DE VENTAS ---" << endl;
                    cout << "1. Agregar venta" << endl;
                    cout << "2. Modificar venta" << endl;
                    cout << "3. Eliminar venta" << endl;
                    cout << "4. Listar ventas" << endl;
                    cout << "5. Volver al menu principal" << endl;
                    cout << "Opcion: ";
                    cin >> opcionSubmenu;

                    system("cls");

                    switch (opcionSubmenu) {
                        case 1: cout << "Agregando venta..." << endl; break;
                        case 2: cout << "Modificando venta..." << endl; break;
                        case 3: cout << "Eliminando venta..." << endl; break;
                        case 4: cout << "Listado de ventas..." << endl; break;
                        case 5: cout << "Volviendo al menu principal..." << endl; break;
                        default: cout << "Opcion no valida." << endl; break;
                    }

                    if (opcionSubmenu != 5) {
                        cout << "\nPresione ENTER para continuar...";
                        cin.ignore();
                        cin.get();
                    }

                } while (opcionSubmenu != 5);
                break;

            case 3:
                system("cls");
                cout << "Saliendo del sistema..." << endl;
                break;

            default:
                cout << "\nOpcion no valida, intente nuevamente." << endl;
                cout << "\nPresione ENTER para continuar...";
                cin.ignore();
                cin.get();
                break;
        }

    } while (opcionPrincipal != 3);

    cout << "\nGracias por usar el sistema de gestion." << endl;
    return 0;
}

