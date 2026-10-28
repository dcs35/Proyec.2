#ifndef COLABORADOR_H
#define COLABORADOR_H
#include <iostream>
using namespace std;

class Colaborador {
private:
    string identificacion;
    string nombre;
    string fechaIngreso;
    string puesto;
public:
    Colaborador();
    Colaborador(string, string, string, string);
    string getIdentificacion() const;
    string getNombre() const;
    string getFechaIngreso() const;
    string getPuesto() const;
    void setNombre(string);
    void setFechaIngreso(string);
    void setPuesto(string);
    bool datosValidos() const;
    void mostrar() const;
};
#endif
