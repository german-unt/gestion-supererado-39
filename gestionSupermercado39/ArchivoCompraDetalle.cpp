#include <cstdio>
#include <cstring>
#include "ArchivoCompraDetalle.h"



ArchivoCompraDetalle::ArchivoCompraDetalle(const char  *nombreArchivo){
    std::strcpy(_nombreArchivo, nombreArchivo);
}

int ArchivoCompraDetalle::agregarRegistro(CompraDetalle nuevoRegistro){

FILE *pArchivo = fopen(_nombreArchivo, "ab");
    if(pArchivo == nullptr){
        return -1;
    }

    int ok = fwrite(&nuevoRegistro,sizeof(CompraDetalle),1,pArchivo);
    fclose(pArchivo);
    if(ok == 1){
        return 1;
    }else{
        return -2;
    }
}

bool ArchivoCompraDetalle::listarPorCompra(int idCompra){
    CompraDetalle registroActual;

    FILE *pArchivo = fopen(_nombreArchivo, "rb");
    if(pArchivo ==  nullptr){
        return false;
    }

    while(fread(&registroActual,sizeof(CompraDetalle),1,pArchivo) == 1){
            if(registroActual.getIdCompra()== idCompra)
            registroActual.mostrarCompraDetalle();
    }

    fclose(pArchivo);
    return true;
}

int ArchivoCompraDetalle::cantidadRegistros(){

    FILE *pArchivo = fopen(_nombreArchivo, "rb");
    if(pArchivo == nullptr){
        return -1;
    }
    int cantidad = 0;
    fseek(pArchivo,0,SEEK_END);
    cantidad = ftell(pArchivo) / sizeof(CompraDetalle);
    fclose(pArchivo);
    return cantidad;
}

