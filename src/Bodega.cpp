#include "Bodega.h"
#include "Paquete.h"
#include <iostream>
#include <iomanip>
using namespace std;

Bodega::Bodega(string codigo, string nombre, int tipo, int filas, int columnas)
    : codigo(codigo), nombre(nombre), tipo(tipo), filas(filas), columnas(columnas) {
    // filas y columnas se validan (> 0) en el menu antes de crear la bodega
    matriz = new Celda*[filas];
    for (int i = 0; i < filas; i++) {
        matriz[i] = new Celda[columnas];
    }
}

Bodega::~Bodega() {
    for (int i = 0; i < filas; i++) {
        delete[] matriz[i];
    }
    delete[] matriz;
}

string Bodega::getCodigo() const { return codigo; }
string Bodega::getNombre() const { return nombre; }
int Bodega::getTipo() const { return tipo; }
int Bodega::getFilas() const { return filas; }
int Bodega::getColumnas() const { return columnas; }

string Bodega::getNombreTipo() const {
    switch (tipo) {
        case 1: return "General";
        case 2: return "Fragil";
        case 3: return "Tecnologia";
        case 4: return "Documentos";
        default: return "Desconocido";
    }
}

bool Bodega::posicionValida(int f, int c) const {
    return f >= 0 && f < filas && c >= 0 && c < columnas;
}

bool Bodega::estaLibre(int f, int c) const {
    return posicionValida(f, c) && matriz[f][c].estaLibre();
}

Paquete* Bodega::getPaquete(int f, int c) const {
    if (!posicionValida(f, c)) return nullptr;
    return matriz[f][c].getPaquete();
}

bool Bodega::asignarPaquete(int f, int c, Paquete* p) {
    if (p == nullptr || !estaLibre(f, c)) return false;
    matriz[f][c].ocupar(p);
    return true;
}

bool Bodega::liberarPosicion(int f, int c) {
    if (!posicionValida(f, c) || matriz[f][c].estaLibre()) return false;
    matriz[f][c].liberar();
    return true;
}

int Bodega::totalCeldas() const { return filas * columnas; }

int Bodega::celdasOcupadas() const {
    int n = 0;
    for (int i = 0; i < filas; i++)
        for (int j = 0; j < columnas; j++)
            if (!matriz[i][j].estaLibre()) n++;
    return n;
}

int Bodega::celdasLibres() const { return totalCeldas() - celdasOcupadas(); }

double Bodega::porcentajeOcupacion() const {
    return (double)celdasOcupadas() / totalCeldas() * 100.0;
}

double Bodega::porcentajeDisponible() const {
    return (double)celdasLibres() / totalCeldas() * 100.0;
}

bool Bodega::estaVacia() const { return celdasOcupadas() == 0; }

// Si filas y columnas son de un digito: A-12. Si no: A-1,12
string Bodega::etiquetaCelda(int f, int c) const {
    if (filas <= 10 && columnas <= 10)
        return codigo + "-" + to_string(f) + to_string(c);
    return codigo + "-" + to_string(f) + "," + to_string(c);
}

void Bodega::mostrarMatriz() const {
    cout << "\nBodega " << codigo << " - " << nombre
         << " (" << getNombreTipo() << ") " << filas << "x" << columnas << "\n\n";
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++)
            cout << "| " << left << setw(10) << etiquetaCelda(i, j) << " ";
        cout << "|\n";
        for (int j = 0; j < columnas; j++) {
            string estado = matriz[i][j].estaLibre()
                ? "LIBRE" : matriz[i][j].getPaquete()->getCodigo();
            cout << "| " << left << setw(10) << estado << " ";
        }
        cout << "|\n";
       for (int j = 0; j < columnas; j++) cout << "+------------";
        cout << "+\n";
    }
}

void Bodega::mostrarResumen() const {
    cout << "Bodega " << codigo << " | " << nombre << " | " << getNombreTipo()
         << " | Celdas: " << totalCeldas()
         << " | Ocupadas: " << celdasOcupadas()
         << " | Libres: " << celdasLibres()
         << " | Ocupacion: " << fixed << setprecision(2)
         << porcentajeOcupacion() << "%" << endl;
}