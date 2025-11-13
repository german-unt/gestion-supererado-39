#include <cstdio>
#include <cstring>
#include <iostream>
#include "ArchivoVentaDetalle.h"
#include "ventaDetalle.h"
#include "ArchivoProducto.h"
#include "Producto.h"


ArchivoVentaDetalle::ArchivoVentaDetalle(const char *nombreArchivo){
    std::strcpy(_nombreArchivo, nombreArchivo);
}

int ArchivoVentaDetalle::agregarRegistro(VentaDetalle registro){

    ArchivoProducto archiProducto;
    Producto prod;

  bool encontrado = archiProducto.buscarPorId(registro.getIdProducto(), prod);


    if (!encontrado) {
        cout << "Producto no encontrado." << endl;
        return -1;
    }

    if (registro.getCantidad() <= 0) {
        cout << "Cantidad inválida" << endl;
        return 0;
    }
    if (!prod.stockDisponible(registro.getCantidad())) {
        cout << "Sin stock disponible" << endl;
        return 0;
    }

    prod.setStock(prod.getStock() - registro.getCantidad());
    archiProducto.modificarRegistro(prod, prod.getIdProducto());

    FILE *pArchivo = fopen(_nombreArchivo, "ab");
    if(pArchivo == nullptr){
        return -1;
    }

    int ok = fwrite(&registro, sizeof(VentaDetalle), 1, pArchivo);
    fclose(pArchivo);

    if (ok == 1) {
        return 1;
    } else {
        return -2;
    }
}



bool ArchivoVentaDetalle::listarPorVenta(int idVenta){
    VentaDetalle registroActual;
    FILE *pArchivo = fopen(_nombreArchivo, "rb");
    if(pArchivo == nullptr){
        return false;
    }
    bool encontrado = false;
    while(fread(&registroActual, sizeof(VentaDetalle),1,pArchivo)==1){
        if(registroActual.getIdVenta() == idVenta){
            encontrado = true;
            registroActual.mostrarVentaDetalle();
        }
    }
    fclose(pArchivo);
    return encontrado;
}

int ArchivoVentaDetalle::cantidadRegistros(){
    FILE *pArchivo = fopen(_nombreArchivo, "rb");
      if(pArchivo == nullptr){
        return -1;
    }
    int cantidad = 0;
    fseek(pArchivo,0,SEEK_END);
    cantidad = ftell(pArchivo) / sizeof(VentaDetalle);
    fclose(pArchivo);
    return cantidad;
}


bool ArchivoVentaDetalle::existeRegistro(int idVenta){

    FILE *pArchivo = fopen(_nombreArchivo, "rb");
    if(pArchivo == nullptr){
        return false;
    }
    VentaDetalle reg;
    bool existe = false;
    while(fread(&reg,sizeof(VentaDetalle),1,pArchivo)== 1){
        if(reg.getIdVenta() == idVenta){
            fclose(pArchivo);
            existe = true;
            return existe;
        }
    }
    fclose(pArchivo);
    return existe;

}
