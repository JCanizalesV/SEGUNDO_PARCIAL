#pragma once

#include <mysql.h>
#include <iostream>
#include <string>
#include "ConexionBD.h"
#include "Estudiante.h"

using namespace std;


class Carnet : Estudiante {

private: string carne;

public:
	Carnet() {
	}
	Carnet(int id, string nom, string ape, string dir, int tel, int gen, string mail, string fn, string car) : Estudiante(id, nom, ape, dir, tel, gen, mail, fn) {
		carne = car;
	}

	//set (modificar)
	void setid_estudiante(int id) { id_estudiante = id; }
	void setCarne(string car) { carne = car; }
	void setNombres(string nom) { nombres = nom; }
	void setApellidos(string ape) { apellidos = ape; }
	void setDireccion(string dir) { direccion = dir; }
	void setTelefono(int tel) { telefono = tel; }
	void setGenero(int gen) { genero = gen; }
	void setEmail(string mail) { email = mail; }
	void setFecha(string fn) { fecha_nacimiento = fn; }

	//get (mostrar)
	int getid_estudiante() { return id_estudiante; }
	string getCarne() { return carne; }
	string getNombres() { return nombres; }
	string getApellidos() { return apellidos; }
	string getDireccion() { return direccion; }
	int getTelefono() { return telefono; }
	int getGenero() { return genero; }
	string getEmail() { return email; }
	string getFecha() { return fecha_nacimiento; }


// CRUD......


	void crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string t = to_string(telefono);
			string g = to_string(genero);
			string insert = "INSERT INTO segundo_parcial.estudiantes(carnet, nombres, apellidos, direccion, telefono, genero, email, fecha_nacimiento) VALUES('"+ carne +"', '"+nombres+"', '"+apellidos + "', '" + direccion + "', " + t + ", b'" + g + "', '" + email + "', '" + fecha_nacimiento +"'); ";
			const char* i = insert.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "El ingreso de los datos se ha realizado con exito....." << endl;
			}
			else {
				cout << "" << endl;
				cout << "El ingreso de los datos produjo un error, vuelva a intentar..." << endl;
			}
		}
		else {
			cout << "------....ERROR EN LA CONEXION....------" << endl;
		}
		cn.cerrar_conexion();
	}


	void mostrar() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getConectar()) {
			string d = to_string(id_estudiante);
			string consulta = "SELECT * FROM segundo_parcial.estudiantes";
		
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());

			while (fila = mysql_fetch_row(resultado)) {
				cout << fila[0] << " , " << fila[1] << " , " << fila[2] << " , " << fila[3] << " , " << fila[4] << " , " << fila[5] << " , " << fila[6] << " , ";
				cout << fila[7] << " , " << fila[8] << endl;
				cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
				}
			}
			else {
				cout << "----...Error al solicitar los datos...----" << endl;
			}
		}
		else {
			cout << "-----...ERROR EN LA CONEXION...-----" << endl;
		}
		cn.cerrar_conexion();
	}


	void actualizar() {
		int q_estado;
		int ac;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {

			string t = to_string(telefono);
			string g = to_string(genero);
			string d = to_string(id_estudiante);

			string actualizar = "UPDATE segundo_parcial.estudiantes SET carnet = '" + carne + "', nombres = '" + nombres + "', apellidos = '" + apellidos + "', direccion= '" + direccion + "', telefono = " + t + ", genero = " + g + ", email = '" + email + "', fecha_nacimiento = '" + fecha_nacimiento + "' WHERE id_estudiante = " + d + "";
			const char* i = actualizar.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "El ID se actualizo con exito...." << endl;
			}
			else {
				cout << "Se presento un error al intentar actualizar el ID, vuelva a intentar...." << endl;
			}

		}
		else {
			cout << "-----...ERROR EN LA CONEXION...-----" << endl;
		}
		cn.cerrar_conexion();
	}

	void borrar() {
		int q_estado;
		int ac;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {

				cin >> id_estudiante;

			string t = to_string(telefono);
			string d = to_string(id_estudiante);

			string borrar = "DELETE FROM segundo_parcial.estudiantes WHERE id_estudiante=" + d + "";
			const char* i = borrar.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {

				cout << "" << endl;
				cout << "El ID del estudiante se elimino con exito...." << endl;
			}
			else {
				cout << "Se presento un error a la hora de eliminar el dato...." << endl;
			}
		}
		else {
			cout << "-----...ERROR EN LA CONEXION...-----" << endl;
		}
		cn.cerrar_conexion();
	}
};

