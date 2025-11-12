#include <cstdio>
#include <cstring>
#include "ArchivoVenta.h"
#include "venta.h"


ArchivoVenta::ArchivoVenta(const char *nombreArchivo){
    std::strcpy(_nombreArchivo, nombreArchivo);
}


int ArchivoVenta::agregarRegistro(Venta nuevoRegistro){
    FILE *pArchivo = fopen(_nombreArchivo, "ab");
    if(pArchivo == nullptr ){
        return -1;
    }
    int ok = fwrite(&nuevoRegistro,sizeof(Venta),1,pArchivo);
    fclose(pArchivo);
    if(ok == 1){
        return 1;
    }else{
        return -2;
    }
}

Venta ArchivoVenta::leer(int numero){
   FILE *p = fopen(_nombreArchivo, "rb");
   if (p==nullptr)
   {
     return Venta();
   }
   Venta aux;
   fseek(p,numero*sizeof(Venta), 0);
   fread(&aux, sizeof(Venta), 1,p);
   fclose(p);
   return aux;
 }



bool ArchivoVenta::listar(){
    Venta registroActual;
    FILE *pArchivo = fopen(_nombreArchivo, "rb");
    if(pArchivo == nullptr ){
        return false;
    }

    while(fread(&registroActual,sizeof(Venta),1,pArchivo)==1){
        if(!registroActual.getEstado()){
            registroActual.mostrarVenta(registroActual);
        }
    }
    fclose(pArchivo);
    return true;
}

int ArchivoVenta::modificarRegistro(Venta registro, int idVenta){
    Venta registroActual;
    FILE *pArchivo = fopen(_nombreArchivo, "rb+");
    if(pArchivo == nullptr ){
        return -1;
    }
    int modificado = 0;
    while(fread(&registroActual,sizeof(Venta),1,pArchivo)==1){
        if(registroActual.getIdVenta() == idVenta){
            fseek(pArchivo, -sizeof(Venta), SEEK_CUR);
            modificado = fwrite(&registro,sizeof(Venta),1,pArchivo);
            break;
        }
    }
    fclose(pArchivo);
    if(modificado == 1){
        return 1;
    }else{
        return -2;
    }
}

int ArchivoVenta::cantidadRegistros(){

    FILE *pArchivo = fopen(_nombreArchivo, "rb");
    if(pArchivo == nullptr ){
        return -1;
    }

    int cantidad = 0;
    fseek(pArchivo,0,SEEK_END);
    cantidad = ftell(pArchivo) / sizeof(Venta);
    fclose(pArchivo);
    return cantidad;
}

bool ArchivoVenta::eliminarLogico(int idVenta){
    Venta registroActual;
    FILE *pArchivo = fopen(_nombreArchivo, "rb+");
    if(pArchivo == nullptr ){
        return false;
    }
    int modificado = 0;
    while(fread(&registroActual,sizeof(Venta),1,pArchivo)==1){
        if(registroActual.getIdVenta()== idVenta){
            fseek(pArchivo,-sizeof(Venta), SEEK_CUR);
            registroActual.setEstado(false);
            modificado = fwrite(&registroActual,sizeof(Venta),1,pArchivo);
            break;
        }
    }
    fclose(pArchivo);
    if(modificado == 1){
        return true;
    }else{
        return false;
    }


}
