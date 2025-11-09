

#include <iostream>
#include <cstring>
#include "Compra.h"
#include "ArchivoCompra.h"

using namespace std;


ArchivoCompra::ArchivoCompra(std::string nombreArchivo){
    _nombreArchivo = nombreArchivo;
}



int ArchivoCompra::agregarRegistro(Compra nuevoRegistro){

    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "ab");
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
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == nullptr){
        return false;
    }

    while(fread(&registro, sizeof(Compra),1,pArchivo)==1){
        //poner mostrarCompra
        registro.getNombre();
    }
    fclose(pArchivo);
    return true;

}


int ArchivoCompra::modificarRegistro(Compra registro, int idCompra){
    Compra registroActual;
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb+");
        if(pArchivo == nullptr){
        return -1;
    }
    int modificado = 0;
    while(fread(&registroActual, sizeof(Compra),1,pArchivo)==1){
        if(registroActual.getId() == idCompra){
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
    Compra registroActual;
        FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
        if(pArchivo == nullptr){
        return -1;
    }
    fseek(pArchivo,0,SEEK_END);
    int cantidad = ftell(pArchivo) / sizeof(Compra);
    fclose(pArchivo);
    return cantidad;

}


bool ArchivoCompra::eliminarLogico(int idCompra){
        Compra registroActual;
        FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb+");
        if(pArchivo == nullptr){
        return false;
    }
    bool modificado=false;

    while(fread(&registroActual,sizeof(Compra),1,pArchivo)==1){
        if(registroActual.getId()== idCompra){
            fseek(pArchivo,-sizeof(Compra),SEEK_CUR);
            registroActual.setEstado(false);
            modificado = fwrite(&registroActual,sizeof(Compra),1,pArchivo) ? true : false;
            break;
        }
    }
    fclose(pArchivo);
    return modificado;
}



bool ArchivoCompra::listarComprasXProveedor(int CodigoProveedor){
    Compra registroActual;
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
        if(pArchivo == nullptr){
        return false;
    }

    while(fread(&registroActual,sizeof(Compra),1,pArchivo)==1){
        if(registroActual.getEstado() == true && registroActual.getCodigoProveedor() == CodigoProveedor){ // preguntar si le agg estado a la compra, puede ser que se anule!
            //poner mostrarCompra
            registroActual.getNombre();
        }
    }
    fclose(pArchivo);
    return true;
}





bool ArchivoCompra::listarComprasXMes(int mes){
    Compra registroActual;
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
        if(pArchivo == nullptr){
        return false;
    }

    while(fread(&registroActual,sizeof(Compra),1,pArchivo)==1){
        if(registroActual.getEstado() == true && registroActual.getFecha().getMes() == mes){
            //poner mostrarCompra
            registroActual.getNombre();
        }
    }
    fclose(pArchivo);
    return true;

}



bool ArchivoCompra::listarComprasXAnio(int anio){
    Compra registroActual;
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
        if(pArchivo == nullptr){
        return false;
    }

    while(fread(&registroActual,sizeof(Compra),1,pArchivo)==1){
        if(registroActual.getEstado() == true && registroActual.getFecha().getAnio() == anio){
            //poner mostrarCompra
            registroActual.getNombre();
        }
    }
    fclose(pArchivo);
    return true;


}
