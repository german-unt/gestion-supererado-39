
#pragma once

class Producto{
private:
  int _idProducto;
  int _idCategoria;
  int  _idMarca;
  float _precioUnitario;
  int _stock;
  char _nombreProducto [20];
  bool _eliminado;


public:
Producto(int idProducto, int idCategoria,int idMarca, float precioUnitario, int stock, const char *nombreProducto, bool eliminado);
Producto();

//setters
void setIdProducto(int idProducto);
void setIdCategoria(int idCategoria);
void setIdMarca(int idMarca);
void setPrecioUnitario(float precioUnitario);
void setStock(int stock);
void setNombreProducto(const char *nombreProductoProdu);
void setEliminado(bool eliminado);

//getters
int getIdProducto();
int getIdCategoria();
int getIdMarca();
float getPrecioUnitario();
int getStock();
const char *getNombreProducto();
bool getEliminado();


void cargarProducto();
void mostrarProducto();

};



