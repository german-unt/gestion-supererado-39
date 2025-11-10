
#pragma once

class producto{
private:
  int idProducto;
  categoria idCategoria;
  marca idMarca;
  float precioUnitario;
  int stock;
  Fecha fechaDeVencimiento;
  char nombreProducto [20];
  bool eliminado;


public:
producto(int idProducto, categoria idCategoria,marca idMarca, float precioUnitario, int stock, Fecha fechaDeVencimiento, const char *nombreProducto, bool eliminado);
producto();

//setters
void setId(int s_idProducto);
void setCategoria(categoria s-idCategoria);
void setMarca(marca s_idMarca);
void setPrecioUnitario(float s_precioUnitario);
void setStock(int s_stock)
void setFecha(fecha s_fechaDeVencimiento);
void setNombreProducto(const char *s_nombreProductoProdu);
void setEliminado(bool s_eliminado);

//getters
int getIdProducto();
categoria getIdCategoria();
marca getIdCategoria();
float getPrecioUnitario();
int getStock();
Fecha getFechaDeVencimiento();
const char *getNombreProducto();
bool getEliminado();


};



