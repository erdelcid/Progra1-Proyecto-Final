#pragma once
#include <mysql.h>
#include <iostream>
#include <string>
#include "ConexionBD.h"
using namespace std;

class Producto
{
	//Atributos
private: string producto, descripcion, imagen;
	   int idmarca, existencia, codigo;
	   float preciocosto, precioventa;
	   
	//Constructor
public:
	Producto() {
	}
	Producto(string prod, int idmar, string desc, string img, float pcos, float pven, int exis, int cod)  {
		producto = prod;
		idmarca = idmar;
		descripcion = desc;
		imagen = img;
		preciocosto = pcos;
		precioventa = pven;
		existencia = exis;
		codigo = cod;
	}

	//set (modificar)
	void setProducto(string prod) { producto = prod; }
	void setIdMarca(int idmar) { idmarca = idmar; }
	void setDescripcion(string desc) { descripcion = desc; }
	void setImagen(string img) { imagen = img; }
	void setPrecioCosto(float pcos) { preciocosto = pcos; }
	void setPrecioVenta(float pven) { precioventa = pven; }
	void setExistencia(int exis) { existencia = exis; }

	//get (mostrar)
	string getProducto() { return producto; }
	int getIdMarca() { return idmarca; }
	string getDescripcion() { return descripcion; }
	string getImagen() { return imagen; }
	float getPrecioCosto() { return preciocosto; }
	float getPrecioVenta() { return precioventa; }
	int getExistencia() { return existencia; }

	//Métodos

	void crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();

		cn.abrir_conexion();
		if (cn.getConectarBD()) {
			string insertar = "INSERT INTO tiendaenlinea.Productos (producto, idmarca, descripcion, imagen, precio_costo, precio_venta, existencia)  VALUES ('" + producto + "', " + to_string(idmarca) + ", '" + descripcion + "', '" + imagen + "', " + to_string(preciocosto) + ", " + to_string(precioventa) + ", " + to_string(existencia) + ");";
			const char* i = insertar.c_str();
			q_estado = mysql_query(cn.getConectarBD(), i);
			if (!q_estado) {
				cout << endl << "Datos insertados correctamente" << endl;
			}
			else {
				cout << endl << "Error al INGRESAR" << endl;
			}
		}
		else {
			cout << "Error en la conexión" << endl;
		}
		cn.cerrar_conexion();
	}

	void leer() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultadoq;

		cn.abrir_conexion();
		if (cn.getConectarBD()) {
			string consulta = "SELECT * FROM Productos;";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectarBD(), c);
			if (!q_estado) {
				resultadoq = mysql_store_result(cn.getConectarBD());
				cout << endl << "=======================================PRODUCTOS======================================" << endl;
				cout << "Codigo, Producto, IdMarca, Descripcion, Imagen, Precio_Costo, Precio_Venta, Existencia" << endl;
				cout << "-------------------------------------------------------------------------------------" << endl;
				while (fila = mysql_fetch_row(resultadoq)) {
					for (int i = 0; i <= 7; i++) {
						cout << fila[i] << ", ";
					}
					cout << endl;
				}
			}
			else {
				cout << endl << "Error al CONSULTAR" << endl;
			}
		}
		else {
			cout << "Error en la conexión" << endl;
		}
		cn.cerrar_conexion();
	}

	void actualizar() {
		int q_estado;
		ConexionBD cn = ConexionBD();

		cn.abrir_conexion();
		if (cn.getConectarBD()) {
			string actualizar = "UPDATE tiendaenlinea.Productos SET producto = '" + producto + "', idmarca = " + to_string(idmarca) + ", descripcion = '" + descripcion + "', imagen = '" + imagen + "', precio_costo = " + to_string(preciocosto) + ", precio_venta = " + to_string(precioventa) + ", existencia = " + to_string(existencia) + " WHERE idProducto = " + to_string(codigo) + "; ";
			const char* i = actualizar.c_str();
			q_estado = mysql_query(cn.getConectarBD(), i);
			if (!q_estado) {
				cout << endl << "Datos actualizados correctamente" << endl;
			}
			else {
				cout << endl << "Error al ACTUALIZAR" << endl;
			}
		}
		else {
			cout << "Error en la conexión" << endl;
		}
		cn.cerrar_conexion();
	}

	void eliminar() {
		int q_estado;
		ConexionBD cn = ConexionBD();

		cn.abrir_conexion();
		if (cn.getConectarBD()) {
			string actualizar = "DELETE FROM tiendaenlinea.Productos WHERE idProducto = " + to_string(codigo) + ";";
			const char* i = actualizar.c_str();
			q_estado = mysql_query(cn.getConectarBD(), i);
			if (!q_estado) {
				cout << endl << "Datos eliminados correctamente" << endl;
			}
			else {
				cout << endl << "Error al ELIMINAR" << endl;
			}
		}
		else {
			cout << "Error en la conexión" << endl;
		}
		cn.cerrar_conexion();
	}

};

