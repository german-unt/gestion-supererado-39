#include <cstring>
#include <iostream>
#include "proveedor.h"
#include "archivoProveedor.h"
using namespace std;



ArchivoProveedor::ArchivoProveedor(std::string nombreArchivo){
    _nombreArchivo = nombreArchivo;
}


int ArchivoProveedor::agregarRegistro(Proveedor registroNuevo){

    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "ab");
    if (pArchivo == nullptr){
        return -1;
    }
    int ok = fwrite(&registroNuevo,sizeof(Proveedor),1,pArchivo);
    fclose(pArchivo);
    if(ok == 1){
        return 1;
    }else{
        return -2;
    }
}


bool ArchivoProveedor::listar(){
    Proveedor registro;
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if (pArchivo == nullptr){
        return false;
    }

    while(fread(&registro, sizeof (Proveedor),1,pArchivo) == 1){
            //poner mostarProveedor;
        cout << registro.getIdProveedor() << " - " << registro.getNombre() << " - " << registro.getEstado()<< endl;
    }
    fclose(pArchivo);
    return true;
}

int ArchivoProveedor::modificarRegistro(Proveedor registro, int id){
    Proveedor registroActual;
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb+");
    if (pArchivo == nullptr){
        return -1;
    }
    int modificado = 0;
    while(fread(&registroActual, sizeof (Proveedor),1,pArchivo) == 1){
        if(registroActual.getIdProveedor() == id){
            fseek(pArchivo,-sizeof(Proveedor), SEEK_CUR);
            modificado = fwrite(&registro,sizeof(Proveedor),1,pArchivo);
            fclose(pArchivo);
            return (modificado == 1) ? 1 : -2;
        }
    }
    fclose(pArchivo);
    return 0;
}

int ArchivoProveedor::cantidadRegistros(){
    Proveedor registro;

    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if (pArchivo == nullptr){
        return -1;
    }

    fseek(pArchivo,0,SEEK_END);
    int cantidad = ftell(pArchivo) / sizeof(Proveedor);
    fclose(pArchivo);
    return cantidad;

}

bool ArchivoProveedor::eliminar(int id){

bool modificado = false;
Proveedor registroActual;
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb+");
    if (pArchivo == nullptr){
        return false;
    }

    while(fread(&registroActual, sizeof (Proveedor),1,pArchivo) == 1){
        if(registroActual.getIdProveedor() == id){
            fseek(pArchivo,-sizeof(Proveedor), SEEK_CUR);
            registroActual.setEstado(false);
            modificado = fwrite(&registroActual,sizeof(Proveedor),1,pArchivo) ? true : false;
            break;
        }
     }
     fclose(pArchivo);
     return modificado;
}


bool ArchivoProveedor::listarXnombre(){

    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if (pArchivo == nullptr){
        return false;
    }

    int registrosTotal = cantidadRegistros();
      if (registrosTotal <= 0) {
        cout << "No hay registros cargados." << endl;
        fclose(pArchivo);
        return false;
    }

    Proveedor *lista = new Proveedor[registrosTotal];
    int cantidad = 0;
    Proveedor registroActual;

     while (fread(&registroActual, sizeof(Proveedor), 1, pArchivo) == 1) {
        if (registroActual.getEstado()) { // solo los activos
            lista[cantidad] = registroActual;
            cantidad++;
        }
    }
    fclose(pArchivo);

    if (cantidad == 0) {
        cout << "No hay proveedores activos." << endl;
        delete [] lista;
        return false;
    }

    for (int i = 0; i < cantidad - 1; i++) {
        for (int j = i + 1; j < cantidad; j++) {
            if (strcmp(lista[i].getNombre().c_str(), lista[j].getNombre().c_str()) > 0) {
                Proveedor aux = lista[i];
                lista[i] = lista[j];
                lista[j] = aux;
            }
        }
    }
    cout << "=== LISTA DE PROVEEDORES ORDENADOS POR NOMBRE ===" << endl;
    for (int i = 0; i < cantidad; i++) {
        cout << lista[i].getIdProveedor() << " - "
             << lista[i].getNombre() << " - "
             << (lista[i].getEstado() ? "Activo" : "Eliminado")
             << endl;
    }

    cout << "Total de proveedores activos: " << cantidad << endl;
    delete [] lista;
    return true;

}
