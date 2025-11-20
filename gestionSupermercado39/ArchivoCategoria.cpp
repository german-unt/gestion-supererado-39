#include "categoria.h"
#include "ArchivoCategoria.h"
#include <iostream>
#include <cstring>

ArchivoCategoria::ArchivoCategoria(const char  *nombreArchivo){
    std::strcpy(_nombreArchivo, nombreArchivo);
}

int ArchivoCategoria::agregarRegistro(Categoria registro){
    FILE *cArchivo = fopen(_nombreArchivo, "ab");

    if(cArchivo==nullptr){
        return -1;
    }

    int ok = fwrite(&registro, sizeof(Categoria),1,cArchivo);
    fclose(cArchivo);
    if(ok == 1){
        return 1;
    }else{
        return -2;
    }
}

int ArchivoCategoria::modificarRegistro(Categoria registro, int idCategoria){
    Categoria registroActual;

    FILE *cArchivo = fopen(_nombreArchivo, "rb+");

    if(cArchivo==nullptr){
        return -1;
    }
    int modificado = 0;
    while(fread(&registroActual,sizeof(Categoria),1,cArchivo)==1){
        if(registroActual.getIdCategoria() == idCategoria){
            fseek(cArchivo, -sizeof(Categoria),SEEK_CUR);
            modificado = fwrite(&registro, sizeof(Categoria),1,cArchivo);
            fclose(cArchivo);
            return (modificado == 1) ? 1 : -2;
        }
    }

    fclose(cArchivo);
    return 0;
}


int ArchivoCategoria::cantidadRegistros(){
    FILE *cArchivo = fopen(_nombreArchivo, "rb");
        if(cArchivo==nullptr){
        return -1;
    }
    int cantidad = 0;
    fseek(cArchivo,0, SEEK_END);
    cantidad = ftell(cArchivo) / sizeof(Categoria);
    fclose(cArchivo);
    return cantidad;

}


bool ArchivoCategoria::eliminarLogico(int idCategoria){
    Categoria registroActual;
        FILE *cArchivo = fopen(_nombreArchivo, "rb+");
        if(cArchivo==nullptr){
        return false;
    }
    bool modificado = false;
    while(fread(&registroActual,sizeof(Categoria),1,cArchivo)==1){
          if(registroActual.getIdCategoria() == idCategoria && registroActual.getEliminado() == false){
            fseek(cArchivo,-sizeof(Categoria), SEEK_CUR);
            registroActual.setEliminado(true);
            modificado = fwrite(&registroActual,sizeof(Categoria),1,cArchivo) ? true : false;
            break;
          }
    }
    fclose(cArchivo);
    return modificado;
}


Categoria ArchivoCategoria::leer(int numero)
 {
   FILE *p = fopen(_nombreArchivo, "rb");
   if (p==nullptr)
   {
     return Categoria();
   }
   Categoria aux;
   fseek(p,numero*sizeof(Categoria), 0);
   fread(&aux, sizeof(Categoria), 1,p);
   fclose(p);
   return aux;
 }


