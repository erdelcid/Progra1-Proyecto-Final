#include <iostream>
#include <string>
#include <conio.h>
#include "Cliente.h"
#include "Puesto.h"
#include "Marca.h"
#include "Proveedor.h"
#include "Producto.h"
#include "Empleado.h"

using namespace std;

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = (SHORT)x - 1;
    coord.Y = (SHORT)y - 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void menucrud(string cat) 
{
	system("cls"); system("color F0");
	gotoxy(25,  5); cout << cat;
	gotoxy(22,  8); cout << "1. AGREGAR";
	gotoxy(22,  9); cout << "2. CONSULTAR";
	gotoxy(22, 10); cout << "3. ACTUALIZAR";
	gotoxy(22, 11); cout << "4. ELIMINAR";
	gotoxy(22, 13); cout << "0. REGRESAR AL MENU ANTERIOR";
	gotoxy(32, 16); cout << "Opcion: ";
}

int main()
{
	char   opcion, opcion2, opcion3;
	string catalogo;
	string nombres, apellidos, nit, telefono, direccion, email;
	int    genero, codigo=0;
	string puesto;
	string marca;
	string proveedor;
	string producto, descripcion, imagen;
	int    idmarca, existencia;
	float  preciocosto, precioventa;
	string dpi, fechanacimiento, fechainiciolabores;
	int    idpuesto;

	do
	{
		system("cls"); system("color F6");
		gotoxy(19,  5); cout << "SUPERMERCADO DON BARATON";
		gotoxy(22,  8); cout << "1. CATALOGOS";
		gotoxy(22,  9); cout << "2. COMPRAS";
		gotoxy(22, 10); cout << "3. VENTAS";
		gotoxy(22, 12); cout << "0. SALIR";
		gotoxy(32, 15); cout << "Opcion: ";

		gotoxy(40, 15); cin >> opcion;
		cin.ignore();

		switch (opcion)
		{
		case '1':
		{
			system("cls"); system("color F6");

			do
			{
				system("cls"); system("color F3");
				gotoxy(26,  5); cout << "CATALOGOS";
				gotoxy(22,  8); cout << "1. PUESTOS";
				gotoxy(22,  9); cout << "2. EMPLEADOS";
				gotoxy(22, 10); cout << "3. CLIENTES";
				gotoxy(22, 11); cout << "4. MARCAS";
				gotoxy(22, 12); cout << "5. PRODUCTOS";
				gotoxy(22, 13); cout << "6. PROVEEDORES";
				gotoxy(22, 15); cout << "0. REGRESAR AL MENU ANTERIOR";
				gotoxy(32, 18); cout << "Opcion: ";

				gotoxy(40, 18); cin >> opcion2;
				cin.ignore();

				switch (opcion2)
				{
				case '1':
				{
					system("cls"); system("color F6");

					do
					{
						catalogo = "PUESTOS";
						menucrud(catalogo);
						gotoxy(40, 16); cin >> opcion3;
						cin.ignore();

						switch (opcion3)
						{
						case '1':
						{
							system("cls"); system("color FC");

							cout << "--------------------------------------------------" << endl;
							cout << "--------INGRESE LOS SIGUIENTES VALORES------------" << endl << endl;

							cout << "Puesto: ";			getline(cin, puesto);

							Puesto p = Puesto(puesto, codigo);
							p.crear();
							p.leer();

							gotoxy(1, 25); _getch();
						}
						break;

						case '2':
						{
							system("cls"); system("color FC");

							Puesto p = Puesto();
							p.leer();

							gotoxy(1, 25); _getch();
						}
						break;

						case '3':
						{
							system("cls"); system("color FC");

							cout << endl << "---------------------------------------------------------------" << endl;
							cout << "--------INGRESE EL CODIGO DEL REGISTRO A ACTUALIZAR------------" << endl << endl;
							cout << "Codigo: ";			cin >> codigo;
							cin.ignore();
							cout << "--------VUELVA A INGRESAR LOS VALORES------------" << endl << endl;
							cout << "Puesto: ";			getline(cin, puesto);

							Puesto p = Puesto(puesto, codigo);
							p.actualizar();
							p.leer();

							gotoxy(1, 25); _getch();
						}
						break;

						case '4':
						{
							system("cls"); system("color FC");

							cout << endl << "---------------------------------------------------------------" << endl;
							cout << "--------INGRESE EL CODIGO DEL REGISTRO A ELIMINAR------------" << endl << endl;
							cout << "Codigo: ";			cin >> codigo;
							cin.ignore();

							Puesto p = Puesto(puesto, codigo);
							p.eliminar();
							p.leer();

							gotoxy(1, 25); _getch();
						}
						break;

						case '0':
							break;

						default:
						{
							gotoxy(28, 20); cout << "OPCION INVALIDA.";
							gotoxy(1, 25); _getch();
						}
						break;
						}
					} while (opcion3 != '0');
				}
				break;

				case '2':
				{
					system("cls"); system("color F6");

					do
					{
						catalogo = "EMPLEADOS";
						menucrud(catalogo);
						gotoxy(40, 16); cin >> opcion3;
						cin.ignore();

						switch (opcion3)
						{
						case '1':
						{
							system("cls"); system("color FC");

							cout << "--------------------------------------------------" << endl;
							cout << "--------INGRESE LOS SIGUIENTES VALORES------------" << endl << endl;

							cout << "Nombres: ";				getline(cin, nombres);
							cout << "Apellidos: ";				getline(cin, apellidos);
							cout << "Direccion: ";				getline(cin, direccion);
							cout << "Telefono: ";				getline(cin, telefono);
							cout << "DPI: ";					getline(cin, dpi);
							cout << "Genero: ";					cin >> genero;
							cin.ignore();
							cout << "Fecha Nacimiento: ";		getline(cin, fechanacimiento);
							cout << "Codigo Puesto: ";			cin >> idpuesto;
							cin.ignore();
							cout << "Fecha Inicio Labores: ";	getline(cin, fechainiciolabores);


							Empleado e = Empleado(nombres, apellidos, direccion, telefono, dpi, genero, fechanacimiento, idpuesto, fechainiciolabores, nit, codigo);
							e.crear();
							e.leer();

							gotoxy(1, 25); _getch();
						}
						break;

						case '2':
						{
							system("cls"); system("color FC");

							Empleado e = Empleado();
							e.leer();

							gotoxy(1, 25); _getch();
						}
						break;

						case '3':
						{
							system("cls"); system("color FC");

							cout << endl << "---------------------------------------------------------------" << endl;
							cout << "--------INGRESE EL CODIGO DEL REGISTRO A ACTUALIZAR------------" << endl << endl;
							cout << "Codigo: ";			cin >> codigo;
							cin.ignore();
							cout << "--------VUELVA A INGRESAR LOS VALORES------------" << endl << endl;
							cout << "Nombres: ";				getline(cin, nombres);
							cout << "Apellidos: ";				getline(cin, apellidos);
							cout << "Direccion: ";				getline(cin, direccion);
							cout << "Telefono: ";				getline(cin, telefono);
							cout << "DPI: ";					getline(cin, dpi);
							cout << "Genero: ";					cin >> genero;
							cin.ignore();
							cout << "Fecha Nacimiento: ";		getline(cin, fechanacimiento);
							cout << "Codigo Puesto: ";			cin >> idpuesto;
							cin.ignore();
							cout << "Fecha Inicio Labores: ";	getline(cin, fechainiciolabores);

							Empleado e = Empleado(nombres, apellidos, direccion, telefono, dpi, genero, fechanacimiento, idpuesto, fechainiciolabores, nit, codigo);
							e.actualizar();
							e.leer();

							gotoxy(1, 25); _getch();
						}
						break;

						case '4':
						{
							system("cls"); system("color FC");
							//string nombres, apellidos, nit, telefono, direccion, email;
							//int genero = 0, codigo = 0;

							cout << endl << "---------------------------------------------------------------" << endl;
							cout << "--------INGRESE EL CODIGO DEL REGISTRO A ELIMINAR------------" << endl << endl;
							cout << "Codigo: ";			cin >> codigo;
							cin.ignore();

							Empleado e = Empleado(nombres, apellidos, direccion, telefono, dpi, genero, fechanacimiento, idpuesto, fechainiciolabores, nit, codigo);
							e.eliminar();
							e.leer();

							gotoxy(1, 25); _getch();
						}
						break;

						case '0':
							break;

						default:
						{
							gotoxy(28, 20); cout << "OPCION INVALIDA.";
							gotoxy(1, 25); _getch();
						}
						break;
						}
					} while (opcion3 != '0');
				}
				break;


				case '3':
				{
					system("cls"); system("color F6");

					do
					{
						catalogo = "CLIENTES";
						menucrud(catalogo);
						gotoxy(40, 16); cin >> opcion3;
						cin.ignore();

						switch (opcion3)
						{
						case '1':
						{
							system("cls"); system("color FC");

							//string nombres, apellidos, nit, telefono, direccion, email;
							//int genero, codigo=0;

							cout << "--------------------------------------------------" << endl;
							cout << "--------INGRESE LOS SIGUIENTES VALORES------------" << endl << endl;

							cout << "Nombres: ";		getline(cin, nombres);
							cout << "Apellidos: ";		getline(cin, apellidos);
							cout << "NIT: ";			getline(cin, nit);
							cout << "Genero: ";			cin >> genero;
							cin.ignore();
							cout << "Telefono: ";		getline(cin, telefono);
							cout << "Email: ";			getline(cin, email);

							Cliente c = Cliente(nombres, apellidos, nit, genero, telefono, direccion, email, codigo);
							c.crear();
							c.leer();

							gotoxy(1, 25); _getch();
						}
						break;

						case '2':
						{
							system("cls"); system("color FC");

							Cliente c = Cliente();
							c.leer();

							gotoxy(1, 25); _getch();
						}
						break;

						case '3':
						{
							system("cls"); system("color FC");
							//string nombres, apellidos, nit, telefono, direccion, email;
							//int genero=0, codigo=0;

//							Cliente c = Cliente(nombres, apellidos, nit, genero, telefono, direccion, email, codigo);
//							c.leer();

							cout << endl << "---------------------------------------------------------------" << endl;
							cout << "--------INGRESE EL CODIGO DEL REGISTRO A ACTUALIZAR------------" << endl << endl;
							cout << "Codigo: ";			cin >> codigo;
							cin.ignore();
							cout << "--------VUELVA A INGRESAR LOS VALORES------------" << endl << endl;
							cout << "Nombres: ";		getline(cin, nombres);
							cout << "Apellidos: ";		getline(cin, apellidos);
							cout << "NIT: ";			getline(cin, nit);
							cout << "Genero: ";			cin >> genero;
							cin.ignore();
							cout << "Telefono: ";		getline(cin, telefono);
							cout << "Email: ";			getline(cin, email);

							Cliente c = Cliente(nombres, apellidos, nit, genero, telefono, direccion, email, codigo);
							c.actualizar();
							c.leer();

							gotoxy(1, 25); _getch();
						}
						break;

						case '4':
						{
							system("cls"); system("color FC");
							//string nombres, apellidos, nit, telefono, direccion, email;
							//int genero = 0, codigo = 0;

							cout << endl << "---------------------------------------------------------------" << endl;
							cout << "--------INGRESE EL CODIGO DEL REGISTRO A ELIMINAR------------" << endl << endl;
							cout << "Codigo: ";			cin >> codigo;
							cin.ignore();

							Cliente c = Cliente(nombres, apellidos, nit, genero, telefono, direccion, email, codigo);
							c.eliminar();
							c.leer();

							gotoxy(1, 25); _getch();
						}
						break;

						case '0':
							break;

						default:
						{
							gotoxy(28, 20); cout << "OPCION INVALIDA.";
							gotoxy(1, 25); _getch();
						}
						break;
						}
					} while (opcion3 != '0');
				}
				break;

				case '4':
				{
					system("cls"); system("color F6");

					do
					{
						catalogo = "MARCAS";
						menucrud(catalogo);
						gotoxy(40, 16); cin >> opcion3;
						cin.ignore();

						switch (opcion3)
						{
						case '1':
						{
							system("cls"); system("color FC");

							cout << "--------------------------------------------------" << endl;
							cout << "--------INGRESE LOS SIGUIENTES VALORES------------" << endl << endl;

							cout << "Marca: ";			getline(cin, marca);

							Marca m = Marca(marca, codigo);
							m.crear();
							m.leer();

							gotoxy(1, 25); _getch();
						}
						break;

						case '2':
						{
							system("cls"); system("color FC");

							Marca m = Marca();
							m.leer();

							gotoxy(1, 25); _getch();
						}
						break;

						case '3':
						{
							system("cls"); system("color FC");

							cout << endl << "---------------------------------------------------------------" << endl;
							cout << "--------INGRESE EL CODIGO DEL REGISTRO A ACTUALIZAR------------" << endl << endl;
							cout << "Codigo: ";			cin >> codigo;
							cin.ignore();
							cout << "--------VUELVA A INGRESAR LOS VALORES------------" << endl << endl;
							cout << "Marca: ";			getline(cin, marca);

							Marca m = Marca(marca, codigo);
							m.actualizar();
							m.leer();

							gotoxy(1, 25); _getch();
						}
						break;

						case '4':
						{
							system("cls"); system("color FC");

							cout << endl << "---------------------------------------------------------------" << endl;
							cout << "--------INGRESE EL CODIGO DEL REGISTRO A ELIMINAR------------" << endl << endl;
							cout << "Codigo: ";			cin >> codigo;
							cin.ignore();

							Marca m = Marca(marca, codigo);
							m.eliminar();
							m.leer();

							gotoxy(1, 25); _getch();
						}
						break;

						case '0':
							break;

						default:
						{
							gotoxy(28, 20); cout << "OPCION INVALIDA.";
							gotoxy(1, 25); _getch();
						}
						break;
						}
					} while (opcion3 != '0');
				}
				break;

				case '5':
				{
					system("cls"); system("color F6");

					do
					{
						catalogo = "PRODUCTOS";
						menucrud(catalogo);
						gotoxy(40, 16); cin >> opcion3;
						cin.ignore();

						switch (opcion3)
						{
						case '1':
						{
							system("cls"); system("color FC");

							cout << "--------------------------------------------------" << endl;
							cout << "--------INGRESE LOS SIGUIENTES VALORES------------" << endl << endl;

							cout << "Producto: ";		getline(cin, producto);
							cout << "Codigo Marca: ";	cin >> idmarca;
							cin.ignore();
							cout << "Descripcion: ";	getline(cin, descripcion);
							cout << "Imagen: ";			getline(cin, imagen);
							cout << "Precio Costo: ";	cin >> preciocosto;
							cin.ignore();
							cout << "Precio Venta: ";	cin >> precioventa;
							cin.ignore();
							cout << "Existencia: ";		cin >> existencia;
							cin.ignore();

							Producto prd = Producto(producto, idmarca, descripcion, imagen, preciocosto, precioventa, existencia, codigo);
							prd.crear();
							prd.leer();

							gotoxy(1, 25); _getch();
						}
						break;

						case '2':
						{
							system("cls"); system("color FC");

							Producto prd = Producto();
							prd.leer();

							gotoxy(1, 25); _getch();
						}
						break;

						case '3':
						{
							system("cls"); system("color FC");

							cout << endl << "---------------------------------------------------------------" << endl;
							cout << "--------INGRESE EL CODIGO DEL REGISTRO A ACTUALIZAR------------" << endl << endl;
							cout << "Codigo: ";			cin >> codigo;
							cin.ignore();
							cout << "--------VUELVA A INGRESAR LOS VALORES------------" << endl << endl;
							cout << "Producto: ";		getline(cin, producto);
							cout << "Codigo Marca: ";	cin >> idmarca;
							cin.ignore();
							cout << "Descripcion: ";	getline(cin, descripcion);
							cout << "Imagen: ";			getline(cin, imagen);
							cout << "Precio Costo: ";	cin >> preciocosto;
							cin.ignore();
							cout << "Precio Venta: ";	cin >> precioventa;
							cin.ignore();
							cout << "Existencia: ";		cin >> existencia;
							cin.ignore();

							Producto prd = Producto(producto, idmarca, descripcion, imagen, preciocosto, precioventa, existencia, codigo);
							prd.actualizar();
							prd.leer();

							gotoxy(1, 25); _getch();
						}
						break;

						case '4':
						{
							system("cls"); system("color FC");
							//string nombres, apellidos, nit, telefono, direccion, email;
							//int genero = 0, codigo = 0;

							cout << endl << "---------------------------------------------------------------" << endl;
							cout << "--------INGRESE EL CODIGO DEL REGISTRO A ELIMINAR------------" << endl << endl;
							cout << "Codigo: ";			cin >> codigo;
							cin.ignore();

							Producto prd = Producto(producto, idmarca, descripcion, imagen, preciocosto, precioventa, existencia, codigo);
							prd.eliminar();
							prd.leer();

							gotoxy(1, 25); _getch();
						}
						break;

						case '0':
							break;

						default:
						{
							gotoxy(28, 20); cout << "OPCION INVALIDA.";
							gotoxy(1, 25); _getch();
						}
						break;
						}
					} while (opcion3 != '0');
				}
				break;

				case '6':
				{
					system("cls"); system("color F6");

					do
					{
						catalogo = "PROVEEDORES";
						menucrud(catalogo);
						gotoxy(40, 16); cin >> opcion3;
						cin.ignore();

						switch (opcion3)
						{
						case '1':
						{
							system("cls"); system("color FC");

							cout << "--------------------------------------------------" << endl;
							cout << "--------INGRESE LOS SIGUIENTES VALORES------------" << endl << endl;

							cout << "Proveedor: ";		getline(cin, proveedor);
							cout << "NIT: ";			getline(cin, nit);
							cout << "Direccion: ";		getline(cin, direccion);
							cout << "Telefono: ";		getline(cin, telefono);

							Proveedor pr = Proveedor(proveedor, nit, direccion, telefono, codigo);
							pr.crear();
							pr.leer();

							gotoxy(1, 25); _getch();
						}
						break;

						case '2':
						{
							system("cls"); system("color FC");

							Proveedor pr = Proveedor();
							pr.leer();

							gotoxy(1, 25); _getch();
						}
						break;

						case '3':
						{
							system("cls"); system("color FC");

							cout << endl << "---------------------------------------------------------------" << endl;
							cout << "--------INGRESE EL CODIGO DEL REGISTRO A ACTUALIZAR------------" << endl << endl;
							cout << "Codigo: ";			cin >> codigo;
							cin.ignore();
							cout << "--------VUELVA A INGRESAR LOS VALORES------------" << endl << endl;
							cout << "Proveedor: ";		getline(cin, proveedor);
							cout << "NIT: ";			getline(cin, nit);
							cout << "Direccion: ";		getline(cin, direccion);
							cout << "Telefono: ";		getline(cin, telefono);

							Proveedor pr = Proveedor(proveedor, nit, direccion, telefono, codigo);
							pr.actualizar();
							pr.leer();

							gotoxy(1, 25); _getch();
						}
						break;

						case '4':
						{
							system("cls"); system("color FC");
							//string nombres, apellidos, nit, telefono, direccion, email;
							//int genero = 0, codigo = 0;

							cout << endl << "---------------------------------------------------------------" << endl;
							cout << "--------INGRESE EL CODIGO DEL REGISTRO A ELIMINAR------------" << endl << endl;
							cout << "Codigo: ";			cin >> codigo;
							cin.ignore();

							Proveedor pr = Proveedor(proveedor, nit, direccion, telefono, codigo);
							pr.eliminar();
							pr.leer();

							gotoxy(1, 25); _getch();
						}
						break;

						case '0':
							break;

						default:
						{
							gotoxy(28, 20); cout << "OPCION INVALIDA.";
							gotoxy(1, 25); _getch();
						}
						break;
						}
					} while (opcion3 != '0');
				}
				break;

				case '0':
					break;

				default:
				{
					gotoxy(28, 20); cout << "OPCION INVALIDA.";
					gotoxy(1, 25); _getch();
				}
				break;

				}
			} while (opcion2 != '0');

//			gotoxy(1, 25); _getch();
		}
		break;

		case '2':
		{
			system("cls"); system("color F6");

			gotoxy(1, 25); _getch();
		}
		break;

		case '3':
		{
			system("cls"); system("color F6");

			gotoxy(1, 25); _getch();
		}
		break;

		case '0':
			break;

		default:
		{
			gotoxy(28, 20); cout << "OPCION INVALIDA.";
			gotoxy(1, 25); _getch();
		}
		break;

		}
	} while (opcion != '0');

/*
    Cliente c = Cliente();
    c.leer();
*/
//    system("pause");
    return 0;
}

