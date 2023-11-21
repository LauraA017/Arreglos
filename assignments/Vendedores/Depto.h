#ifndef DEPTO_h
#define DEPTO_h
#include <iostream>

class Depto {
    public:
        Depto();
        Depto(int i, std::string n);
        int getIdDep() const;
        std::string getNombre() const;
        void setIdDep(int i);
        void setNombre(std::string n);
        void imprime() const;
    private:
        int idDep;
        std::string nombre;
};

#endif