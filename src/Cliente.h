#ifndef CLIENTE_H
#define CLIENTE_H
#include <iostream>
using namespace std;

class Cliente {
private:
    string identificacion;
    string nombre;
    string telefono;
    string correo;
public:
    Cliente();
    Cliente(string, string, string, string);
    virtual ~Cliente();
    string getIdentificacion() const;
    string getNombre() const;
    string getTelefono() const;
    string getCorreo() const;
    void setNombre(string);
    void setTelefono(string);
    void setCorreo(string);
    virtual void mostrar() const;
};
#endif
