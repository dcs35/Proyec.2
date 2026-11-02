#ifndef CLIENTE_H
#define CLIENTE_H
#include <string>
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
    virtual bool datosValidos() const;
    virtual double getDescuento() const;
    virtual void mostrar() const;
};
#endif
