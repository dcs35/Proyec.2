#include "Centro.h"
#include "ListaBodegas.h"
// Descomenten cada include cuando exista la lista:
// #include "ListaClientes.h"
// #include "ListaColaboradores.h"
// #include "ListaPaquetes.h"
// #include "ListaSolicitudes.h"
// #include "ListaDespachos.h"
#include <iostream>
using namespace std;

Centro::Centro() {
    codigo = "";
    nombre = "";
    provincia = "";
    direccion = "";
    telefono = "";
    clientes = nullptr;        // TODO: new ListaClientes();
    colaboradores = nullptr;   // TODO: new ListaColaboradores();
    bodegas = new ListaBodegas();
    paquetes = nullptr;        // TODO: new ListaPaquetes();
    solicitudes = nullptr;     // TODO: new ListaSolicitudes();
    despachos = nullptr;       // TODO: new ListaDespachos();
}

Centro::Centro(string cod, string nom, string prov, string dir, string tel) {
    codigo = cod;
    nombre = nom;
    provincia = prov;
    direccion = dir;
    telefono = tel;
    clientes = nullptr;        // TODO: new ListaClientes();
    colaboradores = nullptr;   // TODO: new ListaColaboradores();
    bodegas = new ListaBodegas();
    paquetes = nullptr;        // TODO: new ListaPaquetes();
    solicitudes = nullptr;     // TODO: new ListaSolicitudes();
    despachos = nullptr;       // TODO: new ListaDespachos();
}

Centro::~Centro() {
    // TODO: delete clientes; delete colaboradores; delete paquetes;
    //       delete solicitudes; delete despachos;
    delete bodegas;
}

string Centro::getCodigo() const { return codigo; }
string Centro::getNombre() const { return nombre; }
string Centro::getProvincia() const { return provincia; }
string Centro::getDireccion() const { return direccion; }
string Centro::getTelefono() const { return telefono; }

void Centro::setNombre(string nom) { nombre = nom; }
void Centro::setProvincia(string prov) { provincia = prov; }
void Centro::setDireccion(string dir) { direccion = dir; }
void Centro::setTelefono(string tel) { telefono = tel; }

ListaClientes* Centro::getClientes() const { return clientes; }
ListaColaboradores* Centro::getColaboradores() const { return colaboradores; }
ListaBodegas* Centro::getBodegas() const { return bodegas; }
ListaPaquetes* Centro::getPaquetes() const { return paquetes; }
ListaSolicitudes* Centro::getSolicitudes() const { return solicitudes; }
ListaDespachos* Centro::getDespachos() const { return despachos; }

bool Centro::datosValidos() const {
    if (codigo == "" || nombre == "" || provincia == "" || direccion == "" || telefono == "") {
        return false;
    }
    return true;
}

bool Centro::tieneDatosAsociados() const {
    if (!bodegas->estaVacia()) return true;
    // TODO: cuando existan las demas listas, agregar:
    // if (!clientes->estaVacia()) return true;
    // if (!colaboradores->estaVacia()) return true;
    // if (!paquetes->estaVacia()) return true;
    // if (!solicitudes->estaVacia()) return true;
    // if (!despachos->estaVacia()) return true;
    return false;
}

void Centro::mostrar() const {
    cout << "******************* CENTRO DE DISTRIBUCION **************************" << endl;
    cout << "Codigo: " << codigo << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Provincia: " << provincia << endl;
    cout << "Direccion: " << direccion << endl;
    cout << "Telefono: " << telefono << endl;
}