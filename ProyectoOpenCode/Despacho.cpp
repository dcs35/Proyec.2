#include "Despacho.h"
#include "Solicitud.h"
#include "Paquete.h"
#include "Cliente.h"
#include "Colaborador.h"
#include "Centro.h"
#include "Utilidades.h"
#include <iostream>
using namespace std;

Despacho::Despacho() {
    codigo = "";
    solicitud = nullptr;
    paquete = nullptr;
    cliente = nullptr;
    responsable = nullptr;
    centroOrigen = nullptr;
    destino = "";
    fecha = "";
    hora = "";
    estado = 1;
}

Despacho::Despacho(string cod, Solicitud* sol, Paquete* paq, Cliente* cli,
                   Colaborador* resp, Centro* origen, string dest,
                   string fec, string hor) {
    codigo = cod;
    solicitud = sol;
    paquete = paq;
    cliente = cli;
    responsable = resp;
    centroOrigen = origen;
    destino = dest;
    fecha = fec;
    hora = hor;
    estado = 1;
}

string Despacho::getCodigo() const { return codigo; }
Solicitud* Despacho::getSolicitud() const { return solicitud; }
Paquete* Despacho::getPaquete() const { return paquete; }
Cliente* Despacho::getCliente() const { return cliente; }
Colaborador* Despacho::getResponsable() const { return responsable; }
Centro* Despacho::getCentroOrigen() const { return centroOrigen; }
string Despacho::getDestino() const { return destino; }
string Despacho::getFecha() const { return fecha; }
string Despacho::getHora() const { return hora; }
int Despacho::getEstado() const { return estado; }

bool Despacho::datosValidos() const {
    return codigo != "" && solicitud != nullptr && paquete != nullptr
           && cliente != nullptr && responsable != nullptr && centroOrigen != nullptr;
}

bool Despacho::finalizar() {
    if (estado != 1) {
        return false;
    }
    estado = 2;
    return true;
}

void Despacho::mostrar() const {
    cout << "************* DESPACHO *************" << endl;
    cout << "Codigo: " << codigo << endl;
    cout << "Solicitud: " << (solicitud != nullptr ? solicitud->getCodigo() : "(sin solicitud)") << endl;
    cout << "Paquete: " << (paquete != nullptr ? paquete->getCodigo() : "(sin paquete)") << endl;
    cout << "Cliente: " << (cliente != nullptr ? cliente->getNombre() : "(sin cliente)") << endl;
    cout << "Responsable: " << (responsable != nullptr ? responsable->getNombre() : "(sin responsable)") << endl;
    cout << "Centro origen: " << (centroOrigen != nullptr ? centroOrigen->getCodigo() : "(sin centro)") << endl;
    cout << "Destino: " << destino << endl;
    cout << "Fecha: " << fecha << "  Hora: " << hora << endl;
    cout << "Estado: " << nombreEstadoDespacho(estado) << endl;
}
