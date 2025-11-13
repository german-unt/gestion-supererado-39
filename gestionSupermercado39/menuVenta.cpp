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
        cout << "5) Listar por anio" << endl;
        cout << "0) Volver" << endl;
        cout << "Opcion: ";
        cin >> opc;

        switch (opc) {
            case 1: {
                system("cls");
                Venta reg;
                reg = reg.cargarVenta();

                int seguir = 1;
                bool huboDetalleValido = false; // NUEVO: inicializamos en false
                reg.setTotal(0);

                do {
                    venDet = venDet.cargarVentaDetalle(reg.getIdVenta());


                    if (venDet.getIdProducto() != 0 && venDet.getCantidad()>0 ) {
                        reg.sumarAlTotal(venDet.getSubtotal());
                        archiVD.agregarRegistro(venDet);
                        huboDetalleValido = true;
                    }

                    cout << "Agregar otro detalle? (1=si, 0=no): ";
                    cin >> seguir;
                } while(seguir == 1);

                if (huboDetalleValido) {
                    archiV.agregarRegistro(reg);
                    cout << "Venta guardada. Total: " << reg.getTotal() << endl;
                } else {
                    cout << "No se registro ninguna venta porque no hay detalles validos cargados." << endl;
                }
                system("pause");
                }
                break;


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
        case 5:
            system("cls");
            int anio;
            cout << "Ingrese el anio: ";
            cin >> anio;
            archiV.listarPorAnio(anio);
            system("pause");
            break;
        case 0: break;
        default: cout << "Opcion invalida." << endl; break;
        }

    } while (opc != 0);
}
