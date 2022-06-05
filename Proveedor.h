#pragma once
#include <mysql.h>
#include <iostream>
#include <string>
#include "ConexionBD.h"

using namespace std;

class Proveedor
{
	//Atributos
private: string proveedor, nit, direccion, telefono;
	   int codigo;
	//Constructor
public:
	Proveedor() {

	}
	Proveedor(string pro, string n, string dir, string tel, int cod){
		proveedor = pro;
		nit = n;
		direccion = dir;
		telefono = tel;
		codigo = cod;
	}

	//set (modificar)
	void setProveedor(string pro) { proveedor = pro; }
	void setNit(string n) { nit = n; }
	void setDireccion(string dir) { direccion = dir; }
	void setTelefono(string tel) { telefono = tel; }

	//get (mostrar)
	string getProveedor() { return proveedor; }
	string getNit() { return nit; }
	string getDireccion() { return direccion; }
	string getTelefono() { return telefono; }

	//Métodos
	void crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();

		cn.abrir_conexion();
		if (cn.getConectarBD()) {
			string insertar = "INSERT INTO tiendaenlinea.Proveedores (proveedor, nit, direccion, telefono) VALUES ('" + proveedor + "', '" + nit + "', '" + direccion + "', '" + telefono + "');";
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
			string consulta = "SELECT * FROM Proveedores;";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectarBD(), c);
			if (!q_estado) {
				resultadoq = mysql_store_result(cn.getConectarBD());
				cout << endl << "===========================PROVEEDORES==========================" << endl;
				cout << "Codigo, Proveedor, NIT, Direccion, Telefono" << endl;
				cout << "-------------------------------------------------------------" << endl;
				while (fila = mysql_fetch_row(resultadoq)) {
					for (int i = 0; i <= 4; i++) {
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
			string actualizar = "UPDATE tiendaenlinea.Proveedores SET proveedor = '" + proveedor + "', nit = '" + nit + "', direccion = '" + direccion + "', telefono = '" + telefono + "' WHERE idProveedor = " + to_string(codigo) + ";";
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
			string actualizar = "DELETE FROM tiendaenlinea.Proveedores WHERE idProveedor = " + to_string(codigo) + ";";
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

