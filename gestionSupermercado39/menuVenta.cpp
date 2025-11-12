#include <iostream>
#include "menuVenta.h"
#include "venta.h"
#include "ventaDetalle.h"
#include "ArchivoVenta.h"
#include "ArchivoVentaDetalle.h"
using namespace std;

void menuVenta(){
    ArchivoVenta archiV;
    ArchivoVentaDetalle archiVD;
    VentaDetalle venDet;
    Venta v;
    int opc;

    do {
        system("cls");
        cout << "--- MENU DE VENTAS ---" << endl;
        cout << "1) Agregar venta" << endl;
        cout << "2) Listar ventas" << endl;
        cout << "3) Listar venta detallada" << endl;
        cout << "4) Eliminar venta detallada" << endl;
        cout << "0) Volver" << endl;
        cout << "Opcion: ";
        cin >> opc;

        switch (opc) {
        case 1: {
            system("cls");

            v = v.cargarVenta();

            int seguir = 1;
            do {
                venDet = venDet.cargarVentaDetalle(v.getIdVenta());
                v.sumarAlTotal(venDet.getSubtotal());
                archiVD.agregarRegistro(venDet);

                cout << "Agregar otro detalle? (1=si, 0=no): ";
                cin >> seguir;
            } while(seguir == 1);

            archiV.agregarRegistro(v);
            cout << "Venta guardada. Total: " << v.getTotal() << endl;
            system("pause");
            break;
        }

        case 2:
            system("cls");
            v.mostrarTodos();
            break;
        case 3:{
                    system("cls");
                    int id;
                    cout << "Ingrese el id de la venta a detallar: ";
                    cin >> id;
                    bool ok = archiVD.existeRegistro(id);
                    bool eliminado = archiV.estado(id);
                    if(!ok){
                        cout << "El id ingresado no se encuenta" <<endl;
                    }else if(eliminado){
                        cout << "La venta se encuentra eliminada " << endl;
                    }else{
                        archiVD.listarPorVenta(id);
                    }
                    system("pause");
                }
            break;
        case 4:
            {
                system("cls");
                int id;
                cout << "Ingrese el id de la venta a eliminar: ";
                cin >> id;
                bool ok = archiVD.existeRegistro(id);
                if(!ok){
                    cout << "El id ingresado no se encuenta" <<endl;
                }else if(archiV.estado(id)){
                    cout << "El archivo ya se elimino anteriormente" << endl;
                }else{
                    bool elimnado  = archiV.eliminarLogico(id);
                    if(elimnado){
                        cout << "Eliminado" << endl;
                    }else{
                        cout << "No se pudo eliminar " << endl;
                    }
                }
                system("pause");
            }
            break;
        case 0: break;
        default: cout << "Opcion invalida." << endl; break;
        }

    } while (opc != 0);
}
