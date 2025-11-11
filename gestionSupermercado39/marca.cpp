#include <cstring>
#include <iostream>
#include "marca.h"
using namespace std;

// Constructor con parámetros
Marca::Marca(int idMarca, const char *nombre, bool eliminado) {
    _idMarca = idMarca;
    strcpy(_nombre, nombre);
    _eliminado = eliminado;
}

// Constructor por defecto
Marca::Marca() {
    _idMarca = 0;
    strcpy(_nombre, "");
    _eliminado = false;
}

// Setters
void Marca::setIdMarca(int idMarca) {
    _idMarca = idMarca;
}

void Marca::setNombre(const char *nombre) {
    strcpy(_nombre, nombre);
}

void Marca::setEliminado(bool eliminado) {
    _eliminado = eliminado;
}

// Getters
int Marca::getIdMarca() {
    return _idMarca;
}

const char *Marca::getNombre() {
    return _nombre;
}

bool Marca::getEliminado() {
    return _eliminado;
}

// Métodos de carga y visualización
void Marca::cargarMarca() {
    cout << "Ingrese ID de la marca: ";
    cin >> _idMarca;
    cin.ignore();
    cout << "Ingrese nombre de la marca: ";
    cin.getline(_nombre, 20);
    _eliminado = false;
}

void Marca::mostrarMarca() {
    cout << "ID Marca: " << _idMarca << endl;
    cout << "Nombre: " << _nombre << endl;
    cout << "Eliminado: " << (_eliminado ? "Si" : "No") << endl;
}
