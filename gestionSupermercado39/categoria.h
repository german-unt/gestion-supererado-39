#ifndef CATEGORIA_H_INCLUDED
#define CATEGORIA_H_INCLUDED
class categoria{
private:
int idCategoria;
char nombre[20];
bool eliminado;

public:
categoria(int idCategoria, const char *nombre, bool eliminado);
categoria();
//setters
void setIdCategoria(int s_idCategoria);
void setNombre (const char *s_nombre);
void setEliminado (bool s_eliminado);

//getters
int getIdCategoria();
const char *getNombre();
bool getEliminado();

};



#endif // CATEGORIA_H_INCLUDED
