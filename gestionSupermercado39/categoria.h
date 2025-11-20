#pragma once


class Categoria{
private:
    int _idCategoria;
    char _nombre[20];
    bool _eliminado = false;

public:
    Categoria(int idCategoria, const char *nombre, bool eliminado);
    Categoria();
    //setters
    void setIdCategoria(int idCategoria);
    void setNombre (const char *nombre);
    void setEliminado (bool eliminado);

    //getters
    int getIdCategoria();
    const char *getNombre();
    bool getEliminado();

    Categoria cargarCategoria();
    void mostrarCategoria(Categoria categoria);
    void mostrarTodos();

};



