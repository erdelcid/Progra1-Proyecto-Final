#pragma once
#include <mysql.h>
#include <iostream>
#include <string>
#include "ConexionBD.h"
#include "Persona.h"
using namespace std;

class Empleado : public Persona
{
	//Atributos
private: string dpi, fechanacimiento, fechainiciolabores;
	   int idpuesto, codigo;
	//Constructor
public:
	Empleado() {
	}
	Empleado(string nom, string ape, string dir, string tel, string dp, bool gen, string fnac, int idpue, string finic, string n, int cod) : Persona(nom, ape, n, gen, tel, dir) {
		dpi = dp;
		fechanacimiento = fnac;
		idpuesto = idpue;
		fechainiciolabores = finic;
		codigo = cod;
	}

	//set (modificar)
	void setNombres(string nom) { nombres = nom; }
	void setApellidos(string ape) { apellidos = ape; }
	void setNit(string n) { nit = n; }
	void setGenero(bool gen) { genero = gen; }
	void setTelefono(string tel) { telefono = tel; }
	void setDireccion(string dir) { direccion = dir; }
	void setDPI(string dp) { dpi = dp; }
	void setFechaNacimiento(string fnac) { fechanacimiento = fnac; }
	void setFechaInicioLabores(string finic) { fechainiciolabores = finic; }
	void setIdPuesto(int idpue) { idpuesto = idpue; }

	//get (mostrar)
	string getNombres() { return nombres; }
	string getApellidos() { return apellidos; }
	string getNit() { return nit; }
	bool   getGenero() { return genero; }
	string getTelefono() { return telefono; }
	string getDireccion() { return direccion; }
	string getDPI() { return dpi; }
	string getFechaNacimiento() { return fechanacimiento; }
	string getFechaInicioLabores() { return fechainiciolabores; }
	int    getIdPuesto() { return idpuesto; }

	//Métodos

	void crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();

		cn.abrir_conexion();
		if (cn.getConectarBD()) {
			string insertar = "INSERT INTO tiendaenlinea.Empleados (nombres, apellidos, direccion, telefono, dpi, genero, fecha_nacimiento, idpuesto, fecha_inicio_labores) VALUES ('" + nombres + "', '" + apellidos + "', '" + direccion + "', '" + telefono + "', '" + dpi + "', " + to_string(genero) + ", '" + fechanacimiento + "', " + to_string(idpuesto) + ", '" + fechainiciolabores + "');";
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
			string consulta = "SELECT * FROM Empleados;";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectarBD(), c);
			if (!q_estado) {
				resultadoq = mysql_store_result(cn.getConectarBD());
				cout << endl << "===================================================EMPLEADOS==================================================" << endl;
				cout << "Codigo, Nombres, Apellidos, Direccion, Telefono, DPI, Genero, Fecha_Nacimiento, IdPuesto, Fecha_Inicio_Labores" << endl;
				cout << "--------------------------------------------------------------------------------------------------------------" << endl;
				while (fila = mysql_fetch_row(resultadoq)) {
					for (int i = 0; i <= 9; i++) {
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
			string actualizar = "UPDATE tiendaenlinea.Empleados SET nombres = '" + nombres + "', apellidos = '" + apellidos + "', direccion = '" + direccion + "', telefono = '" + telefono + "', dpi = '" + dpi + "', genero = " + to_string(genero) + ", fecha_nacimiento = '" + fechanacimiento + "', idpuesto = " + to_string(idpuesto) + ", fecha_inicio_labores = '" + fechainiciolabores + "' WHERE idEmpleado = " + to_string(codigo) + "; ";
			cout << actualizar;
			system("pause");
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
			string actualizar = "DELETE FROM tiendaenlinea.Empleados WHERE idEmpleado = " + to_string(codigo) + ";";
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

