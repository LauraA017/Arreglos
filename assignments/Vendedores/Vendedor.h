#ifndef VENDEDOR_h
#define VENDEDOR_h
#include "Depto.h"

class Vendedor {
public:
    Vendedor();
    Vendedor(std::string, double, Depto);
    std::string getNombre() const;
    Depto getDepartamento() const;
    double getVentas() const;
    void setNombre(std::string);
    void setDepartamento(Depto);
    void setVentas(double);
    void imprime();
private:
    std::string nombre;
    double ventas;
    Depto departamento;
};

#endif //VENDEDOR_H