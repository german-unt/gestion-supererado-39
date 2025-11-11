
#include <iostream>
#include <csting>

#include "categoria.h"
using namespace std;


Categoria::Categoria(int idCategoria, const char *nombre, bool eliminado) {
    _idCategoria = idCategoria;
    strcpy(_nombre, nombre);
    _eliminado = eliminado;
}

Categoria::Categoria() {
    _idCategoria = 0;
    strcpy(_nombre, "");
    _eliminado = false;
}

void Categoria::setIdCategoria(int idCategoria) {
    _idCategoria = idCategoria;
}

void Categoria::setNombre(const char *nombre) {
    strcpy(_nombre, nombre);
}

void Categoria::setEliminado(bool eliminado) {
    _eliminado = eliminado;
}

int Categoria::getIdCategoria() {
    return _idCategoria;
}

const char *Categoria::getNombre() {
    return _nombre;
}

bool Categoria::getEliminado() {
    return _eliminado;
}

void Categoria::cargarCategoria() {
    cout << "Ingrese ID de categoria: ";
    cin >> _idCategoria;
    cin.ignore(); // limpia el buffer
    cout << "Ingrese nombre de la categoria: ";
    cin.getline(_nombre, 20);
    _eliminado = false;
}

void Categoria::mostrarCategoria() {
    cout << "ID Categoria: " << _idCategoria << endl;
    cout << "Nombre: " << _nombre << endl;
    cout << "Eliminado: " << (_eliminado ? "Si" : "No") << endl;
}
