#include "Vendedor.h"
#include <iostream>

Vendedor::Vendedor() : nombre{"Dummy"}, ventas{0}{}

Vendedor::Vendedor(const std::string& _nombre, double _ventas, const Depto& _departamento)
    : nombre(_nombre), ventas(_ventas), departamento(_departamento){}

double Vendedor::getVentas() const{
    return ventas;
}

std::string Vendedor::getNombre() const{
    return nombre;
}

void Vendedor::setVentas(double _ventas){
    ventas = _ventas;
}

void Vendedor::setNombre(std::string _nombre){
    nombre = _nombre;
}

Depto Vendedor::getDepartamento() const{
    return departamento;
}

void Vendedor::setDepartamento(Depto _departamento){
    departamento = _departamento;
}

void Vendedor::imprime() const{
    std::cout << "------------------------------------------------" << std::endl;
    std::cout << "Nombre: " << nombre << std::endl;
    departamento.imprime();
    std::cout << "Ventas: " << ventas << std::endl;
    std::cout << "------------------------------------------------" << std::endl;
}
