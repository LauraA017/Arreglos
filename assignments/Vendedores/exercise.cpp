#include <iostream>
#include <fstream>
using namespace std;
#include "Vendedor.h"


int buscaDepartamento(Depto listaDept[], int cantDept, int idDeptoABuscar) {
    /*Función que busca un id de un departamento en el arreglo de departamentos
    si lo encuentra que regrese la posición del arreglo donde está, si no regresa -1*/
    for (int i = 0; i < cantDept; i++){ 
        if (listaDept[i].getIdDep()==idDeptoABuscar){
            return i;
        }

    }
    return -1;
}

string nombreDepartamento(Depto listaDept[], int cantDept, int idDeptoABuscar) {
    /*Función que busca un id de un departamento en el arreglo de departamentos
      si lo encuentra que regrese el nombre del departamento, si no lo encuentra regresa ""*/
    int index =  buscaDepartamento(listaDept, cantDept, idDeptoABuscar);
    if (index !=1 ){
        return listaDept[index].getNombre();
    } 
    return "";
}

void cargaDatosDepartamentos(Depto listaDeptos[], int &cantDeptos) {
    /*Carga datos del archivo Deptos.txt en listaDeptos y cantDeptos lo actualiza
      con el número de departamentos cargados del archivo*/
    ifstream archivo("Deptos.txt");
    if (!archivo) {
        cout << "Error al abrir el archivo Deptos.txt" << endl;
        return;
    }
    int id;
    string nombre;
    cantDeptos = 0;
    while(archivo>>id>>nombre){
        listaDeptos[cantDeptos]=Depto(id, nombre);
        cantDeptos++;
    }
    archivo.close();

}

void muestraDepartamentos(Depto listaDept[], int cantDep) {
    /*Muestra la lista de departamentos*/
    cout << "Departamentos de la tienda" << endl;
    for (int i = 0; i < cantDep; i++){
        listaDept[i].imprime();
    }
}

void cargaDatosVendedores(Vendedor listaVend[], int &cantVend, Depto listaDep[], int cantDep) {
    /* Función que regresa la listaVend y la cantVend con datos recibe el arreglo vacío
       y la variable cantVend sin inicializar y les pone valor en esta función*/
    ifstream archivo("Vendedores.txt");
    if (!archivo){
        cout << "Error al abrir el archivo Vendedores.txt" << endl;
        return;
    }
    string nombre;
    double ventas;
    int idDepto;
    cantVend = 0;
    while (archivo >> nombre >> ventas >> idDepto){
        int indexDepto = buscaDepartamento(listaDep, cantDep, idDepto);
        if (indexDepto != -1) {
            listaVend[cantVend] = Vendedor(nombre, ventas, listaDep[indexDepto]);
            cantVend++;
        }
    }
    archivo.close();
}

void muestraVendedores(Vendedor listaVen[], int cantVen) {
    /*Muestra la lista de vendedores*/
    cout<<"Vendedores:"<<endl;
    for (int i = 0; i < cantVen; i++){
        listaVen[i].imprime();
    }
    
}

void vendedoresPorDepartamento(Vendedor listaVen[], int cantVend, Depto listaDep[], int cantDept, int idDeptoAConsultar){
    /* Muestra los nombres de los vendedores de un departamento */
    cout <<"Vendedores del departamento" << nombreDepartamento(listaDep, cantDept, idDeptoAConsultar)<<":"<< endl;
    for (int i = 0; i < cantVend; i++){
        if (listaVen[i].getDepartamento().getIdDep() ==idDeptoAConsultar){
            cout << listaVen[i].getNombre() << endl;
        }
    }
}

int registrarVentas(Vendedor listaVend[], int cantVend) {
    /* Registra las ventas de un vendedor de la lista de vendedores existentes
       suma las ventas nuevas a las que ya estaban registradas */
    string nombre;
    double ventas;
    cout<<"Ingrese el nombre del vendedor:"<<endl;
    cin>>nombre;
    cout<<"Ingrese la cantidad de la venta:"<<endl;
    cin>> ventas;
    for (int i = 0; i < cantVend; i++){
        if(listaVend[i].getNombre()==nombre){
            listaVend[i].setVentas(listaVend[i].getVentas()+ventas);
            return 1;
        }
    }
    cout<<"Vendedor no registrado"<<endl;
    return 0;
}

int main() {
    const int MAX = 10;
    char opcion;
    int numDepto;
    Vendedor listaVendedores[MAX];
    int cantVendedores = 0;  // cantidad de empleados en la lista de empleados
    Depto listaDeptos[MAX]; // inicio el arreglo con Deptos default.
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
//Commit