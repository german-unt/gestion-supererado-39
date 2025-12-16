
#include "ArchivoProducto.h"
#include "Producto.h"
#include <iostream>
#include <cstring>

using namespace std;

ArchivoProducto::ArchivoProducto(const char  *nombreArchivo){
    std::strcpy(_nombreArchivo, nombreArchivo);
}

int ArchivoProducto::agregarRegistro(Producto registro){
    FILE *pArchivo = fopen(_nombreArchivo, "ab");

    if(pArchivo==nullptr){
        return -1;
    }

    int ok = fwrite(&registro, sizeof(Producto),1,pArchivo);
    fclose(pArchivo);
    if(ok == 1){
        return 1;
    }else{
        return -2;
    }
}

int ArchivoProducto::modificarRegistro(Producto registro, int idProducto){
    Producto registroActual;

    FILE *pArchivo = fopen(_nombreArchivo, "rb+");

    if(pArchivo==nullptr){
        return -1;
    }
    int modificado = 0;
    while(fread(&registroActual,sizeof(Producto),1,pArchivo)==1){
        if(registroActual.getIdProducto() == idProducto){
            fseek(pArchivo, -sizeof(Producto),SEEK_CUR);
            modificado = fwrite(&registro, sizeof(Producto),1,pArchivo);
            fclose(pArchivo);
            return (modificado == 1) ? 1 : -2;
        }
    }

    fclose(pArchivo);
    return 0;
}


int ArchivoProducto::cantidadRegistros(){
    FILE *pArchivo = fopen(_nombreArchivo, "rb");
        if(pArchivo==nullptr){
        return -1;
    }
    int cantidad = 0;
    fseek(pArchivo,0, SEEK_END);
    cantidad = ftell(pArchivo) / sizeof(Producto);
    fclose(pArchivo);
    return cantidad;

}


bool ArchivoProducto::existeProducto(int idProducto){
    Producto registroActual;
    FILE *pArchivo = fopen(_nombreArchivo, "rb");
        if(pArchivo==nullptr){
        return false;
    }

    while(fread(&registroActual,sizeof(Producto),1,pArchivo)==1){
        if(registroActual.getIdProducto() == idProducto){
            fclose(pArchivo);
            return true;
        }
    }
    fclose(pArchivo);
    return false;
}


bool ArchivoProducto::eliminarLogico(int idProducto){
    Producto registroActual;
        FILE *pArchivo = fopen(_nombreArchivo, "rb+");
        if(pArchivo==nullptr){
        return false;
    }
    bool modificado = false;
    while(fread(&registroActual,sizeof(Producto),1,pArchivo)==1){
          if(registroActual.getIdProducto() == idProducto && registroActual.getEliminado() == false){
            fseek(pArchivo,-sizeof(Producto), SEEK_CUR);
            registroActual.setEliminado(true);
            modificado = fwrite(&registroActual,sizeof(Producto),1,pArchivo) ? true : false;
            break;
          }
    }
    fclose(pArchivo);
    return modificado;
}

Producto ArchivoProducto::leer(int numero)
 {
   FILE *p = fopen(_nombreArchivo, "rb");
   if (p==nullptr)
   {
     return Producto();
   }
   Producto aux;
   fseek(p,numero*sizeof(Producto), 0);
   fread(&aux, sizeof(Producto), 1,p);
   fclose(p);
   return aux;
 }

bool ArchivoProducto::buscarPorId(int idProducto, Producto &productoEncontrado){
    if(idProducto <= 0){
        return false;
    }

    FILE *pArchivo = fopen(_nombreArchivo, "rb");
    if(pArchivo == nullptr){
        return false;
    }

    while(fread(&productoEncontrado,sizeof(Producto),1,pArchivo)==1){
        if(productoEncontrado.getIdProducto() == idProducto &&
           !productoEncontrado.getEliminado()){
            fclose(pArchivo);
            return true;
        }
    }

    fclose(pArchivo);
    return false;
}






bool ArchivoProducto::listarStock(){
    Producto registroActual;
    FILE *pArchivo = fopen(_nombreArchivo, "rb");
    if(pArchivo==nullptr){
        return false;
    }
    bool existeProducto = false;
    while(fread(&registroActual,sizeof(Producto),1,pArchivo)==1){
        if(registroActual.getStock() > 0 && !registroActual.getEliminado()){
            existeProducto = true;
            cout <<"- Nombre Producto: " << registroActual.getNombreProducto() << endl;
            cout <<"- Stock: "<< registroActual.getStock()<< endl;
            cout << "-----------------------------------------" << endl;
        }
    }
    fclose(pArchivo);
    return existeProducto;

}


