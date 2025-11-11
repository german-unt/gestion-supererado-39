
#include "ArchivoProducto.h"
#include "Producto.h"
#include <iostream>
#include <cstring>

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


/*bool ArchivoProducto::listar(){
    Producto registroActual;
    FILE *pArchivo = fopen(_nombreArchivo, "rb");
        if(pArchivo==nullptr){
        return false;
    }

    while(fread(&registroActual,sizeof(Producto),1,pArchivo)==1){
        registroActual.mostrarProducto(); // aca va registroActual.Mostrar()
    }
    fclose(pArchivo);
    return true;
}
*/

bool ArchivoProducto::eliminarLogico(int idProducto){
    Producto registroActual;
        FILE *pArchivo = fopen(_nombreArchivo, "rb+");
        if(pArchivo==nullptr){
        return false;
    }
    bool modificado = false;
    while(fread(&registroActual,sizeof(Producto),1,pArchivo)==1){
          if(registroActual.getIdProducto()== idProducto){
            fseek(pArchivo,-sizeof(Producto), SEEK_CUR);
            registroActual.setEliminado(true);
            modificado = fwrite(&registroActual,sizeof(Producto),1,pArchivo) ? true : false;
            break;
          }
    }
    fclose(pArchivo);
    return modificado;
}


bool ArchivoProducto::listarXnombre(){
    Producto registroActual;
    FILE *pArchivo = fopen(_nombreArchivo, "rb");
        if(pArchivo==nullptr){
        return false;
    }

    while(fread(&registroActual,sizeof(Producto),1,pArchivo)==1){
        registroActual.getNombreProducto();
    }
    fclose(pArchivo);
    return true;
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
/*
bool ArchivoProducto::listarXCategoria(){
    Producto registroActual;
    FILE *pArchivo = fopen(_nombreArchivo, "rb");
        if(pArchivo==nullptr){
        return false;
    }

    while(fread(&registroActual,sizeof(Producto),1,pArchivo)==1){
        registroActual.getCategoria();
    }
    fclose(pArchivo);
    return true;
}

bool ArchivoProducto::listarStock(){
        Producto registroActual;
    FILE *pArchivo = fopen(_nombreArchivo, "rb");
        if(pArchivo==nullptr){
        return false;
    }

    while(fread(&registroActual,sizeof(Producto),1,pArchivo)==1){
        if(registroActual.getStock() > 0){
            registroActual.getNombre();
            registroActual.getStock();
        }
    }
    fclose(pArchivo);
    return true;

}

*/
