#pragma once
#include <iostream>
using namespace std;

class Persona
{
/*	//Atributos
protected: string nombres, apellidos, direccion, fecha_nacimiento;
		 int telefono = 0;

	// Constructor
protected:
	Persona() {

	}

	Persona(string nom, string ape, string dir, int tel, string fn) {
		nombres = nom;
		apellidos = ape;
		direccion = dir;
		telefono = tel;
		fecha_nacimiento = fn;
	}
*/
//Atributos
protected: string nombres, apellidos, nit, telefono, direccion;
		 bool genero = 0;

		 // Constructor
protected:
	Persona() {

	}

	Persona(string nom, string ape, string n, bool gen, string tel, string dir) {
		nombres = nom;
		apellidos = ape;
		nit = n;
		genero = gen;
		telefono = tel;
		direccion = dir;
	}
};

 