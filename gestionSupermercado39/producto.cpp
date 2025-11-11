
#include <iostream>
#include <cstring>
#include "producto.h"

using namespace std;

// Constructor con parámetros
Producto::Producto(int idProducto, int idCategoria, int idMarca, float precioUnitario, int stock, const char *nombreProducto, bool eliminado) {
    _idProducto = idProducto;
    _idCategoria = idCategoria;
    _idMarca = idMarca;
    _precioUnitario = precioUnitario;
    _stock = stock;
    strcpy(_nombreProducto, nombreProducto);
    _eliminado = eliminado;
}

// Constructor por defecto
Producto::Producto() {
    _idProducto = 0;
    _idCategoria = 0;
    _idMarca = 0;
    _precioUnitario = 0.0f;
    _stock = 0;
    strcpy(_nombreProducto, "");
    _eliminado = false;
}

// Setters
void Producto::setIdProducto(int idProducto) {
    _idProducto = idProducto;
}

void Producto::setIdCategoria(int idCategoria) {
    _idCategoria = idCategoria;
}

void Producto::setIdMarca(int idMarca) {
    _idMarca = idMarca;
}

void Producto::setPrecioUnitario(float precioUnitario) {
    _precioUnitario = precioUnitario;
}

void Producto::setStock(int stock) {
    _stock = stock;
}

void Producto::setNombreProducto(const char *nombreProducto) {
    strcpy(_nombreProducto, nombreProducto);
}

void Producto::setEliminado(bool eliminado) {
    _eliminado = eliminado;
}

// Getters
int Producto::getIdProducto() {
    return _idProducto;
}

int Producto::getIdCategoria() {
    return _idCategoria;
}

int Producto::getIdMarca() {
    return _idMarca;
}

float Producto::getPrecioUnitario() {
    return _precioUnitario;
}

int Producto::getStock() {
    return _stock;
}

const char *Producto::getNombreProducto() {
    return _nombreProducto;
}

bool Producto::getEliminado() {
    return _eliminado;
}

// Métodos auxiliares
void Producto::cargarProducto() {
    cout << "Ingrese ID de producto: ";
    cin >> _idProducto;
    cout << "Ingrese ID de categoria: ";
    cin >> _idCategoria;
    cout << "Ingrese ID de marca: ";
    cin >> _idMarca;
    cout << "Ingrese precio unitario: ";
    cin >> _precioUnitario;
    cout << "Ingrese stock: ";
    cin >> _stock;
    cin.ignore();
    cout << "Ingrese nombre del producto: ";
    cin.getline(_nombreProducto, 20);
    _eliminado = false;
}

void Producto::mostrarProducto() {
    cout << "ID Producto: " << _idProducto << endl;
    cout << "ID Categoria: " << _idCategoria << endl;
    cout << "ID Marca: " << _idMarca << endl;
    cout << "Precio Unitario: $" << _precioUnitario << endl;
    cout << "Stock: " << _stock << endl;
    cout << "Nombre: " << _nombreProducto << endl;
    cout << "Eliminado: " << (_eliminado ? "Si" : "No") << endl;
}
