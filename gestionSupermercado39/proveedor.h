#pragma once
class Proveedor{
private:
int _idProveedor;
char _nombre [20];
bool _eliminado;

public:
Proveedor (int idproveedor, const char *nombre, bool eliminado);
Proveedor ();

//setters
void setIdProveedor (int idProveedor);
void setNombre (const char *nombre);
void setEliminado (bool eliminado);

//getters
int getIdProveedor();
const char *getNombre();
bool getEliminado();


};


