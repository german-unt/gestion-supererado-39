#include <iostream>
#include "menuCompras.h"
#include "compra.h"
#include "compraDetalle.h"
#include "ArchivoCompra.h"
#include "ArchivoCompraDetalle.h"
using namespace std;

void menuCompras() {
    ArchivoCompra archiC;
    ArchivoCompraDetalle archiCD;
    CompraDetalle comprDet;
    Compra regis;
    int opc;

    do {
        system("cls");
        cout << "==========================" << endl;
        cout << "     MENU DE COMPRAS " << endl;
        cout << "==========================" << endl;
        cout << "1) Agregar compra" << endl;
        cout << "2) Listar compras" << endl;
        cout << "3) Listar detalle de compra" << endl;
        cout << "4) Eliminar compra" << endl;
        cout << "5) Listar compra por mes" << endl;
        cout << "6) Listar compra por anio" << endl;
        cout << "0) Volver" << endl;
        cout << "Opcion: ";
        cin >> opc;

        switch (opc) {
        case 1:
            {
              system("cls");
            regis = regis.cargarCompra();
            int seguir = 1;
            do {
                comprDet = comprDet.cargarCompraDetalle(regis.getIdCompra());
                regis.sumarAlTotal(comprDet.getSubtotal());
                archiCD.agregarRegistro(comprDet);
                cout << "Agregar otro detalle? (1=si, 0=no): ";
                cin >> seguir;
            } while(seguir == 1);

            archiC.agregarRegistro(regis);
            cout << "Compra guardada. Total: " << regis.getTotal() << endl;
            system("pause");
                break;
            }

        case 2:
            system("cls");
            cout << "==========================" << endl;
            cout << "   LISTADO DE COMPRAS: " << endl;
            cout << "==========================" << endl;
            regis.mostrarTodos();
            break;

        case 3: {
            system("cls");
            int id;
            cout << "Ingrese el id de la compra a detallar: ";
            cin >> id;
            bool ok = archiCD.existeRegistro(id);
            bool eliminado = archiC.estado(id);
            if(!ok){
                cout << "El id ingresado no se encuenta" <<endl;
            }else if(eliminado){
                cout << "La compra se encuentra eliminada " << endl;
            }else{
                archiCD.listarPorCompra(id);
            }
            system("pause");
            }
            break;

        case 4: {
            system("cls");
            int id;
            cout << "Ingrese el id de la compra a eliminar: ";
            cin >> id;
            bool ok = archiCD.existeRegistro(id);
            if(!ok) {
                cout << "El id ingresado no se encuenta" <<endl;
            }else if(archiC.estado(id)){
                    cout << "El archivo ya se elimino anteriormente" << endl;
            } else {
                bool eliminado = archiC.eliminarLogico(id);
                if(eliminado){
                    cout << "Eliminado" << endl;
                }else{
                    cout << "No se pudo eliminar " << endl;
                }
            }
                system("pause");
            }
            break;
        case 5:
            system("cls");
            int mes;
            cout << "Ingrese el mes: ";
            cin >> mes;
            archiC.listarComprasXMes(mes);
            system("pause");
            break;
        case 6:
            system("cls");
            int anio;
            cout << "Ingrese el anio: ";
            cin >> anio;
            archiC.listarComprasXAnio(anio);
            system("pause");
            break;
        case 0: break;
        default:
            cout << "Opción inválida." << endl;
            system("pause");
            break;
        }
    } while(opc != 0);
}
