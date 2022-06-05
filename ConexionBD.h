#pragma once
#include <mysql.h>
#include <iostream>
using namespace std;

class ConexionBD{
private: MYSQL* conectarBD;
public:
	void abrir_conexion() {
		conectarBD = mysql_init(0);
		conectarBD = mysql_real_connect(conectarBD, "192.168.8.170", "usr_empresa", "progra12022", "tiendaenlinea", 3306, NULL, 0);
 	}

	MYSQL* getConectarBD() {
		return conectarBD;
	}

	void cerrar_conexion() {
		mysql_close(conectarBD);
	}

};

