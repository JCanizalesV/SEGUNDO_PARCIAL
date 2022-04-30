
#include <mysql.h>
#include <iostream>
#include "Carnet.h"

using namespace std;

int main()
{
    string carne, nombres, apellidos, direccion, email, fecha_nacimiento;
    int id_estudiante, telefono, genero, menu;


    do
    {
        system("cls");

        cout << "                   .: CRUD MENU :.                   " << endl;
        cout << "" << endl;
        cout << "1.------        CREAR NUEVO PROVEEDOR          %%%%%%" << endl;
        cout << "2.------         MOSTRAR PROVEEDORES           %%%%%%" << endl;
        cout << "3.------         ACTUALIZAR PROVEEDOR          %%%%%%" << endl;
        cout << "4.------          ELIMINAR PROVEEDOR           %%%%%%" << endl;
        cout << "5.------    Presione para 0 finalizar el programa    %%%%%%" << endl;
        cout << "" << endl;


        cout << "Ingrese la opcion que desea realizar:       ";
        cin >> menu;
        cout << "" << endl;

        if (menu == 1)
        {
            system("cls");

            cout << "1.------        INGRESAR NUEVO ESTUDIANTE          %%%%%%" << endl;
            cout << "" << endl;

            cout << "Ingrese Carnet del Estudiante:                 "; cin >> carne;
            cout << "Ingrese Nombres:                               "; cin >> nombres;
            cout << "Ingrese Apellidos:                             "; cin >> apellidos;
            cout << "Ingrese Direccion:                             "; cin >> direccion;
            cout << "Ingrese Telefono:                              "; cin >> telefono;
            cout << "Ingrese Genero (0 = F/ 1= M):                  "; cin >> genero;
            if (genero == 0) {
                cout << "El genero ingresado es Femenino" << endl;
            }
            else {
                cout << "El genero ingresado es Masculino" << endl;
            }
            cout << "Ingrese Email:                                 "; cin >> email;
            cout << "Ingrese Fecha de Nacimiento (AAAA-MM-DD):      "; cin >> fecha_nacimiento;
            cout << "" << endl;

            Carnet c = Carnet(IGNORE(id_estudiante), nombres, apellidos, direccion, telefono, genero, email, fecha_nacimiento, carne);
            c.crear();

            cout << "" << endl;
            system("pause");
        }

        if (menu == 2)
        {
            system("cls");

            cout << "2.------         MOSTRAR PROVEEDORES           %%%%%%" << endl;
            cout << "" << endl;

            Carnet c = Carnet();
            c.mostrar();

            cout << "" << endl;
            system("pause");
        }

        if (menu == 3)
        {
            system("cls");

            cout << "3.------         ACTUALIZAR ESTUDIANTE          %%%%%%" << endl;
            cout << "" << endl;

            cout << "Ingrese el ID del Estudiante que desea actualizar o modificar:      "; cin >> id_estudiante;
            cout << "" << endl;

            cout << "Ingrese Carnet del Estudiante:                 "; cin >> carne;
            cout << "Ingrese Nombres:                               "; cin >> nombres;
            cout << "Ingrese Apellidos:                             "; cin >> apellidos;
            cout << "Ingrese Direccion:                             "; cin >> direccion;
            cout << "Ingrese Telefono:                              "; cin >> telefono;
            cout << "Ingrese Genero (F / M):                        "; cin >> genero;
            cout << "Ingrese Email:                                 "; cin >> email;
            cout << "Ingrese Fecha de Nacimiento (AAAA-MM-DD):      "; cin >> fecha_nacimiento;
            cout << "" << endl;

            Carnet c = Carnet(id_estudiante, nombres, apellidos, direccion, telefono, genero, email, fecha_nacimiento, carne);
            c.actualizar();

            cout << "" << endl;
            system("pause");
        }

        if (menu == 4)
        {
            system("cls");

            cout << "4.------          ELIMINAR ESTUDIANTE           %%%%%%" << endl;
            cout << "" << endl;


            cout << "Ingrese el ID del estudiante que desea eliminar:    ";

            Carnet c = Carnet();
            c.borrar();

            cout << "" << endl;
            system("pause");
        }
    } while (menu != 0);

    cout << "EL PROGRAMA SE FINALIZO CON EXITO........." << endl;
    cout << "" << endl;
    return 0;
}
