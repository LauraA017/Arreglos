#include "Vendedor.h"

Vendedor::Vendedor(){
    nombre = "Dummy";
    ventas = 0;
}

Vendedor::Vendedor(std::string _nombre, double _ventas, Depto _departamento){
    nombre = _nombre;
    ventas = _ventas;
    departamento = _departamento;
}

double Vendedor::getVentas() const{
    return ventas;
}

std::string Vendedor::getNombre() const{
    return nombre;
}

void Vendedor::setVentas(double _ventas){
    ventas = _ventas;
}

void Vendedor::setNombre(std::string _nombre) {
    nombre = _nombre;
}

Depto Vendedor::getDepartamento() const{
    return departamento;
}

void Vendedor::setDepartamento(Depto _departamento) {
    departamento = _departamento;
}

void Vendedor::imprime(){
    std::cout << "------------------------------------------------" << std::endl;
    std::cout << "Nombre: " << nombre << std::endl;
    departamento.imprime();
    std::cout << "Ventas: " << ventas << std::endl;
    std::cout << "------------------------------------------------" << std::endl;
}