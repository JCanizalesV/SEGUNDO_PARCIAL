#pragma once

#include <iostream>

using namespace std;

class Estudiante
{

protected: string nombres, apellidos, direccion, email, fecha_nacimiento;
		 int id_estudiante=0, telefono=0, genero=0;

protected:
	Estudiante() {
	}
	Estudiante(int id, string nom, string ape, string dir, int tel, int gen, string mail, string fn) {
		id_estudiante = id;
		nombres = nom;
		apellidos = ape;
		direccion = dir;
		telefono = tel;
		genero = gen;
		email = mail;
		fecha_nacimiento = fn;
	}


};

