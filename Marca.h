#pragma once
#include <mysql.h>
#include <iostream>
#include <string>
#include "ConexionBD.h"

using namespace std;

class Marca
{
private: string marca;
	   int codigo;

	   //Constructor
public:
	Marca() {
	}
	Marca(string mar, int cod) {
		marca = mar;
		codigo = cod;
	}

	//set (modificar)
	void setMarca(string mar) { marca = mar; }

	//get (mostrar)
	string getMarca() { return marca; }

	//Métodos

	void crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();

		cn.abrir_conexion();
		if (cn.getConectarBD()) {
			string insertar = "INSERT INTO tiendaenlinea.marcas (marca)  VALUES ('" + marca + "');";
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
			string consulta = "SELECT * FROM Marcas;";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectarBD(), c);
			if (!q_estado) {
				resultadoq = mysql_store_result(cn.getConectarBD());
				cout << endl << "===========================MARCAS==========================" << endl;
				cout << "Codigo, Marca" << endl;
				cout << "-------------------------------------------------------------" << endl;
				while (fila = mysql_fetch_row(resultadoq)) {
					for (int i = 0; i <= 1; i++) {
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
			string actualizar = "UPDATE tiendaenlinea.Marcas SET marca = '" + marca + "' WHERE idMarca = " + to_string(codigo) + ";";
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
			string actualizar = "DELETE FROM tiendaenlinea.Marcas WHERE idMarca = " + to_string(codigo) + ";";
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

