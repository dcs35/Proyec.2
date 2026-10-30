#ifndef PAQUETE_H
#define PAQUETE_H
#include <string>
using namespace std;

class Paquete {
private:
    string codigo;
public:
    Paquete(string codigo) : codigo(codigo) {}
    string getCodigo() const { return codigo; }
};

#endif