
#pragma once
#include "fecha.h"

class Producto{
private:
  int _idProducto;
  int _idCategoria;
  int  _idMarca;
  float _precioUnitario;
  int _stock;
  char _nombreProducto [20];
  bool _eliminado;
  Fecha _fechaDeVencimiento;

public:
Producto(int idProducto, int idCategoria,int idMarca, float precioUnitario, int stock, const char *nombreProducto, bool eliminado, Fecha _fechaDeVencimiento);
Producto();

//setters
void setIdProducto(int idProducto);
void setIdCategoria(int idCategoria);
void setIdMarca(int idMarca);
void setPrecioUnitario(float precioUnitario);
void setStock(int stock);
void setNombreProducto(const char *nombreProductoProdu);
void setEliminado(bool eliminado);
void setFechaDeVencimiento(Fecha fechaDeVencimiento);
//getters
int getIdProducto();
int getIdCategoria();
int getIdMarca();
float getPrecioUnitario();
int getStock();
const char *getNombreProducto();
bool getEliminado();
Fecha getFechaDeVencimiento();

Producto cargarProducto();
Producto cargarProductoModificado(int id);
void mostrarProducto(Producto producto);
void mostrarTodos();

};




