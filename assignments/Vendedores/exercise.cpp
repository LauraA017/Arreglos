#include <iostream>
#include <fstream>
using namespace std;
#include "Vendedor.h"


int buscaDepartamento(Depto listaDept[], int cantDept, int idDeptoABuscar) {
    /*Función que busca un id de un departamento en el arreglo de departamentos
    si lo encuentra que regrese la posición del arreglo donde está, si no regresa -1*/


    return -1;
}

string nombreDepartamento(Depto listaDept[], int cantDept, int idDeptoABuscar) {
    /*Función que busca un id de un departamento en el arreglo de departamentos
      si lo encuentra que regrese el nombre del departamento, si no lo encuentra regresa ""*/
    
    return "";
}

void cargaDatosDepartamentos(Depto listaDeptos[], int &cantDeptos) {
    /*Carga datos del archivo Deptos.txt en listaDeptos y cantDeptos lo actualiza
      con el número de departamentos cargados del archivo*/
    int numDepartamento;
    string nombreDepartamento;

}

void muestraDepartamentos(Depto listaDept[], int cantDep) {
    /*Muestra la lista de departamentos*/
    cout << "Departamentos de la tienda" << endl;
    
}

void cargaDatosVendedores(Vendedor listaVend[], int &cantVend, Depto listaDep[], int cantDep) {
    /* Función que regresa la listaVend y la cantVend con datos recibe el arreglo vacío
       y la variable cantVend sin inicializar y les pone valor en esta función*/
    int idDep;
    string nom;
    double vent;
    int num;
    
}

void muestraVendedores(Vendedor listaVen[], int cantVen) {
    /*Muestra la lista de vendedores*/
    
}

void vendedoresPorDepartamento(Vendedor listaVen[], int cantVend, Depto listaDep[], int cantDept, int idDeptoAConsultar) {
    /* Muestra los nombres de los vendedores de un departamento */
    
}

int registrarVentas(Vendedor listaVend[], int cantVend) {
    /* Registra las ventas de un vendedor de la lista de vendedores existentes
       suma las ventas nuevas a las que ya estaban registradas */
}

int main() {
    char opcion;
    int numDepto;
    Vendedor listaVendedores[10];
    int cantVendedores;  // cantidad de empleados en la lista de empleados
    Depto listaDeptos[10]; // inicio el arreglo con Deptos default.
    int cantDeptos = 0;  // cantidad de departamentos en la lista de deptos
    cargaDatosDepartamentos(listaDeptos, cantDeptos);
    cargaDatosVendedores(listaVendedores, cantVendedores, listaDeptos, cantDeptos);
    do {
        cout << endl;
        cout << "Opciones disponibles " << endl;
        cout << " 1) Ver la lista de Departamentos " << endl;
        cout << " 2) Ver la lista de Vendedores " << endl;
        cout << " 3) Consultar vendedores de un departamento " << endl;
        cout << " 4) Registrar ventas "<< endl;
        cout << " 5) Terminar " << endl;
        cin >> opcion;
        switch (opcion) {
            case '1':
                muestraDepartamentos(listaDeptos, cantDeptos);
                cin.ignore();
                cout << "Enter para continuar...";
                cin.get();
                break;
            case '2':
                muestraVendedores(listaVendedores, cantVendedores);
                cin.ignore();
                cout << "Enter para continuar...";
                cin.get();
                break;
            case '3': 
                cout << "Teclea el departamento que quieres consultar " << endl;
                cin >> numDepto;
                vendedoresPorDepartamento(listaVendedores, cantVendedores, listaDeptos, cantDeptos, numDepto);
                cin.ignore();
                cout << "\nEnter para continuar...";
                cin.get();
                break;
            case '4': 
                registrarVentas(listaVendedores, cantVendedores);
                cin.ignore();
                cout << "Enter para continuar...";
                cin.get();
                break;
            case '5':
                cout << "Elegiste salir del programa..."<< endl;
                break;
            default:
                cout << "Opcion invalida"<<endl;
        }
        system("clear");
    } while (opcion != '5');
    return 0;
}