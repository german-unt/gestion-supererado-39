#include <iostream>
#include <cstring>

#include "categoria.h"
#include "ArchivoCategoria.h"
#include "funcionesGlobales.h"
using namespace std;


Categoria::Categoria(int idCategoria, const char *nombre, bool eliminado) {
    setIdCategoria(idCategoria);
    strcpy(_nombre, nombre);
    _eliminado = eliminado;
}

Categoria::Categoria() {
    _idCategoria = 0;
    strcpy(_nombre, "");
    _eliminado = false;
}

void Categoria::setIdCategoria(int idCategoria) {
        while(idCategoria < 0){
        cout << "ID INVALIDO, INGRESE OTRO ID: ";
        cin >> idCategoria;
    }
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

Categoria Categoria::cargarCategoria() {
    ArchivoCategoria archiC;
    Categoria categoria;
    int _idCategoria;
    char _nombre[20];
    bool _eliminado = false;


    if(archiC.cantidadRegistros() == -1){
        _idCategoria = 1;
    }else{

    _idCategoria = archiC.cantidadRegistros()+1;
    }
    categoria.setIdCategoria(_idCategoria);

    cout << "Nombre : ";
    cargarCadena(_nombre,19);
    categoria.setNombre(_nombre);

    categoria.setEliminado(_eliminado);


    return categoria;
}
void Categoria::mostrarCategoria(Categoria categoria) {
    cout << endl;
    cout << "ID Categoria: " << categoria.getIdCategoria() << endl;
    cout << "Nombre: " << categoria.getNombre() << endl;
    if(categoria.getEliminado()){
        cout << "Estado: Eliminado" << endl;
    }else{
        cout <<"Estado: Activo" << endl;
    }
    cout << "**************************************************"  <<endl;
}

void Categoria::mostrarTodos(){
    ArchivoCategoria archi("ArchivoCategoria.dat");
    Categoria categoria;
    for(int i = 0; i < archi.cantidadRegistros(); i++){
        categoria = archi.leer(i);
        if(!categoria.getEliminado()){
            mostrarCategoria(categoria);
        }
    }
    system("pause");

}
