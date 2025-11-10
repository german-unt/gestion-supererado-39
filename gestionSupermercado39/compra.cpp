#include <string>
#include <iostream>
#include "compra.h"
#include "fecha.h"
using namespace std;

void Compra::setIdCompra(int idCompra){_idCompra = idCompra;    }
void Compra::setIdProveedor(int idProveedor){_idProveedor = idProveedor;    }
void Compra::setFecha(int dia, int mes, int anio){
    _fecha.setDia(dia);
    _fecha.setMes(mes);
    _fecha.setAnio(anio);
}
void Compra::setTotal(float total){_total = total;  }
void Compra::setEstado(bool estado){_anulada  = estado; }

///getters
int Compra::getIdCompra(){return _idCompra; }
int Compra::getIdProveedor(){return _idProveedor;   }
std::string Compra::getFecha(){return _fecha.toString();    }
float Compra::getTotal(){return _total; }
bool Compra::getEstado(){return _anulada;   }








