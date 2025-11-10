#ifndef MARCA_H_INCLUDED
#define MARCA_H_INCLUDED
class marca{
private:
    int idMarca;
    char nombre[20];
    bool eliminado;
public:
    marca(int idMarca, const char *nombre, bool eliminado);
    marca();
//setters
void setIdMarca (int s_idMarca);
void setNombre (const char *s_nombre);
void setEliminado (bool s_eliminado);

//getters
int getIdMarca();
const char *getNombre();
bool getELiminado();

};


#endif // MARCA_H_INCLUDED
