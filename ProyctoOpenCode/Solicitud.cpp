#include "Solicitud.h"
#include "Cliente.h"
#include "Paquete.h"
#include "Colaborador.h"
#include "Centro.h"
#include "Utilidades.h"
#include <iostream>
using namespace std;

double Solicitud::tarifas[4] = {1500, 2000, 2500, 1000};

Solicitud::Solicitud() {
    codigo = "";
    cliente = nullptr;
    paquete = nullptr;
    responsable = nullptr;
    centroOrigen = nullptr;
    destino = "";
    fecha = "";
    costoEstimado = 0;
    estado = 1;
}

Solicitud::Solicitud(string cod, Cliente* cli, Paquete* paq, Colaborador* resp,
                     Centro* origen, string dest, string fec) {
    codigo = cod;
    cliente = cli;
    paquete = paq;
    responsable = resp;
    centroOrigen = origen;
    destino = dest;
    fecha = fec;
    estado = 1;
    costoEstimado = calcularCosto(paq, cli);
}

string Solicitud::getCodigo() const { return codigo; }
Cliente* Solicitud::getCliente() const { return cliente; }
Paquete* Solicitud::getPaquete() const { return paquete; }
Colaborador* Solicitud::getResponsable() const { return responsable; }
Centro* Solicitud::getCentroOrigen() const { return centroOrigen; }
string Solicitud::getDestino() const { return destino; }
string Solicitud::getFecha() const { return fecha; }
double Solicitud::getCostoEstimado() const { return costoEstimado; }
int Solicitud::getEstado() const { return estado; }

double Solicitud::tarifaPorCategoria(int categoria) {
    if (categoria >= 1 && categoria <= 4) {
        return tarifas[categoria - 1];
    }
    return 0;
}

double Solicitud::calcularCosto(Paquete* paq, Cliente* cli) {
    if (paq == nullptr) {
        return 0;
    }
    double base = paq->getPeso() * tarifaPorCategoria(paq->getCategoria());
    double descuento = 0;
    if (cli != nullptr) {
        descuento = cli->getDescuento();
    }
    if (descuento < 0 || descuento > 100) {
        descuento = 0;
    }
    return base - (base * descuento / 100);
}

bool Solicitud::datosValidos() const {
    return codigo != "" && cliente != nullptr && paquete != nullptr
           && responsable != nullptr && centroOrigen != nullptr && destino != ""
           && fecha != "";
}

bool Solicitud::esFinal() const {
    return estado == 2 || estado == 3 || estado == 4;
}

bool Solicitud::cambiarEstado(int nuevoEstado) {
    if (estado != 1) {
        return false;
    }
    if (nuevoEstado < 2 || nuevoEstado > 4) {
        return false;
    }
    estado = nuevoEstado;
    return true;
}

void Solicitud::mostrar() const {
    cout << "************* SOLICITUD *************" << endl;
    cout << "Codigo: " << codigo << endl;
    cout << "Cliente: " << (cliente != nullptr ? cliente->getNombre() : "(sin cliente)") << endl;
    cout << "Paquete: " << (paquete != nullptr ? paquete->getCodigo() : "(sin paquete)") << endl;
    cout << "Responsable: " << (responsable != nullptr ? responsable->getNombre() : "(sin responsable)") << endl;
    cout << "Centro origen: " << (centroOrigen != nullptr ? centroOrigen->getCodigo() : "(sin centro)") << endl;
    cout << "Destino: " << destino << endl;
    cout << "Fecha: " << fecha << endl;
    cout << "Costo estimado: " << aTextoDecimal(costoEstimado) << endl;
    cout << "Estado: " << nombreEstadoSolicitud(estado) << endl;
}
