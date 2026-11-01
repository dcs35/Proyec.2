#include "Paquete.h"
#include "Cliente.h"
#include "Centro.h"
#include "Bodega.h"
#include "Colaborador.h"
#include "Utilidades.h"
#include <iostream>
using namespace std;

Paquete::Paquete() {
    codigo = "";
    descripcion = "";
    peso = 0;
    categoria = 0;
    propietario = nullptr;
    centro = nullptr;
    estado = 1;
    bodega = nullptr;
    fila = -1;
    columna = -1;
}

Paquete::Paquete(string cod, string desc, double pes, int cat, Cliente* prop, Centro* cent) {
    codigo = cod;
    descripcion = desc;
    peso = pes;
    categoria = cat;
    propietario = prop;
    centro = cent;
    estado = 1;
    bodega = nullptr;
    fila = -1;
    columna = -1;
}

string Paquete::getCodigo() const { return codigo; }
string Paquete::getDescripcion() const { return descripcion; }
double Paquete::getPeso() const { return peso; }
int Paquete::getCategoria() const { return categoria; }
Cliente* Paquete::getPropietario() const { return propietario; }
Centro* Paquete::getCentro() const { return centro; }
int Paquete::getEstado() const { return estado; }
Bodega* Paquete::getBodega() const { return bodega; }
int Paquete::getFila() const { return fila; }
int Paquete::getColumna() const { return columna; }

bool Paquete::tieneUbicacion() const {
    return bodega != nullptr && fila >= 0 && columna >= 0;
}

void Paquete::setDescripcion(string desc) { descripcion = desc; }
void Paquete::setPeso(double pes) { peso = pes; }
void Paquete::setCategoria(int cat) { categoria = cat; }

bool Paquete::categoriaValida(int cat) {
    return cat >= 1 && cat <= 4;
}

bool Paquete::datosValidos() const {
    return codigo != "" && descripcion != "" && peso > 0 && categoriaValida(categoria)
           && propietario != nullptr && centro != nullptr;
}

bool Paquete::transicionPermitida(int desde, int hasta) {
    if (desde == 1) {
        return hasta == 2 || hasta == 5;
    }
    if (desde == 2) {
        return hasta == 3 || hasta == 5;
    }
    if (desde == 3) {
        return hasta == 4 || hasta == 5;
    }
    if (desde == 5) {
        return hasta == 2 || hasta == 3;
    }
    return false;
}

bool Paquete::cambiarEstado(int nuevoEstado, string fecha, Colaborador* responsable) {
    if (!transicionPermitida(estado, nuevoEstado)) {
        return false;
    }
    int anterior = estado;
    estado = nuevoEstado;
    bitacora.agregar(anterior, nuevoEstado, fecha, responsable);
    return true;
}

void Paquete::asignarUbicacion(Bodega* bod, int f, int c) {
    bodega = bod;
    fila = f;
    columna = c;
}

void Paquete::liberarUbicacion() {
    bodega = nullptr;
    fila = -1;
    columna = -1;
}

bool Paquete::tieneBitacoraDe(Colaborador* colaborador) const {
    return bitacora.contieneColaborador(colaborador);
}

void Paquete::mostrar() const {
    cout << "************* PAQUETE *************" << endl;
    cout << "Codigo: " << codigo << endl;
    cout << "Descripcion: " << descripcion << endl;
    cout << "Peso: " << aTextoDecimal(peso) << " kg" << endl;
    cout << "Categoria: " << nombreCategoriaPaquete(categoria) << endl;
    cout << "Propietario: " << (propietario != nullptr ? propietario->getNombre() : "(sin cliente)") << endl;
    cout << "Centro: " << (centro != nullptr ? centro->getCodigo() : "(sin centro)") << endl;
    cout << "Estado: " << nombreEstadoPaquete(estado) << endl;
    if (tieneUbicacion()) {
        cout << "Ubicacion: Bodega " << bodega->getCodigo() << " celda " << bodega->codigoCelda(fila, columna) << endl;
    } else {
        cout << "Ubicacion: sin asignar" << endl;
    }
}

void Paquete::mostrarBitacora() const {
    cout << "Bitacora del paquete " << codigo << ":" << endl;
    bitacora.mostrar();
}
