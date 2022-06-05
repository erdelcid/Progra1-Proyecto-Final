#pragma once
#include <mysql.h>
#include <iostream>
#include <string>
#include "ConexionBD.h"
#include "Persona.h"
using namespace std;

class Cliente : public Persona
{
/*
	//Atributos
private: string nit;
	   //Constructor
public:
	Cliente() {

	}
	Cliente(string nom, string ape, string dir, int tel, string fn, string n) : Persona(nom, ape, dir, tel, fn) {
		nit = n;
	}

	//set (modificar)
	void setNit(string n) { nit = n; }
	void setNombres(string nom) { nombres = nom; }
	void setApellidos(string ape) { apellidos = ape; }
	void setDireccion(string dir) { direccion = dir; }
	void setTelefono(int tel) { telefono = tel; }

	//get (mostrar)
	string getNit() { return nit; }
	string getNombres() { return nombres; }
	string getApellidos() { return apellidos; }
	string getDireccion() { return direccion; }
	int getTelefono() { return telefono; }

	//Métodos

	void crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectarBD()) {
			string insertar = "INSERT INTO tiendaenlinea.clientes (nombres, apellidos, nit, genero, telefono, correo_electronico, fechaingreso)  VALUES ('" + puesto + "');";
			const char* i = insertar.c_str();
			q_estado = mysql_query(cn.getConectarBD(), i);
			if (!q_estado) {
				cout << "Datos insertados correctamente" << endl;
			}
			else {
				cout << "Error al INGRESAR" << endl;
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
			string consulta = "SELECT * FROM Clientes;";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectarBD(), c);
			if (!q_estado) {
				resultadoq = mysql_store_result(cn.getConectarBD());
				cout << "===================CLIENTES=================" << endl;
				while (fila = mysql_fetch_row(resultadoq)) {
					for (int i = 0; i <= 7;i++) {
						cout << fila[i] << ", ";
					}
					cout << endl;
				}
			}
			else {
				cout << "Error al CONSULTAR" << endl;
			}
		}
		else {
			cout << "Error en la conexión" << endl;
		}
		cn.cerrar_conexion();

	}

*/
	//Atributos
private: string email;
	   int codigo;
	   //Constructor
public:
	Cliente() {
	}
	Cliente(string nom, string ape, string n, bool gen, string tel, string dir, string em, int cod) : Persona(nom, ape, n, gen, tel, dir) {
		email = em;
		codigo = cod;
	}

	//set (modificar)
	void setNombres(string nom) { nombres = nom; }
	void setApellidos(string ape) { apellidos = ape; }
	void setNit(string n) { nit = n; }
	void setGenero(bool gen) { genero = gen; }
	void setTelefono(string tel) { telefono = tel; }
	void setDireccion(string dir) { direccion = dir; }
	void setEmail(string em) { email = em; }

	//get (mostrar)
	string getNombres() { return nombres; }
	string getApellidos() { return apellidos; }
	string getNit() { return nit; }
	bool getGenero() { return genero; }
	string getTelefono() { return telefono; }
	string getDireccion() { return direccion; }
	string getEmail() { return email; }

	//Métodos

	void crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();

		cn.abrir_conexion();
		if (cn.getConectarBD()) {
			string insertar = "INSERT INTO tiendaenlinea.Clientes (nombres, apellidos, nit, genero, telefono, correo_electronico) VALUES ('" + nombres + "', '" + apellidos + "', '" + nit + "', " + to_string(genero) + ", '" + telefono + "', '" + email + "');";
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
			string consulta = "SELECT * FROM Clientes;";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectarBD(), c);
			if (!q_estado) {
				resultadoq = mysql_store_result(cn.getConectarBD());
				cout << endl << "===============================CLIENTES==============================" << endl;
				cout << "Codigo, Nombres, Apellidos, NIT, Genero, Telefono, Correo_Electronico" << endl;
				cout << "---------------------------------------------------------------------" << endl;
				while (fila = mysql_fetch_row(resultadoq)) {
					for (int i = 0; i <= 6;i++) {
//						cprintf(fila[i]);  
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
			string actualizar = "UPDATE tiendaenlinea.Clientes SET nombres = '" + nombres + "', apellidos = '" + apellidos + "', nit = '" + nit + "', genero = " + to_string(genero) + ", telefono = '" + telefono + "', correo_electronico = '" + email + "' WHERE idCliente = " + to_string(codigo) + ";";
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
			string actualizar = "DELETE FROM tiendaenlinea.Clientes WHERE idCliente = " + to_string(codigo) + ";";
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

