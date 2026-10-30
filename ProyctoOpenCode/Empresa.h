#ifndef EMPRESA_H
#define EMPRESA_H
#include "Cliente.h"
using namespace std;

class Empresa : public Cliente {
private:
    string actividadEconomica;
    double porcentajeDescuento;
public:
    Empresa();
    Empresa(string, string, string, string, string, double);
    string getActividadEconomica() const;
    double getPorcentajeDescuento() const;
    void setActividadEconomica(string);
    bool setPorcentajeDescuento(double);
    bool datosValidos() const;
    double getDescuento() const;
    void mostrar() const;
};
#endif
