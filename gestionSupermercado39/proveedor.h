#ifndef PROVEEDOR_H_INCLUDED
#define PROVEEDOR_H_INCLUDED
class proveedor{
private:
int idProveedor;
char nombre [20];
bool eliminado;

public
proveedor (int idproveedor, const char *nombre, bool eliminado);
proveedor ();

//setters
void setIdProveedor (int s_idProveedor);
void setNombre (const char *s_nombre);
void setEliminado (bool s_eliminado);

//getters
int getIdProveedor();
const char *getNombre();
bool getEliminado();


};


#endif // PROVEEDOR_H_INCLUDED
