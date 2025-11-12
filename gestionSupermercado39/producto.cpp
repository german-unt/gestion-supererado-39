
#include <iostream>
#include <cstring>
#include "producto.h"
#include "funcionesGlobales.h"
#include"ArchivoProducto.h"

using namespace std;

// Constructor con parámetros
Producto::Producto(int idProducto, int idCategoria, int idMarca, float precioUnitario, int stock, const char *nombreProducto, bool eliminado, Fecha fechaDeVencimiento) {
    _idProducto = idProducto;
    _idCategoria = idCategoria;
    _idMarca = idMarca;
    _precioUnitario = precioUnitario;
    _stock = stock;
    strcpy(_nombreProducto, nombreProducto);
    _eliminado = eliminado;
    _fechaDeVencimiento = fechaDeVencimiento;
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
    _fechaDeVencimiento = Fecha();
}

// Setters
void Producto::setIdProducto(int idProducto) {
    while (idProducto < 0 ){
        cout << "El id debe ser positivo, ingrese nuevamente el id: ";
        cin >> idProducto;

    }
    _idProducto = idProducto;
}

void Producto::setIdCategoria(int idCategoria) {
    while (idCategoria < 0 ){
        cout << "El id debe ser positivo, ingrese nuevamente el id: ";
        cin >> idCategoria;

    }
    _idCategoria = idCategoria;
}

void Producto::setIdMarca(int idMarca) {
    while (idMarca < 0 ){
        cout << "El id debe ser positivo, ingrese nuevamente el id: ";
        cin >> idMarca;
    }
    _idMarca = idMarca;
}

void Producto::setPrecioUnitario(float precioUnitario) {
    while (precioUnitario < 1 ){
        cout << "El precio debe ser mayor que 0, ingrese nuevamente el precio: ";
        cin >> precioUnitario;
    }
    _precioUnitario = precioUnitario;
}

void Producto::setStock(int stock) {
    while (stock < 0 ){
        cout << "El stock es invalido, ingrese nuevamente el stock: ";
        cin >> stock;
    }
    _stock = stock;
}

void Producto::setNombreProducto(const char *nombreProducto) {
    strcpy(_nombreProducto, nombreProducto);
}

void Producto::setEliminado(bool eliminado) {
    _eliminado = eliminado;
}

void Producto::setFechaDeVencimiento(Fecha fechaDeVencimiento){
     _fechaDeVencimiento = fechaDeVencimiento;
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

Fecha Producto::getFechaDeVencimiento(){
    return _fechaDeVencimiento;
}

// Métodos auxiliares
Producto Producto::cargarProducto() {
    ArchivoProducto archiP;
    Producto producto;
    int idProducto;
    int idCategoria;
    int  idMarca;
    float precioUnitario;
    int stock;
    char nombreProducto [20];
    bool eliminado;
    Fecha fechaDeVencimiento;

    //idProducto = archiP.cantidadRegistros()+1;
    idProducto = archiP.cantidadRegistros()+1;
    producto.setIdProducto(idProducto);

    cout << "ID categoria: ";
    cin >> idCategoria;
    producto.setIdCategoria(idCategoria);

    cout << "ID marca: ";
    cin >> idMarca;
    producto.setIdMarca(idMarca);


    cout << "Precio unitario: ";
    cin >> precioUnitario;
    producto.setPrecioUnitario(precioUnitario);

    cout << "Stock: ";
    cin >> stock;
    producto.setStock(stock);

    cout << "Nombre del producto: ";
    cargarCadena(nombreProducto,19);
    producto.setNombreProducto(nombreProducto);

    eliminado = false;
    producto.setEliminado(eliminado);

    cout <<"Fecha de vencimiento: "<<endl;
    fechaDeVencimiento.Cargar();
    producto.setFechaDeVencimiento(fechaDeVencimiento);

    return producto;

}


Producto Producto::cargarProductoModificado(int idProducto) {
    Producto producto;
    int idCategoria;
    int  idMarca;
    float precioUnitario;
    int stock;
    char nombreProducto [20];
    bool eliminado;
    Fecha fechaDeVencimiento;


    producto.setIdProducto(idProducto);

    cout << "ID categoria: ";
    cin >> idCategoria;
    producto.setIdCategoria(idCategoria);

    cout << "ID marca: ";
    cin >> idMarca;
    producto.setIdMarca(idMarca);


    cout << "Precio unitario: ";
    cin >> precioUnitario;
    producto.setPrecioUnitario(precioUnitario);

    cout << "Stock: ";
    cin >> stock;
    producto.setStock(stock);

    cout << "Nombre del producto: ";
    cargarCadena(nombreProducto,19);
    producto.setNombreProducto(nombreProducto);

    eliminado = false;
    producto.setEliminado(eliminado);

    cout <<"Fecha de vencimiento: "<<endl;
    fechaDeVencimiento.Cargar();
    producto.setFechaDeVencimiento(fechaDeVencimiento);

    return producto;

}


void Producto::mostrarProducto(Producto producto) {
    cout << endl;
    cout << "ID Producto: " << producto.getIdProducto() << endl;
    cout << "ID Categoria: " << producto.getIdCategoria()<< endl;
    cout << "ID Marca: " << producto.getIdMarca() << endl;
    cout << "Precio Unitario: $" << producto.getPrecioUnitario() << endl;
    cout << "Stock: " << producto.getStock() << endl;
    cout << "Nombre: " << producto.getNombreProducto() << endl;
    if(producto.getEliminado()){
        cout << "Estado: Eliminado" << endl;
    }else{
        cout <<"Estado: Activo" << endl;
    }
    cout << "Fecha de vencimiento: " << producto.getFechaDeVencimiento().toString()<< endl;
    cout << "**************************************************"  <<endl;
}

void Producto::mostrarTodos(){
    ArchivoProducto archi("ArchivoProducto.dat");
    Producto producto;
    for(int i = 0; i < archi.cantidadRegistros(); i++){
        producto = archi.leer(i);
        if(!producto.getEliminado()){
            mostrarProducto(producto);
        }
    }
    system("pause");

}
