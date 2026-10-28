
#ifndef CENTRO_H
#define CENTRO_H
#include <iostream>
using namespace std;

class Centro {
private:
    string codigo;
    string nombre;
    string provincia;
    string direccion;
    string telefono;
    ListaClientes* clientes;
    ListaColaboradores* colaboradores;
    ListaBodegas* bodegas;
    ListaPaquetes* paquetes;
    ListaSolicitudes* solicitudes;
    ListaDespachos* despachos;

public:
    Centro();
    Centro(string, string, string, string, string);
    ~Centro();
    string getCodigo() const;
    string getNombre() const;
    string getProvincia() const;
    string getDireccion() const;
    string getTelefono() const;
    void setNombre(string);
    void setProvincia(string);
    void setDireccion(string);
    void setTelefono(string);
    bool datosValidos() const;
    void mostrar() const;
    bool tieneDatosAsociados() const;
};

#endif
