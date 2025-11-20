
#include "ArchivoMarca.h"
#include "Marca.h"
#include <iostream>
#include <cstring>

ArchivoMarca::ArchivoMarca(const char  *nombreArchivo){
    std::strcpy(_nombreArchivo, nombreArchivo);
}

int ArchivoMarca::agregarRegistro(Marca registro){
    FILE *mArchivo = fopen(_nombreArchivo, "ab");

    if(mArchivo==nullptr){
        return -1;
    }

    int ok = fwrite(&registro, sizeof(Marca),1,mArchivo);
    fclose(mArchivo);
    if(ok == 1){
        return 1;
    }else{
        return -2;
    }
}

int ArchivoMarca::modificarRegistro(Marca registro, int idMarca){
    Marca registroActual;

    FILE *mArchivo = fopen(_nombreArchivo, "rb+");

    if(mArchivo==nullptr){
        return -1;
    }
    int modificado = 0;
    while(fread(&registroActual,sizeof(Marca),1,mArchivo)==1){
        if(registroActual.getIdMarca() == idMarca){
            fseek(mArchivo, -sizeof(Marca),SEEK_CUR);
            modificado = fwrite(&registro, sizeof(Marca),1,mArchivo);
            fclose(mArchivo);
            return (modificado == 1) ? 1 : -2;
        }
    }

    fclose(mArchivo);
    return 0;
}


int ArchivoMarca::cantidadRegistros(){
    FILE *mArchivo = fopen(_nombreArchivo, "rb");
        if(mArchivo==nullptr){
        return -1;
    }
    int cantidad = 0;
    fseek(mArchivo,0, SEEK_END);
    cantidad = ftell(mArchivo) / sizeof(Marca);
    fclose(mArchivo);
    return cantidad;

}


bool ArchivoMarca::eliminarLogico(int idMarca){
    Marca registroActual;
        FILE *mArchivo = fopen(_nombreArchivo, "rb+");
        if(mArchivo==nullptr){
        return false;
    }
    bool modificado = false;
    while(fread(&registroActual,sizeof(Marca),1,mArchivo)==1){
          if(registroActual.getIdMarca() == idMarca && registroActual.getEliminado() == false){
            fseek(mArchivo,-sizeof(Marca), SEEK_CUR);
            registroActual.setEliminado(true);
            modificado = fwrite(&registroActual,sizeof(Marca),1,mArchivo) ? true : false;
            break;
          }
    }
    fclose(mArchivo);
    return modificado;
}


Marca ArchivoMarca::leer(int numero)
 {
   FILE *p = fopen(_nombreArchivo, "rb");
   if (p==nullptr)
   {
     return Marca();
   }
   Marca aux;
   fseek(p,numero*sizeof(Marca), 0);
   fread(&aux, sizeof(Marca), 1,p);
   fclose(p);
   return aux;
 }
