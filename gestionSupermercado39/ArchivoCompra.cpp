#include <iostream>
#include <cstring>
#include "Compra.h"
#include "ArchivoCompra.h"




ArchivoCompra::ArchivoCompra(const char *nombreArchivo){
    std::strcpy(_nombreArchivo, nombreArchivo);
}



int ArchivoCompra::agregarRegistro(Compra nuevoRegistro){

    FILE *pArchivo = fopen(_nombreArchivo, "ab");
    if(pArchivo == nullptr){
        return -1;
    }

    int ok = fwrite(&nuevoRegistro,sizeof(Compra),1,pArchivo);
    fclose(pArchivo);
    if(ok == 1){
        return 1;
    }else{
        return -2;
    }

}


bool ArchivoCompra::listar(){
    Compra registro;
    FILE *pArchivo = fopen(_nombreArchivo, "rb");
    if(pArchivo == nullptr){
        return false;
    }

    while(fread(&registro, sizeof(Compra),1,pArchivo)==1){
        registro.mostrarCompra(registro);
    }
    fclose(pArchivo);
    return true;

}


int ArchivoCompra::modificarRegistro(Compra registro, int idCompra){
    Compra registroActual;
    FILE *pArchivo = fopen(_nombreArchivo, "rb+");
        if(pArchivo == nullptr){
        return -1;
    }
    int modificado = 0;
    while(fread(&registroActual, sizeof(Compra),1,pArchivo)==1){
        if(registroActual.getIdCompra() == idCompra){
            fseek(pArchivo,-sizeof(Compra),SEEK_CUR);
            modificado = fwrite(&registro, sizeof(Compra),1,pArchivo);
            fclose(pArchivo);
            return (modificado == 1) ? 1 : -2;
        }
    }
    fclose(pArchivo);
    return 0;
}

int ArchivoCompra::cantidadRegistros(){
        FILE *pArchivo = fopen(_nombreArchivo, "rb");
        if(pArchivo == nullptr){
        return -1;
    }
    int cantidad = 0;
    fseek(pArchivo,0,SEEK_END);
    cantidad = ftell(pArchivo) / sizeof(Compra);
    fclose(pArchivo);
    return cantidad;

}


bool ArchivoCompra::eliminarLogico(int idCompra){
        Compra registroActual;
        FILE *pArchivo = fopen(_nombreArchivo, "rb+");
        if(pArchivo == nullptr){
        return false;
    }
    bool modificado=false;

    while(fread(&registroActual,sizeof(Compra),1,pArchivo)==1){
        if(registroActual.getIdCompra()== idCompra){
            fseek(pArchivo,-sizeof(Compra),SEEK_CUR);
            registroActual.setEstado(true);
            modificado = fwrite(&registroActual,sizeof(Compra),1,pArchivo) ? true : false;
            break;
        }
    }
    fclose(pArchivo);
    return modificado;
}




bool ArchivoCompra::listarComprasXMes(int mes){
    Compra registroActual;
    FILE *pArchivo = fopen(_nombreArchivo, "rb");
        if(pArchivo == nullptr){
        return false;
    }
    bool huboCompras = false;
    float totalMes = 0;

    while(fread(&registroActual,sizeof(Compra),1,pArchivo)==1){
        if(!registroActual.getEstado() && registroActual.getFecha().getMes() == mes){
            registroActual.mostrarCompra(registroActual);
            huboCompras = true;
            totalMes += registroActual.getTotal();
        }
    }
    fclose(pArchivo);
    if(huboCompras){
        cout << "TOTAL DE Compras EN " << mes << ": $" << totalMes << endl;
    } else {
        cout << "No se registraron Compras en el mes " << mes << endl;
    }
    return true;

}



bool ArchivoCompra::listarComprasXAnio(int anio){
    Compra registroActual;
    FILE *pArchivo = fopen(_nombreArchivo, "rb");
        if(pArchivo == nullptr){
        return false;
    }
    bool huboCompras = false;
    float totalAnio = 0;

    while(fread(&registroActual,sizeof(Compra),1,pArchivo)==1){
        if(!registroActual.getEstado() && registroActual.getFecha().getAnio() == anio){
            registroActual.mostrarCompra(registroActual);
            huboCompras = true;
            totalAnio += registroActual.getTotal();
        }
    }
    fclose(pArchivo);
    if(huboCompras){
        cout << "TOTAL DE Compras EN " << anio << ": $" << totalAnio << endl;
    } else {
        cout << "No se registraron Compras en el anio " << anio << endl;
    }
    return true;

}


bool ArchivoCompra::estado(int id){
    Compra registroActual;
    FILE *pArchivo = fopen(_nombreArchivo, "rb");
    if(pArchivo == nullptr ){
        return false;
    }

    bool eliminado = false;
    while(fread(&registroActual,sizeof(Compra),1,pArchivo)== 1){
        if(registroActual.getIdCompra() == id){
            eliminado = registroActual.getEstado();
            fclose(pArchivo);
            return eliminado;
        }
    }
    fclose(pArchivo);
    return eliminado;
}

Compra ArchivoCompra::leer(int numero){
   FILE *p = fopen(_nombreArchivo, "rb");
   if (p==nullptr)
   {
     return Compra();
   }
   Compra aux;
   fseek(p,numero*sizeof(Compra), 0);
   fread(&aux, sizeof(Compra), 1,p);
   fclose(p);
   return aux;
 }





