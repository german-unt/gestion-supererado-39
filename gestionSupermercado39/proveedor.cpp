#include <iostream>
#include <cstring>
#include "proveedor.h"

using namespace std;


Proveedor::Proveedor(int idProveedor, const char *nombre, bool eliminado) {
    setIdProveedor(idProveedor);
    strcpy(_nombre, nombre);   // copia el texto al array
    _eliminado = eliminado;
}


Proveedor::Proveedor() {
    _idProveedor = 0;
    strcpy(_nombre, "");       // inicializa con string vacío
    _eliminado = false;
}

// Setters
void Proveedor::setIdProveedor(int idProveedor) {
    while (idProveedor < 0){
        cout << "El ID debe es invalido, igrese otro: ";
        cin >> idProveedor;
    }
    _idProveedor = idProveedor;
}

void Proveedor::setNombre(const char *nombre) {
    strcpy(_nombre, nombre);
}

void Proveedor::setEliminado(bool eliminado) {
    _eliminado = eliminado;
}

// Getters
int Proveedor::getIdProveedor() {
    return _idProveedor;
}

const char *Proveedor::getNombre() {
    return _nombre;
}

bool Proveedor::getEliminado() {
    return _eliminado;
}
