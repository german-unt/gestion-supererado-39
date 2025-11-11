#pragma once

class Marca {
private:
    int _idMarca;
    char _nombre[20];
    bool _eliminado;

public:
    // Constructores
    Marca(int idMarca, const char *nombre, bool eliminado);
    Marca();

    // Setters
    void setIdMarca(int idMarca);
    void setNombre(const char *nombre);
    void setEliminado(bool eliminado);

    // Getters
    int getIdMarca();
    const char *getNombre();
    bool getEliminado();

    // Métodos auxiliares
    void cargarMarca();
    void mostrarMarca();
};
