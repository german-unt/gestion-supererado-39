#include "funcionesGlobales.h"
#include <cstring>
#include <iostream>
#include "marca.h"
#include"ArchivoMarca.h"
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
    while(idMarca < 0){
        cout << "ID INVALIDO, INGRESE OTRO ID: ";
        cin >> idMarca;
    }
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

Marca Marca::cargarMarca() {
    ArchivoMarca archiM;
    Marca marca;
    int _idMarca;
    char _nombre[20];
    bool _eliminado = false;

    if (archiM.cantidadRegistros() == -1){
        _idMarca = 1;
    }else{

    _idMarca = archiM.cantidadRegistros()+1;
    }
    marca.setIdMarca(_idMarca);


    cout << "Nombre: ";
    cargarCadena(_nombre,19);
    marca.setNombre(_nombre);

    marca.setEliminado(_eliminado);



    return marca;

}
void Marca::mostrarMarca(Marca marca) {
    cout << endl;
    cout << "ID Marca: " << marca.getIdMarca() << endl;
    cout << "Nombre: " << marca.getNombre() << endl;
    if(marca.getEliminado()){
        cout << "Estado: Eliminado" << endl;
    }else{
        cout <<"Estado: Activo" << endl;
    }
    cout << "**************************************************"  <<endl;
}

void Marca::mostrarTodos(){
    ArchivoMarca archi("ArchivoMarca.dat");
    Marca marca;
    for(int i = 0; i < archi.cantidadRegistros(); i++){
        marca = archi.leer(i);
        if(!marca.getEliminado()){
            mostrarMarca(marca);
        }
    }
    system("pause");

}
